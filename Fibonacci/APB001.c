#include <stdio.h>
#include <stdlib.h>

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

	printf("\n*\nEntre com a chave a ser pesquisada:\n*\n");

	while(value != 0)
	{
		scanf("%d", &value);

		binarySearch(fibo, fibonacci_elements, value);
	}

	return 0;
}

/*
* Realiza a busca de uma chave dentro de um array
* através da técnica de Busca Binária
* 
* @param -> name: array[];	type: int
* @param -> name: size;		type: int
* @param -> name: value;	type: int
*    
*/
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
				printf("*\nA chave 1 se encontra na posicao 0 e 1\n*\n");
			}
			else
			{
				printf("*\nA chave %d se encontra na posicao %d\n*\n", value, index);
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

/*
* Calcula o elemento da serie Fibonacci para
* a posicao informada
* 
* @param -> name: value;	type: int
*
* @return -> name: resul;	type: int
*    
*/
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

/*
* Preenche um array com os elementos da
* serie Fibonacci.
* 
* @param -> name: array[];	type: int
* @param -> name: size;		type: int
*    
*/
void fillArray(int array[], int size)
{	
	int i = 0;

	for (i = 0; i < size; ++i)
	{
		array[i] = fibonacci(i + 1);
	}
}

