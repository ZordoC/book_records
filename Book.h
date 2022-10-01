#ifndef BOOK_H
#define BOOK_H

/*
Defines the structure of a book.

A book has:
* ID.
* Name.
* Author's Name.
*/

struct Book
{
    int id;
    char name[20];
    char author[20];
};

/*
Lists all the books. (Books are stored in a file).
*/
void list();

/*
Search a book by it's id.
*/
struct Book search(int id);

/*
Add a new book.
*/
void add(struct Book book);

/*
Update an existing book.
*/
void remove_book(int id);
/*
Update an existing book.
*/
void update(struct Book new_book);

#endif
