
OBJ_DIR_3 = build/QUESTAO_2_&_3
BIN_DIR_3 = bin/QUESTAO_2_&_3
SRC_DIR_3 = src/QUESTAO_2_&_3
INC_DIR_3 = include/QUESTAO_2_&_3
DOC_DIR_3 = doc/QUESTAO_2_&_3

CC = g++
CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -Iinclude/

RM = rm -rvf

OBJS_3 = $(OBJ_DIR_3)/movimentacao.o $(OBJ_DIR_3)/conta.o $(OBJ_DIR_3)/c_poupanca.o $(OBJ_DIR_3)/c_corrente.o $(OBJ_DIR_3)/agencia.o $(OBJ_DIR_3)/main.o

agencia: dir clean $(OBJS_3)
	$(CC) -o $(BIN_DIR_3)/agencia $(OBJS_3)

$(OBJ_DIR_3)/movimentacao.o: $(INC_DIR_3)/movimentacao.hpp
	$(CC) $(CPPFLAGS) -c $(SRC_DIR_3)/movimentacao.cpp -o $@

$(OBJ_DIR_3)/conta.o: $(INC_DIR_3)/conta.hpp $(INC_DIR_3)/movimentacao.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC_DIR_3)/conta.cpp -o $@

$(OBJ_DIR_3)/c_poupanca.o: $(INC_DIR_3)/c_poupanca.hpp $(INC_DIR_3)/conta.hpp
	$(CC) $(CPPFLAGS) -c $(SRC_DIR_3)/c_poupanca.cpp -o $@

$(OBJ_DIR_3)/c_corrente.o: $(INC_DIR_3)/c_corrente.hpp $(INC_DIR_3)/conta.hpp
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/c_corrente.cpp -o $@

$(OBJ_DIR_3)/agencia.o: $(INC_DIR_3)/agencia.hpp $(INC_DIR_3)/conta.hpp $(INC_DIR_3)/c_poupanca.hpp $(INC_DIR_3)/c_corrente.hpp
	$(CC) $(CPPFLAGS) -c $(SRC_DIR_3)/agencia.cpp -o $@

$(OBJ_DIR_3)/main.o: $(INC_DIR_3)/conta.hpp $(INC_DIR_3)/agencia.hpp
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/main.cpp -o $@


OBJ_DIR = build/QUESTAO_1
BIN_DIR = bin/QUESTAO_1
SRC_DIR = src/QUESTAO_1
INC_DIR = include/QUESTAO_1
DOC_DIR = doc/QUESTAO_1

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
	mkdir -p $(BIN_DIR) $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)/*
	$(RM) $(BIN_DIR)/*

doxy:
	mkdir -p doc/
	doxygen Doxyfile