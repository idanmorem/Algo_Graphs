#ifndef ALGO_ADJACENTLIST_H
#define ALGO_ADJACENTLIST_H

class AdjacentList {
    class ListNode{
    private:
        int vertexValue;
        ListNode* next = nullptr;

    public:

        ListNode(int i_vertex){vertexValue = i_vertex;}

    };
private:
    ListNode* head;
    ListNode* tail;
public:
    AdjacentList() {
        head = nullptr;
        tail = nullptr;
    }
    ~AdjacentList() {}



};


#endif //ALGO_ADJACENTLIST_H
