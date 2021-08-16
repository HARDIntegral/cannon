#ifndef VECTOR_H
#define VECTOR_H

#include "../common.h"

typedef struct raw_vector raw_vector;
struct raw_vector {
    double* vector;
    int size;
};

typedef struct vector vector;
struct vector {
    raw_vector* raw_vector;
    ERR_STATE STATE;
};

vector* construct_vector(double values[], int len);
void destroy_vector(vector* vec);

void print_vec(vector* vec);

// MATH

// this operation is non destructive, input vectors are kept safe
void vec_dotp(vector* a, vector* b, double* dotp);

#endif // VECTOR_H
