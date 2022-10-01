

clear-db:
	rm books.dat;

compile-records:
	 gcc -Wall -Wextra records_v2.c -o records_v2;

run:
	./a.out

compile-book:
	gcc -Wall -Wextra -c Book.c

compile-main:
	gcc -Wall -Wextra -c main.c

compile: compile-book compile-main
	gcc Book.c main.c
