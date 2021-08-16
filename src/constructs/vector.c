#include "vector.h"

vector* construct_vector(double values[], int len) {
    vector* new_vector = (vector*)malloc(sizeof(vector));
    new_vector->raw_vector = (raw_vector*)malloc(sizeof(raw_vector));
    
    new_vector->raw_vector->vector = copy_darr(values, len);
    new_vector->raw_vector->size = len;
    
    new_vector->STATE = NONE;

    return new_vector;
}

void destroy_vector(vector *vec) {
    deep_free((void**)(&(vec->raw_vector->vector)));
    deep_free((void**)(&(vec->raw_vector)));
    deep_free((void**)(&vec));
}

void print_vec(vector* vec) {
    if (vec->STATE != NONE)
        return;
    for (int i=0; i < vec->raw_vector->size; i++)
        printf("%f, ", *(vec->raw_vector->vector + i));
    printf("\n");
}

void vec_dotp(vector* a, vector* b, double* dotp) {
    if (a == NULL || b == NULL)
        return;
    if (a->STATE != NONE || b->STATE != NONE)
        return;
    int a_len = a->raw_vector->size;
    if (a_len != b->raw_vector->size)
        return;

    double tmp = 0; 
    for (int i=0; i < a_len; i++)
        tmp += *(a->raw_vector->vector + i) * *(b->raw_vector->vector + i);
    *dotp = tmp;
}
