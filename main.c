#include <stdio.h>
#include "instrucao.h"
#include "arq_instrucao.h"


int main(){
    Instrucao ins;
    ArqInstrucao arq;
    abrirArqInstrucao(&arq, "instrucao.txt");
    while(lerArqInstrucao(arq, &ins)){
        imprimirInstrucao(ins);
        liberarInstrucao(&ins);
    }
    fecharArqInstrucao(&arq);
    return 0;
}
