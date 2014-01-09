#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    double*values;
    int size_i;
    int size_j;
} Matrix;

Matrix* Matrix_create(double*array, int size_i, int size_j);
void Matrix_print(Matrix* m);
Matrix* Matrix_multiply(Matrix* a, Matrix* b);
void Matrix_destroy(Matrix* m);

#endif
