#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct tanks
{
    char nome[50];
    int calibre;
    int PessoTotal;
}t;

int main() {

FILE *arq;
arq = fopen("ArquivoTank.txt", "rb+");
FILE *arq2;
arq2 = fopen("ArquivoTank2.txt", "rb+");
int j, i, l;

printf("digite o numero do tank que voce deseja remover");
scanf("%d", &j);
struct tanks exp[l];

for(i == 0; i < j; i++){

 while(fread(&t, sizeof(t), 1, arq)){
    if(j != i){
    	
    	
    	fwrite(&exp[i], sizeof(exp[i]), 1, arq);
}
	}
    }


fclose(arq);


}
