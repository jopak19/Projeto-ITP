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

/**
 * Retira as informações de uma linha.
 * Guarda essas informações em um struct 'Instrucao'.
 * Retorna 1 se tudo ocorrer bem, caso contrário, retorna 0.
 */
int definirInstrucao(Instrucao* instrucao, char* linha);

/**
 * Define um 'comando' para um struct 'Instrucao'.
 */
void definirComando(Instrucao* instrucao, char* comando);

/**
 * Adiciona um 'argumento' em um struct 'Instrucao'.
 */
void adicionarArgumento(Instrucao* instrucao, char* arg);

/**
 * Libera todos os vetores alocados dinamicamente de um struct 'Instrucao'.
 * Obs.: Sempre deve ser chamado, caso a 'Instrucao' for definida.
 */
void liberarInstrucao(Instrucao* instrucao);

/**
 * Imprime as informações de um struct 'Instrucao'.
 */
void imprimirInstrucao(Instrucao instrucao);

/**
 * Recebe um struct 'Instrucao' e retorna um código
 * referente ao seu comando;
 */
int obterCodigoInstrucao(Instrucao instrucao);

#endif