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
void desenharReta(Ponto ptnInicial, Ponto ptnFinal, Cor cor, Imagem* img);
void desenharPoligono(Imagem* Imagem, Cor cor, Ponto* pontos, int qntPontos);
int pintarPixel(Ponto p, Cor cor, Imagem* imagem);
void plot_point(int x, int y, Ponto p, Cor cor, Imagem* img);
void desenharCirculo(Ponto ponto, int raio, Cor cor, Imagem* img);
void clear(Imagem* img, Cor cor);
void preencherFiguraRecursivo(Imagem* img, Cor tinta, Cor fundo, Ponto pnt);
void preencherFiguraInterativo(Imagem* img, Cor tinta, Cor fundo, Ponto pnt);

#endif