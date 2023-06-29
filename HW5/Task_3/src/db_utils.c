#include "../include/db_utils.h"

/*
 * Exit statuses:
 * 0 – OK
 * 1 – User not found
 */
static void hash_to_string(char string[65], const uint8_t hash[32])
{
    size_t i;
    for (i = 0; i < 32; i++) {
        string += sprintf(string, "%02x", hash[i]);
    }
}

int auth(tStudent *students, char *login, char *password) {
    uint8_t hash[32];
    char hash_string[65];
    //char *hash_string = (char*) malloc(sizeof(char) * 65);
    calc_sha_256(hash, password, strlen(password));
    hash_to_string(hash_string, hash);

    for (int i = 0; i <= get_max_id(students); i++) {
        if (strcmp(students[i].login, login) == 0 && strcmp(students[i].password_hash, hash_string) == 0)
        {
            printf("Welcome, %s!\n", students[i].login);
            return 0;
        }
    }
    printf("Wrong login or password! Try again.\n");
    return 1;
}

int parseData (char **data, int data_len, tStudent *students) {
    for (int i = 0; i < data_len; i++) {
        char *str = NULL;
        char *substr = NULL;
        if (NULL == data[i]) {
            return 1;
        }
        str = data[i];
        substr = strtok(str, ":");
        students[i].id = atoi(substr);
        substr = strtok(NULL, ":");
        students[i].name = substr;
        substr = strtok(NULL, ":");
        students[i].rb_num = atoi(substr);
        substr = strtok(NULL, ":");
        students[i].avrg_mark = atof(substr);
        substr = strtok(NULL, ":");
        students[i].login = substr;
        substr = strtok(NULL, ":");
        students[i].password_hash = substr;
    }
    return 0;
}

int get_max_id(tStudent *students) {
    int max = -1;
    for (int i = 0; i < DB_SIZE; ++i) {
        if (students[i].id > max) {
            max = students[i].id;
        }
    }
    return max != -1 ? max : 0;
}

void add(tStudent *students) {
    tStudent *new_student = NULL;
    char *password = NULL;
    uint8_t hash[32];
    char hash_string[65];


    for (int i = 0; i < DB_SIZE; ++i) {
        if (students[i].id < 0) {
            new_student = &students[i];
            break;
        }
    }
    if (new_student == NULL) {
        puts("Can't add new record. Data base is full");
        return;
    }

    new_student->id = get_max_id(students) + 1;
    puts("Enter name:");
    new_student->name = (char*) malloc(sizeof(char) * BASE_LEN);
    scanf("%s", new_student->name);
    puts("Enter record book number:");
    scanf("%d", &new_student->rb_num);
    puts("Enter average mark:");
    scanf("%f", &new_student->avrg_mark);
    printf("Enter username:\n");
    new_student->login = (char*) malloc(sizeof(char) * BASE_LEN);
    scanf("%s", new_student->login);
    printf("Enter password:\n");
    password = (char*) malloc(sizeof(char) * BASE_LEN);
    scanf("%s", password);

    calc_sha_256(hash, password, strlen(password));
    hash_to_string(hash_string, hash);
    printf("input: %s\n", password);
    printf("hash : %s\n", hash_string);

    free(password);
    new_student->password_hash = hash_string;

    printf("hash in struct: %s\n", new_student->password_hash);
    fflush(stdin);
}

void view(tStudent *students) {
    int id;
    puts("Enter id:");
    scanf("%d", &id);
    fflush(stdin);
    tStudent *current_student = NULL;
    for (int i = 0; i < DB_SIZE; ++i) {
        if (students[i].id == id) {
            current_student = &students[i];
            break;
        }
    }
    if (current_student == NULL) {
        puts("Student with this id was not found");
        return;
    }
    printf("\nID: %d\n", current_student->id);
    printf("Name: %s\n", current_student->name);
    printf("Student ID: %d\n", current_student->rb_num);
    printf("Average score: %.2f\n", current_student->avrg_mark);
}

void del(tStudent *students) {
    int id;
    puts("Write id:");
    scanf("%d", &id);
    fflush(stdin);
    tStudent *current_student = NULL;
    for (int i = 0; i < DB_SIZE; ++i) {
        if (students[i].id == id) {
            current_student = &students[i];
            break;
        }
    }

    if (current_student == NULL) {
        puts("Student with this id was not found");
        return;
    }

    *current_student = empty_note;
    puts("Success");
}


void merge(tStudent *arr, tStudent *left, int leftSize, tStudent *right, int rightSize) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i].avrg_mark > right[j].avrg_mark) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void merge_sort(tStudent *arr, int size) {
    if (size < 2)
        return;
    int mid = size / 2, i;
    tStudent left[mid], right[size - mid];
    for (i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}

void view_all(tStudent *students) {
    merge_sort(students, DB_SIZE);
    for (int i = 0; i < DB_SIZE; ++i) {
        if (-1 == students[i].id) {
            break;
        }
        printf("ID: %d; ", students[i].id);
        printf("Name: %s; ", students[i].name);
        printf("Record book num: %d; ", students[i].rb_num);
        printf("Average mark: %.2f\n", students[i].avrg_mark);
    }
}
