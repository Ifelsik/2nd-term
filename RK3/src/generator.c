#include "../include/generator.h"

Matrix_t* GenerateAdjacencyMatrix(int vertices, int edges) {
    int edges_generated = 0;
    Matrix_t* graph = (Matrix_t*) malloc(sizeof(Matrix_t));
    if (NULL == graph) {
        fprintf(stderr, "In function 'GenerateAdjacencyMatrix': allocation error\n");
        free(graph);
        exit(EXIT_FAILURE);
    }
    if (edges > (vertices + 1) * vertices / 2) {
        fprintf(stderr, "In function 'GenerateAdjacencyMatrix': Such a graph cannot exist\n");
        free(graph);
        return NULL;
    }

    graph->size_v = vertices;
    graph->size_h = graph->size_v;
    graph->matrix = (int**) malloc(sizeof(int*) * graph->size_v);
    for (int i = 0; i < graph->size_v; i++) {
        (graph->matrix)[i] = (int*) calloc(graph->size_v, sizeof(int));

        if (NULL == (graph->matrix)[i]) {
            fprintf(stderr, "In function 'GenerateAdjacencyMatrix': matrix row allocation error\n");
            free(graph);
            exit(EXIT_FAILURE);
        }
    }

    while (edges_generated < edges) {
        int i = (rand() + rand()) % vertices;
        int j = (rand() + rand()) % (i + 1);
        if (!(graph->matrix)[i][j]) {
            (graph->matrix)[i][j] = rand() % 2;
            (graph->matrix)[j][i] = (graph->matrix)[i][j];
            edges_generated += (graph->matrix)[i][j];
        }
    }
    return graph;
}


Matrix_t* GenerateIncidenceMatrix(int vertices, int edges) {
    int edges_generated = 0;
    Matrix_t* graph = (Matrix_t*) malloc(sizeof(Matrix_t));
    if (NULL == graph) {
        fprintf(stderr, "In function 'GenerateIncidenceMatrix': can't allocate memory for structure\n");
        free(graph);
        exit(EXIT_FAILURE);
    }
    if (edges > (vertices + 1) * vertices / 2) {
        fprintf(stderr, "In function 'GenerateIncidenceMatrix': Such a graph cannot exist\n");
        free(graph);
        return NULL;
    }

    graph->size_v = vertices;
    graph->size_h = edges;
    (graph->matrix) = (int**) malloc(sizeof(int*) * graph->size_v);
    if (NULL == graph->matrix) {
        fprintf(stderr, "In function 'GenerateIncidenceMatrix': can't allocate memory for matrix\n");
        free(graph);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < graph->size_v; i++) {
        (graph->matrix)[i] = (int*) calloc(graph->size_h, sizeof(int));
        if (NULL == (graph->matrix)[i]) {
            fprintf(stderr, "In function 'GenerateIncidenceMatrix': can't allocate memory for matrix row\n");
            free(graph);
            exit(EXIT_FAILURE);
        }
    }

    while (edges_generated < edges) {
        int vertex_1 = rand() % vertices;
        int vertex_2 = rand() % vertices;

        if (!(graph->matrix)[vertex_1][edges_generated] &&
            !(graph->matrix)[vertex_2][edges_generated]) {
            (graph->matrix)[vertex_1][edges_generated] = 1;
            (graph->matrix)[vertex_2][edges_generated] = 1;
            edges_generated++;
        }

    }
    return graph;
}

void WriteGraph(Matrix_t *graph, char *path) {
    FILE *file = NULL;

    file = fopen(path, "w");
    if (NULL == file) {
        fprintf(stderr, "In function 'WriteMatrix': can't open file\n");
        return;
    }

    for (int i = 0; i < graph->size_v; i++) {
        for (int j = 0; j < graph->size_h; j++) {
            fprintf(file, "%d ", (graph->matrix)[i][j]);
        }
        fputc('\n', file);
    }

    fclose(file);
}

void __adj_dot(FILE *file, char* template, Matrix_t *graph) {
    fprintf(file,"%s", template);
    for (int i = 0; i < graph->size_v; i++) {
        for (int j = 0; j <= i; j++) {
            if (graph->matrix[i][j])
                fprintf(file, "\t%d -- %d\n", i, j);
        }
    }
    fputc('}', file);
}

void __inc_dot(FILE *file, char *template, Matrix_t *graph) {
    fprintf(file,"%s", template);
    for (int i = 0; i < graph->size_h; i++) {
        int edge_found = -1;
        for (int j = 0; j < graph->size_v; j++) {
            if (graph->matrix[j][i] != 0 && edge_found >= 0) {
                fprintf(file, " %d\n", j);
                edge_found = -1;
            }
            else if (graph->matrix[j][i]) {
                fprintf(file, "\t%d --", j);
                edge_found = j;
            }
        }
        if (edge_found >= 0)
            fprintf(file, " %d\n", edge_found);
    }
    fputc('}', file);
}

void ShowGraph(Matrix_t *graph, char *source_path, char *img_path) {
    int buff_size = 0;
    char *filebuff = NULL;
    FILE *template = fopen(source_path, "r");
    FILE *file = fopen(img_path, "w");

    if (NULL == template) {
        fprintf(stderr, "In function 'ShowGraph': can't open template\n");
        exit(EXIT_FAILURE);
    }
    if (NULL == file) {
        fprintf(stderr, "In function 'ShowGraph': can't open file\n");
        exit(EXIT_FAILURE);
    }
    fseek(template, 0, SEEK_END);
    buff_size = ftell(template);
    fseek(template, 0, SEEK_SET);

    filebuff = (char*) calloc(buff_size, sizeof(char));
    if (NULL == filebuff) {
        fprintf(stderr, "In function 'ShowGraph': can't allocate memory\n");
        exit(EXIT_FAILURE);
    }
    fread(filebuff, sizeof(char), buff_size, template);
    fclose(template);


    if (graph->size_v == graph->size_h) {
        __adj_dot(file, filebuff, graph);
        system("dot -Tpng > ../adjacency_graph.png < ../adjacency_graph.dot");
    }
    else {
        __inc_dot(file, filebuff, graph);
        system("dot -Tpng > ../incidence_graph.png < ../incidence_graph.dot");
    }
    fclose(file);
    free(filebuff);
}