# [382. Linked List Random Node (Medium)](https://leetcode.com/problems/linked-list-random-node/)

<p>Given a singly linked list, return a random node's value from the linked list. Each node must have the <b>same probability</b> of being chosen.</p>

<p><b>Follow up:</b><br>
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?
</p>

<p><b>Example:</b>
</p><pre>// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
</pre>
<p></p>

**Related Topics**:  
[Reservoir Sampling](https://leetcode.com/tag/reservoir-sampling/)

**Similar Questions**:
* [Random Pick Index (Medium)](https://leetcode.com/problems/random-pick-index/)

## Solution 1. Fixed-range Sampling

```cpp
// OJ: https://leetcode.com/problems/linked-list-random-node/
// Author: github.com/lzl124631x
// Time: O(N) for both
// Space: O(1)
class Solution {
    ListNode *h;
    int len = 0;
public:
    Solution(ListNode* head) : h(head) {
        for (; head; ++len) head = head->next;
    }
    int getRandom() {
        auto p = h;
        for (int k = rand() % len; k-- > 0; p = p->next);
        return p->val;
    }
};
```

## Solution 2. Reservoir Sampling

When we don't know the length, we can use Reservoir Sampling.

When we visit the `i`th element, we pick it with probability `1 / (i + 1)`.

For example, when we visit `0`th element, we pick it with probablity `1`. When we visit the `1`th element, we pick it with probability `1/2`.

In this way, each element has the same probability of being chosen.

For the `0`th element, the probability of being chosen is `1 * 1/2 * 2/3 * 3/4 * ... * (N-1)/N = 1/N`.

For the `1`th element, the probability of being chosen is `1/2 * 2/3 * 3/4 * ... * (N-1)/N = 1/N`.

For the `2`th element, the probability of being chosen is `1/3 * 3/4 * ... * (N-1)/N = 1/N`.

...

```cpp
// OJ: https://leetcode.com/problems/linked-list-random-node/
// Author: github.com/lzl124631x
// Time:
//      Solution: O(1)
//      getRandom: O(N)
// Space: O(1)
class Solution {
    ListNode *head;
public:
    Solution(ListNode* head) : head(head) {}
    int getRandom() {
        int base = 1;
        auto p = head, ans = head;
        while (p) {
            int r = rand() % base;
            if (r == 0) ans = p;
            base++;
            p = p->next;
        }
        return ans->val;
    }
};
```