#ifndef COMMON_H
#define COMMON_H 

#include <math.h>
#include <limits.h>
#include <complex.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

#define SUCCESS 1
#define FAILURE 0

typedef enum ERR_STATE ERR_STATE;
enum ERR_STATE {
    NONE,
    OVERFLOW,
    NOT_FULL
};

// COMMON FUNCTIONS
double* copy_darr(double* array, int len);
void deep_free(void** ptr);

#endif // COMMON_H
