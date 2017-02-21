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
    ListNode *head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : head(head) {}
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *p = head->next;
        int cnt = 2, ans = head->val;
        while (p) {
            if (rand() % cnt == 0) ans = p->val;
            p = p->next;
            ++cnt;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */