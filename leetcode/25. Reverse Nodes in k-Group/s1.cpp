/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    bool splitAtK(ListNode *head, int k, ListNode *&nextHead) {
        while (--k && head) head = head->next;
        if (!head) return false;
        nextHead = head->next;
        head->next = NULL;
        return true;
    }
    pair<ListNode*, ListNode*> reverseList(ListNode *head) {
        ListNode dummy(0), *tail = NULL;
        while (head) {
            ListNode *p = head;
            head = head->next;
            if (!tail) tail = p;
            p->next = dummy.next;
            dummy.next = p;
        }
        return { dummy.next, tail };
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *nextHead, dummy(0), *tail = &dummy;
        while (splitAtK(head, k, nextHead)) {
            auto p = reverseList(head);
            tail->next = p.first;
            tail = p.second;
            head = nextHead;
        }
        tail->next = head;
        return dummy.next;
    }
};