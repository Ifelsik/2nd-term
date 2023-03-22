//
// Created by misha on 19.03.2023.
//
#include <stdio.h>
#include <string.h>

typedef struct entry_s {
    char name[30];
    char rb[30];
    float mark;
} student;

void add(student students[], int id, char* name, char* rb, float mark) {
    strcpy(students[id].name, name);  // ?
    strcpy(students[id].rb, rb);  // ?
    students[id].mark = mark;
}

void del(student students[], int id) {
    if (students[id].mark != 0) {
        strcpy(students[id].name, "\0");
        strcpy(students[id].rb, "\0");
        students[id].mark = 0;
    } else
        puts("Doesn't exist");
}

void show(student students[], int id) {
    if (students[id].mark != 0) {
        puts("id \t name \t rb \t mark");
        printf("%d\t%s\t%s\t%f", id, students[id].name, students[id].rb, students[id].mark);
    }
    else
        puts("Doesnt exist!");
}


int main() {
    student students[3];
    for (int id = 0; id < 3; id++) {
        students[id].name = {};

    }
    for (int id = 0; id < 3; id++) {
        char name[30]; // указатель нельзя
        char rb[30]; // указатель нельзя
        float mark;
        gets(name);
        gets(rb);
        scanf("%f", &mark);
        add(students, id, name, rb, mark);
    }
    for (int i = 0; i < 3; i++) {
        printf("%s \t %d\n", students[i].name, students[i].age);
    }
}
