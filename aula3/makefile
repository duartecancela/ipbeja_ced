OBJS=integral_a.o\
f.o

CC=nvc++
CFLAGS= -fopenmp

all: integral_a

f.o: f.cpp
		$(CC) f.cpp -c

integral_a.o: integral_a.cpp f.o
		$(CC) $(CFLAGS) integral_a.cpp -c

integral_a: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o integral_a
		 
clean:
		rm -f *.o
		rm integral_a
