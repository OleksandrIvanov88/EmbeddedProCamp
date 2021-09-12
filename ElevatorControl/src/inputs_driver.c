#include "inputs_driver.h"
#include <stdio.h>

void InputsInit(void)
{
    printf("%s\r\n", __func__);
}

int CabinSwitches()
{
    printf("Enter cabin switch = ");
    int res = 0;
    scanf("%i", &res);
    return res;
}


int DoorSwitches()
{
    printf("Enter door switch = ");
    int res = 0;
    scanf("%i", &res);
    return res;
}

int Keys()
{
    printf("Enter key = ");
    int res = 0;
    scanf("%i", &res);
    return res;
}
