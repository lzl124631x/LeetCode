# [944. Delete Columns to Make Sorted (Easy)](https://leetcode.com/problems/delete-columns-to-make-sorted)

<p>We are given an array&nbsp;<code>A</code> of <code>N</code> lowercase letter strings, all of the same length.</p>

<p>Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.&nbsp; The remaining rows of strings form columns when read north to south.</p>

<p>For example, if we have an array <code>A = ["</code><code>abcdef</code><code>","uvwxyz"]</code> and deletion indices <code>{0, 2, 3}</code>, then the final array after deletions is <code>["</code><code>bef</code><code>"</code><code>,"</code><code>vyz</code><code>"]</code>,&nbsp;and the remaining columns of <code>A</code> are&nbsp;<code>["b"</code><code>,"</code><code>v"]</code>, <code>["e","y"]</code>, and <code>["f","z"]</code>.&nbsp; (Formally, the <code>c</code>-th column is <code>[A[0][c], A[1][c], ..., A[A.length-1][c]]</code>.)</p>

<p>Suppose we chose a set of deletion indices <code>D</code> such that after deletions, each remaining column in A is in <strong>non-decreasing</strong> sorted order.</p>

<p>Return the minimum possible value of <code>D.length</code>.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["cba","daf","ghi"]</span>
<strong>Output: </strong><span id="example-output-1">1</span>
<strong>Explanation: </strong>
After choosing D = {1}, each column ["c","d","g"] and ["a","f","i"] are in non-decreasing sorted order.
If we chose D = {}, then a column ["b","a","h"] would not be in non-decreasing sorted order.
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">["a","b"]</span>
<strong>Output: </strong><span id="example-output-2">0</span>
<strong>Explanation: </strong>D = {}
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">["zyx","wvu","tsr"]</span>
<strong>Output: </strong><span id="example-output-3">3</span>
<strong>Explanation: </strong>D = {0, 1, 2}
</pre>

<p>&nbsp;</p>

<p><strong><span>Note:</span></strong></p>

<ol>
	<li><code>1 &lt;= A.length &lt;= 100</code></li>
	<li><code>1 &lt;= A[i].length &lt;= 1000</code></li>
</ol>
</div>
</div>
</div>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/delete-columns-to-make-sorted
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(1)
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            int j = 1;
            for (; j < M && A[j][i] >= A[j - 1][i]; ++j);
            if (j < M) ans++;
        }
        return ans;
    }
};
```