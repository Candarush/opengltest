# Компилятор
CC=g++

# Стандарт
STD=c++11

OPENCVINCLUDES = $(shell pkg-config --cflags opencv)
OPENCVLIBS = $(shell pkg-config --libs opencv)

SFMLIBS = -lsfml-graphics -lsfml-window -lsfml-system 

OPENGLLIBS = -lGL -lglut -lGLU -lGLEW 

.PHONY: all

all: exec clean

exec: main.o
	$(CC) -L/usr/lib/x86_64-linux-gnu main.o -o exec $(SFMLIBS) $(OPENGLLIBS) $(OPENCVLIBS)
main.o: main.cpp
	$(CC) -std=$(STD) $(OPENCVINCLUDES) -c main.cpp
clean:
	rm -rf *.o
