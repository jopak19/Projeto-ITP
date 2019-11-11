#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>

void* AlocarMemoria(int bytes){
    void* ponteiro;
    ponteiro = malloc(bytes);
    if(ponteiro == NULL){
        exit(1);
    }
    return ponteiro;
}
void liberaMemoria(void* ptr){
    free(ptr);
}

FILE* defineArquivo(){
    FILE* arquivo;
    arquivo = AlocarMemoria(sizeof(FILE*));
    return arquivo;
}
FILE* lerArquivo(){
    FILE* arq = fopen("texto.txt", "r");
    return arq;
}

typedef struct {
    char comando[50];
    int parametros[10];
    int qntParametros;
}Comando;

void fechaArquivo(FILE* arq){
    fclose(arq);
}
Comando* lerComando(FILE* arq){
    char texto_str[50];
    fgets(texto_str, 20, arq);
    Comando* com = (Comando*) calloc(1, sizeof(Comando));

     return com;
}
typedef struct{
     int r;
     int g;
     int b;
}Cor;
typedef struct {
     int pixels;
     Cor** imagem;
}Matriz;
void executaComando(Comando* com, Matriz* mat){


}
void escreveCabecalho(FILE* arq){
    fprintf(arq, "P3\n");
}
int main(){
    Matriz* matriz;

    //para leitura de arquivos e saida de imagem
    // if "criar imagem" fazer isso:
    FILE* saida = fopen("texto2.txt", "a");
    escreveCabecalho(saida);
    FILE* entrada = lerArquivo();
    Comando* com = lerComando(entrada);
    while(com != NULL){
       com = lerComando(entrada);
       executaComando(com, matriz);
       free(com);

    }
    fechaArquivo(entrada);
    fechaArquivo(saida);
}