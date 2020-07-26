#include <stdio.h>
#include <stdlib.h>

int main()
{
    char path[100];
    FILE *read, *write;
    read = fopen("readfile.txt","r");
    write = fopen("writeFile.txt","w");
    while(!feof(read))
    {
        char c = fgetc(read);
    }
    int curpos = ftell(read);
    fseek(read,0,0);
    while(curpos>0)
    {
        char c = fgetc(read);
        fputc(c,write);
        curpos--;
    }
    printf("Done");
}
