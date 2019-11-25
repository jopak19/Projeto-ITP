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

/**
 * Recebe dois inteiros, largura e altura.
 * Armazena as informações em um struct 'Imagem'.
 */
void definirImagem(Imagem* imagem, int altura, int largura);

/**
 * Libera todos os vetores alocados dinamicamente
 * de um struct 'Imagem'.
 * Obs.: Sempre deve ser chamado, caso a 'Imagem' for definida.
 */
void liberarImagem(Imagem* imagem);

/**
 * Desenha uma reta em um struct imagem.
 * Obs.: Essa função foi baseada em um algorimo obtido em:
 * http://letslearnbits.blogspot.com/2014/10/icgt1-algoritmo-de-bresenham.html,
 * que utiliza o algoritimo de bresenham.
 */
void desenharReta(Ponto ptnInicial, Ponto ptnFinal, Cor cor, Imagem* img);

/**
 * Desenha uma poligono em um struct imagem.
 */
void desenharPoligono(Imagem* Imagem, Cor cor, Ponto* pontos, int qntPontos);

/**
 * Muda a Cor de um pixel em um struct 'Imagem'.
 */
int pintarPixel(Ponto p, Cor cor, Imagem* imagem);

/**
 * Obs.: Adaptado do algoritmo de Bresenham.
 */
void plot_point(int x, int y, Ponto p, Cor cor, Imagem* img);

/**
 * Desenha um círculo na 'Imagem'.
 * Obs.: Adaptado do algoritmo de Bresenham.
 */
void desenharCirculo(Ponto ponto, int raio, Cor cor, Imagem* img);

/**
 * Pinta completamente um struct 'Imagem' com uma 'Cor'.
 */
void clear(Imagem* img, Cor cor);

/**
 * Preenche uma figura da 'Imagem' com uma 'Cor'.
 * Obs.: Essa função foi implementada de forma recursiva.
 */
void preencherFiguraRecursivo(Imagem* img, Cor tinta, Cor fundo, Ponto pnt);

/**
 * Preenche uma figura da 'Imagem' com uma 'Cor'.
 * Obs.: Essa função foi implementada de forma interativa.
 */
void preencherFiguraInterativo(Imagem* img, Cor tinta, Cor fundo, Ponto pnt);

#endif