#ifndef PONTO_H
#define PONTO_H


typedef struct {
    int coordenadaX;
    int coordenadaY;
} Ponto;

/**
 * Recebe dois inteiros e retorna um struct 'Ponto'.
 */
Ponto gerarPonto(int x, int y);

/**
 * Retorna a 'coordenadaX' de um struct 'Ponto'.
 */
int getX(Ponto ponto);

/**
 * Retorna a 'coordenadaY' de um struct 'Ponto'.
 */
int getY(Ponto ponto);

/**
 * Altera a 'coordenadaX' de um struct 'Ponto'.
 */
void setX(Ponto* ponto, int x);

/**
 * Altera a 'coordenadaY' de um struct 'Ponto'.
 */
void setY(Ponto* ponto, int y);

/**
 * Verifica se um struct 'Ponto' está dentro de um espaço retangular.
 * Retorna 1 se tudo ocorrer bem, caso contrário, retorna 0.
 */
int validarPonto(Ponto ponto, int largura, int altura);

#endif