#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tanks {
    char nome[50];
    int calibre;
    int PessoTotal;
}t;

void TanksImprime(char *nomeDoArquivo)
{
    FILE *arq;
    t T;
    t vetor[100];
    int i = 0;
    int j;

    arq = fopen(nomeDoArquivo, "rb");
    while (fread(&T, sizeof(T), 1, arq))
    {
        vetor[i] = T;
        i++;
    }

    bubble_sort(vetor, i);

    printf("\nTanks Cadastrados\n");

    for (j = 0; j < i; j++)
    {
        printf("    %d - %s, %dmm, %d\n", j + 1, vetor[j].nome, vetor[j].calibre, vetor[j].PessoTotal);
    }

    printf("\n\n");

    fclose(arq);
    sleep(1);
}

void bubble_sort(t vetor[], int size)
{
    t temp;
    int i, j;

    for (i = 0; i < size; i++)
    {
        for (j = 1; j < size; j++)
        {
            if (strcmp(vetor[j - 1].nome, vetor[j].nome) > 0)
            {
                temp = vetor[j - 1];
                vetor[j - 1] = vetor[j];
                vetor[j] = temp;
            }
        }
	}
}

void TankBinario (char *nomeDoArquivo){
    FILE *arq;
	arq = fopen("TanksBinario.txt", "wb");


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


void TankEdicao(char *nomeDoArquivo){
    FILE *arq;
arq = fopen("TanksBinario.txt", "rb+");

	struct tanks T;

int i = 0;
    while(fread(&T, sizeof(T), 1, arq)){
    printf("%i -- %s, %dmm, %d\n", i, T.nome, T.calibre, T.PessoTotal);
    i++;
    }

    printf("Digite o identificador do tank que deseja modificar:\n");
    scanf("%d", &i);
    getchar();
    
    system("cls");
    
    printf("Digite o nome do novo tank: %d\n", i);
    scanf("%s", T.nome);
    
    printf("Digite o calibre do novo tank %d \n", i);
    scanf("%d", &T.calibre);
    
    printf("Digite o Pesso em toneladas do novo tank %d \n", i);
    scanf("%d", &T.PessoTotal);
    
    fseek(arq, i * sizeof(T), SEEK_SET);
    fwrite(&T, sizeof(T), 1, arq);


fclose(arq);


}

void TankDeleta(nomeDoArquivo){
	
    struct tanks T;
    FILE *arq, *arqDel;
	arq = fopen("TanksBinario.txt", "rb");
	
int j = 0;

    while(fread(&T, sizeof(T), 1, arq)){
    
	printf("#%d, %s, %dmm, %d\n", j, T.nome, T.calibre, T.PessoTotal);

    j++;
	}
    fclose(arq);

    int d;
    printf("Qual entrada voce gostaria de deletar?");
    scanf("%d", &d);

    
    arq = fopen("TanksBinario.txt", "rb");
    arqDel = fopen("arquivoDel.txt", "wb");


    if(arqDel){
    
j=0;
	   while(fread(&T, sizeof(T), 1, arq)){
	       if (j != d){
	    		fwrite(&T, sizeof(T), 1, arqDel);
	    		
	    	}
		j++;
		}

	remove("TanksBinario.txt");
    }
    else{
        printf("Ero ao criar arquivo");
    }

    fclose(arqDel);

    arq = fopen("TanksBinario.txt", "wb");
    arqDel = fopen("arquivoDel.txt", "rb");

    if (arq){
        int j = 0;
        while(fread(&T, sizeof(T), 1, arqDel)){
            fwrite(&T, sizeof(T), 1, arq);
            j++;
        }
    }
    else{
        printf("Erro ao abrir arquivo");
        }

    remove("arquivoDel.txt");
    fclose(arq);
}

void BuscaTanks(char *NomeArquivo) {
    FILE *arq;
    arq = fopen("TanksBinario.txt", "rb");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    
    struct tanks T;
    char nomeBuscado[20];
    printf("Digite o nome do Tank: ");
    fgets(nomeBuscado, 20, stdin);
    strtok(nomeBuscado, "\n");

    
    while(fread(&T, sizeof(T), 1, arq)) {
        if (strcmp(T.nome, nomeBuscado) == 0) {
            printf("\n\nTank encontrado:\n");
            printf(" Nome - %s\n Calibre - %dmm\n Peso - %d\n", T.nome, T.calibre, T.PessoTotal);
            fclose(arq);
            return;
        }
    }
    
    printf("\n\nTank nao encontrado!\n");
    fclose(arq);
    
    sleep(1);
}

int tankAdiciona(char *NomeArquivo) {

FILE *arq;
arq = fopen("TanksBinario.txt", "ab+");
struct tanks T;

int i = 0;
	printf("-----------Atualmente No arquivo Ja tem os seguintes tanks registrados----------------\n\n");	
    while(fread(&T, sizeof(T), 1, arq)){
    printf("            \n     %i -- %s, %d, %d\n", i, T.nome, T.calibre, T.PessoTotal);
    i++;
    }
	printf("\n--------------------------------------------------------------------------------------\n");	
    

    
    
    
    printf("Digite o nome da segunda parte dos tank: %d\n", i);
    scanf("%s", T.nome);
    
    printf("Digite o calibre da segunda parte dos tank %d \n", i);
    scanf("%d", &T.calibre);
    
    printf("Digite o Pesso em toneladas da segunda parte dos tank %d \n", i);
    scanf("%d", &T.PessoTotal);
    
    
    fwrite(&T, sizeof(T), 1, arq);


fclose(arq);


}

int main(){
    char nomeDoArquivo[] = "TanksBinario.txt";

    int opcao;
    do {
        printf("Digite a opcao desejada:\n\n\n\n");
        printf(" 0 - Encerrar\n 1 - Cadastrar Tanks\n 2 - Ler Tanks cadastrados\n 3 - Editar entrada\n 4 - Deletar entrada\n 5 - Buscar Tanks\n 6 - Adicionar tanks\n");
        scanf("%d", &opcao);
        printf("\n\n");
        getchar();

        switch (opcao){
            case 1:
                TankBinario(nomeDoArquivo);
                break;
            case 2:
                TanksImprime(nomeDoArquivo);
                break;
            case 3:
                TankEdicao(nomeDoArquivo);
                break;
            case 4:
                TankDeleta(nomeDoArquivo);
                break;
            case 5:
                BuscaTanks(nomeDoArquivo);
                break;
            case 6:
                tankAdiciona(nomeDoArquivo);
                break;
            default:
                printf("\nFIM\n");
        }
    }
    while (opcao != 0);
}
