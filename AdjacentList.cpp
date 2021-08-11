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

void AdjacentList::deleteNode(ListNode* previousNode)
{
    if(previousNode == nullptr)
        deleteFromBeginningOfList();
    else if(previousNode->getNext() == tail)
        deleteFromEndOfList(previousNode);
    else
        deleteFromInnerPlaceInList(previousNode);
}

void AdjacentList::deleteFromBeginningOfList()
{
    ListNode* nodeToDelete = head;
    head = head->getNext();
    delete nodeToDelete;
    if(head == nullptr)
        tail = nullptr;
}
void AdjacentList::deleteFromEndOfList(ListNode* previousNode)
{
    delete previousNode->getNext();
    tail = previousNode;
    previousNode->setNext(nullptr);
}
void AdjacentList::deleteFromInnerPlaceInList(ListNode* previousNode)
{
    ListNode* nodeToDelete = previousNode->getNext();

    previousNode->setNext(nodeToDelete->getNext());
    delete nodeToDelete;
}

