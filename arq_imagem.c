#include "arq_imagem.h"


int abrirArqImagem(ArqImagem* arquivo, char* nome){
    FILE* temp = fopen(nome, "w");
    fclose(temp);
    temp = fopen(nome, "a");
    if (temp == NULL) return 0;
    arquivo->canal = temp;
    arquivo->nome = (char*) malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(arquivo->nome, nome);
    return 1;
}

void fecharArqImagem(ArqImagem* arquivo){
    fclose(arquivo->canal);
    free(arquivo->nome);
}

void salvarImagem(ArqImagem* arquivo, Imagem img){
    fprintf(arquivo->canal, "P3\n");
    fprintf(arquivo->canal, "%d %d\n", img.largura, img.altura);
    fprintf(arquivo->canal, "255\n");
    for (int i = 0; i < img.altura; i++){
        for (int j = 0; j < img.largura; j++){
            fprintf(arquivo->canal, "%d %d %d\n", img.matriz[i][j].red,
             img.matriz[i][j].green, img.matriz[i][j].blue);
        }
    }
}