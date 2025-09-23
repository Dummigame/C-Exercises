// // Deg(C) = (5/9)*(Deg(F)-32)

#include <stdio.h>

// /* print Fahrenheit-Celsius table
// for fahr = 0, 20, ..., 300; floating-point version */

// int main(void)
// {
// float fahr, celsius;
// float lower, upper, step;

// lower = 0;
// upper = 300;
// step = 20;

// /* lower limit of temperatuire scale */
// /* upper limit */
// /* step size */

// fahr = lower;
// printf("Temperature conversion table example (Fahrenheit to Celsius) \n");
// while (fahr <= upper) {
// celsius = (5.0/9.0) * (fahr-32.0);
// printf("%3.0f \t \t \t \t %6.1f\n", fahr, celsius);
// fahr = fahr + step;
// }
// return 0;
// }

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