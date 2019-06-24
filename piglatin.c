#include <stdio.h>
#include <string.h>

#define MAX 43

char lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return c;
}

char upper(char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return c;
}

int isVowel(char c)
{
	return  c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
			c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int isUpper(char c)
{
	return c >= 'A' && c <= 'Z';
}

void transpose(char a[], int n, int i)
{
	int u = isUpper(a[0]);
	
	char tmp[n-i];
	char tmp2[i];
	strcpy(tmp, a + i);
	
	a[i] = '\0';
	strcpy(tmp2, a);
	
	strcpy(a, tmp);
	strcat(a, tmp2);
	
	if (u)
	{
		a[n-i] = lower(a[n-i]);
		a[0] = upper(a[0]);
	}
}

char* ToPigLatin(char* word)
{
	char *c = word;
	int i, len;
	
	len = strlen(word);
	if (isVowel(word[0]))
		strcat(word, "way");
	else
	{
		for (i = 1; i < len; i++)
		{
			if (isVowel(word[i]) || word[i] == 'Y' || word[i] == 'y')
				break;
		}
		
		transpose(word, len, i);
		strcat(word, "ay");
	}
	
	return word;
}

int main()
{
	char word[5][MAX];
	int i;
	
	printf("Input 5 words: ");
	for (i = 0; i < 5; i++)
		scanf("%s", word[i]);
	
	printf("\nPig Latin version of the 5 words:\n");
	for (i = 0; i < 3; i++)
	{
		ToPigLatin(word[i]);
		printf("%s ", word[i]);
	}
	
	printf("%s ", ToPigLatin(word[3]));
	printf("%s\n", ToPigLatin(word[4]));
	
	return 0;
}

