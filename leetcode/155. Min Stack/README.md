# [155. Min Stack (Easy)](https://leetcode.com/problems/min-stack/)

<p>Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.</p>

<ul>
	<li>push(x) -- Push element x onto stack.</li>
	<li>pop() -- Removes the element on top of the stack.</li>
	<li>top() -- Get the top element.</li>
	<li>getMin() -- Retrieve the minimum element in the stack.</li>
</ul>

<p>&nbsp;</p>

<p><b>Example:</b></p>

<pre>MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --&gt; Returns -3.
minStack.pop();
minStack.top();      --&gt; Returns 0.
minStack.getMin();   --&gt; Returns -2.
</pre>

<p>&nbsp;</p>


**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Sliding Window Maximum (Hard)](https://leetcode.com/problems/sliding-window-maximum/)
* [Max Stack (Easy)](https://leetcode.com/problems/max-stack/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/min-stack/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(N)
class MinStack {
    stack<int> mn;
    stack<int> val;
public:
    MinStack() {}
    void push(int x) {
        val.push(x);
        if (mn.empty() || mn.top() >= x) mn.push(x);
    }
    void pop() {
        if (val.top() == mn.top()) mn.pop();
        val.pop();
    }
    int top() {
        return val.top();
    }
    int getMin() {
        return mn.top();
    }
};
```