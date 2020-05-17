# [225. Implement Stack using Queues (Easy)](https://leetcode.com/problems/implement-stack-using-queues/)

<p>Implement the following operations of a stack using queues.</p>

<ul>
	<li>push(x) -- Push element x onto stack.</li>
	<li>pop() -- Removes the element on top of the stack.</li>
	<li>top() -- Get the top element.</li>
	<li>empty() -- Return whether the stack is empty.</li>
</ul>

<p><b>Example:</b></p>

<pre>MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false</pre>

<p><b>Notes:</b></p>

<ul>
	<li>You must use <i>only</i> standard operations of a queue -- which means only <code>push to back</code>, <code>peek/pop from front</code>, <code>size</code>, and <code>is empty</code> operations are valid.</li>
	<li>Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.</li>
	<li>You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).</li>
</ul>


**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Implement Queue using Stacks (Easy)](https://leetcode.com/problems/implement-queue-using-stacks/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/implement-stack-using-queues
// Author: github.com/lzl124631x
// Time: O(N) for push, O(1) for others
// Space: O(1)
class MyStack {
private:
  queue<int> q;
public:
  MyStack() {}
  void push(int x) {
    q.push(x);
    for (int i = 0; i < q.size() - 1; ++i) {
      q.push(q.front());
      q.pop();
    }
  }
  int pop() {
    int val = q.front();
    q.pop();
    return val;
  }
  int top() {
    return q.front();
  }
  bool empty() {
    return q.empty();
  }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/implement-stack-using-queues/
// Author: github.com/lzl124631x
// Time: O(N) for pop, O(1) for others
// Space: O(1)
class MyStack {
    queue<int> q;
    int t;
public:
    MyStack() {}
    void push(int x) {
        q.push(x);
        t = x;
    }
    int pop() {
        int n = q.size();
        while (--n) {
            int val = q.front();
            if (n == 1) t = val;
            q.push(val);
            q.pop();
        }
        int val = q.front();
        q.pop();
        return val;
    }
    int top() {
        return t;
    }
    bool empty() {
        return !q.size();
    }
};
```