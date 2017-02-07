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
    void quickSort(ListNode *begin, ListNode *end) {
        if (begin == end || begin->next == end) return;
        auto p = partition(begin, end);
        quickSort(begin, p.first);
        quickSort(p.second, end);
    }
    
    pair<ListNode*, ListNode*> partition(ListNode *begin, ListNode *end) {
        int pivot = begin->val;
        ListNode *eqHead = begin, *eqTail = begin, *p = begin->next;
        while (p != end) {
            if (p->val <= pivot) {
                if (p->val < pivot) {
                    swap(eqHead->val, p->val);
                    eqHead = eqHead->next;
                }
                swap(p->val, eqTail->next->val);
                eqTail = eqTail->next;
            }
            p = p->next;
        }
        return make_pair(eqHead, eqTail->next);
    }
public:
    ListNode* sortList(ListNode* head) {
        quickSort(head, NULL);
        return head;
    }
};