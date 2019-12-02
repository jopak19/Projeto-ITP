#include "arquivo.h"

int abrirArquivo(Arquivo* arquivo, char* nome, char* tipo){
    FILE* temp = fopen(nome, tipo);
    if (temp == NULL) return 0;
    arquivo->canal = temp;
    arquivo->nome = malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(arquivo->nome, nome);
    return 1;
}

void fecharArquivo(Arquivo* arquivo){
    fclose(arquivo->canal);
    free(arquivo->nome);
}

void escreverImagem(Arquivo* arquivo, Imagem img){
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

char* lerLinha(Arquivo arquivo){
    char* linha = (char*) malloc(sizeof(char));
    int tamanho = 1;
    char letra = fgetc(arquivo.canal);
    if(letra != EOF){
        while(letra != EOF && letra != '\n'){
            linha = (char*) realloc(linha, ++tamanho * sizeof(char));
            linha[tamanho - 2] = letra;
            letra = fgetc(arquivo.canal);
        }
    }
    linha[tamanho - 1] = '\0';
    return linha;
}

int lerInstrucao(Arquivo arquivo, Instrucao* instrucao){
    char* linha = lerLinha(arquivo);
    if (linha == NULL){
        free(linha);
        return 0;
    }
    if (!definirInstrucao(instrucao, linha)){
        free(linha);
        return 0;
    }
    free(linha);
    return 1;
}
