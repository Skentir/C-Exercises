#include <stdio.h>
#include <string.h>
typedef char Array[30];

int uppercase(int c)
{
    if (c >= 97 && c <= 122)
        return (c-32);
    else if (c <= 97 && c >= 122)
        return c;
}

void common(char* word1, char* word2)
{
    int i, j, N, P;
    N = (int)strlen(word1);
    P = (int)strlen(word2);
    for(i=0; i<N; i++)
    {
        for(j=0; j<P; j++)
            if (word1[i] == word2[j])
                word2[j]=uppercase(word2[j]);

    }
}
int main() {
    Array word1;
    Array word2;

    printf("Enter word 1:"); scanf("%s", word1);
    printf("Enter word 2: "); scanf("%s", word2);

    common(word1, word2);

    int i, N;
    N = (int)strlen(word2);

    for(i=0; i<N; i++)
        printf("%c",word2[i]);

    return 0;
}
