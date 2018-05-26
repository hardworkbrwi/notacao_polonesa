# Makefile para "laboratório 4"
# Creado por Bruno César 26/05/2018
#
# Makefile completo separando os diferentes elementos da aplicacao como codigo (src),
# cabecalhos como templates (include), executaveis (build), bibliotecas (lib), etc.
# Cada elemento é alocado em uma pasta especifica, organizando melhor o código fonte.
#
# Algumas variáveis são usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC = g++

# Variaveis para os subdiretorios
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build
DOC = ./doc

# Criando estruturas de diretórios
MKDIR_P = mkdir -p

# Todos os diretórios da aplicação
DIR_CRT = $(BIN) $(OBJ) $(DOC)

# Define o nome do binário/executável final
PROG = $(BIN)/notacao_polonesa

# Garante que os alvos desta lista não sejam confundidos com arquivos de mesmo nome
.PHONY: all clean debug doxy doc

# Opcões de compilacão
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

# Lista dos arquivos objeto (.o) que formam o binário/executável final
OBJS = $(OBJ)/main.o

all : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

# Alvo para a compilação com informações de debug
# Altera a flag CPPFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CPPFLAGS += -g -O0 
debug: all

# Alvo para a construcao do objeto build/main.o
# Define os arquivos objeto dos quais main.o depende.
$(OBJ)/main.o: $(INC)/pilha.h
	$(MKDIR_P) $(DIR_CRT)
	$(RM) $(PROG) $(OBJS)
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

# Alvo para a criação do arquivo Doxyfile.
doxy:
	doxygen -g

# Alvo (target) para a geração automática de documentacão usando o Doxygen.
# Sempre remove a documentacão anterior (caso exista) e gera uma nova.
doc:
	$(RM) $(DOC)/*
	doxygen ./Doxyfile

# Alvo (target) usado para limpar os arquivos temporários (objeto)
# gerados durante a compilacão, assim como os arquivos binários/executáveis.
clean:
	$(RM) $(PROG) $(OBJS)
