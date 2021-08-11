#ifndef ALGO_ADJACENTLIST_H
#define ALGO_ADJACENTLIST_H


class AdjacentList {

public:
    class ListNode { // maybe we should use it as a struct
        int vertexValue;
        ListNode* next;

    public:
        void setVertexValue(int vertexValue) { ListNode::vertexValue = vertexValue; }
        void setNext(ListNode *next) { ListNode::next = next; }
        int getVal() const{ return vertexValue; };
        ListNode *getNext() const { return next;};

    };

private:
    ListNode* head;
    ListNode* tail;
    int size;

public:

    ListNode* CreateNode(int i_vertex){
        auto* n = new ListNode;
        n->setVertexValue(i_vertex);
        n->setNext(nullptr);
        return n;
    }

    // Constructor
    AdjacentList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    // Destructor
    ~AdjacentList() {
        ListNode* curr = head;
        ListNode* next ;
        while( curr != nullptr )
        {
            next = curr->getNext();
            delete curr;
            curr = next;
        }
    }
    bool IsEmpty() const { if (head == nullptr) { return false;}}
    void pushBack(ListNode* n);
    int getTailVal(){ return tail->getVal(); };
    ListNode *getHead() const;
    void deleteNode(ListNode* previousNode);
    void deleteFromBeginningOfList();
    void deleteFromEndOfList(ListNode* previousNode);
    void deleteFromInnerPlaceInList(ListNode* previousNode);
};


#endif //ALGO_ADJACENTLIST_H
