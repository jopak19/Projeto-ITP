#include <stdio.h>

int main(){
    FILE* arquivo;
    arquivo = fopen("image.PPM", "w");
    fprintf(arquivo, "P3\n");
    fprintf(arquivo, "100 100\n");
    fprintf(arquivo, "%i\n", 255);
    for (int x = 0; x < (100*100); x++) {
        fprintf(arquivo, "%d %d %d", 255, 255, 255);
    }
    fclose(arquivo);

    return 0;
}