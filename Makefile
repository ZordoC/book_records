

clear-db:
	rm *.dat;

run:
	./a.out

compile-book:
	gcc -Wall -Wextra -c Book.c

compile-menu:
	gcc -Wall -Wextra -c Menu.c

compile-main:
	gcc -Wall -Wextra -c main.c

compile: compile-book compile-menu compile-main
	gcc Book.c Menu.c main.c
