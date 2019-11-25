#include "ponto.h"


Ponto gerarPonto(int x, int y){
    Ponto p;
    p.coordenadaX = x;
    p.coordenadaY = y;
    return p;
}

int validarPonto(Ponto ponto, int largura, int altura){
    if((getX(ponto) >= largura || getX(ponto) < 0) || (getY(ponto) >= altura || getY(ponto) < 0)){
        return 0;
    }
    return 1;
}

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
