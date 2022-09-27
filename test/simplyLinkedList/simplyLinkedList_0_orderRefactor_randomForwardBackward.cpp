
#include "../sharedTestRoutine.h"
#include "simplyLinkedList_0_orderRefactor.h"
#include "scenario.h"





int main()
{
    SimplyLinkedList_0_orderRefactor *simplyLinkedList = new SimplyLinkedList_0_orderRefactor();

    bool res = simulateForEachSize(simplyLinkedList, "SimplyLinkedList_0_orderRefactor", randomForwardBackward);

    if (res)
        return 0;
    else
        return -1;
}
