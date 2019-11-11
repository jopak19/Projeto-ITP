#ifndef INSTRUCAO_H
#define INSTRUCAO_H


typedef struct{
    char* comando;
    int* args;
    int argsQuant;
} Instrucao;

void definirInstrucao(Instrucao* instrucao, char* comando, int* args, int quant);
void liberarInstrucao(Instrucao* instrucao);
char* obterComandoInstrucao(Instrucao instrucao);
int obterArgInstrucao(Instrucao instrucao, int indice);
int obterArgsQuantInstrucao(Instrucao instrucao);
void imprimirInstrucao(Instrucao instrucao);

#endif