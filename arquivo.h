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

/**
 * Abre um 'FILE', salva suas informações em um 'Arquivo';
 * Retorna 1 se tudo ocorrer bem, caso contrário, retorna 0.
 */
int abrirArquivo(Arquivo* arquivo, char* nome, char* tipo);

/**
 * Fechar um 'Arquivo' já aberto.
 */
void fecharArquivo(Arquivo* arquivo);

/**
 * Lê uma linha do 'Arquivo'.
 * Retorna uma string com as informações.
 * Caso a linha esteja vazia retorna NULL.
 */
char* lerLinha(Arquivo arquivo);

/**
 * Lê uma instrução do 'Arquivo'.
 * Armazena as informações no parâmetro 'instrucao'.
 * Retorna 1 se tudo ocorrer bem, caso contrário, retorna 0.
 */
int lerInstrucao(Arquivo arquivo, Instrucao* instrucao);

/**
 * Escreve uma imagem ppm no 'Arquivo'.
 */
void escreverImagem(Arquivo* arquivo, Imagem img);

#endif