# [1381. Design a Stack With Increment Operation (Medium)](https://leetcode.com/problems/design-a-stack-with-increment-operation/)

<p>Design a stack which supports the following operations.</p>

<p>Implement the <code>CustomStack</code> class:</p>

<ul>
	<li><code>CustomStack(int maxSize)</code> Initializes the object with <code>maxSize</code> which is the maximum number of elements in the stack or do nothing if the stack reached the <code>maxSize</code>.</li>
	<li><code>void push(int x)</code>&nbsp;Adds <code>x</code> to the top of the stack if the stack hasn't reached the <code>maxSize</code>.</li>
	<li><code>int pop()</code>&nbsp;Pops and returns the top of stack or <strong>-1</strong> if the stack is empty.</li>
	<li><code>void inc(int k, int val)</code> Increments the bottom <code>k</code> elements of the stack by <code>val</code>. If there are less than <code>k</code> elements in the stack, just increment all the elements in the stack.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
<strong>Output</strong>
[null,null,null,2,null,null,null,null,null,103,202,201,-1]
<strong>Explanation</strong>
CustomStack customStack = new CustomStack(3); // Stack is Empty []
customStack.push(1);                          // stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
customStack.pop();                            // return 2 --&gt; Return top of the stack 2, stack becomes [1]
customStack.push(2);                          // stack becomes [1, 2]
customStack.push(3);                          // stack becomes [1, 2, 3]
customStack.push(4);                          // stack still [1, 2, 3], Don't add another elements as size is 4
customStack.increment(5, 100);                // stack becomes [101, 102, 103]
customStack.increment(2, 100);                // stack becomes [201, 202, 103]
customStack.pop();                            // return 103 --&gt; Return top of the stack 103, stack becomes [201, 202]
customStack.pop();                            // return 202 --&gt; Return top of the stack 102, stack becomes [201]
customStack.pop();                            // return 201 --&gt; Return top of the stack 101, stack becomes []
customStack.pop();                            // return -1 --&gt; Stack is empty return -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= maxSize &lt;= 1000</code></li>
	<li><code>1 &lt;= x &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li><code>0 &lt;= val &lt;= 100</code></li>
	<li>At most&nbsp;<code>1000</code>&nbsp;calls will be made to each method of <code>increment</code>, <code>push</code> and <code>pop</code> each separately.</li>
</ul>

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/), [Design](https://leetcode.com/tag/design/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/design-a-stack-with-increment-operation/
// Author: github.com/lzl124631x
// Time:
//      CustomStack, push, pop: O(1)
//      increment: O(k)
// Space: O(N)
class CustomStack {
    int N;
    vector<int> v;
public:
    CustomStack(int maxSize): N(maxSize) {}
    void push(int x) {
        if (v.size() >= N) return;
        v.push_back(x);
    }
    int pop() {
        if (v.empty()) return -1;
        int n = v.back();
        v.pop_back();
        return n;
    }
    void increment(int k, int val) {
        k = min(k, (int)v.size());
        for (int i = 0; i < k; ++i) v[i] += val;
    }
};
```

## Solution 2. Lazy Propogation

```cpp
// OJ: https://leetcode.com/problems/design-a-stack-with-increment-operation/
// Author: github.com/lzl124631x
// Time:
//      CustomStack: O(N)
//      push, pop, increment: O(1)
// Space: O(N)
// Ref: https://leetcode.com/problems/design-a-stack-with-increment-operation/discuss/539716/JavaC%2B%2BPython-Lazy-increment-O(1)
class CustomStack {
    stack<int> s;
    vector<int> update;
public:
    CustomStack(int maxSize) : update(maxSize) {}
    
    void push(int x) {
        if (s.size() == update.size()) return;
        s.push(x);
    }
    
    int pop() {
        if (s.empty()) return -1;
        int ans = s.top(), index = s.size() - 1;
        s.pop();
        ans += update[index];
        if (index - 1 >= 0) update[index - 1] += update[index];
        update[index] = 0;
        return ans;
    }
    
    void increment(int k, int val) {
        k = min(k, (int)s.size()) - 1;
        if (k >= 0) update[k] += val;
    }
};
```