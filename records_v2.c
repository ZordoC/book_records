#include<stdio.h>
#include<string.h>



struct Book
{
    int id;
    char name[20];
    char author[20];
};


void read();
struct Book search();
void add_book();
void list();

void list()
{
    FILE *infile;
    struct Book input;

    // Open person.dat for reading
    infile = fopen ("books.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        return;
    };

    // read file contents till end of file
    while(fread(&input, sizeof(struct Book), 1, infile))
        printf ("id = %d ; name = %s ; author = %s\n", input.id,
        input.name, input.author);

    // close file
    fclose (infile);
};

void add_book (struct Book book)
{
    FILE *outfile;

    // open file for writing
    outfile = fopen ("books.dat", "a+");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        return;
    };

    struct Book repeated = search(book.id);

    printf("%d \n",  repeated.id);

    if (repeated.id == book.id)
    {
        printf("That ID already exists ... exiting");
        return;
    }

    // write struct to file
    fwrite (&book, sizeof(struct Book), 1, outfile);

    if(&fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");

    // close file
    fclose (outfile);

};

struct Book search(int id){
    FILE *infile;
    struct Book input;


    // Open person.dat for reading
    infile = fopen ("books.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        struct Book file = {0, "", ""};
        return file;
    };

    while(fread(&input, sizeof(struct Book), 1, infile))
    {
        if(input.id == id) {
            printf("Book found !\n");
            return input;
            fclose (infile);
        }
    }
    printf("Book not found !\n");
    fclose (infile);
    struct Book not_found = {0, "", ""};
    return not_found;
};


void update(struct Book new_book)
{

    FILE *f;
    // open file for writing
    f = fopen ("books.dat", "rb+");
    struct Book input;

    // check for existance of book
    printf("Checking for the existance of a book id ...\n");
    struct Book book = search(new_book.id);
    if (book.id == 0){
        return;
    }
    printf("Updating book record \n");

    while(fread(&input,sizeof(struct Book),1,f))
    {
        if(input.id == new_book.id)
        {
            fseek(f,-sizeof(struct Book),SEEK_CUR);
            fwrite(&new_book,sizeof(struct Book),1,f);
        }
    }
}

int main (){


    struct Book input1 = {1, "Clean Code", "Robert"};
    struct Book input2 = {2, "Clean Coder", "Robert"};
    struct Book input3 = {3, "Clean Architecture", "Robert"};

    add_book(input1);
    add_book(input2);
    add_book(input3);
    struct Book book = search(2);

    printf("%i %s %s \n", book.id, book.name, book.author);
    list();

    struct Book input4 = {3, "Agile Scrum", "Robert"};
    update(input4);
    list();
    // struct Book book2 = search(2);

    // printf("%i %s %s \n", book2.id, book2.name, book2.author);
    // search(10);
    return 0;
}