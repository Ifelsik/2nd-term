#include <assert.h>
// #include "../main.h"
#include "../include/auth.h"

static errors_count = 0;

struct dataset {
    Data_t user;
    String_t login;
    String_t password;
};

// static const struct dataset data_vector[] = {
//     {
//         {}
//     }
// };

int main() { 
    // assert(auth_checkUser(&(data_vector[0].user), data_vector[0].login, data_vector[0].password) == 1);
    return 0;
}
