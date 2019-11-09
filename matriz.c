#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    int*** matriz;
    int largura;
    int altura;
} Imagem;

void imprimirImagem(Imagem* img);
void liberarImagem(Imagem* img);
void alocarImagem(Imagem* img);

void alocarImagem(Imagem* img){
    printf("alocarImagem\n");
    img->matriz = (int***) malloc(img->altura * sizeof(int**));
    for (int i = 0; i < img->altura; i++){
        img->matriz[i] = (int**) malloc(img->largura * sizeof(int*));
        for (int j = 0; j < img->largura; j++){
            img->matriz[i][j] = (int*) calloc(3, sizeof(int));
        }
    }
}

void liberarImagem(Imagem* img){
    printf("liberarImagem\n");
    for (int i = 0; i < img->altura; i++){
        for(int j = 0; j < img->largura; j++) {
            free(img->matriz[i][j]);
            //printf("p[%d][%d] liberado!\n", i, j);
        }
        free(img->matriz[i]);
        //printf("p[%d] liberado!\n", i);
    }
    free(img->matriz);
    //printf("p liberado!\n");
}

void imprimirImagem(Imagem* img){
    printf("imprimirImagem\n");
    for (int i = 0; i < img->altura; i++){
        for (int j = 0; j < img->largura; j++){
            printf("(%d, %d, %d)\t", img->matriz[i][j][0], img->matriz[i][j][1], img->matriz[i][j][2]);
        }
        printf("\n");
    }
}

int main(){
    Imagem img;

    scanf("%d %d", &img.altura, &img.largura);
    alocarImagem(&img);
    /*
    img.matriz = (int***) malloc(2 * sizeof(int**));
    for (int i = 0; i < 2; i++){
        img.matriz[i] = (int**) malloc(2 * sizeof(int*));
        for (int j = 0; j < 2; j++){
            img.matriz[i][j] = (int*) calloc(3, sizeof(int));
        }
    }
    */
    imprimirImagem(&img);
    liberarImagem(&img);
    /*
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            free(img.matriz[i][j]);
        }
        free(img.matriz[i]);
    }
    free(img.matriz);
    */

    //printf("</main: fim>\n");
    return 0;
}
