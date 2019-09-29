#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    char *nome, *nome2;
    int i, quant = -2147483646, idcont=0, subi=0;
    nome = malloc(sizeof(char));
    nome2 = malloc(sizeof(char));
    printf("Digite o que deve ser buscado: ");
    gets(nome);
    if(strcmpi(nome, "deus") == 0){
        printf("Error 404: Não existe.");
        return 0;
    }
    for(i = 0; i < (strlen(nome)); i++){
        nome[i] = toupper(nome[i]);
    }
    do{
        if(quant >= 2147483646){
            srand(time(NULL));
            quant = -2147483646;
            subi++;
        }
        for(i = 0; i < (strlen(nome)); i++){
            nome2[i] = (rand() % 26) + 65;
            if(nome[i] == nome2[i]){
                idcont++;
            }
        }
        nome2[i] = '\0';
        quant++;
        if((idcont*100)/strlen(nome) > 66){
            printf("Palavra parecida achada: %s -- Palavras geradas: %d -- %d° Seed\n", nome2, quant+2147483646, subi);
        }
        idcont = 0;
    }while(strcmpi(nome, nome2) != 0);


    printf("Palavra buscada: %s\nPalavra achada: %s", nome, nome2);
    return 0;
}
