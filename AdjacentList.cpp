#include "AdjacentList.h"


void AdjacentList::pushBack(ListNode* n) {
    if(!head )
    {
        head = n;
        tail = n;
        size++;
        return;
    }
    else
    {
        tail->setNext(n);
        tail = n;
        size++;
    }
}

AdjacentList::ListNode *AdjacentList::getHead() const {
    return head;
}


