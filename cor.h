#ifndef COR_H
#define COR_H


typedef struct{
    int red;
    int green;
    int blue;
} Cor;

Cor gerarCor(int red, int green, int blue);
int compararCor(Cor c1, Cor c2);

#endif