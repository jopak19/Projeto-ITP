#include "imagem.h"
#include "ponto.h"
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
void desenharReta(Ponto ptnInicial, Ponto ptnFinal, Cor cor){
    int dx = ptnFinal.coordenadaX - ptnInicial.coordenadaX;
    int dy = ptnFinal.coordenadaY - ptnInicial.coordenadaY;
    int inclinacao=0; 
    if(dx<0) // caso ponto final < ponto inicial
    {
        desenharReta(ptnFinal,ptnInicial,cor);
        return;
    }
    if(dy<0)
        inclinacao = -1;
    else
        inclinacao = 1;

    int incE, incNE, d;

    Ponto ponto = ptnInicial;

    PutPixel(ponto,cor);
    if(dx >= inclinacao*dy){    // m<=1
        if(dy<0){ // caso y2<y1
            d = 2*dy+dx;
            while(ponto.x<pixel2.x){
                if(d<0){ // escolhido é o I
                    d += 2*(dy+dx);
                    ponto.x++;
                    ponto.y--;
                }
                else{ // escolhido é o S
                    d+=2*dy;
                    ponto.x++; // varia apenas no eixo x
                }
                PutPixel(ponto,color);
            }
        }
        else{ // caso y1<y2
            d=2*dy-dx;
            while(ponto.x<pixel2.x){
                if(d<0){ // escolhido é o I
                    d+=2*dy;
                    ponto.x++; // varia apenas no eixo x
                }
                else{ // escolhido é o S
                    d+=2*(dy-dx);
                    ponto.x++;
                    ponto.y++;
                }
PutPixel(ponto,color);
            }
        }
    }
    else{ // |m|>1
        if(dy<0){ // caso y2<y1 
            d=dy+2*dx;
            while(ponto.y > pixel2.y){
                if(d<0){
                    d += 2*dx;
                    ponto.y--; // varia apenas no eixo y
                }
                else{
                    d+=2*(dy+dx);
                    ponto.x++;
                    ponto.y--;
                }
PutPixel(ponto,color);
            }
        }
        else{ // caso y1<y2
            d=dy-2*dx;
            while(ponto.y<pixel2.y){
                if(d<0){
                    d+=2*(dy-dx);
                    ponto.x++;
                    ponto.y++; 
                }
                else{
                    d+=-2*dx;
                    ponto.y++; // varia apenas no eixo y
                }
                PutPixel(ponto,color);
                }
            }
        }
    PutPixel(pixel2,color2);
}
