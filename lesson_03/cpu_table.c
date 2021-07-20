#include <stdio.h>

int main(void)
{
    char cpu_name_1[32] = "Apple M1 8 Core 3200 MHz";
    char cpu_name_2[32] = "Intel Core i9-11900KF @ 3.50GHz";
    char cpu_name_3[32] = "Intel Core i9-11900F @ 2.50GHz";

    int cpu_mark_1 = 3767;
    int cpu_mark_2 = 3594;
    int cpu_mark_3 = 3577;

    float price_1 = 0.0;
    float price_2 = 587.99;
    float price_3 = 519.99;
    //Heading
    printf("-----------------------------------------------------------\n");
    printf("| %-31s | %4s | %s |\n", "CPU", "CPU Mark", "Price (USD)");
    printf("-----------------------------------------------------------\n");
    scanf("%s %i %f", &cpu_name_1[0], &cpu_mark_1, &price_1);
    scanf("%s %i %f", &cpu_name_2[0], &cpu_mark_2, &price_2);
    scanf("%s %i %f", &cpu_name_3[0], &cpu_mark_3, &price_3);
    //Body
    printf("-----------------------------------------------------------\n");
    printf("| %-31s | %4s | %s |\n", "CPU", "CPU Mark", "Price (USD)");
    printf("-----------------------------------------------------------\n");
    printf("%-31s %8i %11.2f\n", &cpu_name_1[0], cpu_mark_1, price_1);
    printf("%-31s %8i %11.2f\n", &cpu_name_2[0], cpu_mark_2, price_2);
    printf("%-31s %8i %11.2f\n", &cpu_name_3[0], cpu_mark_3, price_3);

    return 0;
}