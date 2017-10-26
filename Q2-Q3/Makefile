
OBJ_DIR_3 = build
BIN_DIR_3 = bin
SRC_DIR_3 = src
INC_DIR_3 = include
DOC_DIR_3 = doc

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
	$(CC) $(CPPFLAGS) -c $(SRC_DIR_3)/c_corrente.cpp -o $@

$(OBJ_DIR_3)/agencia.o: $(INC_DIR_3)/agencia.hpp $(INC_DIR_3)/conta.hpp $(INC_DIR_3)/c_poupanca.hpp $(INC_DIR_3)/c_corrente.hpp
	$(CC) $(CPPFLAGS) -c $(SRC_DIR_3)/agencia.cpp -o $@

$(OBJ_DIR_3)/main.o: $(INC_DIR_3)/conta.hpp $(INC_DIR_3)/agencia.hpp
	$(CC) $(CPPFLAGS) -c $(SRC_DIR_3)/main.cpp -o $@
dir:
	mkdir -p bin/ build/

clean:
	$(RM) $(OBJ_DIR_3)/*
	$(RM) $(BIN_DIR)_3/*

doxy:
	mkdir -p doc/
	doxygen Doxyfile