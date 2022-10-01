#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/time.h>
#include "Book.h"
#include<unistd.h>



struct Book user_book_factory()
{

    int id;
    char name[20];
    char author[20];

    printf("ID:\n");
    scanf("%d", &id);
    printf("Book Name:\n");
    scanf("%s", name);
    printf("Author's Name:\n");
    scanf("%s", author);

    struct Book book;

    // assign value to name of p1
    book.id = id;
    strcpy(book.name, name);
    strcpy(book.author, author);

    return book;
}


int get_id_from_user()
{
    int id;

    printf("Provide an ID (id) \n");
    scanf("%d", &id);
    return id;
}


struct Book book_user_update_id(int id)
{
    struct Book new_book;
    char name[20];
    char author[20];

    printf("Book Name:\n");
    scanf("%s", name);
    printf("Author's Name:\n");
    scanf("%s", author);

    new_book.id = id;

    strcpy(new_book.name, name);
    strcpy(new_book.author, author);

    return new_book;
}


void main_menu()
{
	// char char_choice[3];
	int int_choice = 0;
	do
	{
		system("clear");
		printf("\n");
		printf("Simple Book library -- Main Menu: \n\n");
		printf("1. Add Book\n");
		printf("2. Remove Book\n");
		printf("3. Update Book\n");
		printf("4. Search Book\n");
		printf("5. List Book\n");
		printf("6. Exit\n");

		scanf("%d", &int_choice);

        struct Book new_book;
        struct Book search_result;
        int id;

		switch (int_choice)
		{
			case 1:
                system("clear");
                new_book = user_book_factory();
                add(new_book);
                sleep(3);
                break;
			case 2:
                system("clear");
                id = get_id_from_user();
                remove_book(id);
                sleep(3);
				break;
			case 3:
                system("clear");
                id = get_id_from_user();
                new_book = search(id);
                if (new_book.id == 0)
                {
                    printf("Book not found...");
                    break;
                }
                new_book = book_user_update_id(id);
                update(new_book);
                break;

			case 4:
				system("clear");
                id = get_id_from_user();
                search_result = search(id);
                printf("***************************************\n");
                printf("ID: %i \t  NAME: %s \t AUTHOR: %s \n", search_result.id, search_result.name, search_result.author);
                printf("*************************************** \n");
                sleep(3);
				break;
			case 5:
                printf("***************************************\n");
			    list_books();
                printf("***************************************\n");
                sleep(3);
                break;
			case 6:
				// Not yet used.
                    exit(0);
			default:printf("Wrong choice. Enter Again");
			        break;
		}
	}while(int_choice !=99);
}
