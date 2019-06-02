#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char String[50];

struct name {
    String first;
    String last;
    char initial;
};

struct date {
    int month;
    int day;
    int year;
};

typedef struct name Name;
typedef struct date Date;

struct person {
    Name fullname;
    int id;
    float allowance;
    char gender;
    Date birthday;
};
typedef struct person Human;

void populate(Human people[], int num)
{
int i; char dummy;
for (i = 0; i < num; i++)
{
    printf("Enter first name:");
    scanf("%s", people[i].fullname.first);
    printf("Enter last name:");
    scanf("%s", people[i].fullname.last);
    printf("Enter initial:");
    scanf("%c", &dummy);
    scanf("%c", &people[i].fullname.initial);

    printf("Enter ID number:");
    scanf("%d", &people[i].id);
    printf("Enter Allowance:");
    scanf("%f", &people[i].allowance);
    printf("Enter gender:");
    scanf("%c", &dummy);
    scanf("%c", &people[i].gender);

    printf("Enter month of birth:");
    scanf("%d", &people[i].birthday.month);
    printf("Enter day of birth:");
    scanf("%d", &people[i].birthday.day);
    printf("Enter year of birth:");
    scanf("%d", &people[i].birthday.year);
}
}

void display(Human p)
{
    printf("%s, %s %c. \n", p.fullname.last, p.fullname.first, p.fullname.initial);
    printf("%d \n", p.id);
    printf("%d/%d/%d \n", p.birthday.month, p.birthday.day, p.birthday.year);
    printf("%c \n", p.gender);
    printf("\n");
}
void total(Human people[], int num)
{
    float sum = 0, temp = 0;
    int max = 0;
    int i, j;
    for(i=0; i < num; i++)
    {
        sum = temp + people[i].allowance;
        temp = sum;
        // max = i+1;
        if (people[i].allowance >= people[max].allowance)
                max = i;

}
    printf("The sum is %f\n", sum);
    printf("%s has the highest allowance", people[max].fullname.first);

}
void getID(Human people[], int id, int num)
{
    int i;
    for(i =0; i<num; i++)
    {
        if(people[i].id ==id)
            printf("ID %d is %s, %s %c \n", id, people[i].fullname.last, people[i].fullname.first, people[i].fullname.initial);
    }
}
void swap(Human *b, Human *a)
{
    Human temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sort(Human people[], int num)
{
    int i, j; int min;
    for (i = 0; i < num; i++)
    {
        min = i;
        for (j = i+1; j < num; j++)
            if (strcmp(people[i].fullname.last,people[j].fullname.last) > 0)
                min = j;
        swap(&people[i], &people[min]);
    }
    for (i = 0; i < num; i++)
        display(people[i]);
}
int main() {
    int num, i, choice, id;
    printf("Enter number of people:");
    scanf("%d", &num);
    Human people[num];
    populate(people, num);

    printf("Pick a choice:\n[1]Display Names\n[2]Total Allowance\n[3]ID Searcher\n[4]Sort by Surname\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            system("cls");
            for (i = 0; i < num; i++)
                display(people[i]);
            break;
        case 2:
            system("cls");
            total(people, num);
            break;
        case 3:
            system("cls");
            printf("Enter ID number:");
            scanf("%d", &id);
            getID(people, id, num);
            break;
        case 4:
            system("cls");
            sort(people, num);
            break;
    }
    return 0;
}
