#include "../include/book.h"

// char* getstr(char *buffer) {
//     int c;
//     while ((c = getchar()) == '\n');
//     do {
//         buffer = (char) c;
//         buffer++;
//     } while((c = getchar()) != '\n');
//     return buffer;
// }

Book_t* book_init(const char *books_path) {
    FILE *file = fopen(books_path, "r");
    
    if (NULL == file) {
        err_msg("In func 'book_init': 'file' opening err");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    int file_len = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *line = (char*) calloc(file_len, sizeof(char));
    
    if (NULL == line) {
        err_msg("In func 'book_init': 'line' calloc err");
        exit(EXIT_FAILURE);
    }

    Book_t *books_list = NULL;
    Book_t *temp = NULL;

    while (fgets(line, file_len, file) != NULL) {
        books_list = (Book_t*) malloc(sizeof(Book_t));
        if (NULL == books_list) {
            err_msg("In func 'book_init': 'books_list' malloc err");
            exit(EXIT_FAILURE);
        }
        books_list->next = temp;
        books_list->prev = NULL;
        if (NULL != temp) {
            temp->prev = books_list;
        }
        temp = books_list;
        books_list->authors = (char*) calloc(file_len, sizeof(char));
        books_list->title = (char*) calloc(file_len, sizeof(char));
        if (NULL == books_list->authors) {
            err_msg("In func '__book_parse': 'books_list->authors' calloc err");
            exit(EXIT_FAILURE);
        }
        if (NULL == books_list->title) {
            err_msg("In func '__book_parse': 'books_list->title' calloc err");
            exit(EXIT_FAILURE);
        }

        char *substr = (char*) calloc (file_len, sizeof(char));
        if (NULL == substr) {
            err_msg("In func '__book_parse': 'substr' calloc err");
            exit(EXIT_FAILURE);
        }
        strcpy(substr, line);
        

        books_list->isbn = atoll(strtok(substr, ","));
        books_list->authors = strtok(NULL, ","); //  what?
        books_list->title = strtok(NULL, ",");
        books_list->total = atoi(strtok(NULL, ","));
        books_list->availible = atoi(strtok(NULL, ","));
        // yeah, memory leak!!!!
        //free(substr);   // what the fuck is going here?
        substr = NULL;
    }
    fclose(file);
    free(line);
    log_msg("'book_init': success");
    return books_list;
}

Book_t* book_find(Book_t *books_list, unsigned long long isbn) {
    while (books_list != NULL) {
        if (books_list->isbn == isbn)
            return books_list;
        books_list = books_list->next;
    }
    return NULL;
} 

bool book_isExist(Book_t *books_list, unsigned long long isbn) {
    return (book_find(books_list, isbn) != NULL) ? true : false;
}

void book_add(Book_t **books_list_ptr) {
    unsigned long long isbn = 0;
    printf("Enter new book's isbn:\n");
    scanf("%llu", &isbn);

    if (book_isExist(*books_list_ptr, isbn)) {
        err_msg("The operation can't be executed: a book with such ISBN exists\n");
        return;
    }
    Book_t *temp = (Book_t*) malloc(sizeof(Book_t));
    if (NULL == temp) {
        err_msg("In func 'book_addNew': 'temp' malloc err");
        exit(EXIT_FAILURE);
    }

    int len = BOOK_H_BASE_LEN;
    temp->isbn = isbn;
    temp->title = (char*) calloc(len, sizeof(char));
    temp->authors = (char*) calloc(len, sizeof(char));

    if (NULL == temp->authors) {
        err_msg("In func 'book_addNew': 'temp->authors' calloc err");
        return;
    }
    if (NULL == temp->title) {
        err_msg("In func 'book_addNew': 'temp->title' calloc err");
        return;
    }
    printf("Enter new book's authors:\n");
    scanf(" %[^\n]s", temp->authors);  // scanf() reading ends at gap
    printf("Enter new book's title:\n");
    scanf(" %[^\n]s", temp->title);  // scanf() reading ends at gap
    printf("Enter new book's total number:\n");
    scanf("%u", &(temp->total));

    temp->availible = temp->total;
    temp->next = (*books_list_ptr);
    (*books_list_ptr)->prev = temp;
    temp->prev = NULL;
    (*books_list_ptr) = temp;

    printf("book_addNew: Success!\n");
}

void book_del(Book_t **books_list_ptr, unsigned long long isbn) {
    Book_t *book = book_find(*books_list_ptr, isbn);
    if (NULL == book) {
        err_msg("'book_del' - The operation can't be executed: a book with such ISBN doesn't exists\n");
        return;
    }
    if (book->availible != book->total) {
        err_msg("'book_del' - The operation can't be executed: not all books have been returned\n");
        return;
    }

    // left edge (head)
    if (book->prev == NULL && book->next != NULL) {
        (*books_list_ptr)->next->prev = NULL;
        (*books_list_ptr) = book->next;
    } 
    // right edge
    else if (book->next == NULL && book->prev != NULL){
        book->prev->next = NULL;
    }
    // for any
    else {
        book->prev->next = book->next;
        book->next->prev = book->prev;
    }
    
    // free(book->authors);
    // free(book->title);
    // free(book);
    printf("book_del: Success!\n");
}

void book_info(Book_t *books_list, unsigned long long isbn) {
    Book_t *book = book_find(books_list, isbn);
    if (NULL == book) {
        err_msg("The operation can't be executed: a book with such ISBN doesn't exists\n");
        return;
    }
    printf("ISBN: %15llu\n", book->isbn);
    printf("Title: %15s\n", book->title);    
    printf("Authors: %15s\n", book->authors);
    printf("Total: %15u\n", book->total);
    printf("Availible: %15u\n", book->availible);
}

/**
 * @brief sorting of books by ISBN
 * @param books_list pointer to list of 'Book_t' type
 * @returns sorted array of pointers to Book_t 
*/
struct ArrayBook_s* __book_sortByISBN(Book_t *books_list) {
    int len = BOOK_H_BASE_ARRAY_LEN; 
    int books_added = 0;

    struct ArrayBook_s* array_struct = (struct ArrayBook_s*) malloc(sizeof(struct ArrayBook_s));
    if (NULL == array_struct) {
        err_msg("In func '__book_sortByISBN': 'books_array_struct' malloc err");
        return NULL;
    }

    array_struct->books_array = (Book_t**) calloc(len, sizeof(Book_t*));
    
    if (NULL == array_struct->books_array) {
        err_msg("In func '__book_sortByISBN': 'books_array' calloc err");
        return NULL;
    }

    // adding pointers to array
    while (books_list != NULL) {
        if (books_added >= len) {
            len *= 2;
            array_struct->books_array = (Book_t**) 
                realloc(array_struct->books_array, len * sizeof(Book_t*));
            
            if (NULL == array_struct->books_array) {
                err_msg("In func '__book_sortByISBN': 'books_array' realloc err");
                return NULL;
            }
        }
        array_struct->books_array[books_added++] = books_list;
        books_list = books_list->next;
    }

    // sorting
    for (int i = 0; i < books_added; i++) {
        for (int j = i; j < books_added; j++) {
            if (array_struct->books_array[j]->isbn > array_struct->books_array[i]->isbn) {
                Book_t *temp = array_struct->books_array[i];
                array_struct->books_array[i] = array_struct->books_array[j];
                array_struct->books_array[j] = temp;
            }
        }
    }
    array_struct->size = books_added;

    return array_struct;
}

void book_infoAll(Book_t *books_list) {
    struct ArrayBook_s *books_arr_struct = __book_sortByISBN(books_list);
    if (NULL == books_arr_struct->books_array) {
        err_msg("The operation can't be executed: sorting err\n");
        return;
    }
    
    printf("%10s %30s %30s %10s %12s\n",
        "ISBN", "| Title", "| Authors", "| Total", "| Availible\n");
    for (int i = 0; i < books_arr_struct->size; i++)
        printf("%10llu %30s %30s %5d %5d\n", 
            books_arr_struct->books_array[i]->isbn,
            books_arr_struct->books_array[i]->title,
            books_arr_struct->books_array[i]->authors,
            books_arr_struct->books_array[i]->total,
            books_arr_struct->books_array[i]->availible
        );

}

void book_edit(Book_t *books_list, unsigned long long isbn) {
    Book_t *book = book_find(books_list, isbn);
    if (NULL == book) {
        err_msg("'book_edit': a book with such ISBN doesn't exists\n");
        return;
    }    
    printf("Enter new book's authors:\n");
    scanf(" %[^\n]s", book->authors);
    printf("Enter new book's title:\n");
    scanf(" %[^\n]s", book->title);
    printf("Enter new book's total number:\n");
    scanf("%u", &(book->total));
}

void book_save(Book_t *books_list, const char *saving_path) {
    if (NULL == books_list) {
        err_msg("'book_save': 'books_list' is NULL");
        log_msg("'book_save': 'books_list' is NULL");
        return;
    }

    FILE *file = fopen(saving_path, "w+");
    if (NULL == file) {
        err_msg("'book_save': 'file' opening err");
        log_msg("'book_save': 'file' opening err");
        return;
    }
    while (books_list != NULL) {
        fprintf(file, "%llu,%s,%s,%u,%u\n",
                books_list->isbn,
                books_list->authors,
                books_list->title,
                books_list->total,
                books_list->availible);
        books_list = books_list->next;
    }
    fclose(file);
    printf("'book_save': book's data successfully saved\n");
    log_msg("'book_save': book's data successfully saved");
}