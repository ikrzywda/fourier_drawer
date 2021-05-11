SRC = src/main src/Canvi
CC=g++
CFLAGS=-I$(IDIR) -Wall 

LIBS=-lsfml-graphics -lsfml-window -lsfml-system 

debug: 
	$(CC) -o build/fourier_drawer $(LIBS) -std=c++17 -fsanitize=address src/*.cpp
	./build/fourier_drawer

production:
	$(CC) -o build/fourier_drawer $(LIBS) -std=c++17 src/*.cpp

	

