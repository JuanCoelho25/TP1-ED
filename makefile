CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/Stack.o $(OBJ)/BooleanEvaluation.o $(OBJ)/BinaryTree.o
HDRS = $(INC)/BooleanEvaluation.hpp $(INC)/Stack.hpp $(INC)/BinaryTree.hpp
CFLAGS = -Wall -std=c++11 -c -g -I$(INC)

EXE = $(BIN)/tp1.out

run:  $(EXE)
		./$(EXE) -a "0 | 1" 01
		./$(EXE) -a "0 | 1 & 2" 010
		./$(EXE) -a "~ ( 0 | 1 ) & 2" 101
		./$(EXE) -s "0 | 1 & 2" a11
		./$(EXE)	-s	"0 | 1 & 2"	e11
		# ./$(EXE) -s	"0 | 1 & 2" e00
		# ./$(EXE) -s "0 | 1" ea
		# ./$(EXE) -s "0 | ~ ~ 1" ea
		 ./$(EXE) -s "( ( 0 & 1 ) & ( 2 & 3 ) & ( 4 & 5 ) & ( 6 & 7 ) & ( 8 & 9 ) )" e1e1e1e1e1
		# ./$(EXE)	-s	"0 | 1 & 2"	ee0



all: $(BIN)/tp1.out


$(BIN)/tp1.out: $(OBJS)
	$(CC) -g -o $(BIN)/tp1.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp  

$(OBJ)/BooleanEvaluation.o: $(HDRS) $(SRC)/BooleanEvaluation.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BooleanEvaluation.o $(SRC)/BooleanEvaluation.cpp	 

$(OBJ)/BinaryTree.o: $(HDRS) $(SRC)/BinaryTree.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BinaryTree.o $(SRC)/BinaryTree.cpp

clean:
	rm -f $(EXE) $(OBJS) gmon.out