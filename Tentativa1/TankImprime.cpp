#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tanks {
    char nome[50];
    int calibre;
    int PessoTotal;
}t;

int main() {

FILE *arq;
arq = fopen("ArquivoTank.txt", "rb");



    while(fread(&t, sizeof(t), 1, arq)){
    
	printf("%s, %d, %d\n", t.nome, t.calibre, t.PessoTotal);

    
	}

fclose(arq);

}
