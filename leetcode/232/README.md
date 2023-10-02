# [232. Implement Queue using Stacks (Easy)](https://leetcode.com/problems/implement-queue-using-stacks/)

<p>Implement the following operations of a queue using stacks.</p>

<ul>
	<li>push(x) -- Push element x to the back of queue.</li>
	<li>pop() -- Removes the element from in front of queue.</li>
	<li>peek() -- Get the front element.</li>
	<li>empty() -- Return whether the queue is empty.</li>
</ul>

<p><b>Example:</b></p>

<pre>MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false</pre>

<p><b>Notes:</b></p>

<ul>
	<li>You must use <i>only</i> standard operations of a stack -- which means only <code>push to top</code>, <code>peek/pop from top</code>, <code>size</code>, and <code>is empty</code> operations are valid.</li>
	<li>Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.</li>
	<li>You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).</li>
</ul>


**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Implement Stack using Queues (Easy)](https://leetcode.com/problems/implement-stack-using-queues/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/implement-queue-using-stacks
// Author: github.com/lzl124631x
// Time: O(1) amortized.
// Space: O(1)
class MyQueue {
    stack<int> in, out;
public:
    MyQueue() {}
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int val = peek();
        out.pop();
        return val;
    }
    
    int peek() {
        if (out.empty()) {
            while (in.size()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};
```