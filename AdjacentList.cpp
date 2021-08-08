#include "AdjacentList.h"


void AdjacentList::pushBack(ListNode* n) {
    if(!head )
    {
        head = n;
        return;
    }
    else
    {
        tail->setNext(n);
        tail = n;
    }
}


