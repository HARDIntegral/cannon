#include "matrix.h"

mod_vec* gen_colum_vec(double* values, int len);
int append_column_vec(vec_list* vlist, double* data, int len);
int fill_mtx(matrix* mtx, double** values, int width, int height);

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

    new_mtx->raw_mtx->columns = (vec_list*)malloc(sizeof(vec_list));
    if (new_mtx->raw_mtx->columns == NULL)
        return NULL;
    new_mtx->raw_mtx->num_columns = width;
    new_mtx->raw_mtx->len_columns = height;
    
    new_mtx->raw_mtx->columns->size = 0;
    new_mtx->raw_mtx->columns->head = NULL;

    fill_mtx(new_mtx, values, width, height);

    return new_mtx;
}

mod_vec* gen_colum_vec(double* values, int len) {
    mod_vec* new_col_vec = (mod_vec*)malloc(sizeof(mod_vec));
    if (new_col_vec == NULL)
        return NULL;
    new_col_vec->vec = construct_vector(values, len);
    new_col_vec->next = NULL;
    return new_col_vec;
}

int append_column_vec(vec_list* vlist, double* data, int len) {
    mod_vec* new_col_vec = gen_colum_vec(data, len);
    if (new_col_vec == NULL)
        return FAILURE;

    if (vlist->head == NULL) 
        vlist->head = new_col_vec;
    else {
        mod_vec* tmp = vlist->head;
        while(tmp->next != NULL) 
            tmp = tmp->next;
        tmp->next = new_col_vec;
    }

    vlist->size++;
    return SUCCESS;
}

int fill_mtx(matrix* mtx, double** values, int width, int height) {
    for (int i=0; i < width; i++) {
        if(append_column_vec(mtx->raw_mtx->columns, *(values + i), height) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}
