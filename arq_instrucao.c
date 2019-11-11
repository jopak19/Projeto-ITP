#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arq_instrucao.h"


int abrirArqInstrucao(ArqInstrucao* arquivo, char* nome){
    FILE* temp = fopen(nome, "r");
    if (temp == NULL) return 0;
    arquivo->canal = temp;
    arquivo->nome = malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(arquivo->nome, nome);
    return 1;
}

void fecharArqInstrucao(ArqInstrucao* arquivo){
    fclose(arquivo->canal);
    free(arquivo->nome);
}

int lerArqInstrucao(ArqInstrucao arquivo, Instrucao* instrucao){
    char** linha = (char**) malloc(0);
    int numPalavras = 0;
    int tamanhoPalavraAtual = 1;
    char ultimaLetra;

    while(1){
        do{
            ultimaLetra = fgetc(arquivo.canal);
            // verifica se a ultima palavra chegou ao fim;
            if (ultimaLetra == ' ' && tamanhoPalavraAtual > 1){
                // termina a palavra atual e reinicia o tamanho;
                linha[numPalavras - 1][tamanhoPalavraAtual - 1] = '\0';
                tamanhoPalavraAtual = 1;
            }
            // repete enquanto não achar uma letra e a linha não terminar;
        } while(ultimaLetra == ' ' && ultimaLetra != EOF && ultimaLetra != '\n');
        // para o loop se a linha chegar ao fim;
        if (ultimaLetra == EOF || ultimaLetra == '\n') break;
        // verifica se a ultima palavra já tem algum caracter;
        if (tamanhoPalavraAtual > 1){
            // adiciona um novo caracter na ultima palavra;
            tamanhoPalavraAtual += 1;
            linha[numPalavras - 1] = (char*) realloc(linha[numPalavras - 1], tamanhoPalavraAtual * sizeof(char));
            linha[numPalavras - 1][tamanhoPalavraAtual - 2] = ultimaLetra;
        }
        else {
            // adiciona uma palavra na 'linha';
            numPalavras += 1;
            linha = (char**) realloc(linha, numPalavras * sizeof(char*));
            // adiciona o primeiro caracter da palavra recém definida;
            tamanhoPalavraAtual += 1;
            linha[numPalavras - 1] = (char*) malloc(tamanhoPalavraAtual * sizeof(char));
            linha[numPalavras - 1][tamanhoPalavraAtual - 2] = ultimaLetra;
        }
    }
    // testa se a linha tem palavras;
    if (numPalavras > 0){
        int* args;
        args = (int*) malloc((numPalavras - 1) * sizeof(int));
        // se a linha tem mais de uma palavra converte o restante em números;
        for (int i = 0; i < numPalavras - 1; i++){
            args[i] = atoi(linha[i + 1]);
        }
        definirInstrucao(instrucao, linha[0], args, numPalavras - 1);
        // libera os vetores alocados dinamicamente até agora;
        free(args);
        for (int i = 0; i < numPalavras; i++){
            free(linha[i]);
        }
        free(linha);
        // parâmetro 'instrucao' foi modificado? 1 - sim, 0 - não;
        return 1;
    }
    // parâmetro 'instrucao' foi modificado? 1 - sim, 0 - não;
    return 0;
}
