#ifndef IMAGEM_H
#define IMAGEM_H
#include <stdlib.h>
#include "cor.h"
#include "ponto.h"


typedef struct{
    int altura;
    int largura;
    Cor** matriz;
} Imagem;

void definirImagem(Imagem* imagem, int altura, int largura);
void liberarImagem(Imagem* imagem);
void desenharReta(Ponto ptnInicial, Ponto ptnFinal, Cor* cor, Imagem* img);
void desenharPoligono(Imagem* Imagem, Cor* cor, Ponto* pontos, int qntPontos);
void pintarPixel(Ponto p, Cor* cor, Imagem* imagem);

#endif