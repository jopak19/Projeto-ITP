#include <stdio.h>
#include "instrucao.h"
#include "imagem.h"
#include "arquivo.h"
#include "ponto.h"
#include "cor.h"
#define MAX 50


int main(){
    Instrucao instrucao;
    Arquivo entrada;
    Arquivo saida;
    Arquivo help;
    Imagem imagem;
    Cor base;
    Ponto* pontos;
    int qntPontos;
    char nome[MAX];
    int modo;
    char* linhaArquivo;
    char linhaTerminal[MAX];

    // simula a palheta;
    base = gerarCor(0, 0, 0);

    do{
        printf("Escolha um dos modos:\n");
        printf("1) Ler um arquivo de instruções.\n");
        printf("2) Ler instruções pelo terminal.\n");
        printf("3) Cancelar\n");

        scanf("%i", &modo);
        setbuf(stdin, NULL);

        switch (modo){
        case 1:
            printf("Digite o nome do arquivo:\n");
            // recebe uma string;
            fgets(nome, MAX, stdin);
            // retira o '\n', se tiver;
            if (nome[strlen(nome) - 1] == '\n') nome[strlen(nome) - 1] = '\0';
            setbuf(stdin, NULL);

            // tenta abrir o arquivo;
            if (!abrirArquivo(&entrada, nome, "r")){
                printf("Erro ao abrir arquivo!\n\n");
                modo = -1;
            }
            break;
        
        case 2:
            printf("Digite as instruções ('help' para mais informações):\n");
            break;
        
        case 3:
            return 0;
            break;
        
        default:
            break;
        }
    }while(modo > 3 || modo < 1);

    // define uma imagem vazia;
    definirImagem(&imagem, 0, 0);

    while(1){
        if (modo == 1){
            // lê uma linha do arquivo de entrada;
            linhaArquivo = lerLinha(entrada);
            // tenta transformar em uma instrução;
            if (!definirInstrucao(&instrucao, linhaArquivo)){
                free(linhaArquivo);
                fecharArquivo(&entrada);
                break;
            }
            free(linhaArquivo);
        } else if (modo == 2){
            // lê uma linha do terminal;
            fgets(linhaTerminal, MAX, stdin);
            // retira o '\n' se tiver;
            if (linhaTerminal[strlen(linhaTerminal) - 1] == '\n') linhaTerminal[strlen(linhaTerminal) - 1] = '\0';
            setbuf(stdin, NULL);
            // tenta transformar em instrução;
            if (!definirInstrucao(&instrucao, linhaTerminal)) break;
        }
        // exibe a instrução se tiver no modo de leitura por arquivo;
        if (modo == 1) imprimirInstrucao(instrucao);
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
            break;

        case RECT:
            // gera quatro pontos apartir das informações do ponto inicial, largura e altura;
            pontos = (Ponto*) malloc(4 * sizeof(Ponto));
            qntPontos = 4;
            pontos[0] = gerarPonto(atoi(instrucao.args[0]), atoi(instrucao.args[1]));
            pontos[1] = gerarPonto(atoi(instrucao.args[0]) + atoi(instrucao.args[2]), atoi(instrucao.args[1]));
            pontos[2] = gerarPonto(atoi(instrucao.args[0]) + atoi(instrucao.args[2]),
                                   atoi(instrucao.args[1]) + atoi(instrucao.args[3]));
            pontos[3] = gerarPonto(atoi(instrucao.args[0]), atoi(instrucao.args[1]) + atoi(instrucao.args[3]));
            desenharPoligono(&imagem, base, pontos, qntPontos);
            free(pontos);
            break;
        
        case HELP:
            // abre o arquivo de ajuda;
            abrirArquivo(&help, "help.txt", "r");
            while(1){
                linhaArquivo = lerLinha(help);
                // para de repetir quando não tiver linha;
                if(strlen(linhaArquivo) == 0){
                    free(linhaArquivo);
                    break;
                }
                if(instrucao.qntArgs != 0){
                    if (strncmp(instrucao.args[0], linhaArquivo, strlen(instrucao.args[0])) == 0){
                       printf("%s\n", linhaArquivo);
                    }
                } else printf("%s\n", linhaArquivo);
                free(linhaArquivo);
            }
            fecharArquivo(&help);
            break;

        default:
            break;
        }
        liberarInstrucao(&instrucao);
    }
    liberarImagem(&imagem);
    return 0;
}
