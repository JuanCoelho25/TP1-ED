CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/Stack.o $(OBJ)/BooleanEvaluation.o $(OBJ)/BinaryTree.o $(OBJ)/Node.o
HDRS = $(INC)/BooleanEvaluation.hpp $(INC)/Stack.hpp $(INC)/BinaryTree.hpp $(INC)/Node.hpp
CFLAGS = -Wall -std=c++11 -c -g -I$(INC)

EXE = $(BIN)/tp1.out

run:  $(EXE)

all: $(BIN)/tp1.out


$(BIN)/tp1.out: $(OBJS)
	$(CC) -g -o $(BIN)/tp1.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp  

$(OBJ)/BooleanEvaluation.o: $(HDRS) $(SRC)/BooleanEvaluation.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BooleanEvaluation.o $(SRC)/BooleanEvaluation.cpp	 

$(OBJ)/Node.o: $(HDRS) $(SRC)/Node.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Node.o $(SRC)/Node.cpp	

$(OBJ)/BinaryTree.o: $(HDRS) $(SRC)/BinaryTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BinaryTree.o $(SRC)/BinaryTree.cpp



clean:
	rm -f $(EXE) $(OBJS) gmon.out
