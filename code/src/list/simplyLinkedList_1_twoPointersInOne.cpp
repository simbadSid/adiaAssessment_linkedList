#include "simplyLinkedList_1_twoPointersInOne.h"


void SimplyLinkedList_1_twoPointersInOne::setList(std::list<int> *l)
{
    log("%s: Instantiating a SimplyLinkedList_1_twoPointersInOne object (Ox%p) of size %u\n", __FILE__, this, l->size());

    this->listOrdering = forward;
    this->size = l->size();
    if (l->empty())
    {
        this->listHead = NULL;
        this->listTail = NULL;
    }
    else
    {
        typename std::list<int>::const_iterator it = l->begin();
        Node *current = new Node(*it);
        Node *previous = NULL;
        this->listHead = current;
        ++it;
        while(it != l->end())
        {
            Node *successor = new Node(*it);
            current->next = Merge(previous, successor);
            previous = current;
            current = successor;
            ++it;
        }

        current->next = Merge(previous, NULL);
        this->listTail = current;
    }
}

unsigned long SimplyLinkedList_1_twoPointersInOne::walk(
        ListOrdering ordering,
        bool keepListOrder,
        void (*treatment)(int, unsigned long))
{
    unsigned long index = 0;
    Node *current=NULL, *previous=NULL;

    if (ordering == forward)
        current = this->listHead;
    else
        current = this->listTail;

    while (current != NULL)
    {
        treatment(current->elem, index);
        Node *next = Merge(previous, current->next);
        previous = current;
        current = next;

        ++ index;
    }

    return index;
}

bool SimplyLinkedList_1_twoPointersInOne::isEqual(std::list<int> *l)
{
    if (this->size != l->size())
        return false;

    Node *current=this->listHead, *previous=NULL;

    typename std::list<int>::const_iterator it;
    for (it = l->begin(); it != l->end(); ++it)
    {
        if ((current == NULL) || (*it != current->elem))
            return false;
        Node *next = Merge(previous, current->next);
        previous = current;
        current = next;
    }

    return true;
}
