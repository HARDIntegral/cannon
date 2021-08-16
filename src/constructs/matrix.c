#include "matrix.h"

matrix* construct_matrix(double** values, int width, int height) {
    if (values == NULL || width == 0 || height == 0)
        return NULL;

    matrix* new_mtx = (matrix*)malloc(sizeof(matrix));
    if (new_mtx == NULL)
        return NULL;
    new_mtx->STATE = NONE;
    new_mtx->raw_mtx = (raw_matrix*)malloc(sizeof(raw_matrix));
    if (new_mtx->raw_mtx == NULL)
        return NULL;

    new_mtx->raw_mtx->values = values;
    new_mtx->raw_mtx->num_rows = height;
    new_mtx->raw_mtx->len_rows = width;

    return new_mtx;
}

void destroy_matrix(matrix *mtx) {
    deep_free((void**)(mtx->raw_mtx->values));
    deep_free((void**)&(mtx->raw_mtx));
    deep_free((void**)&mtx);
}

void print_matrix(matrix* mtx) {
    if (mtx->STATE != NONE)
        return;
    for (int i=0; i < mtx->raw_mtx->num_rows; i++) {
        for (int j=0; j < mtx->raw_mtx->len_rows; j++)
            printf("%f ", *(*(mtx->raw_mtx->values + i) + j));
        printf("\n");
    }
}
