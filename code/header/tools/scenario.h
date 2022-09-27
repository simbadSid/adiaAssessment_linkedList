/**
 * @def scenario
 * @details Walks through an input list depending on the chosen scenario.
 * The considered scenario is set by defining the macro SCENARIO_<scenarioName>
 * @author Riyane
 * @date 26/09/2022
 */

#ifndef ADIAASSESSMENT_LINKEDLIST_SCENARIO_H
#define ADIAASSESSMENT_LINKEDLIST_SCENARIO_H

#include <stdlib.h>

#include "simplyLinkedList.h"
#include "tools.h"

#define NB_WALKS 10

/**
 * @def runScenario
 * @details Walks through an input list depending on the chosen scenario.
 * The considered scenario is set by defining the macro SCENARIO_<scenarioName>
 * @return the total execution time for running the NB_WALKS.
 */
long long runScenario(SimplyLinkedList *simplyLinkedList);

void onlyForward               (SimplyLinkedList *simplyLinkedList);
void onlyBackward              (SimplyLinkedList *simplyLinkedList);
void halfForwardHalfBackward   (SimplyLinkedList *simplyLinkedList);
void randomForwardBackward     (SimplyLinkedList *simplyLinkedList);

#endif //ADIAASSESSMENT_LINKEDLIST_SCENARIO_H
