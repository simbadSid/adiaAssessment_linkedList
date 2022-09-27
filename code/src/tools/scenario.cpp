#include "scenario.h"


long long runScenario(SimplyLinkedList *simplyLinkedList)
{
    auto startTime = std::chrono::system_clock::now();

    #ifdef SCENARIO_onlyForward
        onlyForward(simplyLinkedList);

    #elif SCENARIO_onlyBackward
        onlyBackward(simplyLinkedList);

    #elif SCENARIO_halfForwardHalfBackward
        halfForwardHalfBackward(simplyLinkedList);

    #elif SCENARIO_randomForwardBackward
        randomForwardBackward(simplyLinkedList);

    #else
        fprintf(stderr, "%s: no scenario has been defined (you need to define the macros SCENARIO_<scenarioName>)\n", __FILE_NAME__);
        fflush(stderr);
        abort();
    #endif

    auto endTime = std::chrono::system_clock::now();
    auto executionTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime-startTime).count();

    return executionTime;
}

void onlyForward(SimplyLinkedList *simplyLinkedList)
{
    log("%s: Execute scenario \"onlyForward\"\n", __FILE_NAME__);

    for (unsigned walk=0; walk<NB_WALKS; ++walk)
    {
        simplyLinkedList->walk(forward, false);
    }
}

void onlyBackward(SimplyLinkedList *simplyLinkedList)
{
    log("%s: Execute scenario \"onlyBackward\"\n", __FILE_NAME__);

    for (unsigned walk=0; walk<NB_WALKS; ++walk)
    {
        simplyLinkedList->walk(backward, false);
    }
}

void halfForwardHalfBackward(SimplyLinkedList *simplyLinkedList)
{
    log("%s: Execute scenario \"halfForwardHalfBackward\"\n", __FILE_NAME__);

    for (unsigned walk=0; walk<NB_WALKS/2; ++walk)
    {
        simplyLinkedList->walk(forward, false);
    }

    for (unsigned walk=NB_WALKS/2; walk<NB_WALKS; ++walk)
    {
        simplyLinkedList->walk(backward, false);
    }
}

void randomForwardBackward(SimplyLinkedList *simplyLinkedList)
{
    log("%s: Execute scenario \"randomForwardBackward\"\n", __FILE_NAME__);

    for (unsigned walk=0; walk<NB_WALKS; ++walk)
    {
        ListOrdering ordering = (std::rand()%2 ==0) ? forward : backward;
        simplyLinkedList->walk(ordering, false);
    }
}
