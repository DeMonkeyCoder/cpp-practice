#include<iostream>
#include<cmath>
#include<conio.h>
#include "IIIMatrix.h"
using namespace std;
double det(int n, double mat[matrixSize][matrixSize],double accumulator)
{
	int c, subi, i, j, subj;
	double submat[matrixSize][matrixSize];
	if (n == 2)
	{
		return((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
	}
	else
	{
		for (c = 0; c < n; c++)
		{
			subi = 0;
			for (i = 1; i < n; i++)
			{
				subj = 0;
				for (j = 0; j < n; j++)
				{
					if (j == c)
					{
						continue;
					}
					submat[subi][subj] = mat[i][j];
					subj++;
				}
				subi++;
			}
			accumulator = accumulator + (pow(-1, c) * mat[0][c] * det(n - 1, submat,accumulator));
		}
	}
	return accumulator;
}