#include "do_elevator_logic.h"
#include "inputs_driver.h"
#include "type.h"
#include "elevator_logic.h"

void run_elevator(void)
{
    ELFSM_ElvInit();
    while (1)
    {
         ELFSM_ElvCabinSwitchToNextPhase();
    }
}