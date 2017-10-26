
OBJ_DIR = build
BIN_DIR = bin
SRC_DIR = src
INC_DIR = include
DOC_DIR = doc

CC = g++
CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -Iinclude/

RM = rm -rvf

OBJS = $(OBJ_DIR)/produto.o $(OBJ_DIR)/fruta.o $(OBJ_DIR)/roupa.o $(OBJ_DIR)/bebida.o $(OBJ_DIR)/main.o

loja: dir clean $(OBJS)
	$(CC) -o $(BIN_DIR)/loja $(OBJS)

$(OBJ_DIR)/produto.o: $(INC_DIR)/produto.h
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/produto.cpp -o $@

$(OBJ_DIR)/fruta.o: $(INC_DIR)/fruta.h
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/fruta.cpp -o $@

$(OBJ_DIR)/roupa.o: $(INC_DIR)/roupa.h
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/roupa.cpp -o $@

$(OBJ_DIR)/bebida.o: $(INC_DIR)/bebida.h
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/bebida.cpp -o $@

$(OBJ_DIR)/main.o: $(INC_DIR)/produto.h $(INC_DIR)/fruta.h $(INC_DIR)/roupa.h $(INC_DIR)/bebida.h
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/main.cpp -o $@

dir:
	mkdir -p bin/ build/

clean:
	$(RM) $(OBJ_DIR)/*
	$(RM) $(BIN_DIR)/*

doxy:
	mkdir -p doc/
	doxygen Doxyfile