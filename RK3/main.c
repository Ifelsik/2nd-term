#include "main.h"


int main(int argc, char *argv[]) {
    char *opts = "aie:v:";
    int opt = 0;
    int vertices = 0;
    int edges = 0;
    bool has_arg_a = false;
    bool has_arg_i = false;
    Matrix_t *adj_matrix = NULL;
    Matrix_t *inc_matrix = NULL;

    while ((opt = getopt(argc, argv, opts)) != -1) {
        switch (opt) {
            case 'v':
                sscanf(optarg, "%d", &vertices);
                break;
            case 'e':
                sscanf(optarg, "%d", &edges);
                break;
            case 'a':
                has_arg_a = true;
                adj_matrix = GenerateAdjacencyMatrix(vertices, edges);
                WriteGraph(adj_matrix, "../files/adjacency_matrix.txt");
                ShowGraph(adj_matrix, "../files/dot_template.txt",
                          "../adjacency_graph.dot");
                break;
            case 'i':
                has_arg_i = true;
                inc_matrix = GenerateIncidenceMatrix(vertices, edges);
                WriteGraph(inc_matrix, "../files/incidence_matrix.txt");
                ShowGraph(inc_matrix, "../files/dot_template.txt",
                          "../incidence_graph.dot");
                break;
            default:
                printf("Option not found\n");
                break;
        }
    }

    if (!has_arg_a && !has_arg_i) {
        printf("Incorrect program arguments\n");
        return 1;
    }

    
    return 0;
}
