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

int pintarPixel(Ponto p, Cor cor,Imagem* imagem){
    if(validarPonto(p, imagem->largura, imagem->altura) == 0) return 0;
    imagem->matriz[p.coordenadaY][p.coordenadaX].red = cor.red;
    imagem->matriz[p.coordenadaY][p.coordenadaX].green = cor.green;
    imagem->matriz[p.coordenadaY][p.coordenadaX].blue = cor.blue;
    return 1;
}


void desenharReta(Ponto ptnInicial, Ponto ptnFinal, Cor cor, Imagem* img){
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

void desenharPoligono(Imagem* Imagem, Cor cor, Ponto* pontos, int qntPontos){
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

// as funções "plot_point()" e "desenharCirculo()" foram baseadas e adaptadas do algoritmo de Bresenham
void plot_point(int x, int y, Ponto p, Cor cor, Imagem* img)
{
  pintarPixel(gerarPonto(p.coordenadaX+x, p.coordenadaY+y), cor, img);
  pintarPixel(gerarPonto(p.coordenadaX+x, p.coordenadaY-y), cor, img);
  pintarPixel(gerarPonto(p.coordenadaX+y, p.coordenadaY+x), cor, img);
  pintarPixel(gerarPonto(p.coordenadaX+y, p.coordenadaY-x), cor, img);
  pintarPixel(gerarPonto(p.coordenadaX-x, p.coordenadaY-y), cor, img);
  pintarPixel(gerarPonto(p.coordenadaX-y, p.coordenadaY-x), cor, img);
  pintarPixel(gerarPonto(p.coordenadaX-x, p.coordenadaY+y), cor, img);
  pintarPixel(gerarPonto(p.coordenadaX-y, p.coordenadaY+x), cor, img);
}

void desenharCirculo(Ponto ponto, int raio, Cor cor, Imagem* img){
  int x=0;
  int y = raio;
  float pk=(5.0/4.0)-raio;
  plot_point(x,y, ponto, cor, img);
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point(x,y, ponto, cor, img);
  }
}

void clear(Imagem* img, Cor cor){
    for(int i = 0; i < img->altura; i++){
        for(int j = 0; j < img->largura; j++)
        {
            img->matriz[i][j] = cor;
        }
        
    }
}

void preencherFiguraRecursivo(Imagem* img, Cor tinta, Cor fundo, Ponto pnt){
    // testa se o ponto está dentro da imagem;
    if (validarPonto(pnt, img->largura, img->altura)){
        // testa se o ponto já foi pintado e se a tinta tem a mesma cor do fundo inicial;
        if(compararCor(img->matriz[getY(pnt)][getX(pnt)], fundo) && !compararCor(tinta, fundo)){
            // pinta o pixel que atende aos requisitos;
            pintarPixel(pnt, tinta, img);
            // chama a função para o pixel de cima;
            preencherFiguraRecursivo(img, tinta, fundo, gerarPonto(getX(pnt), getY(pnt) + 1));
            // chama a função para o pixel de baixo;
            preencherFiguraRecursivo(img, tinta, fundo, gerarPonto(getX(pnt), getY(pnt) - 1));
            // chama a função para o pixel da direita;
            preencherFiguraRecursivo(img, tinta, fundo, gerarPonto(getX(pnt) + 1, getY(pnt)));
            // chama a função para o pixel da esquerda;
            preencherFiguraRecursivo(img, tinta, fundo, gerarPonto(getX(pnt) - 1, getY(pnt)));
        }
    }
}

void preencherFiguraInterativo(Imagem* img, Cor tinta, Cor fundo, Ponto pnt){
    // define a lista de pontos que vão passar pela função;
    Ponto* lista;
    // adiciona o primeiro ponto;
    lista = (Ponto*) malloc(sizeof(Ponto));
    int tamanho = 1;
    lista[0] = pnt;
    // define uma variável para guardar o ponto atual;
    Ponto pntTemp;
    // define uma variável para guardar o número de interações;
    int interacoes = 0;
    do{
        // incrementa o número de interações em 1;
        interacoes += 1;
        // guarda o primeiro ponto da lista;
        pntTemp = lista[0];
        // testa se o primeiro ponto está dentro da imagem;
        if(validarPonto(pntTemp, img->largura, img->altura)){
            // testa se o primeiro ponto já foi pintado e se a tinta tem a mesma cor do fundo inicial;
            if(compararCor(img->matriz[getY(pntTemp)][getX(pntTemp)], fundo) && !compararCor(tinta, fundo)){
                // pinta o pixel do primeiro ponto;
                pintarPixel(pntTemp, tinta, img);
                // adiciona três pontos ao fim da lista;
                tamanho += 3;
                lista = (Ponto*) realloc(lista, tamanho * sizeof(Ponto));
                lista[tamanho - 3] = gerarPonto(getX(pntTemp), getY(pntTemp) + 1);
                lista[tamanho - 2] = gerarPonto(getX(pntTemp), getY(pntTemp) - 1);
                lista[tamanho - 1] = gerarPonto(getX(pntTemp) - 1, getY(pntTemp));
                // adiciona um ponto na primeira posição da lista;
                lista[0] = gerarPonto(getX(pntTemp) + 1, getY(pntTemp));
            } else goto erro; // caso não atenda aos requisitos vá para 'erro:'
        } else{
            // em caso de erro;
            erro:
            // move o último ponto para a primeira posição da lista;
            lista[0] = lista[tamanho - 1];
            tamanho -= 1;
            lista = (Ponto*) realloc(lista, tamanho * sizeof(Ponto));
        }
        // repete enquanto a lista tiver elementos;
    } while (tamanho > 0);
    printf("Interações: %d\n", interacoes);
    // libera a lista;
    free(lista);
}
