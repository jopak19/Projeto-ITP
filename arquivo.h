#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char comando[50];
    int parametros[10];
    int qntParametros;
}Comando;
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

FILE* lerArquivo();
FILE* escreverArquivo();
void fecharArquivo(FILE* arq);
int lerComando(FILE* arq, Comando* com);
void liberarImagem(Matriz* img);
Matriz alocarImagem(int linhas, int colunas);
void executaComando(Comando* com, Matriz* mat);
void passaMatriz(Matriz mat, FILE*  arq);

#endif