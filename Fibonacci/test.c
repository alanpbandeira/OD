#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )

// File access methods
//void fileToCharArray(FILE *f, char *array);
//void fileToIntArray(FILE *f, int *array);


// Sorting Methods
/*void bubbleSort();
void insertionSort();
void selectionSort();
void quickSort();
void mergeSort();
void heapSort();*/

// Search methods
//int intBinarySearch

void testaEssaPorra(int array[], int size)
{
	int i = 0;

	for (i = 0; i < size; ++i)
	{
		printf("%d\n", array[i]);
	}	
}

int main(int argc, char const *argv[])
{
	int array_list[] = {0,1,2,3,4,5,6,7,8,9};
	int this_size = ARRAY_SIZE(array_list);

	testaEssaPorra(array_list, this_size);
	return 0;
}