#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void display(char str[], int size)
{
    int i;
    printf("[");
    for(i=0; i<size; i++)
    {

        printf("%c ", str[i]);
      if (i != size-1)
        printf(",");

    }
    printf("[");
}

char toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return c;
}

void bubbleSort(char str[], int size)
{
    int i, checker = 1, counter = 0; //counts number of swaps
    char tmp;

    while (checker != 0) // 0 if in ascending, 1 if not!!
    {
        tmp = toupper(str[0]);
        checker = 0;
        for (i = 1; i < size; i++)
        {
            if (toupper(str[i]) < tmp)
                checker = 1;
            else
                tmp = toupper(str[i]);
        }

        for(i=0; i<size-1; i++)
        {
            if(toupper(str[i]) > toupper(str[i+1]))
            {
                swap(&str[i], &str[i+1]);
                counter++;
            }

        }
    }
    display(str, size);
}
int main()
{
    char str[100];
    printf("Enter a word: ");
    fgets(str, sizeof str, stdin);
    bubbleSort(str, (int) strlen(str));
    return 0;
}
