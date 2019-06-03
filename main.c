#include "csmath2_vectors.h"
#include <stdio.h>

int main () {

    /* Initialize the Vector */
    int vsize, msize;
    printf("Enter size of Vector A: "); scanf("%d", &vsize);
    double numbersA[vsize];
    /* Populate Vectors */
    printf("Values for A: \n");
    for (int i = 0; i < vsize; i++)
        scanf("%lf", &numbersA[i]);
    printf("\nEnter size of Vector B: "); scanf("%d", &msize);
    double numbersB[msize];
    printf("Values for B: \n");
    for (int i = 0; i < msize; i++)
        scanf("%lf", &numbersB[i]);



    vector vectorA = initVector(vsize, numbersA);
    printf("\nVector A contains: ");
    printVector(vectorA);

    vector vectorB = initVector(msize, numbersB);
    printf("\nVector B contains: ");
    printVector(vectorB);

    /* Sum */
    vector sum = add(vectorA, vectorB);
    printf("\nSum contains: ");
    printVector(sum);

    /* Scalar Multiplication */
    double val_scalar;
    printf("\nEnter a scalar value: "); scanf("%lf", &val_scalar);
    vector scalar = scale(vectorA, val_scalar);
    printf("Scalar A contains: ");
    printVector(scalar);

    scalar = scale(vectorB, val_scalar);
    printf("\nScalar B contains: ");
    printVector(scalar);


    /* Dot Product */
    double prod = dot(vectorA, vectorB);
    printf("\n\nDot Product is: %.2lf ", prod);

    /* Magnitude */
    double mag = length(vectorA);
    printf("\nMagnitude of A is: %.2lf ", mag);
    mag = length(vectorB);
    printf("\nMagnitude of B is: %.2lf ", mag);
    return 0;
}
