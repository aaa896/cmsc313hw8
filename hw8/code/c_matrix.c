#include <stdio.h>


typedef struct {
    float data[4][4];
    int rows;
    int cols;
}Mat4x4;


Mat4x4 transpose_mat4x4(Mat4x4* mat) {
    Mat4x4 res;
    res.cols = mat->rows;
    res.rows = mat->cols;
    for (int row = 0; row <4; ++row) {
        for (int col = 0; col <4; ++col) {
            res.data[col][row] = mat->data[row][col];
        }
    }
    return res;
}


void scale_mat4x4(Mat4x4 *mat, float scalar) {
    for (int row = 0; row <4; ++row) {
        for (int col = 0; col <4; ++col) {
            mat->data[row][col] *= scalar;
        }
    }
}


void print_mat4x4(Mat4x4 *mat) {
    for (int row = 0; row <mat->rows; ++row) {
        for (int col = 0; col <mat->cols; ++col) {
            printf("%f ", mat->data[row][col]);
        }
        putchar('\n');
    }
}


Mat4x4 add_mat4x4(Mat4x4 *left, Mat4x4 *right) {
    Mat4x4 res;    
    if (right->cols > left->cols) res.cols = right->cols;
    else                          res.cols = left->cols;
    if (right->rows > left->rows) res.rows = right->rows;
    else                          res.rows = left->rows;

    for (int row = 0; row <4; ++row) {
        for (int col = 0; col <4; ++col) {
            res.data[row][col] = left->data[row][col] + right->data[row][col];
        }
    }
    return res;
}


Mat4x4 mult_matrix(Mat4x4 *m1, Mat4x4* m2) {
    Mat4x4 res ={0};
    res.rows = m1->rows; 
    res.cols = m2->cols;

    for (int i = 0; i <4; ++i) {
        for (int j = 0; j <4; ++j) {
            for (int k = 0; k <4; ++k) {
                res.data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
    return res;
}


int main() {
    Mat4x4 a = {0};
    a.rows = 2;
    a.cols = 2;
    a.data[0][0] = 6;
    a.data[0][1] = 4;
    a.data[1][0] = 8;
    a.data[1][1] = 3;

    Mat4x4 b = {0};
    b.rows = 2;
    b.cols = 3;
    b.data[0][0] = 1;
    b.data[0][1] = 2;
    b.data[0][2] = 3;
    b.data[1][0] = 4;
    b.data[1][1] = 5;
    b.data[1][2] = 6;

    Mat4x4 c = {0};
    c.rows = 2;
    c.cols = 3;
    c.data[0][0] = 2;
    c.data[0][1] = 4;
    c.data[0][2] = 6;
    c.data[1][0] = 1;
    c.data[1][1] = 3;
    c.data[1][2] = 5;

    scale_mat4x4(&b, 3); 

    Mat4x4 c_t  = transpose_mat4x4(&c);
    Mat4x4 bc_t = mult_matrix(&b,&c_t);
    Mat4x4 res  = add_mat4x4( &bc_t, &a);
    printf("C program result:\n");
    print_mat4x4(&res);
    putchar('\n');
}
