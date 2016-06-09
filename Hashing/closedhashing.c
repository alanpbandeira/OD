#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int key;
	int value;
	int status;
} HashTable;

int hashFunction(int value);
void hashInsert(HashTable table[], int value);
void hashRemove(HashTable table[], int key);
void hashPrint(HashTable table[]);
void fillArray(int array[], int array_size);
void showMenu();
void emptyTable(HashTable table[], int table_size);

int main(int argc, char const *argv[])
{
	int array_size = 50;
	int table_size = 100;
	int array[array_size];
	int count = 0;
	int menu_input = -1;
	int key_remove = -1;
	int x = 1;

	HashTable table[table_size];

	emptyTable(table, table_size);
	//system("cls"); //unconment for windows
	system("clear");
	printf("Uma tabela vazia foi criada\n\n");

	while(menu_input != 0)
	{
		//system("cls"); //unconment for windows
		system("clear");
		showMenu();
		scanf("%d", &menu_input);
		
		switch(menu_input)
		{
			case 1:
				fillArray(array, array_size);
				
				break;
			case 2:
				x = 1;
				//system("cls"); //unconment for windows
				system("clear");
				for (count = 0; count < array_size; count ++)
				{
					printf("%d\n", array[count]);
				}
				printf("\n\nEntre com 0 para retornar ao menu:\n");
				while(x != 0)
				{
					scanf("%d", &x);
				}
				
				break;
			case 3:
				for (count = 0; count < 50; count++)
				{
					hashInsert(table, array[count]);
				}
				
				break;
			case 4:
				x = 1;
				//system("cls"); //unconment for windows
				system("clear");
				
				hashPrint(table);
				printf("\n\nEntre com 0 para retornar ao menu:\n");
				
				while(x != 0)
				{
					scanf("%d", &x);
				}
				
				break;
			case 5:
				printf("Entre com a chave que deseja remover\n");
				scanf("%d", &key_remove);
				hashRemove(table, key_remove);
				
				break;
			default:
				break;
		}		
	}

	return 0;
}

int hashFunction(int value)
{
	int result = 0;

	result = value % 99;

	return result;
}

void hashInsert(HashTable table[], int value)
{
	int element = value;
	
	if (element == 0)
	{
		element++;
	}

	int key = hashFunction(element);
	int current_key = key;

	while (table[current_key].status != 0)
	{
		current_key++;

		if (current_key == 99)
		{
			current_key = 0;
		}
	}

	table[current_key].key   = key;
	table[current_key].value = element;

	if (current_key != key)
	{
		table[current_key].status = 100;
	}
	else
	{
		table[current_key].status = 1;
	}
}

void hashRemove(HashTable table[], int key)
{
	if (key < 0)
	{
		printf("Chave invalida\n");
		return;
	}

	int current_key = key;
	int count = current_key + 1;

	table[current_key].status = 0;
	table[current_key].value = 0;

	while (count < 100)
	{		
		if (table[count].status == 100)
		{
			if (current_key >= table[count].key)
			{
				table[current_key].key = table[count].key;
				table[current_key].value = table[count].value;
				if (current_key == table[current_key].key)
				{
					table[current_key].status = 1;
				}
				else
				{
					table[current_key].status = 100;
				}
				
				table[count].status = 0;
				table[count].value = 0;

				current_key = count;
				count ++;
			}
			else
			{
				count ++;
			}
		}
		else
		{
			count ++;
		}
	}
}

void hashPrint(HashTable table[])
{
	int count = 0;

	printf("Tabela\n\n");
	printf("----------------------------\n");
	
	for (count; count < 100; count++)
	{
		if (table[count].status == 0)
		{
			printf("| %d |    |            | %d |\n", count, table[count].status);
			printf("----------------------------\n");
		}
		else if (table[count].status == 1)
		{
			printf("| %d | %d | %d | %d |\n", count,
											  table[count].key, 
										 	  table[count].value, 
										 	  table[count].status);
			printf("----------------------------\n");		
		}
		else if (table[count].status == 100)
		{
			printf("| %d | %d | %d | * |\n", count, 
											 table[count].key, 
											 table[count].value);
			printf("----------------------------\n");
		}
	}

	printf("\n");
}

void fillArray(int array[], int array_size)
{
	time_t t;
	int count = 0;

	srand((unsigned) time(&t));

	for (count; count < array_size; count++)
	{
		array[count] = rand();
	}
}

void showMenu()
{
	printf("Menu:\n");
	printf("\t Entre com a opcao desejada:\n");	
	printf("\t1. Gerar lista de numeros aleatorios.\n");	
	printf("\t2. Exibir lista.\n");
	printf("\t3. Inserir valores da lista na tabela.\n");	
	printf("\t4. Exibir tabela.\n\t5. Remover valor da tabela.\n");	
	printf("Entre com o valor 0 para encerrar\n\n");
}

void emptyTable(HashTable table[], int table_size)
{
	int count = 0;

	for (count; count < table_size; count++)
	{
		table[count].key = 0;
		table[count].value = 0;
		table[count].status = 0;
	}
	
}











