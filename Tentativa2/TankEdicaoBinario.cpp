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

int i = 0;
    while(fread(&t, sizeof(t), 1, arq)){
    printf("%i -- %s, %d, %d\n", i, t.nome, t.calibre, t.PessoTotal);
    i++;
    }

    printf("Digite o identificador do tank que deseja modificar:\n");
    scanf("%d", &i);
    getchar();
    
    system("cls");
    
    printf("Digite o nome do novo tank: %d\n", i);
    scanf("%s", t.nome);
    
    printf("Digite o calibre do novo tank %d \n", i);
    scanf("%d", &t.calibre);
    
    printf("Digite o Pesso em toneladas do novo tank %d \n", i);
    scanf("%d", &t.PessoTotal);
    
    fseek(arq, i * sizeof(t), SEEK_SET);
    fwrite(&t, sizeof(t), 1, arq);


fclose(arq);


}
