#include "instrucao.h"


void liberarInstrucao(Instrucao* instrucao){
    free(instrucao->comando);
    for (int i = 0; i < instrucao->qntArgs; i++){
        free(instrucao->args[i]);
    }
    free(instrucao->args);
    instrucao->qntArgs = 0;
}

void definirComando(Instrucao* instrucao, char* comando){
    instrucao->comando = (char*) malloc((strlen(comando) + 1) * sizeof(char));
    strcpy(instrucao->comando, comando);
}

void adicionarArgumento(Instrucao* instrucao, char* arg){
    instrucao->qntArgs += 1;
    instrucao->args = (char**) realloc(instrucao->args, instrucao->qntArgs * sizeof(char*));
    instrucao->args[instrucao->qntArgs - 1] = (char*) malloc((strlen(arg) + 1) * sizeof(char));
    strcpy(instrucao->args[instrucao->qntArgs - 1], arg);
}

int definirInstrucao(Instrucao* instrucao, char* linha){
    char* palavra = strtok(linha, " ");
    if(palavra == NULL) return 0;
    definirComando(instrucao, palavra);
    instrucao->args = (char**) malloc(0);
    instrucao->qntArgs = 0;
    palavra = strtok(NULL, " ");
    while(palavra != NULL){
        adicionarArgumento(instrucao, palavra);
        palavra = strtok(NULL, " ");
    }
    return 1;
}

void imprimirInstrucao(Instrucao instrucao){
    printf("%s", instrucao.comando);
    for (int i = 0; i < instrucao.qntArgs; i++){
        printf(" %s", instrucao.args[i]);
    }
    printf("\n");
}

int obterCodigoInstrucao(Instrucao instrucao){
    if (strncmp(instrucao.comando, "image", 5) == 0) {
        return IMAGE;
    } else if(strncmp(instrucao.comando, "color", 5) == 0){
        return COLOR;
    } else if(strncmp(instrucao.comando, "clear", 5) == 0){
        return CLEAR;
    } else if(strncmp(instrucao.comando, "rect", 4) == 0){
        return RECT;
    } else if(strncmp(instrucao.comando, "circle", 6) == 0){
        return CIRCLE;
    } else if(strncmp(instrucao.comando, "polygon", 7) == 0){
        return POLYGON;
    } else if(strncmp(instrucao.comando, "fill", 4) == 0){
        return FILL;
    } else if(strncmp(instrucao.comando, "save", 4) == 0){
        return SAVE;
    } else if(strncmp(instrucao.comando, "open", 5) == 0){
        return OPEN;
    } else if(strncmp(instrucao.comando, "line", 5) == 0){
        return LINE;
    } else if(strncmp(instrucao.comando, "help", 9) == 0){
        return HELP;
    } else{
        return ERROR;
    }  
}
