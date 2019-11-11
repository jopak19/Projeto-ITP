#include "instrucao.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void liberarInstrucao(Instrucao* instrucao){
    free(instrucao->comando);
    free(instrucao->args);
    instrucao->argsQuant = 0;
}

void definirInstrucao(Instrucao* instrucao, char* comando, int* args, int quant){
    // define instrucao.comando;
    instrucao->comando = (char*) malloc((strlen(comando) + 1) * sizeof(char));
    strcpy(instrucao->comando, comando);
    // define instrucao.args;
    instrucao->args = (int*) malloc(quant * sizeof(int));
    for (int i = 0; i < quant; i++){
        instrucao->args[i] = args[i];
    }
    instrucao->argsQuant = quant;
}

char* obterComandoInstrucao(Instrucao instrucao){
    return instrucao.comando;
}

int obterArgInstrucao(Instrucao instrucao, int indice){
    return instrucao.args[indice];
}

int obterArgsQuantInstrucao(Instrucao instrucao){
    return instrucao.argsQuant;
}

void imprimirInstrucao(Instrucao instrucao){
    printf("%s:", instrucao.comando);
    for (int i = 0; i < instrucao.argsQuant; i++){
        printf(" %i", instrucao.args[i]);
    }
    printf("\n");
}
