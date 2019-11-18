#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instrucao.h"
#include "imagem.h"


typedef struct{
    FILE* canal;
    char* nome;
} Arquivo;

int abrirArquivo(Arquivo* arquivo, char* nome, char* tipo);
void fecharArquivo(Arquivo* arquivo);
char* lerLinha(Arquivo arquivo);
int lerInstrucao(Arquivo arquivo, Instrucao* instrucao);
void escreverImagem(Arquivo* arquivo, Imagem img);

#endif