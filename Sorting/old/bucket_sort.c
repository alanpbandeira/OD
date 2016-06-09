#include <stdio.h>
#include <stdio.h>

#define tam_bucket 100
#define num_bucket 10
#define max 10

typedef struct
{
	int top;
	int bucket[tam_bucket];
}Bucket;

void bucketSort(int array[], int size)