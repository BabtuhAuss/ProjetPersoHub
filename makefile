CC = g++
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=result
ACTUALWORK_MAIN=allocation_tableau.o
ACTUALWORK_MAIN_LIBS=allocation_tableau/main_allocation_tableau.h

all: $(EXEC)

result: $(ACTUALWORK_MAIN) main.o
	$(CC) -o $@ $^ $(LDFLAGS)

allocation_tableau.o: allocation_tableau/main_allocation_tableau.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.cpp $(ACTUALWORK_MAIN_LIBS)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
ifeq ($(OS),Windows_NT)
	del /s /q *.o
else
	rm -rf *.o
endif

mrproper: clean
ifeq ($(OS),Windows_NT)
	del /s /q $(EXEC).exe
else
	rm -rf $(EXEC)
endif



