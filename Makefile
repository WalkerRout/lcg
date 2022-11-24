
CC = gcc
OBJS = src/*.c #src/include/*.c

OBJ_NAME_WIN = bin/bezierc.exe
OBJ_NAME_MAC = bin/bezierc
OBJ_NAME = $(OBJ_NAME_WIN)

all: build run

build:
	$(CC) $(OBJS) -w -o $(OBJ_NAME) 

run:
	./$(OBJ_NAME)

clean:
	rm ./$(OBJ_NAME)

