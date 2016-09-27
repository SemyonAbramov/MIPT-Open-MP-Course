/**
  * Exponent calculation.
  * Semyon Abramov, MIPT, Open MP Course
  * 2016
  */

#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

double factorial(int n)
{
	int j = 0;
	double fact = 1;
	
	for (j = 1; j < n; j++)
		fact = fact * j; 

	return fact;
}


int main(int argc, char** argv)
{
	if (argc != 2)
	{	
		printf("Please, enter 1 argument (number of summations)\n");
		return 0;
	}

	int N = atoi(argv[1]);
	int i = 0; 
	double num = 0;

	
	#pragma omp parallel
	{
		#pragma omp for private(i) reduction(+:num)
		for (i = 1; i <= N; i++)
		{
			num += 1 / factorial(i);		
		}
	}

	printf("exp: %10.15lf\n", num);

	return 0;
}