# [1640. Check Array Formation Through Concatenation (Easy)](https://leetcode.com/problems/check-array-formation-through-concatenation/)

<p>You are given an array of <strong>distinct</strong> integers <code>arr</code> and an array of integer arrays <code>pieces</code>, where the integers in <code>pieces</code> are <strong>distinct</strong>. Your goal is to form <code>arr</code> by concatenating the arrays in <code>pieces</code> <strong>in any order</strong>. However, you are <strong>not</strong> allowed to reorder the integers in each array <code>pieces[i]</code>.</p>

<p>Return <code>true</code> <em>if it is possible </em><em>to form the array </em><code>arr</code><em> from </em><code>pieces</code>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [85], pieces = [[85]]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [15,88], pieces = [[88],[15]]
<strong>Output:</strong> true
<strong>Explanation:</strong> Concatenate <code>[15]</code> then <code>[88]</code>
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [49,18,16], pieces = [[16,18,49]]
<strong>Output:</strong> false
<strong>Explanation:</strong> Even though the numbers match, we cannot reorder pieces[0].
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
<strong>Output:</strong> true
<strong>Explanation:</strong> Concatenate <code>[91]</code> then <code>[4,64]</code> then <code>[78]</code></pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> arr = [1,3,5,7], pieces = [[2,4,6,8]]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pieces.length &lt;= arr.length &lt;= 100</code></li>
	<li><code>sum(pieces[i].length) == arr.length</code></li>
	<li><code>1 &lt;= pieces[i].length &lt;= arr.length</code></li>
	<li><code>1 &lt;= arr[i], pieces[i][j] &lt;= 100</code></li>
	<li>The integers in&nbsp;<code>arr</code>&nbsp;are <strong>distinct</strong>.</li>
	<li>The integers in&nbsp;<code>pieces</code> are <strong>distinct</strong>&nbsp;(i.e., If we flatten pieces in a 1D array, all the integers in this array are distinct).</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/check-array-formation-through-concatenation/
// Author: github.com/lzl124631x
// Time: O(AP)
// Space: O(1)
class Solution {
public:
    bool canFormArray(vector<int>& A, vector<vector<int>>& P) {
        for (int i = 0 ; i < A.size(); ) {
            int j = 0;
            for (; j < P.size(); ++j) {
                if (P[j][0] == A[i]) break;
            }
            if (j == P.size()) return false;
            for (int k = 0; k < P[j].size(); ++k) {
                if (A[i] != P[j][k]) return false;
                ++i;
            }
        }
        return true;
    }
};
```