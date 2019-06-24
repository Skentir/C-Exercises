#include <stdio.h>
#include <string.h>
void removespaces(char str[],int size)
{
    int i, j;
    for(i=0; i<size; i++)
    {
        if (str[i] == ' ') {
            for(j=i; j<size-1; j++) {
                str[j] = str[j+1];
                //str--;
            }
        }

    }
    printf("Removed spaces is");
    for(i=0;i<=size;i++)
        printf("%c",str[i]);
}
void swap(char *a, char *b)
{
    char temp;
    temp = *b;
    *b = *a;
    *a = temp;
}
void reverse(char str[], int size)
{
    int i;
    for(i=0; i<=size/2; i++)
    {
        swap(&str[i],&str[size-i]);
    }
    printf("Reversed is");
    for(i=0;i<=size;i++)
        printf(" %c",str[i]); }

void asterisk(char str[], int size)
{
    int i;
    for(i = 0; i<size; i++)
    {
        if(str[i]==' ')
            str[i] = '*';
    }
    printf("String is %s", str);
}

int main()
{
    char str[50];
    printf("Print here:");
fgets(str, sizeof(str), stdin);

/*for(i=0; i<strlen(str);i++)
   if(str[i] == '\n')
        str[i] = '\0';
*/
// asterisk(str, (int) strlen(str));
removespaces(str,(int) strlen(str));
reverse(str, (int) strlen(str));
return 0;
}
