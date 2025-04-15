#include <stdio.h>

struct Mat4x4 {
    float data[4][4];
    int rows;
    int cols;

    Mat4x4 operator+(const Mat4x4& other) {
        Mat4x4 res;
        if (other.cols > this->cols)  res.cols = other.cols;
        else                          res.cols = this->cols;
        if (other.rows > this->rows)  res.rows = other.rows;
        else                          res.rows = this->rows;

        for (int row = 0; row <4; ++row) {
            for (int col = 0; col <4; ++col) {
                res.data[row][col] = this->data[row][col] + other.data[row][col];
            }
        }
        return res;
    }

    Mat4x4 operator*(const Mat4x4 & other) {
        Mat4x4 res ={0};
        res.rows = this->rows; 
        res.cols = other.cols;

        for (int i = 0; i <4; ++i) {
            for (int j = 0; j <4; ++j) {
                for (int k = 0; k <4; ++k) {
                    res.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return res;
    }

    Mat4x4 operator*(float scalar) {
        Mat4x4 res ={0};
        res.rows = this->rows; 
        res.cols = this->cols;

        for (int i = 0; i <4; ++i) {
            for (int j = 0; j <4; ++j) {
               res.data[i][j] = (this->data[i][j] * scalar);
            }
        }
        return res;
    }

    Mat4x4& operator=(Mat4x4& other) {
        this->cols = other.cols;
        this->rows = other.rows;
        for (int i = 0; i <4; ++i) {
            for (int j = 0; j <4; ++j) {
                this->data[i][j] = other.data[i][j];
            }
        }

        return *this;
    }
};

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

void print_mat4x4(Mat4x4 *mat) {
    for (int row = 0; row <mat->rows; ++row) {
        for (int col = 0; col <mat->cols; ++col) {
            printf("%f ", mat->data[row][col]);
        }
        putchar('\n');
    }
}


int main() {
    Mat4x4 a = {};
    a.rows = 2;
    a.cols = 2;
    a.data[0][0] = 6;
    a.data[0][1] = 4;
    a.data[1][0] = 8;
    a.data[1][1] = 3;

    Mat4x4 b = {};
    b.rows = 2;
    b.cols = 3;
    b.data[0][0] = 1;
    b.data[0][1] = 2;
    b.data[0][2] = 3;
    b.data[1][0] = 4;
    b.data[1][1] = 5;
    b.data[1][2] = 6;

    Mat4x4 c = {};
    c.rows = 2;
    c.cols = 3;
    c.data[0][0] = 2;
    c.data[0][1] = 4;
    c.data[0][2] = 6;
    c.data[1][0] = 1;
    c.data[1][1] = 3;
    c.data[1][2] = 5;

    printf("C ++ program result:\n");
    Mat4x4 res = a + (b * 3) * transpose_mat4x4(&c) ;
    print_mat4x4(&res);
    putchar('\n');
    return (0);
}
