#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct tanks {
    char nome[50];
    int calibre;
    int PessoTotal;
}t;

int CompararCalibre (const void *x, const void *y) {
    int pri = ((struct tanks *)x)->calibre;
    int seg = ((struct tanks *)y)->calibre;
    return (pri - seg);
}

int CompararPesso (const void *p, const void *q) {
    int pri = ((struct tanks *)p)->PessoTotal;
    int seg = ((struct tanks *)q)->PessoTotal;
    return (pri - seg);
}

int CompararNome (const void *a, const void *b) {
    return strcmp (((struct tanks *)a)->nome,((struct tanks *)b)->nome);
}

int main(){


FILE *arq;
arq = fopen("ArquivoTankOrdenado.txt", "wb");


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
    
     
     qsort(exp, i, sizeof(struct tanks), CompararCalibre);
      printf("\nTanks ordenados pelo calibre:\n");
   for (i = 0; i < l; i++) {
    // printf("(nome)%s: (calibre)%d, (peso do tank)%d toneladas\n", exp[i].nome, exp[i].calibre,exp[i].PessoTotal);
     fwrite(&exp[i], sizeof(exp[i]), 1, arq);
   }
   
  // qsort(exp, l, sizeof(struct tanks), CompararNome);
     
     // printf("\nTanks ordenados pelo nome:\n");
  // for (i = 0; i < l; i++) {
    // printf("(nome)%s: (calibre)%d, (peso do tank)%d toneladas\n", exp[i].nome, exp[i].calibre,exp[i].PessoTotal);
  // }
   
   //qsort(exp, l, sizeof(struct tanks), CompararPesso);
     
    //  printf("\nTanks ordenados pelo peso:\n");
   //for (i = 0; i < l; i++) {
  //   printf("(nome)%s: (calibre)%d, (peso do tank)%d toneladas\n", exp[i].nome, exp[i].calibre,exp[i].PessoTotal);
  // }
    
    fclose(arq);


}
