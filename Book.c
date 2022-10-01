#include<stdio.h>
#include<stdbool.h>
#include "Book.h"


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

bool check_exists(FILE *file, int id){

    if (file == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        return false;
    };

    struct Book repeated = search(id);

    if (repeated.id == id)
    {
        return true;
    }
    return false;
};


void add (struct Book book)
{
    FILE *outfile;

    // open file for writing
    outfile = fopen ("books.dat", "a+");

    if (check_exists(outfile, book.id) == true)
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


void remove_book(int id){

    FILE *file, *file2;
    int flag = 0;
    struct Book input;

    // Open person.dat for reading
    file = fopen ("books.dat", "r");

    if (check_exists(file, id) == false)
    {
        printf("Book not found with id %i", id);

    }

    file2 = fopen("temp.dat","wb+");

	while(fread(&input,sizeof(struct Book),1,file))
		{
			if(input.id != id)
            {
				fwrite(&input,sizeof(struct Book),1, file2);
            }
            if(input.id == id)
            {
                flag = 1;
            }
        }
        fclose(file);
        fclose(file2);

        if (flag == 0)
           {
            remove("data");
			rename("temp.txt","project");
            printf("Successfully deleted record");
           }

}


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
    }

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

    if (check_exists(f, new_book.id) == false)
    {
        printf("Book doesn't exist \n");
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
