#include "constructs/vector.h"
#include "constructs/matrix.h"

int main(int argc, char** argv) {
    // test stuff
    {
        printf("testing vectors\n");
        double values[3] = {324, 453, 542};
        vector* test_vec = construct_vector(values, 3);
        printf("vector size: %d\n", test_vec->raw_vector->size);
        print_vec(test_vec);
        destroy_vector(test_vec);
    }
    {
        printf("testing matrices\n");
        int height = 3;
        int width = 2;
        double** values = (double**)malloc(height * sizeof(double*));
        double layer0[] = {0, 1};
        double layer1[] = {2, 3};
        double layer2[] = {4, 5};
        *(values + 0) = layer0;
        *(values + 1) = layer1;
        *(values + 2) = layer2;
        matrix* test_mtx = construct_matrix(values, width, height);
        printf("mtx dims: %dx%d\n", test_mtx->raw_mtx->num_rows, test_mtx->raw_mtx->len_rows);
        print_matrix(test_mtx);
        destroy_matrix(test_mtx);
    }
    {
        printf("testing vector dot product\n");
        double a_values[3] = {3, 5, 8};
        double b_values[3] = {2, 7, 1};
        vector* a = construct_vector(a_values, 3);
        vector* b = construct_vector(b_values, 3);
        double* c = (double*)malloc(sizeof(double));
        vec_dotp(a, b, c);
        printf("the dot product is: %f\n", *c);
        destroy_vector(a); 
        destroy_vector(b);
        free(c);
    }
}
