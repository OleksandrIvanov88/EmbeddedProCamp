#include <stdio.h>

typedef char myString[31];

typedef struct
{
    myString CpuName;
    int CpuMark;
    float Price;
}TABLE_RAW_S;

void Output(TABLE_RAW_S* table_raw);
void Input(TABLE_RAW_S* table_raw);

int main(void)
{
    TABLE_RAW_S table[3];
    int i = 0;
    //Heading
    printf("-----------------------------------------------------------\n");
    printf("| %-31s | %4s | %s |\n", "CPU", "CPU Mark", "Price (USD)");
    printf("-----------------------------------------------------------\n");
    for(i = 0; i <= 2; i++)
    {
        Input(&table[i]);
    }
    //Body
    printf("-----------------------------------------------------------\n");
    printf("| %-31s | %4s | %s |\n", "CPU", "CPU Mark", "Price (USD)");
    printf("-----------------------------------------------------------\n");
    for(i = 0; i <= 2; i++)
    {
        Output(&table[i]);
    }

    return 0;
}


void Output(TABLE_RAW_S* table_raw)
{
      printf("%-31s %8i %11.2f\n", table_raw->CpuName, table_raw->CpuMark, table_raw->Price);
}

void Input(TABLE_RAW_S* table_raw)
{
      scanf("%s %i %f", table_raw->CpuName, &table_raw->CpuMark, &table_raw->Price);
}