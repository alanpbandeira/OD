//Compilado em Linux.Sujeito a mudanças caso outro sistema seja utilizado.
 
 #include <stdio.h>
 
 #define tam_bucket 100
 #define num_bucket 10
 #define max 10
 
 typedef struct {
         int topo;
         int balde[tam_bucket];
 }bucket;
 
 void bucket_sort(int v[],int tam);                   //cabeçalho das funções
 void bubble(int v[],int tam);                                                 

int main(int argc, char const *argv[])
{       
        int array_size = 6;
        int point[array_size]={0,0,1,0,0,0};
        //int array[array_size];
        //array = {14,6,73,2,46,54,45,43,46,56,5,42,42,23,4,5,6};

        bucket_sort(array, array_size);
        int i;

        for (i=0; i < array_size; i++)
        {
                printf("%d\n", array[i]);
        }
        return 0;
}


                                                                  
 void bucket_sort(int v[],int tam){                                     
         bucket b[num_bucket];                                      
         int i,j,k;                                                 
 /* 1 */ for(i=0;i<num_bucket;i++)                    //inicializa todos os "topo"
                 b[i].topo=0;
         
 /* 2 */ for(i=0;i<tam;i++){                          //verifica em que balde o elemento deve ficar
                 j=(num_bucket)-1;
                 while(1){
                         if(j<0)
                                 break;
                         if(v[i]>=j*10){
                                 b[j].balde[b[j].topo]=v[i];
                                 (b[j].topo)++;
                                 break;
                         }
                         j--;
                 }
         }
         
 /* 3 */ for(i=0;i<num_bucket;i++)                     //ordena os baldes
                 if(b[i].topo)
                         bubble(b[i].balde,b[i].topo);
         
         i=0;
 /* 4 */ for(j=0;j<num_bucket;j++){                    //põe os elementos dos baldes de volta no vetor
                 for(k=0;k<b[j].topo;k++){
                         v[i]=b[j].balde[k];
                         i++;
                 }
         }
 }
 
 void bubble(int v[],int tam){
         int i,j,temp,flag;
         if(tam)
                 for(j=0;j<tam-1;j++){
                         flag=0;
                         for(i=0;i<tam-1;i++){
                                 if(v[i+1]<v[i]){
                                         temp=v[i];
                                         v[i]=v[i+1];
                                         v[i+1]=temp;
                                         flag=1;
                                 }
                         }
                         if(!flag)
                                 break;
                 }
 }
