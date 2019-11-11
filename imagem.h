#ifndef IMAGEM_H
#define IMAGEM_H
#include "cor.h"


typedef struct{
    int altura;
    int largura;
    Cor** matriz;
} Imagem;

void definirImagem(Imagem* img, int altura, int largura);
void liberarImagem(Imagem* imagem);

#endif