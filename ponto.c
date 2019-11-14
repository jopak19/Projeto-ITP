#include "ponto.h"


int getX(Ponto ponto){
    return ponto.coordenadaX;
}

int getY(Ponto ponto){
    return ponto.coordenadaY;
}

void setX(Ponto* ponto, int x){
    (*ponto).coordenadaX = x;
}

void setY(Ponto* ponto, int y){
    (*ponto).coordenadaY = y;
}