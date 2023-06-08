#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int size_v;  // vertical size
    int size_h;  // horizontal size
    int **matrix;
} Matrix_t;

Matrix_t* GenerateAdjacencyMatrix(int vertices, int edges);

Matrix_t* GenerateIncidenceMatrix(int vertices, int edges);

void WriteGraph(Matrix_t *matrix_p, char *path);

void ShowGraph(Matrix_t *graph, char *source_path, char *img_path);

#endif