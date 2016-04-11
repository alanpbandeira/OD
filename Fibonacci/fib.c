#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

int fibonacci(int value);
void fillArray(int array[], int size);
void binarySearch(int array[], int size, int value);

int main(int argc, char const *argv[])
{
	int fibonacci_elements = 40;
	int fibo[fibonacci_elements];
	int value = -1;
	int index = 0;
	int iterator = 0;

	fillArray(fibo, fibonacci_elements);

	for (iterator = 0; iterator < fibonacci_elements; iterator++)
	{
		printf("%d\n", fibo[iterator]);
	}

	printf("\n*\nEntre com o valor a ser pesquisado\n*\n");

	while(value != 0)
	{
		scanf("%d", &value);

		binarySearch(fibo, fibonacci_elements, value);

	}

	return 0;
}

void binarySearch(int array[], int size, int value)
{
	int start = 0;
	int end   = size - 1;
	int midle = 0;
	int index = 0;
	int found = 0;

	while (!found)
	{
		midle = ((start + end) / 2);

		if (array[midle] == value)
		{
			index = midle;
			found = 1;
			if (index == 1)
			{
				printf("*\nA chave 1 se encontra na posição 0 e 1\n*\n");
			}
			else
			{
				printf("*\nA chave %d se encontra na posição %d\n*\n", value, index);
			}
		}
		else if (array[midle] < value)
		{
			start = midle + 1;
		} 
		else if (array[midle] > value)
		{
			end = midle - 1;
		}

		if (end < start)
		{
			printf("*\nO valor %d nao se encontra no vetor\n*\n", value);
			found = 1;
			index = -1;
		}
	}
}

int fibonacci(int value)
{
	int num = value;
	int result = 1;
	int prev_result = 1;
	int temp = 0;
	int count = 0;

	if (num <= 2)
	{
		return 1;
	}
	else
	{
		for (count = 3; count <= value; count++)
		{
			temp = result;
			result = result + prev_result;
			prev_result = temp;
		}
	}

	return result;
}

void fillArray(int array[], int size)
{	
	int i = 0;

	for (i = 0; i < size; ++i)
	{
		array[i] = fibonacci(i + 1);
	}
}
