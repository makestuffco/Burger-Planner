CC = gcc
CPP = g++
CFLAGS = -I . -std=c++17 -O3
OBJ =  burgerAPI.o main.o
DEPS =  burgerAPI.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS)

Burger: $(OBJ)
	$(CPP) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f  burgerAPI.o main.o
