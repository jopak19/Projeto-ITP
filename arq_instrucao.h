#ifndef ARQ_INSTRUCAO_H
#define ARQ_INSTRUCAO_H
#include <stdio.h>
#include "instrucao.h"


typedef struct{
    FILE* canal;
    char* nome;
} ArqInstrucao;

int abrirArqInstrucao(ArqInstrucao* arquivo, char* nome);
void fecharArqInstrucao(ArqInstrucao* arquivo);
int lerArqInstrucao(ArqInstrucao arquivo, Instrucao* instrucao);

#endif