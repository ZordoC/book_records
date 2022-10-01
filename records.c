#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include<stdio.h>


struct Book
{
    char* name;
    char* author;
    int year;

};

typedef struct Book Book;

void add_book(Book book){

    printf("yo!");
    FILE *fp;
    fp = fopen("book_store_db", "ab+");
    if(fp == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fwrite (&book, sizeof(struct Book), 1, fp);
    fclose(fp);

}

void read(){

    FILE* ptr;
    char ch;

    ptr = fopen("book_store_db", "rb");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

    printf("content of this file are \n");

    // Printing what is written in file
    // character by character using loop.
    do {
        ch = fgetc(ptr);
        printf("%c", ch);

        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);

    // Closing the file
    fclose(ptr);
}


int main()
{
   // Create an array of books
   struct Book arr[20];

   // Access array members
   arr[0].name = "Clean Code";
   arr[0].author = "Robert C Martin";
   arr[0].year = 2003;

   arr[1].name = "Clean Coder";
   arr[1].author = "Robert C Martin";
   arr[1].year = 2004;

   printf("%s %s %d", arr[0].name, arr[0].author, arr[0].year);
   printf("\n");
   printf("%s %s %d", arr[1].name, arr[1].author, arr[1].year);

   add_book(arr[0]);
   read();
}


