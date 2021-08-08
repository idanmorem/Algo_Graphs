#ifndef ALGO_ADJACENTLIST_H
#define ALGO_ADJACENTLIST_H


class AdjacentList {
public:
    class ListNode {
        int vertexValue;
        ListNode* next;
    public:
        void setVertexValue(int vertexValue) { ListNode::vertexValue = vertexValue; }
        void setNext(ListNode *next) { ListNode::next = next; }
        int getVal() const{ return vertexValue; };

    };
private:
    ListNode* head;
    ListNode* tail;
public:
    ListNode* CreateNode(int i_vertex){
        auto* n = new ListNode;
        n->setVertexValue(i_vertex);
        n->setNext(nullptr);
        return n;
    }

    AdjacentList() {
        head = nullptr;
        tail = nullptr;
    }
    ~AdjacentList() {}
    bool IsEmpty() const { if (head == nullptr) { return false;}}
    void pushBack(ListNode* n);
    int getTailVal(){ return tail->getVal(); };
};


#endif //ALGO_ADJACENTLIST_H
