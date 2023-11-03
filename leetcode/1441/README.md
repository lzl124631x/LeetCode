# [1441. Build an Array With Stack Operations (Medium)](https://leetcode.com/problems/build-an-array-with-stack-operations)

<p>You are given an integer array <code>target</code> and an integer <code>n</code>.</p>

<p>You have an empty stack with the two following operations:</p>

<ul>
	<li><strong><code>&quot;Push&quot;</code></strong>: pushes an integer to the top of the stack.</li>
	<li><strong><code>&quot;Pop&quot;</code></strong>: removes the integer on the top of the stack.</li>
</ul>

<p>You also have a stream of the integers in the range <code>[1, n]</code>.</p>

<p>Use the two stack operations to make the numbers in the stack (from the bottom to the top) equal to <code>target</code>. You should follow the following rules:</p>

<ul>
	<li>If the stream of the integers is not empty, pick the next integer from the stream and push it to the top of the stack.</li>
	<li>If the stack is not empty, pop the integer at the top of the stack.</li>
	<li>If, at any moment, the elements in the stack (from the bottom to the top) are equal to <code>target</code>, do not read new integers from the stream and do not do more operations on the stack.</li>
</ul>

<p>Return <em>the stack operations needed to build </em><code>target</code> following the mentioned rules. If there are multiple valid answers, return <strong>any of them</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> target = [1,3], n = 3
<strong>Output:</strong> [&quot;Push&quot;,&quot;Push&quot;,&quot;Pop&quot;,&quot;Push&quot;]
<strong>Explanation:</strong> Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Pop the integer on the top of the stack. s = [1].
Read 3 from the stream and push it to the stack. s = [1,3].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> target = [1,2,3], n = 3
<strong>Output:</strong> [&quot;Push&quot;,&quot;Push&quot;,&quot;Push&quot;]
<strong>Explanation:</strong> Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Read 3 from the stream and push it to the stack. s = [1,2,3].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> target = [1,2], n = 4
<strong>Output:</strong> [&quot;Push&quot;,&quot;Push&quot;]
<strong>Explanation:</strong> Initially the stack s is empty. The last element is the top of the stack.
Read 1 from the stream and push it to the stack. s = [1].
Read 2 from the stream and push it to the stack. s = [1,2].
Since the stack (from the bottom to the top) is equal to target, we stop the stack operations.
The answers that read integer 3 from the stream are not accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 100</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= target[i] &lt;= n</code></li>
	<li><code>target</code> is strictly increasing.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Stack](https://leetcode.com/tag/stack), [Simulation](https://leetcode.com/tag/simulation)

**Similar Questions**:
* [Minimum Operations to Collect Elements (Easy)](https://leetcode.com/problems/minimum-operations-to-collect-elements)

**Hints**:
* Use “Push” for numbers to be kept in target array and [“Push”, “Pop”] for numbers to be discarded.

## Solution 1.

We use `i` to scan from `1` to `n`, and `j` to scan each element in `A`.

For each `i`:
* if `i` doesn't exist in `A`, we push `"Push"` and `"Pop"` into the answer.
* if `i` exist in `A`, we push `"Push"` into the answer, and increment `j`.

We should break the loop once `j` reaches the end of `A`.

```cpp
// OJ: https://leetcode.com/problems/build-an-array-with-stack-operations/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space
class Solution {
public:
    vector<string> buildArray(vector<int>& A, int n) {
        vector<string> ans;
        int i = 1, j = 0;
        while (j < A.size()) {
            while (i != A[j]) {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++i;
            } 
            ans.push_back("Push");
            ++i;
            ++j;
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/build-an-array-with-stack-operations
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space
class Solution {
public:
    vector<string> buildArray(vector<int>& A, int n) {
        vector<string> ans;
        for (int i = 0, j = 1; j <= n && i < A.size(); ++j) {
            ans.push_back("Push");
            if (A[i] != j) ans.push_back("Pop");
            else ++i;
        }
        return ans;
    }
};
```