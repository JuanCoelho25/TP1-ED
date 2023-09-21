CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/Stack.o $(OBJ)/BooleanEvaluation.o
HDRS = $(INC)/BooleanEvaluation.hpp $(INC)/Stack.hpp
CFLAGS = -Wall -c -g -I$(INC)

EXE = $(BIN)/main

run:  $(EXE)
		./$(EXE) -a "0 | 1" 01
		./$(EXE) -a "0 | 1 & 2" 010
		./$(EXE) -a "~ ( 0 | 1 ) & 2" 101
		./$(EXE) -s "0 | 1 & 2" 0e0
		./$(EXE) -s	"0 | 1 & 2" e00
		./$(EXE) -s "1 | 2 & 3" a11

$(BIN)/main: $(OBJS)
	$(CC) -g -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/Stack.o: $(HDRS) $(SRC)/Stack.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/Stack.o $(SRC)/Stack.cpp  

$(OBJ)/BooleanEvaluation.o: $(HDRS) $(SRC)/BooleanEvaluation.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/BooleanEvaluation.o $(SRC)/BooleanEvaluation.cpp	 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out