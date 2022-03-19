# [895. Maximum Frequency Stack (Hard)](https://leetcode.com/problems/maximum-frequency-stack/)

<p>Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.</p>

<p>Implement the <code>FreqStack</code> class:</p>

<ul>
	<li><code>FreqStack()</code> constructs an empty frequency stack.</li>
	<li><code>void push(int val)</code> pushes an integer <code>val</code> onto the top of the stack.</li>
	<li><code>int pop()</code> removes and returns the most frequent element in the stack.
	<ul>
		<li>If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
<strong>Output</strong>
[null, null, null, null, null, null, null, 5, 7, 5, 4]

<strong>Explanation</strong>
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= val &lt;= 10<sup>9</sup></code></li>
	<li>At most <code>2 * 10<sup>4</sup></code> calls will be made to <code>push</code> and <code>pop</code>.</li>
	<li>It is guaranteed that there will be at least one element in the stack before calling <code>pop</code>.</li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Stack](https://leetcode.com/tag/stack/)

## Solution 1.

We push elements based on frequency first then the order they pushed into the stack.

Consider input `5 7 5 7 4 5`, if we label their frequency at the top

```
1 1 2 2 1 3
5 7 5 7 4 5
```

We can reorder them in this way

```
1: 5 7 4
2: 5 7
3: 5
```

When popping elements, we pop the 3rd stack first, then the 2nd, then the 1st.

```cpp
// OJ: https://leetcode.com/problems/maximum-frequency-stack/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(N)
class FreqStack {
    unordered_map<int, int> freq; // number -> frequency
    vector<vector<int>> v; // frequency -> stack of numbers
public:
    FreqStack() {}
    void push(int val) {
        int f = freq[val]++;
        if (v.size() <= f) v.emplace_back();
        v[f].push_back(val);
    }
    int pop() {
        int val = v.back().back();
        v.back().pop_back();
        --freq[val];
        if (v.back().empty()) v.pop_back();
        return val;
    }
};
```