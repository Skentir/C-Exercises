#include <stdio.h>
#include <ctype.h>

int main()
{
  float fTemp;
  char response;

  printf("Select an initial temperature unit to convert.\n");
  printf("1. Celsius\n2. Fahrenheit\n3. Kelvin \n");
  scanf("%c", &response);
  if ((response == 'C') || (response == 'c') || (response == '1') || (response == 'F') || (response == 'f') || (response == '2') || (response == 'K') || (response == 'k') || (response == '3'))
  {
    if ((response == 'C') || (response == 'c') || (response == '1'))
    {
        printf("Enter temperature value.\n");
        scanf("%f", &fTemp);
        printf ("Fahrenheit %6.1f \n", ((9.0/5.0) * fTemp) - 32.0);
        printf ("Kelvin %6.1f \n", (273.15 + fTemp));
        }
        else
        {
        printf ("Enter valid temperature value.");
        }
    }
    if ((response == 'F') || (response == 'f') || (response == '2'))
    {
        printf("Enter temperature value.\n");
        scanf("%f", &fTemp);
        printf ("Celsius %6.1f \n", ((5.0/9.0) * fTemp) + 32.0);
        printf ("Kelvin %6.1f \n", ((5.0/9.0 * fTemp + 32.0) + 273.15));
    }
    if ((response == 'K') || (response == 'k') || (response == '3'))
    {
        printf("Enter temperature value.\n");
        scanf("%f", &fTemp);
        printf ("Celsius %6.1f \n", (fTemp - 273.15));
        printf ("Fahrenheit %6.1f \n", (9.0/5.0 * (fTemp - 273.15) + 32));
    }
  else
  {
    printf("Please enter a valid option. Just choose from the choices mentioned.");
  }
}
