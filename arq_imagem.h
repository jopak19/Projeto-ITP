#ifndef ARQ_IMAGEM_H
#define ARQ_IMAGEM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imagem.h"


typedef struct{
    FILE* canal;
    char* nome;
} ArqImagem;

int abrirArqImagem(ArqImagem* arquivo, char* nome);
void fecharArqImagem(ArqImagem* arquivo);
void salvarImagem(ArqImagem* arquivo, Imagem img);

#endif