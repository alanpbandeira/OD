#include <stdio.h>
#include <stdlib.h>

int main(){
	float m[100][10],aux=0.0;
	int i,j,k,col=0,auxi=0;
	printf("\nMatriz ORIGINAL \n");
	for(i=0;i<100;i++){
		printf("\n\t");
		for(j=0;j<10;j++){
			aux=rand()%1001;
			m[i][j]=aux/100; // Joga valores randomicas na tabela < 100
			printf("%4.1f  ",m[i][j]);
		}
	}
	printf("\nDigite a coluna que deseja classificar (0 a 9)");
	scanf(" %d",&col);
	getchar();
	printf("\n\n");	

	// CLASSIFICACAO PELO METODO DA SELECAO
	printf("Selecione a ordem:\nA - Ascendente\nD - Descendente\n");
	char ordem = getchar();
	
	float sort_aux = 0;
	int actual_line = 0;
	int next_line = actual_line + 1;
	int min = 0;
	int count = 0;
	
	if(ordem == 'A')
	{
		while(actual_line <= 98)
		{
			if (next_line > 99)
			{
				actual_line ++;
				next_line = actual_line + 1;
			}
			else if (m[actual_line][col] <= m[next_line][col])
			{
				next_line ++;
			}
			else
			{
				for (count = 0; count < 10; count++)
				{
					sort_aux = m[actual_line][count];
					m[actual_line][count] = m[next_line][count];
					m[next_line][count] = sort_aux;
				}
				next_line++;
			}
		}	
	}
	else if(ordem == 'D')
	{
		while(actual_line <= 98)
		{
			if (next_line > 99)
			{
				actual_line ++;
				next_line = actual_line + 1;
			}
			else if (m[actual_line][col] >= m[next_line][col])
			{
				next_line ++;
			}
			else
			{
				for (count = 0; count < 10; count++)
				{
					sort_aux = m[actual_line][count];
					m[actual_line][count] = m[next_line][count];
					m[next_line][count] = sort_aux;
				}
				next_line++;
			}
		}	
	}
	else
	{
		printf("Invalid Input\n");
		return 0;
	}

	printf("\nMatriz CLASSIFICADA \n");
	for(i=0;i<100;i++){
			printf("\n");
			for(j=0;j<10;j++){
				printf("%4.1f\t",m[i][j]);
			};};	
		printf("\n\n");	
	system("pause");
}
