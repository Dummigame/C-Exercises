// Deg(C) = (5/9)*(Deg(F)-32)
#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */
int main(void)
{
float fahr, celsius;
float lower, upper, step;
lower = 0;
upper = 300;
step = 20;
/* lower limit of temperatuire scale */
/* upper limit */
/* step size */
fahr = lower;
while (fahr <= upper) {
celsius = (5.0/9.0) * (fahr-32.0);
printf("%3.0f %6.1f\n", fahr, celsius);
15
fahr = fahr + step;
}
return 0;
}