# [382. Linked List Random Node (Medium)](https://leetcode.com/problems/linked-list-random-node/)

<p>Given a singly linked list, return a random node's value from the linked list. Each node must have the <strong>same probability</strong> of being chosen.</p>

<p>Implement the <code>Solution</code> class:</p>

<ul>
	<li><code>Solution(ListNode head)</code> Initializes the object with the integer array nums.</li>
	<li><code>int getRandom()</code> Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be choosen.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/16/getrand-linked-list.jpg" style="width: 302px; height: 62px;">
<pre><strong>Input</strong>
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
<strong>Output</strong>
[null, 1, 3, 2, 2, 3]

<strong>Explanation</strong>
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the linked list will be in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>4</sup> &lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>getRandom</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>What if the linked list is extremely large and its length is unknown to you?</li>
	<li>Could you solve this efficiently without using extra space?</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Math](https://leetcode.com/tag/math/), [Reservoir Sampling](https://leetcode.com/tag/reservoir-sampling/), [Randomized](https://leetcode.com/tag/randomized/)

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