#include <stdio.h>
#include <string.h>
#define SIZE 50
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void selection(char word[])
{
    int i, j;
    char min;
    int N=(int)strlen(word);
    for(i=0; i<N; i++)
    {
        min = word[i];
        for(j=i+1; j<N; j++)
            if(min>word[j])
                min = word[j];
        swap(&min, &word[i]);
        printf("%c", word[i]);
    }
}
void removeElement(int N, int k, char words[])
{
    int i;
    for(i=k; i<N; i++)
        words[k] = words[k+1];
    (words)--;
}
void antiduplicate(char word[])
{
    int i, j;
    char prev = '\0';
    for (i = j = 0; word[i] != '\0'; i++) {
        if (prev != word[i])
            word[j++] = word[i];
        prev = word[i];
    }
    word[j] = '\0';

    printf("%s\n", word);
}
void piglatin(char words[])
{
        printf("%s", words + 1);      /* print word except first character */
        printf("%c", words[0]);       /* print first character of word     */
        printf("ay\n");              /* print "ay"                        */
}
int main()
{
    char str[SIZE];
    printf("Enter a word: ");scanf("%s",str);
    printf("Pig Latin: ");piglatin(str);
    printf("Removed consecutive duplicates: ");antiduplicate(str);
    printf("Sort the letters: "); selection(str);
    printf("\n");

}
