CC = g++ $(CCFLAGS)

CCFLAGS = -std=c++11

all: baseN

baseN: main.o convertBase.o
	$(CC) main.o convertBase.o -o base.exe

main.o: src/main.cpp include/convertBase.h
	$(CC) -c src/main.cpp

convertBase.o: src/convertBase.cpp include/convertBase.h
	$(CC) -c src/convertBase.cpp
