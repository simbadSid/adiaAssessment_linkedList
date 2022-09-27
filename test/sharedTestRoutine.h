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


bool simulateForEachSize(SimplyLinkedList* simplyLinkedList, std::string className, void (*scenarioFunction)(SimplyLinkedList*))
{
    std::list<std::pair<SimplyLinkedList*, std::string> > l = {
            std::pair<SimplyLinkedList*, std::string> (new SimplyLinkedList_0_orderRefactor(), "SimplyLinkedList_0_orderRefactor")
    };

    // For each list class
    for (const auto& c : l)
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
            scenarioFunction(simplyLinkedList);
            if (!simplyLinkedList->isEqual(content))
                return false;

            //TODO test that all the element have been correctly visited

            formerSize = size;
        }
        std::cout << std::endl;

        delete c.first;
    }

    return true;
}

#endif //TEST_SHAREDTESTROUTINE_H
