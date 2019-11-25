#ifndef PONTO_H
#define PONTO_H


typedef struct {
    int coordenadaX;
    int coordenadaY;
} Ponto;

Ponto gerarPonto(int x, int y);
int getX(Ponto ponto);
int getY(Ponto ponto);
void setX(Ponto* ponto, int x);
void setY(Ponto* ponto, int y);
int validarPonto(Ponto ponto, int largura, int altura);

#endif