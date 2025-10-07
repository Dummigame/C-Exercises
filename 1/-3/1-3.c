// Temperature conversion table example (Celsius to Fahrenheit up to 300C)

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main(void)
{

float fahr, celsius = 0;
int i = 0;

printf("Temperature conversion table example (Celsius to Fahrenheit) \n");
while (i <= UPPER)
{
    fahr = celsius*1.8 + 32;
    printf("C:%3.0f \t \t \t \t F:%3.0f\n", celsius, fahr);
    celsius+=STEP;
    i = i + STEP;
}
return 0;
}