


test:phone.o main.o
	gcc -o test phone.o main.o
phone.o:phone.c
	gcc -c phone.c
main.o:main.c
	gcc -c main.c
clean:
	rm -rf *.o test
