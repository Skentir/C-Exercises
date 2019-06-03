//
// Created by Kirsten S. on 2019-06-02.
// Section: S12
//

#ifndef CSMATH_CSMATH2_VECTORS_H
#define CSMATH_CSMATH2_VECTORS_H
#include <stdio.h>
#include <math.h>
#define MAX 1000

typedef  struct vec {
    int size;
    double values[MAX];
} vector;

vector new_vector;

vector initZeroVector(int size) {
    new_vector.size = size;
    if (size > 0) {
        for (int i = 0; i < size; i++)
            new_vector.values[i] = 0.0;
        return new_vector;
    } else
        return new_vector;
}

vector initVector(int size, double values[MAX]) {
    new_vector.size = size;
    for (int j = 0; j < size; ++j)
        new_vector.values[j] = values[j];
    return new_vector;
}

void printVector(vector print) {
    if (print.size > 0) {
        printf("[ ");
        for (int m = 0; m < print.size; m++)
                printf("%.2lf ", print.values[m]);
        printf("]");
    } else
        printf("NULL");
}

vector add(vector a, vector b) {
    vector sum;
    if (a.size == b.size) {
        sum.size = a.size;
        for(int i = 0; i < a.size; i++ )
            sum.values[i] = a.values[i] + b.values[i];
        return sum;
    } else
        return initZeroVector(-1);
}

vector scale(vector a, double s) {
    vector quotient;
    if (a.size > 0) {
        quotient.size = a.size;
        for (int j = 0; j < quotient.size; j++)
            quotient.values[j] = s * a.values[j];
        return quotient;
    } else {
        quotient.size = 0;
        return quotient;
    }
}

double dot(vector a, vector b) {
    double sum = 0;
    if (a.size == b.size) {
        for (int m = 0; m < a.size; m++)
            sum += a.values[m] * b.values[m];
        return sum;
    } else
        return 0;
}

double length(vector a) {
    if (a.size > 0) {
        return sqrt(dot(a,a));
    } else
        return 0.00;
}
#endif //CSMATH_CSMATH2_VECTORS_H
