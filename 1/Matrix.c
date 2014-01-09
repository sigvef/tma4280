#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Matrix.h"

Matrix* Matrix_create(double*array, int size_i, int size_j){
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->size_i = size_i;
    m->size_j = size_j;
    m->values = (double*) malloc(sizeof(double) * size_i * size_j);
    if(array != NULL){
        for(int i=0;i<size_i * size_j;i++){
            m->values[i] = array[i];
        }
    }else {
        for(int i=0;i<size_i * size_j;i++){
            m->values[i] = 0;
        }
    }
    return m;
}

void Matrix_print(Matrix* m){
    for(int i=0;i<m->size_i;i++){
        for(int j=0;j<m->size_j;j++){
            printf("%f ", m->values[i*m->size_j + j]);
        }
    printf("\n");
    }
}


Matrix* Matrix_multiply(Matrix* a, Matrix* b){
    assert(a->size_j == b->size_i);
    Matrix*m = Matrix_create(NULL, a->size_i, b->size_j);

    for(int j=0;j<m->size_j;j++){
        for(int i=0;i<m->size_i;i++){
            double dot_product = 0;
            for(int k=0;k<a->size_j;k++){
                dot_product += a->values[i * a->size_j + k]
                             * b->values[k * b->size_j + j];
            }
            m->values[i * m->size_j + j] = dot_product;
        }
    }

    return m;
}

void Matrix_destroy(Matrix* m){
    free(m->values);
    free(m);
    m = NULL;
}
