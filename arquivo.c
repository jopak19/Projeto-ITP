#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char* result = fgets(texto_str, 50, arq);
    if (result==NULL) {
        return NULL;
    }
    // so teste
    Comando* com = (Comando*) calloc(1, sizeof(Comando));
    strcpy(com->comando, "image");
    com->parametros[0] = 20;
    com->parametros[1] = 20;
    com->qntParametros = 2;

    return com;
}
typedef struct{
     int r;
     int g;
     int b;
}Cor;
typedef struct {
    int x;
    int y;
}Ponto;

typedef struct {
     int linhas;
     int colunas;
     Cor** imagem;
}Matriz;
void liberaImagem(Matriz* mat){
    for (int i =0; i< mat->linhas; i++) {
        free(mat->imagem[i]);
    }
    free(mat);
}
void executaComando(Comando* com, Matriz* mat){

    if (strcmp(com->comando, "image") == 0) {
        mat->imagem = (Cor**) calloc(com->parametros[0], sizeof(Cor*));
        for (int i =0; i < com->parametros[0]; i++) {
            mat->imagem[i] = calloc(com->parametros[1], sizeof(Cor));
        }
        for (int i = 0; i<mat->linhas; i++) {
            for (int j =0; j<mat->colunas; j++) {
                Cor cor;
                cor.r = 255;
                cor.g = 255;
                cor.b = 255;
                mat->imagem[i][j] = cor;
            }
        }
    }

}
void passaMatriz(FILE* arq, Matriz* mat){

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

    while(1){
        if (com == NULL) {
            break;
        }
        executaComando(com, matriz);
        free(com);
        com = lerComando(entrada);

    }
    free(com);
    liberaImagem(matriz);
    fechaArquivo(entrada);
    fechaArquivo(saida);
}