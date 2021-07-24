#include <stdio.h>
#include <stdint.h>

/******************TIOBE programming language index*************************
 *  TIOBE ratings are calculated by counting hits of the most popular 
 * search engines. Twenty-five search engines are used to calculate 
 * the TIOBE index. The TIOBE Programming Community index is an indicator 
 * of the popularity of programming languages. The index started in the year 
 * 2001 and updated once a month https://statisticstimes.com/tech/top-computer-languages.php 
 */
typedef char myString[31];

typedef struct 
{
    uint32_t pos_2021;
    uint32_t pos_2020;
    myString lang;
    float raiting;
    float trand;
} Lang_item;

void scan_data(Lang_item* item);
void print_data(const Lang_item* item);

#define NLINE (sizeof(data) / sizeof(Lang_item))

int main(void)
{
    printf("Enter the amount of tabel lines = ");
    int32_t lines_number = 0;
    scanf("%i", &lines_number);
    Lang_item data[lines_number];
    
    for(int i = 0; i < lines_number; ++i)
    {
        scan_data(&data[i]);
    }

    printf("------------------------------------------------------\n");
    printf("| %5s | %5s | %-10s| %5s | %5s |\n", "May 2021", "May 2020", "Language",
                                                               "Raiting", "Trends");
    printf("------------------------------------------------------\n");

    for (size_t i = 0; i < NLINE; ++i)
    {
        print_data(&data[i]);
    }

    return 0;
}

void scan_data(Lang_item* item)
{
    printf("Enter: Position_2021 | Position_2020 | Language | Rainting Trends |\n");
    scanf("%u %u %s %f %f", &item->pos_2021, &item->pos_2020, &item->lang[0], 
                                                     &item->raiting, &item->trand);
        
}
void print_data(const Lang_item* item)
{
    printf("%*s%u %*s%u %*s%-9s %-5.2f %% %+7.2f %%\n", 5, "", item->pos_2021,
                                                        10, "", item->pos_2020,
                                                        6, "", item->lang,
                                                        item->raiting, item->trand);
}
