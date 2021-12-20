# [716. Max Stack (Easy)](https://leetcode.com/problems/max-stack/)

<p>Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.</p>

<p>Implement the <code>MaxStack</code> class:</p>

<ul>
	<li><code>MaxStack()</code> Initializes the stack object.</li>
	<li><code>void push(int x)</code> Pushes element <code>x</code> onto the stack.</li>
	<li><code>int pop()</code> Removes the element on top of the stack and returns it.</li>
	<li><code>int top()</code> Gets the element on the top of the stack without removing it.</li>
	<li><code>int peekMax()</code> Retrieves the maximum element in the stack without removing it.</li>
	<li><code>int popMax()</code> Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the <strong>top-most</strong> one.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["MaxStack", "push", "push", "push", "top", "popMax", "top", "peekMax", "pop", "top"]
[[], [5], [1], [5], [], [], [], [], [], []]
<strong>Output</strong>
[null, null, null, null, 5, 5, 1, 5, 1, 5]

<strong>Explanation</strong>
MaxStack stk = new MaxStack();
stk.push(5);   // [<strong><u>5</u></strong>] the top of the stack and the maximum number is 5.
stk.push(1);   // [<u>5</u>, <strong>1</strong>] the top of the stack is 1, but the maximum is 5.
stk.push(5);   // [5, 1, <strong><u>5</u></strong>] the top of the stack is 5, which is also the maximum, because it is the top most one.
stk.top();     // return 5, [5, 1, <strong><u>5</u></strong>] the stack did not change.
stk.popMax();  // return 5, [<u>5</u>, <strong>1</strong>] the stack is changed now, and the top is different from the max.
stk.top();     // return 1, [<u>5</u>, <strong>1</strong>] the stack did not change.
stk.peekMax(); // return 5, [<u>5</u>, <strong>1</strong>] the stack did not change.
stk.pop();     // return 1, [<strong><u>5</u></strong>] the top of the stack and the max element is now 5.
stk.top();     // return 5, [<strong><u>5</u></strong>] the stack did not change.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>7</sup> &lt;= x &lt;= 10<sup>7</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>push</code>, <code>pop</code>, <code>top</code>, <code>peekMax</code>, and <code>popMax</code>.</li>
	<li>There will be <strong>at least one element</strong> in the stack when <code>pop</code>, <code>top</code>, <code>peekMax</code>, or <code>popMax</code> is called.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you come up with a solution that supports <code>O(1)</code> for each <code>top</code> call and <code>O(logn)</code> for each other call?&nbsp;

**Companies**:  
[LinkedIn](https://leetcode.com/company/linkedin), [Microsoft](https://leetcode.com/company/microsoft), [Lyft](https://leetcode.com/company/lyft), [Facebook](https://leetcode.com/company/facebook), [Yandex](https://leetcode.com/company/yandex)

**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Stack](https://leetcode.com/tag/stack/), [Design](https://leetcode.com/tag/design/), [Doubly-Linked List](https://leetcode.com/tag/doubly-linked-list/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

**Similar Questions**:
* [Min Stack (Easy)](https://leetcode.com/problems/min-stack/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/max-stack/
// Author: github.com/lzl124631x
// Time:
//      MaxStack, top, peekMax: O(1)
//      push: log(N)
//      pop, popMax: O(logN) amortized
// Space: O(N)
class MaxStack {
    map<int, vector<int>> m;
    vector<int> v;
    void pop(int n) {
        int i = m[n].back();
        v[i] = INT_MIN;
        m[n].pop_back();
        if (m[n].empty()) m.erase(n);
        while (v.size() && v.back() == INT_MIN) v.pop_back();
    }
public:
    MaxStack() {}
    void push(int x) {
        m[x].push_back(v.size());
        v.push_back(x);
    }
    int pop() {
        int n = v.back();
        pop(n);
        return n;
    }
    int top() {
        return v.back();
    }
    int peekMax() {
        return m.rbegin()->first;
    }
    int popMax() {
        int n = peekMax();
        pop(n);
        return n;
    }
};
```