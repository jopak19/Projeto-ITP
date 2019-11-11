#include <stdio.h>
#include "instrucao.h"


int main(){
    Instrucao ins;
    int args[] = {255, 255, 255};
    definirInstrucao(&ins, "cor", args, 3);
    imprimirInstrucao(ins);
    liberarInstrucao(&ins);
    return 0;
}
