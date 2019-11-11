#include "arquivo.h"

int main(){
    Matriz matriz;

    //para leitura de arquivos e saida de imagem
    // if "criar imagem" fazer isso:
    FILE* saida = escreverArquivo();
    FILE* entrada = lerArquivo();

    Comando* com = malloc(sizeof(Comando));
    int result = lerComando(entrada, com);

    while(1){
        if (result == 1) {
            break;
        }
        executaComando(com, &matriz);

        result = lerComando(entrada, com);

    }
    free(com);
    passaMatriz(matriz, saida);
    liberarImagem(&matriz);

    fecharArquivo(entrada);
    fecharArquivo(saida);
}
