#include "simplyLinkedList_0_orderRefactor.h"


void SimplyLinkedList_0_orderRefactor::walk(
        ListOrdering ordering,
        bool keepListOrder,
        void (*treatment)(int, unsigned))
{
    log("%s: Walking through the current list\n", __FILE_NAME__);

    bool hasBeenInverted = false;

    // Invert list if needed
    if (this->listOrdering != ordering)
    {
        this->invertList();
        hasBeenInverted = true;
    }

    // Walk through list
    Node* current = this->list;
    unsigned index = 0;
    while (current != NULL)
    {
        treatment(current->elem, index);
        current = current->next;
        ++ index;
    }

    // Reset initial list if needed
    if (keepListOrder && hasBeenInverted)
        this->invertList();
}
