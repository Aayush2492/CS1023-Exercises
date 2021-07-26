CC=clang++
CPPFLAGS=-c -Wall -std=c++17
OBJS=main.o

all: exec

exec: $(OBJS)
		$(CC) -o executable $(OBJS) && rm -rf *.o

main.o: main.cpp
		$(CC) $(CPPFLAGS) main.cpp

clean_o:
		rm -rf *.o

clean_exec:
		rm -rf executable