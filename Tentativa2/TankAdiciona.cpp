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
arq = fopen("ArquivoTank.txt", "ab+");

int i = 0;
	printf("-----------Atualmente No arquivo Ja tem os seguintes tanks registrados----------------\n\n");	
    while(fread(&t, sizeof(t), 1, arq)){
    printf("            \n     %i -- %s, %d, %d\n", i, t.nome, t.calibre, t.PessoTotal);
    i++;
    }
	printf("\n--------------------------------------------------------------------------------------\n");	
    

    
    
    
    printf("Digite o nome da segunda parte dos tank: %d\n", i);
    scanf("%s", t.nome);
    
    printf("Digite o calibre da segunda parte dos tank %d \n", i);
    scanf("%d", &t.calibre);
    
    printf("Digite o Pesso em toneladas da segunda parte dos tank %d \n", i);
    scanf("%d", &t.PessoTotal);
    
    
    fwrite(&t, sizeof(t), 1, arq);


fclose(arq);


}
