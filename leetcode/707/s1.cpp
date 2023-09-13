// OJ: https://leetcode.com/problems/design-linked-list/
// Author: github.com/lzl124631x
// Time:
//     get: O(N)
//     addAtHead: O(1)
//     addAtTail: O(1)
//     addAtIndex: O(N)
//     deleteAtIndex: O(N)
// Space: O(1)
class MyListNode {
public:
    int val;
    MyListNode *next = NULL;
    MyListNode(int v): val(v) {}
};

class MyLinkedList {
private:
    MyListNode dummy = MyListNode(0), *tail = &dummy;
    int len = 0;
public:
    MyLinkedList() {}
    
    int get(int index) {
        if (index >= len) return -1;
        auto p = dummy.next;
        while (index--) p = p->next;
        return p->val;
    }
    
    void addAtHead(int val) {
        auto node = new MyListNode(val);
        node->next = dummy.next;
        dummy.next = node;
        if (tail == &dummy) tail = node;
        ++len;
    }
    
    void addAtTail(int val) {
        tail->next = new MyListNode(val);
        tail = tail->next;
        ++len;
    }
    
    void addAtIndex(int index, int val) {
        if (index > len) return;
        auto node = new MyListNode(val);
        if (index == len) {
            tail->next = node;
            tail = node;
        } else {
            auto p = &dummy;
            while (index--) p = p->next;
            node->next = p->next;
            p->next = node;
        }
        ++len;
    }
    
    void deleteAtIndex(int index) {
        if (index >= len) return;
        auto p = &dummy;
        while (index--) p = p->next;
        auto node = p->next;
        p->next = node->next;
        if (tail == node) tail = p;
        delete node;
        --len;
    }
};