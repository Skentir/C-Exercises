//
// Created by Kirsten S. on 2019-06-19.
// CSMATH - S12
//

#ifndef UNTITLED_CSMATH2_MATRIX_H
#define UNTITLED_CSMATH2_MATRIX_H

#endif //UNTITLED_CSMATH2_MATRIX_H
#include <math.h>
#include <stdio.h>
#define MAX 100
#define LEN(arr) ((int)(sizeof (arr) /sizeof(arr)[0]))

typedef struct mtx {
    int rows, cols;
    double values[MAX][MAX];
} matrix;


matrix initZeroMatrix(int rows, int cols) {
    matrix A; int i,j;
    A.rows = rows; A.cols = cols;

    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            A.values[i][j]=0;
    return A;
}

matrix initIdentity(int size) {
    matrix A; int i, j;
    A.rows = size;
    A.cols = size;

    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(i == j)
                A.values[i][j] = 1;
            else
                A.values[i][j] = 0;

        }
    }
    return A;
}

matrix initMatrix(int rows, int cols, double values[MAX][MAX]) {
    matrix A; int i, j;
    A.rows = rows; A.cols = cols;

    for(i=0; i<rows; i++)
        for(j=0; j<cols; j++)
            A.values[i][j] = values[i][j];

    return A;
}

void printMatrix(matrix toPrint) {
    int i, j;
    if(toPrint.rows >= 0 || toPrint.cols >= 0) {
        for (i = 0; i < toPrint.rows; i++) {
            printf("[");
            for (j = 0; j < toPrint.cols; j++)
                printf(" %.2lf ", toPrint.values[i][j]);
            printf("]\n");
        }
    } else
        printf("NULL\n");
}

matrix add(matrix A, matrix B) {
    matrix C; int i, j;
    if (A.rows == B.rows && A.cols == B.cols) {
        C.rows = A.rows; C.cols = A.cols;
        for(i=0; i<A.rows; i++)
            for(j=0; j<A.cols; j++)
                C.values[i][j]= A.values[i][j] + B.values[i][j];
    } else
        C =  initZeroMatrix(-1, -1);
    return C;
}

matrix scale(matrix A, double s) {
    matrix B; int i, j;
    if (A.rows > 0 || A.cols > 0) {
        B.rows = A.rows;
        B.cols = A.cols;
        for(i=0; i<A.rows; i++)
            for(j=0; j<A.cols; j++)
                B.values[i][j] = s * A.values[i][j];
    } else
        B = initZeroMatrix(-1,-1);
    return B;
}

matrix mult(matrix A, matrix B) {
    matrix C; int i,j,k; double sum, quo=0;
    if(A.cols == B.rows)
    {
        C.rows = A.rows;
        C.cols = B.cols;

        for(i=0; i<C.rows; i++)
        {
            //sum = 0;
            for(k=0; k<B.cols; k++)
            {
                sum = 0;
                for(j=0; j<B.rows; j++) {
                    quo = A.values[i][j] * B.values[j][k];
                    printf("%.2lf ", quo);
                    sum += quo;
                }
                printf("\nsum: %.2lf\n",sum);
                C.values[i][k] = sum;
            }

        }

        return C;
    } else
        return initZeroMatrix(-1,-1);
}

matrix transpose(matrix A) {
    matrix B;
    int i, j;
    if (A.rows > 0 || A.cols > 0) {
        B.rows = A.cols;
        B.cols = A.rows;
        for (i = 0; i < B.rows; i++)
            for (j = 0; j < B.cols; j++)
                B.values[i][j] = A.values[j][i];
        return B;
    } else
        return initZeroMatrix(-1,-1);
}

matrix minor(matrix base, int ROW, int COL) {
    int r = 0, c;
    matrix buffer;
    buffer.rows = base.rows-1;
    buffer.cols = base.cols-1;

    for (int i=0; i < base.rows; i++) {
        c = 0;
        if (i != ROW) {
            for (int j=0; j < base.cols; j++)
            {
                if (j != COL) {
                    buffer.values[r][c] = base.values[i][j];
                    c++;
                }
            }
            r++;
        }
    }
    return buffer;
}
double determinant(matrix base) {
    if (base.rows == 1&& base.cols == 1)
        return base.values[0][0];
   // else if (base.rows == 2 && base.cols == 2) /* optional case, but still gives correct output*/
     //   return base.values[0][0]* base.values[1][1] - base.values[1][0] * base.values[0][1];
    else {
        double cf = 0;
        for (int i = 0; i < base.rows; i++) {
          matrix b_minor = minor(base, 0, i);
          cf += (pow(-1, i) * base.values[0][i] * determinant(b_minor));
        }
        return cf;
    }
}

