#include "arquivo.h"


FILE* lerArquivo(){
    FILE* arq = fopen("texto.txt", "r");
    return arq;
}
FILE* escreverArquivo(){
    FILE* arq = fopen("imagem.PPM", "a");
    return arq;
}
void fecharArquivo(FILE* arq){
    fclose(arq);
}
int lerComando(FILE* arq, Comando* com){
    char texto_str[50];
    char* result = fgets(texto_str, 50, arq);
    if (result==NULL) {
        return 1;
    }
    strcpy(com->comando, "image");
    com->parametros[0] = 200;
    com->parametros[1] = 200;
    com->qntParametros = 2;

    return 0;
}

void liberarImagem(Matriz* img){
    printf("liberarImagem\n");
    for (int i = 0; i < img->linhas; i++){
        free(img->imagem[i]);
    }
    free(img->imagem);
}

Matriz alocarImagem(int linhas, int colunas){
    Matriz img;
    img.linhas = linhas;
    img.colunas = colunas;
    printf("alocarImagem\n");
    img.imagem = (Cor**) malloc(linhas * sizeof(Cor*));
    for (int i = 0; i < linhas; i++){
        img.imagem[i] = (Cor*) malloc(colunas * sizeof(Cor));
        for (int j = 0; j < colunas; j++)
        {
            img.imagem[i][j].r = 255;
            img.imagem[i][j].g = 255;
            img.imagem[i][j].b = 255;
        }
        
    }
    return img;
}
void executaComando(Comando* com, Matriz* mat){
    //se for comando "image"
    if (strncmp(com->comando, "image", 5) == 0) {
        *mat = alocarImagem(com->parametros[0], com->parametros[1]);
       
    }

}
//passa a matriz para o arquivo de saida no formato correto
void passaMatriz(Matriz mat, FILE*  arq){
    fprintf(arq, "P3\n");
    fprintf(arq, "%d %d\n", mat.colunas, mat.linhas);
    fprintf(arq, "%d\n", 255);
    for (int i = 0; i < mat.linhas; i++)
    {
        for (int j = 0; j < mat.colunas; j++)
        {
            fprintf(arq, "%d %d %d\n", mat.imagem[i][j].r, mat.imagem[i][j].g, mat.imagem[i][j].b);
        }
        
    }
}