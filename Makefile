### Makefile ###
# Nome do compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -g

#Ligação com as bibliotecas
LDFLAGS = -lm

#wildcard é utilizado para listar os arquivos-fonte no diretório atual

FONTES = $(wildcard *.c)

#gera a lista dos arquivos-objeto usando a lista de arquivos-fonte
OBJETOS = $(FONTES:.c=.o)

# nome do arquivo executável
EXECUTAVEL = main

all: $(EXECUTAVEL)

# main: ponto.o circulo.o quadrado.o desenho.o main.c
#	gcc main.c -o main ponto.o circulo.o quadrado.o desenho.o

$(EXECUTAVEL): $(OBJETOS)
	@$(CC) -o $@ $^ 

#desenho.o: desenho.c
#	gcc -c desenho.c

#circulo.o: circulo.c
#	gcc -c circulo.c

#quadrado.o: quadrado.c
#	gcc -c quadrado.c

#ponto.o: ponto.c
#	gcc -c ponto.c

%.o: %.c
	@$(CC) -c $(CFLAGS) $^

clean:
	rm -f *.o
