#include "scenario.h"


long long runScenario(SimplyLinkedList *simplyLinkedList)
{
    // Record the start time
    std::clock_t startTime = std::clock();
    
    #ifdef SCENARIO_onlyForward
        onlyForward(simplyLinkedList);

    #elif SCENARIO_onlyBackward
        onlyBackward(simplyLinkedList);

    #elif SCENARIO_halfForwardHalfBackward
        halfForwardHalfBackward(simplyLinkedList);

    #elif SCENARIO_randomForwardBackward
        randomForwardBackward(simplyLinkedList);

    #else
        fprintf(stderr, "%s: no scenario has been defined (you need to define the macros SCENARIO_<scenarioName>)\n", __FILE__);
        fflush(stderr);
        abort();
    #endif

    // Record the end time
    std::clock_t endTime = std::clock();
    
    // Calculate the elapsed time in milliseconds
    long long executionTime = 1000 * (endTime - startTime) / CLOCKS_PER_SEC;

    return executionTime;
}

/**
 * @brief Walks through the list NB_WALKS times in a forward way.
 * @return If the TEST macros is not set, then the result is irrelevant.
 * Otherwise, the function returns true if the exploration has crossed the correct number of elements
 */
bool onlyForward(SimplyLinkedList *simplyLinkedList)
{
    log("%s: Execute scenario \"onlyForward\"\n", __FILE__);

    for (unsigned walk=0; walk<NB_WALKS; ++walk)
    {
        #ifdef TEST
            unsigned long nbElement = simplyLinkedList->walk(forward, false);
            if (nbElement != simplyLinkedList->getSize())
                return false;
        #else
            simplyLinkedList->walk(forward, false);
        #endif
    }

    #ifdef TEST
        return true;
    #else
        return false;
    #endif
}

/**
 * @brief Walks through the list NB_WALKS times in a backward way.
 * @return If the TEST macros is not set, then the result is irrelevant.
 * Otherwise, the function returns true if the exploration has crossed the correct number of elements
 */
bool onlyBackward(SimplyLinkedList *simplyLinkedList)
{
    log("%s: Execute scenario \"onlyBackward\"\n", __FILE__);

    for (unsigned walk=0; walk<NB_WALKS; ++walk)
    {
        #ifdef TEST
            unsigned long nbElement = simplyLinkedList->walk(backward, false);
            if (nbElement != simplyLinkedList->getSize())
                    return false;
        #else
            simplyLinkedList->walk(backward, false);
        #endif
    }

    #ifdef TEST
        return true;
    #else
        return false;
    #endif
}

/**
 * @brief Walks through the list NB_WALKS/2 times in a forward way and NB_WALKS/2 times in a backward way.
 * @return If the TEST macros is not set, then the result is irrelevant.
 * Otherwise, the function returns true if the exploration has crossed the correct number of elements
 */
bool halfForwardHalfBackward(SimplyLinkedList *simplyLinkedList)
{
    log("%s: Execute scenario \"halfForwardHalfBackward\"\n", __FILE__);

    for (unsigned walk=0; walk<NB_WALKS/2; ++walk)
    {
        #ifdef TEST
            unsigned long nbElement = simplyLinkedList->walk(forward, false);
            if (nbElement != simplyLinkedList->getSize())
                return false;
        #else
            simplyLinkedList->walk(forward, false);
        #endif
    }

    for (unsigned walk=NB_WALKS/2; walk<NB_WALKS; ++walk)
    {
        #ifdef TEST
            unsigned long nbElement = simplyLinkedList->walk(backward, false);
            if (nbElement != simplyLinkedList->getSize())
                return false;
        #else
            simplyLinkedList->walk(backward, false);
        #endif
    }

    #ifdef TEST
        return true;
    #else
        return false;
    #endif
}

/**
 * @brief Walks through the list NB_WALKS times by randomly picking a direction at each exploration.
 * @return If the TEST macros is not set, then the result is irrelevant.
 * Otherwise, the function returns true if the exploration has crossed the correct number of elements
 */
bool randomForwardBackward(SimplyLinkedList *simplyLinkedList)
{
    log("%s: Execute scenario \"randomForwardBackward\"\n", __FILE__);

    for (unsigned walk=0; walk<NB_WALKS; ++walk)
    {
        ListOrdering ordering = (std::rand()%2 ==0) ? forward : backward;
        #ifdef TEST
            unsigned long nbElement = simplyLinkedList->walk(ordering, false);
            if (nbElement != simplyLinkedList->getSize())
                return false;
        #else
            simplyLinkedList->walk(ordering, false);
        #endif
    }

    #ifdef TEST
        return true;
    #else
        return false;
    #endif
}
