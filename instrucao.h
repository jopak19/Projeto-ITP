#ifndef INSTRUCAO_H
#define INSTRUCAO_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct{
    char* comando;
    char** args;
    int qntArgs;
} Instrucao;

enum CodigoInstrucao{
    ERROR = -1,
    PRIMITIVA,
    IMAGE,
    COLOR,
    CLEAR,
    LINE,
    REACT,
    CIRCLE,
    POLYGON,
    FILL,
    SAVE,
    OPEN
};

int definirInstrucao(Instrucao* instrucao, char* linha);
void definirComando(Instrucao* instrucao, char* comando);
void adicionarArgumento(Instrucao* instrucao, char* arg);
void liberarInstrucao(Instrucao* instrucao);
void imprimirInstrucao(Instrucao instrucao);
int obterCodigoInstrucao(Instrucao instrucao);

#endif