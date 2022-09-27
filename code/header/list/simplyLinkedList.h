/**
 * @def SimplyLinkedList
 * @details Base class (abstract) of a simply-linked list implementation.
 *      Defines a simply-linked list, a pointer to the head  (or tail) of the list and a parameter defining the current ordering.
 * @author Riyane
 * @date 26/09/2022
 */

#ifndef ADIAASSESSMENT_LINKEDLIST_SIMPLYLINKEDLIST_H
#define ADIAASSESSMENT_LINKEDLIST_SIMPLYLINKEDLIST_H

#include <iostream>
#include <list>

#include "tools.h"


enum ListOrdering {forward, backward};

class Node
{
public:
    int elem;
    Node *next;

    Node(int elem);
    ~Node() = default;
};

void defaultTreatment(int element, unsigned long index);

class SimplyLinkedList
{
protected:
    Node *listHead;
    ListOrdering listOrdering = forward;
    unsigned long size;

public:
    virtual ~SimplyLinkedList() = default;
    /**
     * @details Transforms the input list in the current list-class
     */
    virtual void setList(std::list<int> *l);

    /**
     * @details Remove all the elements of the list
     */
    void clearList();


    /**
     * @def walk
     * @details Walks through the list from the first (respectively last) element to the last (respectively first) and applies the input function to each element.
     * @param ordering indicates weather to walk through the list in a backward or forward manner.
     * @param treatment function that applies a user-defined treatment to its 2 inputs: an element of the list and its index.
     * @param keepListOrder boolean indicating weather or not the current ordering of the list might be changed.
     * @returns the number of element that have been parsed.
     */
    virtual unsigned long walk(
            ListOrdering ordering,
            bool keepListOrder                      = false,
            void (*treatment)(int, unsigned long)   = defaultTreatment) = 0;

    /**
     * @details check weather the current list (forward order) is equal to the input one.
     */
    virtual bool isEqual(std::list<int> *l);

    unsigned long getSize() ;

};



#endif //ADIAASSESSMENT_LINKEDLIST_SIMPLYLINKEDLIST_H
