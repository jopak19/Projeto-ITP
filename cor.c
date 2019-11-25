#include "cor.h"


Cor gerarCor(int red, int green, int blue){
    Cor cor;
    cor.red = red;
    cor.green = green;
    cor.blue = blue;
    return cor;
}

int compararCor(Cor c1, Cor c2){
    if (c1.blue == c2.blue && c1.green == c2.green && c1.red == c2.red){
        return 1;
    }
    return 0;
}
