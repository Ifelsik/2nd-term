#include "../include/auth.h"

static void __hash_to_string(char string[65], const uint8_t hash[32])
{
    size_t i;
    for (i = 0; i < 32; i++) {
        string += sprintf(string, "%02x", hash[i]);
    }
}

User_t* auth_init(char *users_path) {
    FILE *file = fopen(users_path, "r");
    
    if (NULL == file) {
        err_msg("In func 'auth_init': 'file' opening err");
        log_msg("In func 'auth_init': 'file' opening err");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    int file_len = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *line = (char*) calloc(file_len, sizeof(char));
    
    if (NULL == line) {
        err_msg("In func 'auth_init': 'line' calloc err");
        exit(EXIT_FAILURE);
    }

    User_t *users_list = NULL;
    User_t *temp = NULL;

    while (fgets(line, file_len, file) != NULL) {
        users_list = (User_t*) malloc(sizeof(User_t));
        if (NULL == users_list) {
            err_msg("In func 'auth_init': 'users_list' malloc err");
            log_msg("In func 'auth_init': 'users_list' malloc err");
            exit(EXIT_FAILURE);
        }
        users_list->next = temp;
        users_list->prev = NULL;
        if (NULL != temp) {
            temp->prev = users_list;
        }
        temp = users_list;
        users_list->login = (char*) calloc(file_len, sizeof(char));
        users_list->password_hash = (char*) calloc(file_len, sizeof(char));

        if (NULL == users_list->login) {
            err_msg("In func 'auth_init': 'users_list->login' calloc err");
            log_msg("In func 'auth_init': 'users_list->login' calloc err");
            exit(EXIT_FAILURE);
        }
        if (NULL == users_list->password_hash) {
            err_msg("In func 'auth_init': 'users_list->password_hash' calloc err");
            log_msg("In func 'auth_init': 'users_list->password_hash' calloc err");
            exit(EXIT_FAILURE);
        }

        char *substr = (char*) calloc (file_len, sizeof(char));
        if (NULL == substr) {
            err_msg("In func 'auth_init': 'substr' calloc err");
            log_msg("In func 'auth_init': 'substr' calloc err");
            exit(EXIT_FAILURE);
        }
        strcpy(substr, line);
        

        users_list->login = strtok(substr, ",");
        users_list->password_hash = strtok(NULL, ","); //  what?
        users_list->students_access = atoi(strtok(NULL, ","));
        users_list->books_access = atoi(strtok(NULL, ","));
        // yeah, memory leak!!!!
        //free(substr);   // what the fuck is going here?
        substr = NULL;
    }
    fclose(file);
    free(line);

    log_msg("'auth_init': success");
    return users_list;
}

/**
 * @brief Checks whether such a user exists
 * @return 1 if exist, else 0
*/
int auth_checkUser(User_t *users_list, char *login, char *password_hash) {
    User_t *user = auth_findUserByLogin(users_list, login);
    if (user != NULL && strcmp(user->login, login) == 0)
        return 1;
    return 0;
}

/**
 * @brief Checks whether such a user exists with ECHO
 * @return 1 if exist, else 0
*/
int auth_checkUserWithEcho(User_t *users_list, char *login, char *password_hash) {
    User_t *user = auth_findUserByLogin(users_list, login);
    if (user != NULL && strcmp(user->password_hash, password_hash) == 0) {
        printf("Welcome, %s!\n", user->login);
        char msg[64];
        sprintf(msg, "'auth_checkUserWithEcho': logged user - '%s'", user->login);
        log_msg(msg);
        return 1;
    }
    printf("Wrong login or password. Please, try again!\n");
    return 0;
}

User_t* auth_findUserByLogin(User_t *users_list, char *login) {
    while (users_list != NULL) {
        if (!strcmp(users_list->login, login))
            return users_list;
        users_list = users_list->next;
    }
    return NULL;
}

/**
 * @brief authentication
 * @param users_list ptr to the list of users
 * @returns user if auth is successfull
*/
User_t* auth(User_t *users_list) {
    uint8_t hash[32];
    char password_hash[65];
    char *login = (char*) calloc(BASE_LEN, sizeof(char));
    char *password = (char*) calloc(BASE_LEN, sizeof(char));

    if (login == NULL) {
        err_msg("In function 'auth': 'login' calloc error");
        log_msg("In function 'auth': 'login' calloc error");
        exit(EXIT_FAILURE);
    }
    if (password == NULL) {
        err_msg("In function 'auth': 'password_hash' calloc error");
        log_msg("In function 'auth': 'password_hash' calloc error");
        exit(EXIT_FAILURE);
    }


    do {
        printf("Please, enter your login:\n");
        scanf("%s", login);

        printf("Please, enter your password:\n");
        scanf("%s", password);

        calc_sha_256(hash, password, strlen(password));
        __hash_to_string(password_hash, hash);
    } while (auth_checkUserWithEcho(users_list, login, password_hash) == 0);

    free(password); // login must be cleaned too
    return auth_findUserByLogin(users_list, login);
}

void auth_save(User_t *users_list, char *saving_path) {
    if (NULL == users_list) {
        err_msg("'auth_save': 'users_list' is NULL");
        log_msg("'auth_save': 'users_list' is NULL");
        return;
    }

    FILE *file = fopen(saving_path, "w+");
    if (NULL == file) {
        err_msg("'auth_save': 'file' opening err");
        log_msg("'auth_save': 'file' opening err");
        return;
    }
    while (users_list != NULL) {
        fprintf(file, "%s,%s,%d,%d\n",
                users_list->login,
                users_list->password_hash,
                users_list->students_access,
                users_list->books_access);
        users_list = users_list->next;
    }
    fclose(file);
    printf("'auth_save': user's data successfully saved\n");
    log_msg("'auth_save': user's data successfully saved");
}
