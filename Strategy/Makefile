CC=clang++
CPPFLAGS=-c -Wall
OBJS=main.o

all: exec

exec: $(OBJS)
		$(CC) -o executable $(OBJS)

main.o: main.cpp
		$(CC) $(CPPFLAGS) main.cpp

clean:
		rm -rf *.o executable