#include "Matrix.h"


int main(){

    double A_array[3 * 3] = {
        0.3, 0.4, 0.3,
        0.7, 0.1, 0.2,
        0.5, 0.5, 0.0
    };

    double x_array[3 * 1] = {
        1.0,
        1.0,
        1.0
    };

    Matrix* A = Matrix_create(A_array, 3, 3);
    Matrix* x = Matrix_create(x_array, 3, 1);
    Matrix* y = Matrix_multiply(A, x);

    Matrix_print(y);

    Matrix_destroy(A);
    Matrix_destroy(x);
    Matrix_destroy(y);

    return 0;
}

