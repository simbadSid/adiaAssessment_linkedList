
#include "../sharedTestRoutine.h"
#include "simplyLinkedList_1_twoPointersInOne.h"
#include "scenario.h"





int main()
{
    SimplyLinkedList_1_twoPointersInOne *simplyLinkedList = new SimplyLinkedList_1_twoPointersInOne();

    bool res = simulateForEachSize(simplyLinkedList, "SimplyLinkedList_1_twoPointersInOne", halfForwardHalfBackward);

    if (res)
        return 0;
    else
        return -1;
}
