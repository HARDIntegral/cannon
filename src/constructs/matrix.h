#ifndef MATRIX_H
#define MATRIX_H

#include "../common.h"
#include "vector.h"

typedef struct raw_matrix raw_matrix;
struct raw_matrix {
    double** values;
    int num_rows;
    int len_rows;
};

typedef struct matrix matrix;
struct matrix {
    raw_matrix* raw_mtx;
    ERR_STATE STATE;
};

matrix* construct_matrix(double** values, int width, int height);
void destroy_matrix(matrix* mtx);

void print_matrix(matrix* mtx);

#endif // MATRIX_H
