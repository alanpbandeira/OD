#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct
{
	int key;
	int value;
	int status = 0;
} HashTable;

int hashFunction(int value);
void hashInsert(HashTable table[], int value);
void hashRemove(HashTable table[], key);

int main(int argc, char const *argv[])
{
	int array[50];
	int count = 0;
	HashTable table[100];
	time_t t;

	srand((unsigned) time(&t));

	for (count = 0; count < 50; count++)
	{
		array[count] = rand();
	}

	return 0;
}


int hashFunction(int value)
{
	int result = 0;

	result = value % 99;

	return result
}

void hashInsert(HashTable table[], int value)
{
	int elemet = value;
	
	if (elemet == 0)
	{
		elemet++;
	}

	int key = hashFunction(element);
	int alternate_key = key;

	while (table[alternate_key].status != 0)
	{
		alternate_key++;

		if (alternate_key == 99)
		{
			alternate_key = 0;
		}
	}

	table[alternate_key].key   = key;
	table[alternate_key].value = element;

	if (alternate_key != key)
	{
		table[alternate_key].status = 100;
	}
	else
	{
		table[alternate_key].status = 1;
	}
}

void hashRemove(HashTable table[], int key)
{
	int alternate_key = key;

	if (alternate_key)

	while(alternate_key < 100)
	{
		if (alternate_key == table[alternate_key + 1].key)
		{
			table[alternate_key].key = table[alternate_key + 1].key];
			table[alternate_key].value = table[alternate_key + 1].value];
			table[alternate_key].status = 1;
			alternate_key++;
		}
		else
		{
			table[alternate_key].key = table[alternate_key + 1].key];
			table[alternate_key].value = table[alternate_key + 1].value];
			alternate_key++;	
		}
	}
}
















