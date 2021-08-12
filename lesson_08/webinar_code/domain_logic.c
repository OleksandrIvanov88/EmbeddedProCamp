#include <stdio.h>
#include <string.h> 

#include "domain_logic.h"
#include "input_processor.h"
#include "output_processor.h"


static void dl_WriteData(char* pData, unsigned int sizeOfData);

char buffer[1024];

void Create_table(void)
{

    IP_Init(dl_WriteData);
 
    IP_Input();
  
    OP_Init(buffer);
    OP_Output(buffer);
    
}

static void dl_WriteData(char* pData, unsigned int sizeOfData)
{
    static int i = 0;
    memcpy(&buffer[sizeOfData * i], pData, sizeOfData);
    i++;
}