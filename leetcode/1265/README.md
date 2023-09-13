# [1265. Print Immutable Linked List in Reverse (Medium)](https://leetcode.com/problems/print-immutable-linked-list-in-reverse/)

<p>You are given an immutable linked list, print out all values of each node in reverse with the help of the following&nbsp;interface:</p>

<ul>
	<li><code>ImmutableListNode</code>:&nbsp;An interface of immutable linked list, you are given the head of the list.</li>
</ul>

<p>You need to use the following functions to access the linked list (you <strong>can't</strong> access the <code>ImmutableListNode</code> directly):</p>

<ul>
	<li><code>ImmutableListNode.printValue()</code>: Print value of the current node.</li>
	<li><code>ImmutableListNode.getNext()</code>: Return the next node.</li>
</ul>

<p>The input is only given to initialize the linked list internally.&nbsp;You must solve this problem without modifying the linked list. In other words, you must operate&nbsp;the linked list using only the mentioned&nbsp;APIs.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> head = [1,2,3,4]
<strong>Output:</strong> [4,3,2,1]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> head = [0,-4,-1,3,-5]
<strong>Output:</strong> [-5,3,-1,-4,0]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> head = [-2,0,6,4,4,-6]
<strong>Output:</strong> [-6,4,4,6,0,-2]
</pre>

<ul>
</ul>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The length of the linked list&nbsp;is between <code>[1, 1000]</code>.</li>
	<li>The value of each&nbsp;node in the linked list&nbsp;is between <code>[-1000, 1000]</code>.</li>
</ul>

<p>&nbsp;</p>

<p><strong>Follow up:</strong></p>

<p>Could you solve this problem in:</p>

<ul>
	<li>Constant space complexity?</li>
	<li>Linear time complexity and less than linear space complexity?</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Stack](https://leetcode.com/tag/stack/), [Recursion](https://leetcode.com/tag/recursion/)

## Solution 1. Recursion

```cpp
// OJ: https://leetcode.com/problems/print-immutable-linked-list-in-reverse/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (!head) return;
        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};
```

## Solution 2. Brute force

```cpp
// OJ: https://leetcode.com/problems/print-immutable-linked-list-in-reverse/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        ImmutableListNode* last = NULL;
        while (last != head) {
            auto p = head;
            while (p->getNext() != last) p = p->getNext(); 
            p->printValue();
            last = p;
        }
    }
};
```

## Solution 3. Sqrt Decomposition

We break the list into batches, each of which is of length `sqrt(N)`. We store all heads of batches in a stack. After the stack is filled, we start popping the stack, and for each popped head, we use the recursive print method in Solution 1 to print this batch.

### Complexity Analysis

`getLength` takes `O(N)` time and `O(1)` space.

Filling the stack takes `O(N)` time and `O(sqrt(N))` space.

Printing each batch takes `O(sqrt(N))` time and `O(sqrt(N))` space. Because there are `sqrt(N)` batches, this popping stack and printing step takes `O(sqrt(N) * sqrt(N)) = O(N)` time and `O(sqrt(N))` space (the space doesn't add up).

```cpp
// OJ: https://leetcode.com/problems/print-immutable-linked-list-in-reverse/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(sqrt(N))
class Solution {
    int getLength(ImmutableListNode *head) {
        int ans = 0;
        for (; head; head = head->getNext(), ++ans);
        return ans;
    }
    void print(ImmutableListNode *head, int len) {
        if (!head || !len) return;
        print(head->getNext(), len - 1);
        head->printValue();
    }
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        int len = ceil(sqrt(getLength(head)));
        stack<ImmutableListNode*> s;
        for (int i = 0; head; head = head->getNext(), ++i) {
            if (i % len == 0) s.push(head);
        }
        while (s.size()) {
            print(s.top(), len);
            s.pop();
        }
    }
};
```