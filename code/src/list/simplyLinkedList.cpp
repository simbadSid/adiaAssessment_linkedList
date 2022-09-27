#include "simplyLinkedList.h"

#include <iostream>
#include <list>

Node::Node(int elem)
{
    this->elem = elem;
    this->next = NULL;
}

void defaultTreatment(int element, unsigned index)
{
    log("\t- Treating element[%u] %d\n", index, element);
}

void SimplyLinkedList::setList(std::list<int> *l)
{
    log("%s: Instantiating a SimplyLinkedList object (Ox%p) of size %u\n", __FILE_NAME__, this, l->size());
    if (l->empty())
    {
        this->list = NULL;
    }
    else
    {
        typename std::list<int>::const_iterator it = l->begin();
        this->list = new Node(*it);
        ++it;
        Node *currentNode = this->list;

        for (; it != l->end(); ++it)
        {
            currentNode->next = new Node(*it);
            currentNode = currentNode->next;
        }
    }
}


void SimplyLinkedList::clearList()
{
    log("%s: Cleaning a SimplyLinkedList object (Ox%p)\n", __FILE_NAME__, this);

    while (this->list != NULL)
    {
        Node *tmp = this->list;
        this->list = this->list->next;
        delete tmp;
    }
}

bool SimplyLinkedList::isEqual(std::list<int> *l)
{
    Node *currentNode = this->list;

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
        for (it = l->rbegin(); it != l->rend(); ++it) {
            if ((currentNode == NULL) || (*it != currentNode->elem))
                return true;
            currentNode = currentNode->next;
        }
    }

    return true;
}

void SimplyLinkedList::invertList()
{
    log("%s: Inverting the current list\n", __FILE_NAME__);

    Node* current = this->list;
    Node *previous = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    this->list = previous;

    if (this->listOrdering == forward)
        this->listOrdering = backward;
    else
        this->listOrdering = forward;
}
