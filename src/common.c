#include "common.h"
#include <stdlib.h>

double* copy_darr(double* array, int len) {
    double* new_arr = (double*)malloc(len);
    for (int i=0; i < len; i++)
        *(new_arr + i) = *(array + i);

    return new_arr;
}

void deep_free(void** ptr) {
    free(*ptr);
    *ptr = NULL;
}
