#include <stdio.h>
#include <stdio.h>
#include <strings.h>

//#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

int fibonacci(int value);
void fillArray(int array[], int size);

int main(int argc, char const *argv[])
{
	int fibonacci_elements = 40;
	int array[fibonacci_elements];
	int i = 0;

	fillArray(array, fibonacci_elements);

	for (i = 0; i < fibonacci_elements; i++)
	{
		printf("%d\n", array[i]);
	}

	return 0;
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
