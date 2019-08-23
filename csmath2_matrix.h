// Co, Sean Timothy S. 11813296  CSMATH2-S12
// Sison, Danielle Kirsten T.  11837292  CSMATH-S12
#include <stdio.h>
#include <math.h>
#define MAX 100

typedef struct mtx {
	
	int rows, cols;
	
	double values[MAX][MAX];
	
} matrix;

matrix initZeroMatrix(int rows, int cols)
{
	int i, j;
	matrix ZeroMatrix;
	
	ZeroMatrix.rows = rows;
	ZeroMatrix.cols = cols;
	
	for(i=0; i<rows; i++)
		for(j=0; j<cols; j++)
		{
			ZeroMatrix.values[i][j] = 0;
		}
			
	return ZeroMatrix;		
}

matrix initIdentity(int size)
{
	int i, j;
	matrix Identity;
	
	Identity.rows = size;
	Identity.cols = size;
	
	for(i=0; i<size; i++)
		for(j=0; j<size; j++)
		{
			if(i == j)
				Identity.values[i][j] = 1;
			else
				Identity.values[i][j] = 0;	
		}
		
	return Identity;	
}

matrix initMatrix(int rows, int cols, double values[MAX][MAX])
{
	int i, j;
	matrix SetMatrix;
	
	SetMatrix.rows = rows;
	SetMatrix.cols = cols;
	
	for(i=0; i<rows; i++)
		for(j=0; j<cols; j++)
		SetMatrix.values[i][j] = values[i][j];
		
	return SetMatrix;	
}

void printMatrix(matrix toPrint)
{
	int i, j;
	
	for(i=0; i<toPrint.rows; i++)
	{
		printf("[ ");
		for(j=0; j<toPrint.cols; j++)
		{
			printf("%.2lf ", toPrint.values[i][j]);	
			if(j == toPrint.cols - 1)
				printf("]\n");
		}
	}
}

matrix add(matrix a, matrix b)
{
	int i, j;
	matrix AddMatrix;
	
	if(a.rows == b.rows && a.cols == b.cols)
	{
		AddMatrix.rows = a.rows;
		AddMatrix.cols = a.cols;
		
		for(i=0; i<a.rows; i++)
			for(j=0; j<a.cols; j++)
			AddMatrix.values[i][j] = a.values[i][j] + b.values[i][j];
		
		
		return AddMatrix;
	}
	else
	{
		AddMatrix.rows = -1;
		AddMatrix.cols = -1;
		
		return AddMatrix;
	}
}

matrix scale(matrix a, double s)
{
	int i, j;
	matrix ScaleMatrix;
	
	ScaleMatrix.rows = a.rows;
	ScaleMatrix.cols = a.cols;
	
	for(i=0; i<a.rows; i++)
		for(j=0; j<a.cols; j++)
		ScaleMatrix.values[i][j] = a.values[i][j] * s;
		
	return ScaleMatrix;		
}

matrix mult(matrix a, matrix b)
{
	int i, j, k;
	double temp;
	matrix MultMatrix;
	
	MultMatrix.rows = a.rows;
	MultMatrix.cols = b.cols;
	
	if(a.cols != b.rows)
	{
		MultMatrix.rows = -1;
		MultMatrix.cols = -1;
		
		return MultMatrix;
	}
	else	
	{	
		for(i=0; i<a.rows; i++)
		{
			for(j=0; j<b.cols; j++)
			{
				for(k=0; k<b.rows; k++)
				{
					temp = temp + a.values[i][k] * b.values[k][j];
				}
				
				MultMatrix.values[i][j] = temp;
				temp = 0;
			}
		}
 
		return MultMatrix;
	}
}

matrix transpose(matrix a)
{
	int i, j;
	matrix TransposeMatrix;
	
	TransposeMatrix.rows = a.cols;
	TransposeMatrix.cols = a.rows;
	
	for(i=0; i<a.rows; i++)
		for(j=0; j<a.cols; j++)
			TransposeMatrix.values[j][i] = a.values[i][j];
	
	return TransposeMatrix;
}

matrix minor(matrix base, int row, int col)
{
	int i, j, k, l, r, c;
	matrix MinorMatrix;
	
	for(i=0; i<base.rows; i++)
	{	
		for(j=col; j<base.cols; j++)
		{
			base.values[i][j] = base.values[i][j+1];
		}	
	}
	
	for(l=0; l<base.cols; l++)
	{	
		for(k=row; k<base.rows; k++)
		{
			base.values[k][l] = base.values[k+1][l];
		}	
	}
	
	MinorMatrix.rows = base.rows-1;
	MinorMatrix.cols = base.cols-1;
	
	for(r=0; r<base.rows; r++)
		for(c=0; c<base.cols; c++)
			MinorMatrix.values[r][c] = base.values[r][c];
		
	return MinorMatrix;
}

double determinant(matrix base)
{	
	double matrixDet=0;
	int i, j, sign=1;
	
	if(base.rows != base.cols)
		return 0;
	else if(base.rows == 1 && base.cols == 1)
		return base.values[0][0];	
	else 
	{
		for(i=0; i<base.rows; i++)
			for(j=0; j<base.cols; j++)
			{
					matrixDet = matrixDet + sign * (base.values[0][j]*determinant(minor(base,i,j)));
					sign *= -1;
			}
		return matrixDet;
	}
}

double det_REF(matrix base, int base_rows, int base_cols) {
    int h, j, a, b, c, d, notZero, k, l, m, n;
    double determinant = 1, multiplier = 1;
    double tempA[MAX];
    double tempB[MAX];
    
    if (base_rows != base_cols)
        return 0;
    
    //REF
    for (h = 0; h < base_rows; h++)
    {
        if (base.values[h][h] == 0) {
            //swapping process 
            for (j = 0; j < base.cols; j++)
                tempA[j] = base.values[h][j];
            
            notZero = 0;
            a = h + 1;
            
            while (notZero == 0 && a < base.rows) {
                if (base.values[a][h] != 0) {
                    l = a;
                    for (b = 0; b < base.cols; b++) 
                        tempB[b] = base.values[a][b];
                    notZero = 1;
                }
                a++;
            }

            for (k = 0; k < base.cols; k++) {
                base.values[h][k] = tempB[k];
                base.values[l][k] = tempA[k];
            }
            // multiply determinant by -1 due to swapping
            determinant *= -1;
        }

        for (m = h + 1; m < base_rows; m++)
        {
            if (base.values[h][h] == 0)
                continue;
            else
                multiplier = base.values[m][h] / base.values[h][h];

            for (n = h; n < base_cols; n++)
                base.values[m][n] -= base.values[h][n] * multiplier;
        }
    }

    for (c = 0; c < base_rows; c++)
    {
        for (d = 0; d < base_cols; d++)
        {
            if (c == d)
                   determinant *= base.values[c][d];
        }
    }
    
    if (determinant == -0)
        determinant = 0;
    
	return determinant;
}

matrix GJE(matrix base, int base_rows, int base_cols, matrix augment, int aug_rows, int aug_cols)
{
    int i, j, k, l, m;
    matrix GJE;
    
    GJE.rows = augment.rows;
    GJE.cols = base.cols + augment.cols;
    
    for (i = 0; i < GJE.rows; i++) {
        k = 0;
        for (j = 0; j < GJE.cols; j++) {
            if (j >= base.cols)
                GJE.values[i][j] = augment.values[i][k++];
            else
                GJE.values[i][j] = base.values[i][j];
        }
    }
    
    double factor, divisor = 0.0;
    
    for (i=0; i < base_rows && i < base_cols; i++)
    {
        divisor = GJE.values[i][i];
        for (j=0; j < GJE.cols; j++)
            GJE.values[i][j] /= divisor;
        for (l=0; l < GJE.rows; l++)
        {
            if (l != i)
            {
                factor = GJE.values[l][i];
                for (k = 0; k < GJE.cols; k++)
                    GJE.values[l][k] = GJE.values[l][k] - factor * GJE.values[i][k];
            }
        }
    }
    
    for(i = 0; i < GJE.rows; i++)
    {
        k = 0;
        for(j = base.cols; j < GJE.cols; j++) {
            if (GJE.values[i][j] == INFINITY)
                return initZeroMatrix(-1, -1);
            else {
                augment.values[i][k] = GJE.values[i][j];
                k++;
            }
        }
    }
    
    return augment;
}






