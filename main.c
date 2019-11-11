#include <stdio.h>
#include "instrucao.h"
#include "arq_instrucao.h"
#include "arq_imagem.h"


int main(){
    Instrucao ins;
    ArqInstrucao arq;
    ArqImagem ppm;
    Imagem img;
    definirImagem(&img, 500, 300);
    abrirArqInstrucao(&arq, "instrucao.txt");
    while(lerArqInstrucao(arq, &ins)){
        imprimirInstrucao(ins);
        liberarInstrucao(&ins);
    }
    fecharArqInstrucao(&arq);
    abrirArqImagem(&ppm, "imagem.PPM");
    salvarImagem(&ppm, img);
    liberarImagem(&img);
    fecharArqImagem(&ppm);
    return 0;
}
