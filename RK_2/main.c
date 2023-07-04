#include "./include/main.h"

int main() {
    char *path = "../files/students.json";
    char *data = NULL;
    Stack_t *stack_head = NULL;
    Student_t **students = NULL;
    cJSON *data_json = NULL;
    const cJSON *students_json = NULL;
    const cJSON *student_json = NULL;
    int students_array_size = 0;

    data = readFile(path);

    data_json = cJSON_Parse(data);
    assert(NULL != data_json);

    students_json = cJSON_GetObjectItem(data_json, "students");
    assert(NULL != students_json);

    students_array_size = cJSON_GetArraySize(students_json);
    students = (Student_t**) malloc(sizeof(Student_t*) * students_array_size);

    int i = 0;
    cJSON_ArrayForEach(student_json, students_json) {
        cJSON *student_id = cJSON_GetObjectItem(student_json, "student_id");
        cJSON *student_name = cJSON_GetObjectItem(student_json, "student_name");
        cJSON *student_record_number = cJSON_GetObjectItem(student_json, "student_record_number");
        cJSON *student_rating = cJSON_GetObjectItem(student_json, "student_rating");
        cJSON *student_attendance = cJSON_GetObjectItem(student_json, "student_attendance");
        cJSON *student_login = cJSON_GetObjectItem(student_json, "student_login");
        students[i] = (Student_t*) malloc(sizeof(Student_t));
        students[i]->student_id = student_id->valueint;
        students[i]->student_name = student_name->valuestring;
        students[i]->student_record_number = student_record_number->valueint;
        students[i]->student_rating = student_rating->valuedouble;
        students[i]->student_attendance = student_attendance->valueint;
        students[i]->student_login = student_login->valuestring;
        i++;
    }

    printStudentAll(students, students_array_size);

    int students_added = 0;
    while (students_added < students_array_size) {
        Student_t *student = NULL;
        int id = -1;
        printf("Enter student ID:\n");
        scanf("%d", &id);
        student = findStudentByID(students, students_array_size, id);
        if (student != NULL) {
            stackPush(&stack_head, student);
            students_added++;
        }
    }

    stackPopAll(&stack_head, printStudent);

    cJSON_Delete(data_json);
    return 0;
}
