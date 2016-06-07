#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 200
#define NUM_BUCKETS 200
#define BUCKET_SIZE 100

typedef struct
{
	int topo;
	int bucket[BUCKET_SIZE];
} Bucket;

// Funtion Prototypes
void fillArray(int array[], int array_size);
void showArray(int array[], int array_size);
void persistArray(int array[], int array_size);
void arrayFromFile(int array[], int array_size);
void insertionSort(int array[], int array_size);
void bucketSort(int array[], int array_size);

int main(int argc, char const *argv[])
{
	int array[ARRAY_SIZE];

	fillArray(array, ARRAY_SIZE);
	showArray(array, ARRAY_SIZE);
	bucketSort(array, ARRAY_SIZE);
	persistArray(array, ARRAY_SIZE);

	return 0;
}

// Sort an array using the Bucket Sort algorithm
//
void bucketSort(int array[], int array_size)
{
	Bucket b[NUM_BUCKETS];
	int i, j, index;
	int current_position = 0;
	
	for (i = 0; i < array_size; i++)
	{
		b[i].topo = 0;
	}

	for (i = 0; i < array_size; i++)
	{
		index = (int)((float)array_size * ((float)array[i] / 100.0));
		b[index].bucket[b[index].topo] = array[i];
		b[index].topo++;
	}

	for (i = 0; i < NUM_BUCKETS; i++)
	{
		if (b[i].topo > 0)
		{
			insertionSort(b[i].bucket, b[i].topo);
		}
	}

	for (i = 0; i < NUM_BUCKETS; i++)
	{
		if (b[i].topo != 0)
		{
			for (j = 0; j < b[i].topo; j++)
			{
				array[j + current_position] = b[i].bucket[j];
			}
			current_position = current_position + b[i].topo;
		}
	}
}

// Sort an array using the Insert Sort algorithm
//
void insertionSort(int array[], int array_size)
{
	int current, next, key;

	for (current = 1; current < array_size; ++current)
	{
		next = current - 1;
		key = array[current];
		while ((next >= 0) && (array[next] >= key))
		{
			array[next + 1] = array[next];
			next = next - 1;
		}
		array[next + 1] = key;
	}

}

// Instantiate an array with integer values from a
// given file.
//
void arrayFromFile(int array[], int array_size)
{
	FILE *fp;

	fp = fopen("test01.txt", "r");
	int i; 
	int count = 0;

	while (fscanf(fp, "%d", &i) != EOF && count < array_size)
	{
		array[count] = i;
		count++;
	}

	fclose(fp);
}

// Writes a file with the elements of a given array
//
void persistArray(int array[], int array_size)
{
	FILE *fp;
	fp = fopen("result.txt", "w");

	int count;
	
	for (count = 0; count < array_size; count++)
	{
		fprintf(fp, "%d\n", array[count]);
	}

	fclose(fp);

}


// Fills an array with random integer values less
// than 100
//
void fillArray(int array[], int array_size)
{
	time_t t;
	int count;

	srand((unsigned) time(&t));

	for (count = 0; count < array_size; count++)
	{
		array[count] = rand()%100;
	}
}

// Print the array in the console
//
void showArray(int array[], int array_size)
{
	int count;
	printf("\n");
	for (count = 0; count < array_size; ++count)
	{
		printf("%i ", array[count]);
	}
	printf("\n");
}