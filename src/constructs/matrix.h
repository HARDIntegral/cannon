#ifndef MATRIX_H
#define MATRIX_H

#include "../common.h"
#include "vector.h"

typedef struct mod_vec mod_vec;
struct mod_vec {
    vector* vec;
    mod_vec* next;
};

typedef struct vec_list vec_list;
struct vec_list {
    mod_vec* list;
    int len;
};

typedef struct raw_matrix raw_matrix;
struct raw_matrix {
    vec_list* columns;
    int num_columns;
    int len_columns;
};

typedef struct matrix matrix;
struct matrix {
    raw_matrix* raw_matrix;
    ERR_STATE STATE;
};

matrix* construct_matrix(double** values, int width, int height);
void destroy_matrix(matrix* mtx);

void print_matrix(matrix* matrix);

#endif // MATRIX_H
