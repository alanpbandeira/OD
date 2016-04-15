#include <stdio.h>
#include <stdlib.h>

float fibonacci(float value);
void fillArray(float array[], int size);
void goldenNumber(float array[], int size);

int main(int argc, char const *argv[])
{
	int fibonacci_elements = 40;
	float fibo[fibonacci_elements];
	
	fillArray(fibo, fibonacci_elements);
	
	goldenNumber(fibo, fibonacci_elements);

	return 0;
}

/*
* Calcula a relação Fibonacci(n) / Fibonacci(n - 1)
* para cada elemento do array de elementos da serie
* fibonacci.
* 
* @param -> name: array[];	type: float
* @param -> name: size;		type: int
*    
*/
void goldenNumber(float array[], int size)
{
	int iterator = 0;
	float number = 0;
	
	printf("RELACAO\t\t\tRESULTADO\n");
	
	for (iterator = 1; iterator < size; iterator ++)
	{
		number = array[iterator] / array[iterator - 1];
		printf("%.1f / %.1f\t\t%f\n", array[iterator], array[iterator - 1], number);
	}
}

/*
* Calcula o elemento da serie Fibonacci para
* a posicao informada
* 
* @param -> name: value;	type: float
*
* @return -> name: result;	type: float
* 
*/
float fibonacci(float value)
{
	float num = value;
	float result = 1;
	float prev_result = 1;
	float temp = 0;
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

/*
* Preenche um array com os elementos da
* serie Fibonacci.
* 
* @param -> name: array[];	type: float
* @param -> name: size;		type: int
*    
*/
void fillArray(float array[], int size)
{	
	int i = 0;

	for (i = 0; i < size; ++i)
	{
		array[i] = fibonacci(i + 1);
	}
}

