# [2337. Move Pieces to Obtain a String (Medium)](https://leetcode.com/problems/move-pieces-to-obtain-a-string)

<p>You are given two strings <code>start</code> and <code>target</code>, both of length <code>n</code>. Each string consists <strong>only</strong> of the characters <code>'L'</code>, <code>'R'</code>, and <code>'_'</code> where:</p>
<ul>
	<li>The characters <code>'L'</code> and <code>'R'</code> represent pieces, where a piece <code>'L'</code> can move to the <strong>left</strong> only if there is a <strong>blank</strong> space directly to its left, and a piece <code>'R'</code> can move to the <strong>right</strong> only if there is a <strong>blank</strong> space directly to its right.</li>
	<li>The character <code>'_'</code> represents a blank space that can be occupied by <strong>any</strong> of the <code>'L'</code> or <code>'R'</code> pieces.</li>
</ul>
<p>Return <code>true</code> <em>if it is possible to obtain the string</em> <code>target</code><em> by moving the pieces of the string </em><code>start</code><em> <strong>any</strong> number of times</em>. Otherwise, return <code>false</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> start = "_L__R__R_", target = "L______RR"
<strong>Output:</strong> true
<strong>Explanation:</strong> We can obtain the string target from start by doing the following moves:
- Move the first piece one step to the left, start becomes equal to "<strong>L</strong>___R__R_".
- Move the last piece one step to the right, start becomes equal to "L___R___<strong>R</strong>".
- Move the second piece three steps to the right, start becomes equal to "L______<strong>R</strong>R".
Since it is possible to get the string target from start, we return true.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> start = "R_L_", target = "__LR"
<strong>Output:</strong> false
<strong>Explanation:</strong> The 'R' piece in the string start can move one step to the right to obtain "_<strong>R</strong>L_".
After that, no pieces can move anymore, so it is impossible to obtain the string target from start.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> start = "_R", target = "R_"
<strong>Output:</strong> false
<strong>Explanation:</strong> The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == start.length == target.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>start</code> and <code>target</code> consist of the characters <code>'L'</code>, <code>'R'</code>, and <code>'_'</code>.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Valid Parentheses (Easy)](https://leetcode.com/problems/valid-parentheses/)
* [Swap Adjacent in LR String (Medium)](https://leetcode.com/problems/swap-adjacent-in-lr-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/move-pieces-to-obtain-a-string
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canChange(string A, string B) {
        int i = 0, j = 0, N = A.size();
        for (; i < N; ++i) {
            if (A[i] == '_') continue;
            while (j < N && B[j] == '_') ++j;
            if (j == N || A[i] != B[j] || (A[i] == 'L' && j > i) || (A[i] == 'R' && j < i)) return false;
            ++j;
        }
        while (j < N && B[j] == '_') ++j;
        return j == N;
    }
};
```