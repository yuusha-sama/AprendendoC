#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct tanks {
    char nome[50];
    int calibre;
    int PessoTotal;
}t;

int main(){


FILE *arq;
arq = fopen("ArquivoTank.txt", "wb");


printf("Voce conhece quantos tanks?\n");
int l, i;
scanf("%d", &l);
while(getchar()!='\n');
struct tanks exp[l];

system("cls");

printf("Digite as caracteristicas de %d tanks: \n", l);

for (i = 0; i < l; i++) {

	fflush(stdin);

    printf("Voce sabe o nome do tank %d ? \n", i+1);
    fgets(exp[i].nome, 50, stdin);
    strtok(exp[i].nome, "\n");
   
    

    printf("e quanto o calibre do tank %d, voce sabe? \n", i+1);
    scanf("%d", &exp[i].calibre);
    

    printf("o pesso total em toneladas do tank %d, voce sabe qual e? \n", i+1);
    scanf("%d", &exp[i].PessoTotal);
    
    while(getchar() != '\n');
    

    fwrite(&exp[i], sizeof(exp[i]), 1, arq);

	system("cls");
    }
    fclose(arq);


}
