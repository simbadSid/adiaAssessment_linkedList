/**
 * @def SimplyLinkedList_0_orderRefactor
 * @details Keeps the parent simply-linked list.
 * When an exploration is required with a way opposed to the current one, the list is inverted before the exploration.
 * @author Riyane
 * @date 26/09/2022
 */

#ifndef TEST_SIMPLYLINKEDLIST_0_ORDERREFACTOR_H
#define TEST_SIMPLYLINKEDLIST_0_ORDERREFACTOR_H

#include "simplyLinkedList.h"

class SimplyLinkedList_0_orderRefactor : public SimplyLinkedList
{
public:
    /**
     * @def walk
     * @details Refactors the inner simply-linked-list if the current order is not forward; then walks through the list.
     * @param ordering indicates weather to walk through the list in a backward or forward manner.
     * @param treatment function that applies a user-defined treatment to its 2 inputs: an element of the list and its index.
     * @param keepListOrder boolean indicating weather or not the current ordering of the list might be changed.
     * @returns the number of element that have been parsed.
     */
    virtual unsigned long walk(
        ListOrdering ordering,
        bool keepListOrder,
        void (*treatment)(int, unsigned long)) override;

private:
    void invertList();
};
#endif //TEST_SIMPLYLINKEDLIST_0_ORDERREFACTOR_H
