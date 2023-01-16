#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void main()
{
	float *Array, *Check, serial_sum, sum, partialsum;
	int array_size, i;

	printf("Enter the size of the array\n");
	scanf("%d", &array_size);

	Array = (float *) malloc(sizeof(float) * array_size);
	Check = (float *) malloc(sizeof(float) * array_size);


	for (i = 0; i < array_size; i++) {
		Array[i] = i+1;
		Check[i] = Array[i];
	}

	printf("The Array Elements Are \n");

	for (i = 0; i < array_size; i++)
		printf("Array[%d]=%f\n", i, Array[i]);

	sum = 0.0;
	partialsum = 0.0;


#pragma omp parallel for shared(sum)
	for (i = 0; i < array_size; i++) {
#pragma omp critical
		sum = sum + Array[i];

	}

	serial_sum = 0.0;
	for (i = 0; i < array_size; i++)
		serial_sum = serial_sum + Check[i];


	if (serial_sum == sum)
		printf("\nThe Serial And Parallel Sums Are Equal\n");
	else {
		printf("\nThe Serial And Parallel Sums Are UnEqual\n");
	}

	printf("\nThe SumOfElements Of The Array Using OpenMP Directives Is %f\n", sum);
	printf("\nThe SumOfElements Of The Array By Serial Calculation Is %f\n", serial_sum);
}
