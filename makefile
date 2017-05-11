main:main.o threadpool.o condition.o
	gcc main.o -o main -lpthread
main.o:main.c threadpool.h
	gcc -c main.c
threadpool.o:threadpool.c threadpool.h
	gcc -c threadpool.c
condition.o:condition.c condition.h
	gcc -c condition.c
clean:
	rm *.o
