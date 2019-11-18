#include <stdio.h>
#include "instrucao.h"
#include "imagem.h"
#include "arquivo.h"
#include "ponto.h"
#include "cor.h"


int main(){
    Instrucao instrucao;
    Arquivo entrada;
    Arquivo saida;
    Imagem imagem;
    Cor base;
    Ponto* pontos;
    int qntPontos;

    // simula a palheta;
    base = gerarCor(0, 0, 0);

    // define uma imagem vazia;
    definirImagem(&imagem, 0, 0);

    abrirArquivo(&entrada, "instrucao.txt", "r");

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
                         gerarPonto(atoi(instrucao.args[2]), atoi(instrucao.args[3])), &base, &imagem);
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
            desenharPoligono(&imagem, &base, pontos, qntPontos);
            free(pontos);
            break;
        default:
            break;
        }
        liberarInstrucao(&instrucao);
    }
    liberarImagem(&imagem);
    fecharArquivo(&entrada);
    return 0;
}
