#include "imagem.h"
#include "stdio.h"

void definirImagem(Imagem* imagem, int altura, int largura){
    imagem->altura = altura;
    imagem->largura = largura;
    imagem->matriz = (Cor**) malloc(altura * sizeof(Cor*));
    for (int i = 0; i < altura; i++){
        imagem->matriz[i] = (Cor*) malloc(largura * sizeof(Cor));
        for (int j = 0; j < largura; j++){
            imagem->matriz[i][j] = gerarCor(255, 255, 255);
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

void pintarPixel(Ponto p, Cor* cor,Imagem* imagem){
    imagem->matriz[p.coordenadaY][p.coordenadaX].red = cor->red;
    imagem->matriz[p.coordenadaY][p.coordenadaX].green = cor->green;
    imagem->matriz[p.coordenadaY][p.coordenadaX].blue = cor->blue;
}


/* A função a seguir 'desenharReta()' foi implementada baseada em um algorimo obtida em: 
http://letslearnbits.blogspot.com/2014/10/icgt1-algoritmo-de-bresenham.html, o qual utiliza o
algoritimo de bresenham.
*/
void desenharReta(Ponto ptnInicial, Ponto ptnFinal, Cor* cor, Imagem* img){
    int dx = ptnFinal.coordenadaX - ptnInicial.coordenadaX;
    int dy = ptnFinal.coordenadaY - ptnInicial.coordenadaY;
    int inclinacao=0;    
    if(dx<0) // caso ponto final < ponto inicial
    {
        desenharReta(ptnFinal,ptnInicial, cor, img);
        return;
    }
    if(dy<0)
        inclinacao = -1;
    else
        inclinacao = 1;

    int d;

    Ponto pixel = ptnInicial;
    pintarPixel(pixel,cor, img);
    if(dx >= inclinacao*dy){    // m<=1
        if(dy<0){ // caso y2<y1
            d = 2*dy+dx;
            while(pixel.coordenadaX<ptnFinal.coordenadaX){
                if(d<0){ // escolhido é o I
                    d += 2*(dy+dx);
                    pixel.coordenadaX++;
                    pixel.coordenadaY--;
                }
                else{ // escolhido é o S
                    d+=2*dy;
                    pixel.coordenadaX++; // varia apenas no eixo x
                }
                pintarPixel(pixel,cor, img);
            }
        }
        else{ // caso y1<y2
            d=2*dy-dx;
            while(pixel.coordenadaX<ptnFinal.coordenadaX){
                if(d<0){ // escolhido é o I
                    d+=2*dy;
                    pixel.coordenadaX++; // varia apenas no eixo x
                }
                else{ // escolhido é o S
                    d+=2*(dy-dx);
                    pixel.coordenadaX++;
                    pixel.coordenadaY++;
                }
pintarPixel(pixel,cor, img);
            }
        }
    }
    else{ // |m|>1
        if(dy<0){ // caso y2<y1 
            d=dy+2*dx;
            while(pixel.coordenadaY > ptnFinal.coordenadaY){
                if(d<0){
                    d += 2*dx;
                    pixel.coordenadaY--; // varia apenas no eixo y
                }
                else{
                    d+=2*(dy+dx);
                    pixel.coordenadaX++;
                    pixel.coordenadaY--;
                }
pintarPixel(pixel,cor, img);
            }
        }
        else{ // caso y1<y2
            d=dy-2*dx;
            while(pixel.coordenadaY<ptnFinal.coordenadaY){
                if(d<0){
                    d+=2*(dy-dx);
                    pixel.coordenadaX++;
                    pixel.coordenadaY++; 
                }
                else{
                    d+=-2*dx;
                    pixel.coordenadaY++; // varia apenas no eixo y
                }
                pintarPixel(pixel,cor, img);
                }
            }
        }
    pintarPixel(ptnFinal,cor, img);
}

void desenharPoligono(Imagem* Imagem, Cor* cor, Ponto* pontos, int qntPontos){
    Ponto pntInicial;
    Ponto pntFinal;
    if (qntPontos < 3) return;
    for (int i = 0; i + 1 < qntPontos; i++){
        pntInicial = pontos[i];
        pntFinal = pontos[i + 1];
        desenharReta(pntInicial, pntFinal, cor, Imagem);
    }
    desenharReta(pntFinal, pontos[0], cor, Imagem);
}
