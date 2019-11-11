#include "imagem.h"
#include <stdlib.h>


void definirImagem(Imagem* img, int altura, int largura){
    img->altura = altura;
    img->largura = largura;
    img->matriz = (Cor**) malloc(altura * sizeof(Cor*));
    for (int i = 0; i < altura; i++){
        img->matriz[i] = (Cor*) malloc(largura * sizeof(Cor));
        for (int j = 0; j < largura; j++){
            img->matriz[i][j] = definirCor(200, 50, 100);
        }
    }
}

void liberarImagem(Imagem* imagem){
    for (int i = 0; i < imagem->altura; i++){
        free(imagem->matriz[i]);
    }
    free(imagem->matriz);
    imagem->altura = 0;
    imagem->largura = 0;
}
