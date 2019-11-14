#ifndef PONTO_H
#define PONTO_H


typedef struct {
    int coordenadaX;
    int coordenadaY;
} Ponto;

int getX(Ponto ponto);
int getY(Ponto ponto);
void setX(Ponto* ponto, int x);
void setY(Ponto* ponto, int y);

#endif