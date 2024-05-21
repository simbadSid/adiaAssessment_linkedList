#include "simplyLinkedList.h"

#include <iostream>
#include <list>

Node::Node(int elem)
{
    this->elem = elem;
    this->next = NULL;
}

void defaultTreatment(int element, unsigned long index)
{
    log("\t- Treating element[%ul] %d\n", index, element);
}

void SimplyLinkedList::setList(std::list<int> *l)
{
    log("%s: Instantiating a SimplyLinkedList object (Ox%p) of size %u\n", __FILE__, this, l->size());

    this->listOrdering = forward;
    this->size = l->size();
    if (l->empty())
    {
        this->listHead = NULL;
    }
    else
    {
        typename std::list<int>::const_iterator it = l->begin();
        this->listHead = new Node(*it);
        ++it;
        Node *currentNode = this->listHead;

        for (; it != l->end(); ++it)
        {
            currentNode->next = new Node(*it);
            currentNode = currentNode->next;
        }
    }
}


void SimplyLinkedList::clearList()
{
    log("%s: Cleaning a SimplyLinkedList object (Ox%p)\n", __FILE__, this);

    while (this->listHead != NULL)
    {
        Node *tmp = this->listHead;
        this->listHead = this->listHead->next;
        delete tmp;
    }
    this->size = 0;
}

bool SimplyLinkedList::isEqual(std::list<int> *l)
{
    if (this->size != l->size())
        return false;

    Node *currentNode = this->listHead;

    if (this->listOrdering == forward)
    {
        typename std::list<int>::const_iterator it;
        for (it = l->begin(); it != l->end(); ++it)
        {
            if ((currentNode == NULL) || (*it != currentNode->elem))
                return false;
            currentNode = currentNode->next;
        }
    }
    else
    {
        typename std::list<int>::reverse_iterator it;
        for (it = l->rbegin(); it != l->rend(); ++it)
        {
            if ((currentNode == NULL) || (*it != currentNode->elem))
                return false;
            currentNode = currentNode->next;
        }
    }

    return true;
}

unsigned long SimplyLinkedList::getSize()
{
    return this->size;
}

