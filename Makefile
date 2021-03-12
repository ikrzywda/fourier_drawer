SRC = src/main src/Canvi
CC=g++
CFLAGS=-I$(IDIR) -Wall 

ODIR=obj

LIBS=-lsfml-graphics -lsfml-window -lsfml-system

make: 
	$(CC) -o vf $(LIBS) src/*.cpp
	

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
