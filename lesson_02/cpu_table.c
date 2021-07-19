#include <stdio.h>

int main(void)
{
    //Heading
    printf("-----------------------------------------------------------\n");
    printf("| %-31s | %4s | %s |\n", "CPU", "CPU Mark", "Price (USD)");
    printf("-----------------------------------------------------------\n");
    //Body
    printf("%-31s %8i %11.2f\n", "Apple M1 8 Core 3200 MHz", 3767, 0.0);
    printf("%-31s %8i %11.2f\n", "Intel Core i9-11900KF @ 3.50GHz", 3594, 587.99);
    printf("%-31s %8i %11.2f\n", "Intel Core i9-11900F @ 2.50GHz", 3577, 519.99);

    return 0;
}