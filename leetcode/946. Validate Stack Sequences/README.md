# [946. Validate Stack Sequences (Medium)](https://leetcode.com/problems/validate-stack-sequences/)

<p>Given two integer arrays <code>pushed</code> and <code>popped</code> each with distinct values, return <code>true</code><em> if this could have been the result of a sequence of push and pop operations on an initially empty stack, or </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
<strong>Output:</strong> true
<strong>Explanation:</strong> We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -&gt; 4,
push(5),
pop() -&gt; 5, pop() -&gt; 3, pop() -&gt; 2, pop() -&gt; 1
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
<strong>Output:</strong> false
<strong>Explanation:</strong> 1 cannot be popped before 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pushed.length &lt;= 1000</code></li>
	<li><code>0 &lt;= pushed[i] &lt;= 1000</code></li>
	<li>All the elements of <code>pushed</code> are <strong>unique</strong>.</li>
	<li><code>popped.length == pushed.length</code></li>
	<li><code>popped</code> is a permutation of <code>pushed</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [tiktok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Stack](https://leetcode.com/tag/stack/), [Simulation](https://leetcode.com/tag/simulation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/validate-stack-sequences/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int p = 0;
        for (int i : pushed) {
            s.push(i);
            while (s.size() && s.top() == popped[p]) {
                s.pop();
                ++p;
            }
        }
        return s.empty();
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/validate-stack-sequences/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space.
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int N = pushed.size(), i = 0, j = 0;
        for (int n : pushed) {
            pushed[i++] = n;
            while (i && pushed[i - 1] == popped[j]) --i, ++j;
        }
        return i == 0;
    }
};
```