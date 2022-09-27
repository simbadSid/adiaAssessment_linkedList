#include "tools.h"
#include "simplyLinkedList_0_orderRefactor.h"
#include "scenario.h"

#ifndef TEST_SHAREDTESTROUTINE_H
#define TEST_SHAREDTESTROUTINE_H


std::list<int> SIZE_LIST = std::list<int>({10, 15, 20, 30, 50, 100, 150, 250, 500, 750, 1000});


void appendRandomList(unsigned size, std::list<int> *outputList)
{
    for (unsigned i=0; i<size; ++i)
    {
        outputList->push_front(std::rand());
    }
}


bool simulateForEachSize(SimplyLinkedList* simplyLinkedList, std::string className, bool (*scenarioFunction)(SimplyLinkedList*))
{
    unsigned formerSize = 0;
    std::list<int> *content = new std::list<int>();

    std::cout << std::endl << "Execution time (class: " << className << "): ";

    // For each list size
    for (const auto& size : SIZE_LIST)
    {
        assert(size >= formerSize);

        // Set the list to scan
        appendRandomList(size - formerSize, content);
        simplyLinkedList->setList(content);

        // Scan the list
        bool isCorrectlyParsed = scenarioFunction(simplyLinkedList);

        // Case where the list has not been properly explored
        if (!isCorrectlyParsed)
        {
            log_error("%s: not correctly parsed\n", __FILE_NAME__);
            return false;
        }

        // Case where the list has been corrupted
        if (!simplyLinkedList->isEqual(content))
        {
            log_error("%s: list corrupted\n", __FILE_NAME__);
            return false;
        }

        formerSize = size;
    }
    std::cout << std::endl;

    return true;
}

#endif //TEST_SHAREDTESTROUTINE_H
