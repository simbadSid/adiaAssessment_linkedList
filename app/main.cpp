#include "tools.h"
#include "simplyLinkedList_0_orderRefactor.h"
#include "scenario.h"

//std::list<int> SIZE_LIST = std::list<int>({1000000, 11000000, 21000000, 31000000, 41000000, 51000000, 61000000, 71000000, 81000000, 91000000});
std::list<int> SIZE_LIST = std::list<int>({5, 6, 7});

void appendRandomList(unsigned size, std::list<int> *outputList)
{
    for (unsigned i=0; i<size; ++i)
    {
        outputList->push_front(std::rand());
    }
}


int main()
{
    std::list<std::pair<SimplyLinkedList*, std::string> > l = {
            std::pair<SimplyLinkedList*, std::string> (new SimplyLinkedList_0_orderRefactor(), "SimplyLinkedList_0_orderRefactor")
    };

    // For each list class
    for (const auto& c : l)
    {
        SimplyLinkedList* simplyLinkedList = c.first;
        std::string className = c.second;
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
            auto executionTime = runScenario(simplyLinkedList);
            std::cout << executionTime << ", ";
            fflush(stdout);
            formerSize = size;
        }
        std::cout << std::endl;

        delete c.first;
    }
}
