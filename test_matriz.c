#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int*** matriz;
    int largura;
    int altura;
} Imagem;

void imprimirImagem(Imagem img);
void liberarImagem(Imagem* img);
Imagem alocarImagem(int altura, int largura);

Imagem alocarImagem(int altura, int largura){
    Imagem img;
    img.altura = altura;
    img.largura = largura;
    printf("alocarImagem\n");
    img.matriz = (int***) malloc(altura * sizeof(int**));
    for (int i = 0; i < altura; i++){
        img.matriz[i] = (int**) malloc(largura * sizeof(int*));
        for (int j = 0; j < largura; j++){
            img.matriz[i][j] = (int*) calloc(3, sizeof(int));
        }
    }
    return img;
}

void liberarImagem(Imagem* img){
    printf("liberarImagem\n");
    for (int i = 0; i < img->altura; i++){
        for(int j = 0; j < img->largura; j++) {
            free(img->matriz[i][j]);
        }
        free(img->matriz[i]);
    }
    free(img->matriz);
}

void imprimirImagem(Imagem img){
    printf("imprimirImagem\n");
    for (int i = 0; i < img.altura; i++){
        for (int j = 0; j < img.largura; j++){
            printf("(%d, %d, %d)\t", img.matriz[i][j][0], img.matriz[i][j][1], img.matriz[i][j][2]);
        }
        printf("\n");
    }
}

/*
int main(){
    Imagem img;
    int altura, largura;
    scanf("%d %d", &altura, &largura);
    img = alocarImagem(altura, largura);
    imprimirImagem(img);
    liberarImagem(&img);
    return 0;
}
*/