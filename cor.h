#ifndef COR_H
#define COR_H


typedef struct{
    int red;
    int green;
    int blue;
} Cor;

/**
 * Recebe três inteiros e retorna um struct 'Cor'.
 */
Cor gerarCor(int red, int green, int blue);

/**
 * Compara duas cores.
 * Retorna 1 se as cores forem iguais, caso contrário, retorna 0;
 */
int compararCor(Cor c1, Cor c2);

#endif