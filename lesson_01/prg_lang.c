#include <stdio.h>
#include <stdint.h>

/******************TIOBE programming language index*************************
 *  TIOBE ratings are calculated by counting hits of the most popular 
 * search engines. Twenty-five search engines are used to calculate 
 * the TIOBE index. The TIOBE Programming Community index is an indicator 
 * of the popularity of programming languages. The index started in the year 
 * 2001 and updated once a month https://statisticstimes.com/tech/top-computer-languages.php 
 */

struct lang_item
{
    uint8_t pos_2021;
    uint8_t pos_2020;
    char *change;
    char *lang;
    float raiting;
    float trand;
};

int main(void)
{
    struct lang_item data[] =
        {
            {1, 1, " ", "C", 13.38, -3.68},
            {2, 3, "\u2191", "Python", 11.87, +2.75},
            {3, 2, "\u2193", "Java", 11.74, -4.54},
            {4, 4, " ", "C++", 7.81, +1.69}};

    printf("---------------------------------------------------------------\n");
    printf("| %5s | %5s | %5s | %-10s| %5s | %5s |\n", "May 2021", "May 2020", "Change", "Language",
                                                       "Raiting", "Trends");
    printf("---------------------------------------------------------------\n");
    size_t size = sizeof(data) / sizeof(struct lang_item);
    for (size_t i = 0; i < size; ++i)
    {
        printf("%*s%u %*s%u %*s%s %*s%-9s %-5.2f %% %6.2f %%\n", 5, "", data[i].pos_2021,
                                                                 10, "", data[i].pos_2020,
                                                                 8, "", data[i].change,
                                                                 6, "", data[i].lang,
                                                                 data[i].raiting, data[i].trand);
    }

    return 0;
}