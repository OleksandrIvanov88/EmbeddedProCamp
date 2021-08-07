#ifndef _TYPE_H_
#define _TYPE_H_

typedef char myString[31];

typedef enum
{
    CPU_DATA_TYPE = 1,
    ORDER_DATA_TYPE
}DATA_TYPE_E;

typedef struct
{
    myString CpuName;
    int CpuMark;
    float Price;
}CPU_TABLE_ROW_S;

typedef struct 
{
    unsigned int OrderNumber;
    myString CpuName;
    unsigned int Number;
    float Price;
    float TotalPrice;
}ORDER_TABLE_ROW_S;

typedef union 
{
    CPU_TABLE_ROW_S cpu;
    ORDER_TABLE_ROW_S order;
} TABLE_ROW_DATA_U;

typedef struct 
{
    DATA_TYPE_E DataType;
    TABLE_ROW_DATA_U Data;
}TABLE_ROW_S;



#endif
