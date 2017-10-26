
OBJ_DIR = build
BIN_DIR = bin
SRC_DIR = src
INC_DIR = include
DOC_DIR = doc

CC = g++
CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -Iinclude/

RM = rm -rvf

OBJS = $(OBJ_DIR)/movimentacao.o $(OBJ_DIR)/conta.o $(OBJ_DIR)/c_poupanca.o $(OBJ_DIR)/c_corrente.o $(OBJ_DIR)/main.o

agencia: dir clean $(OBJS)
	$(CC) -o $(BIN_DIR)/agencia $(OBJS)

$(OBJ_DIR)/movimentacao.o: $(INC_DIR)/movimentacao.hpp
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/movimentacao.cpp -o $@

$(OBJ_DIR)/conta.o: $(INC_DIR)/conta.hpp $(INC_DIR)/movimentacao.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/conta.cpp -o $@

$(OBJ_DIR)/c_poupanca.o: $(INC_DIR)/c_poupanca.hpp $(INC_DIR)/conta.hpp
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/c_poupanca.cpp -o $@

$(OBJ_DIR)/c_corrente.o: $(INC_DIR)/c_corrente.hpp $(INC_DIR)/conta.hpp
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/c_corrente.cpp -o $@

$(OBJ_DIR)/main.o: $(INC_DIR)/conta.hpp $(INC_DIR)/movimentacao.hpp $(INC_DIR)/c_corrente.hpp $(INC_DIR)/c_poupanca.hpp
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/main.cpp -o $@

dir:
	mkdir -p bin/ build/

clean:
	$(RM) $(OBJ_DIR)/*
	$(RM) $(BIN_DIR)/*

doxy:
	mkdir -p doc/
	doxygen Doxyfile