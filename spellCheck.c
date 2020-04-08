#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define TOTAL 30000 // total de buckets

//entrada: dicionario com 307856 linhas(palavras + 1 linha vazia)
// 307856/7 = 43979,4285714
// novo numero primo == 43987
FILE * arqu;
clock_t tempo;
int encontrado, naoencontrado;
int np;
char buff [50]= "";

struct Node
{
  char palavra[50];
  struct Node *next;
};

struct Lista
{
  struct Node *head;
  int size;
};

struct Lista bucket[TOTAL]; // array de buckets que forma a tabela hash
                            // cada bucket é uma lista simplesmente encadeada
 struct Node * ptr;


///////////funcao de hash ////////////////////////
unsigned int hash(char * blau)
{
  unsigned int hashinho = 0;
  int i;

  for(i=0; blau[i]!='\0'; i++){
    hashinho += ((hashinho*251) + blau[i]);
  } 

  return hashinho%TOTAL;
}

////////////////////Adiçao das palvras do Dicionario aos buckets
void insereDici(){
    int calc=0;
    arqu =  fopen("dicionario.txt", "r");
    if(arqu == NULL)
        printf("dicionario nao encontrado\n");
    else{
        while (fgets(buff,50,arqu) != NULL)
        {
            np++;
            calc =  hash(buff);

        if(bucket[calc].head == NULL){ //verifica se ja existe palavra nesse bucket, caso não tenha ele aloca a palavra na primeira posição
        struct Node* noAtual = (struct Node*) malloc (sizeof(struct Node)); //cria um novo nó dinamicamente

        for(int i = 0; i < 50; i++){
            noAtual->palavra[i] = buff[i];
        }
        noAtual->next = NULL;
        bucket[calc].head = noAtual; // faz o ponteiro apontar para o novo nó

    }else{ // se o primeiro nó da lista já estiver ocupado verifica os próximos até encontrar o nó que está vazio
        struct Node * ptr; //cria um ponteiro auxiliar
        ptr = bucket[calc].head; //faz com que o ponteiro auxiliar aponte para o primeiro

        while(ptr->next != NULL){ // roda um laço de repetição até encontrar um nó vazio
            ptr = ptr->next; //faz com que o ponteiro auxiliar aponte para o próximo para que o laço de repetição funcione
        }

        struct Node* noAtual = (struct Node*) malloc (sizeof(struct Node)); //cria um novo nó dinamicamente

        for(int i = 0; i < 50; i++){
            noAtual->palavra[i] = buff[i];
        }

        noAtual->next = NULL;

        ptr->next = noAtual; //faz com que o ponteiro do ultimo nó da lista aponte para o nó novo
    }
            
        }
        fclose(arqu);
    }

}

void verifica(){
    unsigned int calc;
    arqu = fopen("arquivo.txt", "r");
   if(arqu == NULL)
        printf("Arquivo nao encontrado\n");
    else{
    while (fgets(buff, 50, arqu))
    {
         
        calc = hash(buff);
        ptr = bucket[calc].head;
        if (ptr == NULL)
        {
            naoencontrado++;
        }
        
         while(ptr != NULL){ //roda até que o ponteiro aponte para nada sinalizando o final da lista
         
                if(strcmp(buff, ptr->palavra) == 1){ //compara as palavras
                    encontrado++; //atualiza a contagem de palavras encontradas
                    break;//para o loop pois não precisa avançar mais na lista já que já encontrou a palavra desejada
                }else
                {
                    naoencontrado++;
                }
                

                ptr = ptr->next;//atualiza o ponteiro caso a palavra não tenha sido encontrada
            }
         


    }
    
    
    fclose(arqu);
    }


}


int main(){

   for(int i = 0; i < TOTAL; i++)
        bucket[i].head = NULL; 

    insereDici();
    
    tempo = clock();
    verifica();
    tempo = clock() - tempo;
  
printf("Tempo de execucao: %lf\n\n", ((double)tempo)/((CLOCKS_PER_SEC))/1000);

printf("Palavras encontradas: %d\n Numero de  Palavras do dicionario:%d\n Palavras nao encontradas:%d\n",encontrado,np, naoencontrado);



}