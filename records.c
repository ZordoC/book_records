#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include<stdio.h>


struct Book
{
    char name;
    char author;
    int year;

};

typedef struct Book Book;

void add_book(Book book){

    printf(book);
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

    FILE *infile;
    struct Book input;
     
    // Open person.dat for reading
    infile = fopen ("book_store_db.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
     
    // read file contents till end of file
    while(fread(&input, sizeof(struct Book), 1, infile))
        printf ("name = %d author = %s %i\n", input.name,
        input.author, input.year);
 
    // close file
    fclose (infile);
}

 
int main()
{
   // Create an array of books
   struct Book arr[10];
 
   // Access array members
   arr[0].name = "Clean Code";
   arr[0].author = "Robert C Martin";
   arr[0].year = 2003;

   arr[1].name = "Clean Coder";
   arr[1].author = "Robert C Martin";
   arr[1].year = 2004;
    
   printf("%d %d %d", arr[0].name, arr[0].author, arr[0].year);
   printf("%d %d %d", arr[1].name, arr[1].author, arr[1].year);

   add_book(&arr[0]);
   read();
   return 0;
}


