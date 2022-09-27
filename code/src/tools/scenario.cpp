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

/**
 * @brief Walks through the list NB_WALKS times in a forward way.
 * @return If the TEST macros is not set, then the result is irrelevant.
 * Otherwise, the function returns true if the exploration has crossed the correct number of elements
 */
bool onlyForward(SimplyLinkedList *simplyLinkedList)
{
    log("%s: Execute scenario \"onlyForward\"\n", __FILE_NAME__);

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
    log("%s: Execute scenario \"onlyBackward\"\n", __FILE_NAME__);

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
    log("%s: Execute scenario \"halfForwardHalfBackward\"\n", __FILE_NAME__);

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
    log("%s: Execute scenario \"randomForwardBackward\"\n", __FILE_NAME__);

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
