#include <stdio.h>
#include <stdlib.h>
#include <dir.h>

int main()
{
    char DIR[10];
    int i;
    while(1)
    {
        printf("E.g.: E:\\Movies\n");
        printf("Enter Directory name\n");
        scanf("%s",DIR);
        i=mkdir(DIR);
        if(!i)
        {
            printf("Created\n");
            break;
        }
        else
        {
            printf("Not created\n");
            printf("Enter other filename\n");
        }
    }
    return 0;
}
