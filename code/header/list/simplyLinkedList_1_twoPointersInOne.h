/**
 * @def SimplyLinkedList_1_twoPointersInOne
 * @details Keeps the parent simply-linked list.
 * Each node n keeps a fictive address = Merge(n-1, n+1) where the Merge function:
 *     - is associative
 *     - is commutative
 *     - has as a neutral element (e.g. 0)
 *     - insures that Merge(x, x) = 0
 * Consequently, knowing the addresses of:
 *     - a given node at a position n (hence knowing Merge(n-1, n+1))
 *     - the address of its predecessor (respectively successor) n-1
 *  we are able to compute the address of its successor (respectively predecessor) n+1 as follows
 *     Merge(n, n-1)    = Merge(Merge(n-1, n+1), n-1)
 *                      = Merge(Merge(n+1, n-1), n-1)
 *                      = Merge(n+1, Merge(n-1, n-1))
 *                      = Merge(n+1, 0)
 *                      = n+1
 * @author Riyane
 * @date 26/09/2022
 */


#ifndef TEST_SIMPLYLINKEDLIST_1_TWOPOINTERSINONE_H
#define TEST_SIMPLYLINKEDLIST_1_TWOPOINTERSINONE_H

#include "simplyLinkedList.h"

#define Merge(ptrNodePrev, ptrNodeNext) (Node*)((uintptr_t)ptrNodePrev ^ (uintptr_t)ptrNodeNext)

class SimplyLinkedList_1_twoPointersInOne : public SimplyLinkedList
{
private:
    Node *listTail;

public:
    /**
     * @details Transforms the input list in the current list-class by setting in each node a single pointer merging the address of the previous and next node.
     */
    void setList(std::list<int> *l) override;

    /**
     * @def walk
     * @details Walks through the inner list in a single exploration O(N).
     * @param ordering indicates weather to walk through the list in a backward or forward manner.
     * @param treatment function that applies a user-defined treatment to its 2 inputs: an element of the list and its index.
     * @param keepListOrder not used.
     * @returns the number of element that have been parsed.
     */
    virtual unsigned long walk(
            ListOrdering ordering,
            bool keepListOrder,
            void (*treatment)(int, unsigned long)) override;

    bool isEqual(std::list<int> *l) override;
};

#endif //TEST_SIMPLYLINKEDLIST_1_TWOPOINTERSINONE_H
