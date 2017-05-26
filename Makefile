all: kursach

.PHONY: all clean

shell.o: shell1.c
	gcc -Wall -Werror -fPIC -c shell1.c -o shell1.o

merge.o: merge.c
	gcc -Wall -Werror -fPIC -c merge.c -o merge.o

libsorts.so: shell1.o merge.o
	gcc -Wall -Werror -shared -o libsorts.so shell1.o merge.o

main.o: main.c
	gcc -Wall -Werror -c main.c -o main.o

kursach: libsorts.so main.o shell1.o merge.o
	gcc -Wall -Werror main.o -L. -lsorts -o kursach

clean: rm -rf libsorts.so *.o
