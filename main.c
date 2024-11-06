#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char D[100];
    char stack[10][100];
    int top = -1;

    FILE *filepointer = fopen("Stack.txt","a");

    //step1:Create file with some data
    if(filepointer == NULL)
    {
        puts("Cannot open file");
        exit(1);
    }
    printf("Enter few lines :\n");
    while(strlen(gets(D)) > 0)
    {
        fputs(D,filepointer);
        fputs("\n",filepointer);
    }
    fclose(filepointer);

    //step2:Read and Display file content
    printf("\nFile contents are being read now....\n",D);
    filepointer = fopen("Stack.txt","r");
    if(filepointer == NULL)
    {
        puts("cannot open file");
        exit(2);
    }
    while(fgets(D,99,filepointer) != NULL)
    {
        printf("%s",D);
    }
    fclose(filepointer);

    //step3:Reverse file content using stack

    //pushing the content into stack
    filepointer = fopen("Stack.txt", "r");

    while(fgets(D, sizeof(D), filepointer) != NULL)
    {

        if (top < 10)
        {
            top++;
            strcpy(stack[top-1], D);
        }
    }
    fclose(filepointer);

    //popping the stored content
    printf("Reversed content of the file:\n");

    while(top >= 0)
    {
        printf("%s", stack[top]);
        top--;
    }

    printf("File lines reversed successfully.\n");

    return 0;
}
