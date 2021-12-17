FLAGS = -Wall -g

all: stringProg

lib_myString.a: functions.o
	ar -rcs lib_myString.a functions.o

functions.o: functions.c functions.h
	gcc $(FLAGS) -c functions.c

main.o: main.c functions.h
	gcc $(FLAGS) -c main.c

stringProg: main.o functions.o lib_myString.a
	gcc $(FLAGS) -o stringProg main.o functions.o lib_myString.a

clean:
	rm -f *.o *.a *.so stringProg