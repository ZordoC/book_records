#include <stdio.h>
#include "Book.h"


int main (){

    struct Book input1 = {1, "Clean Code", "Robert"};
    struct Book input2 = {2, "Clean Coder", "Robert"};
    struct Book input3 = {3, "Clean Architecture", "Robert"};

    // Testing adding
    add(input1);
    add(input2);
    add(input3);
    list();

    add(input1); // Trying to re-add existing element.

    // Testing search
    struct Book book = search(2);

    printf("%i %s %s \n", book.id, book.name, book.author);

    // Testing update.
    struct Book input4 = {3, "Agile Scrum", "Robert"};
    update(input4);
    list();
    struct Book input5 = {4, "Agile Scrum", "Robert"};

    update(input5); //Updating something that doesn't exist

    list();

    // Removing a book

    remove_book(1);
    list();

    remove_book(2);

    return 0;
}