#include <stdio.h>
#include "instrucao.h"
#include "imagem.h"
#include "arquivo.h"
#include "ponto.h"
#include "cor.h"
#define MAX 20


int main(){
    Instrucao instrucao;
    Arquivo entrada;
    Arquivo saida;
    Imagem imagem;
    Cor base;
    Ponto* pontos;
    int qntPontos;
    char nome[MAX];

    // simula a palheta;
    base = gerarCor(0, 0, 0);

    // recebe uma string;
    fgets(nome, MAX, stdin);
    // retira o '\n', se tiver;
    if (nome[strlen(nome) - 1] == '\n') nome[strlen(nome) - 1] = '\0';
    setbuf(stdin, NULL);

    // tenta abrir o arquivo;
    if (!abrirArquivo(&entrada, nome, "r")){
        printf("Erro ao abrir arquivo!\n");
        return 0;
    }

    // define uma imagem vazia;
    definirImagem(&imagem, 0, 0);

    // ler cada instrucao;
    while(lerInstrucao(entrada, &instrucao)){
        imprimirInstrucao(instrucao);
        switch (obterCodigoInstrucao(instrucao)){
        case IMAGE:
            // libera a imagem anterior;
            liberarImagem(&imagem);
            // define uma nova imagem em branco;
            definirImagem(&imagem, atoi(instrucao.args[1]), atoi(instrucao.args[0]));
            break;
        
        case SAVE:
            abrirArquivo(&saida, instrucao.args[0],"w");
            escreverImagem(&saida, imagem);
            fecharArquivo(&saida);
            break;
        
        case LINE:
            desenharReta(gerarPonto(atoi(instrucao.args[0]), atoi(instrucao.args[1])),
                         gerarPonto(atoi(instrucao.args[2]), atoi(instrucao.args[3])), base, &imagem);
            break;
        
        case COLOR:
            base = gerarCor(atoi(instrucao.args[0]), atoi(instrucao.args[1]), atoi(instrucao.args[2]));
            break;

        case POLYGON:
            pontos = (Ponto*) malloc(0);
            qntPontos = 0;
            // gera uma lista de pontos apartir da lista de coordenadas de instrucao.args;
            for (int i = 0; i + 1 < instrucao.qntArgs; i += 2){
                pontos = realloc(pontos, ++qntPontos * sizeof(Ponto));
                pontos[qntPontos - 1] = gerarPonto(atoi(instrucao.args[i]), atoi(instrucao.args[i + 1]));
            }
            desenharPoligono(&imagem, base, pontos, qntPontos);
            free(pontos);
            break;

        case CIRCLE:
           desenharCirculo(gerarPonto(atoi(instrucao.args[0]), atoi(instrucao.args[1])),
            atoi(instrucao.args[2]), base, &imagem);
            break;

        case CLEAR:
            clear(&imagem, gerarCor(atoi(instrucao.args[0]), atoi(instrucao.args[1]), atoi(instrucao.args[2])));
            break;

        case OPEN:
            abrirArquivo(&saida, instrucao.args[0], "r");
            lerLinha(saida);
            definirInstrucao(&instrucao, lerLinha(saida));
            lerLinha(saida);
            definirImagem(&imagem, atoi(instrucao.args[0]), atoi(instrucao.comando));
            for(int i = 0; i < imagem.altura; i++)
            {
                for(int j = 0; j < imagem.largura; j++){
                    definirInstrucao(&instrucao, lerLinha(saida));
                    imagem.matriz[i][j] = gerarCor(atoi(instrucao.comando), atoi(instrucao.args[0]), atoi(instrucao.args[1]));
                }   
            }
            break;

        case FILL:
            preencherFiguraRecursivo(&imagem, base, imagem.matriz[atoi(instrucao.args[1])][atoi(instrucao.args[0])],
                                     gerarPonto(atoi(instrucao.args[0]), atoi(instrucao.args[1])));

        default:
            break;
        }
        liberarInstrucao(&instrucao);
    }
    liberarImagem(&imagem);
    fecharArquivo(&entrada);
    return 0;
}
