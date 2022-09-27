#include "simplyLinkedList_0_orderRefactor.h"


unsigned long SimplyLinkedList_0_orderRefactor::walk(
        ListOrdering ordering,
        bool keepListOrder,
        void (*treatment)(int, unsigned long))
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
    Node* current = this->listHead;
    unsigned long index = 0;
    while (current != NULL)
    {
        treatment(current->elem, index);
        current = current->next;
        ++ index;
    }

    // Reset initial list if needed
    if (keepListOrder && hasBeenInverted)
        this->invertList();

    return index;
}

void SimplyLinkedList_0_orderRefactor::invertList()
{
    log("%s: Inverting the current list\n", __FILE_NAME__);

    Node* current = this->listHead;
    Node *previous = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    this->listHead = previous;

    if (this->listOrdering == forward)
        this->listOrdering = backward;
    else
        this->listOrdering = forward;
}

