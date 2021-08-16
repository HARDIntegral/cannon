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
