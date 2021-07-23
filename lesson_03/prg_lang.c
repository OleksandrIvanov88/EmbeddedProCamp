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
    uint32_t pos_2021;
    uint32_t pos_2020;
    char lang[100];
    float raiting;
    float trand;
};

int main(void)
{
    // struct lang_item data[] =
    //     {
    //         {1, 1, "C", 13.38, -3.68},
    //         {2, 3, "Python", 11.87, +2.75},
    //         {3, 2, "Java", 11.74, -4.54},
    //         {4, 4, "C++", 7.81, +1.69}};
    printf("Enter the amount of tabel lines = ");
    int32_t lines_number = 0;
    scanf("%i", &lines_number);
    struct  lang_item data[lines_number];
    
    for(int i = 0; i < lines_number; ++i)
    {
        printf("Enter Position_2021 Position_2020 Language Rainting Trends for line #%u:\n", i + 1);
        scanf("%u %u %s %f %f", &data[i].pos_2021, &data[i].pos_2020, &data[i].lang[0], 
                                                     &data[i].raiting, &data[i].trand);
    }

    printf("------------------------------------------------------\n");
    printf("| %5s | %5s | %-10s| %5s | %5s |\n", "May 2021", "May 2020", "Language",
                                                       "Raiting", "Trends");
    printf("------------------------------------------------------\n");
    size_t size = sizeof(data) / sizeof(struct lang_item);
    for (size_t i = 0; i < size; ++i)
    {
        printf("%*s%u %*s%u %*s%-9s %-5.2f %% %+7.2f %%\n", 5, "", data[i].pos_2021,
                                                                 10, "", data[i].pos_2020,
                                                                 6, "", data[i].lang,
                                                                 data[i].raiting, data[i].trand);
    }

    return 0;
}