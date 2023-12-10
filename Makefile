# Makefile para compilar e executar o programa

# Nome do programa de saída
TARGET = main.out

# Compilador
CC = gcc

# Opções do compilador
CFLAGS = -Wall -Wextra -g

# Bibliotecas
LIBS = -lSDL2main -lSDL2 -lSDL2_ttf

# Arquivos fonte
SOURCES = main.c front.c list.c reference_counting.c mark-and-sweep.c memory_manipulation.c 

# Comando padrão para compilar o programa
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET) $(LIBS)

# Regra para limpar arquivos temporários e o programa compilado
clean:
	rm -f $(TARGET)

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)
