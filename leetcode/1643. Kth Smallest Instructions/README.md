# [1643. Kth Smallest Instructions (Hard)](https://leetcode.com/problems/kth-smallest-instructions/)

<p>Bob is standing at cell <code>(0, 0)</code>, and he wants to reach <code>destination</code>: <code>(row, column)</code>. He can only travel <strong>right</strong> and <strong>down</strong>. You are going to help Bob by providing <strong>instructions</strong> for him to reach <code>destination</code>.</p>

<p>The <strong>instructions</strong> are represented as a string, where each character is either:</p>

<ul>
	<li><code>'H'</code>, meaning move horizontally (go <strong>right</strong>), or</li>
	<li><code>'V'</code>, meaning move vertically (go <strong>down</strong>).</li>
</ul>

<p>Multiple <strong>instructions</strong> will lead Bob to <code>destination</code>. For example, if <code>destination</code> is <code>(2, 3)</code>, both <code>"HHHVV"</code> and <code>"HVHVH"</code> are valid <strong>instructions</strong>.</p>

<ul>
</ul>

<p>However, Bob is very picky. Bob has a lucky number <code>k</code>, and he wants the <code>k<sup>th</sup></code> <strong>lexicographically smallest instructions</strong> that will lead him to <code>destination</code>. <code>k</code> is <strong>1-indexed</strong>.</p>

<p>Given an integer array <code>destination</code> and an integer <code>k</code>, return <em>the </em><code>k<sup>th</sup></code><em> <b>lexicographically smallest instructions</b>&nbsp;that will take Bob to </em><code>destination</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2020/10/12/ex1.png" style="width: 300px; height: 229px;"></p>

<pre><strong>Input:</strong> destination = [2,3], k = 1
<strong>Output:</strong> "HHHVV"
<strong>Explanation:</strong> All the instructions that reach (2, 3) in lexicographic order are as follows:
["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"].
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/10/12/ex2.png" style="width: 300px; height: 229px;"></strong></p>

<pre><strong>Input:</strong> destination = [2,3], k = 2
<strong>Output:</strong> "HHVHV"
</pre>

<p><strong>Example 3:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/10/12/ex3.png" style="width: 300px; height: 229px;"></strong></p>

<pre><strong>Input:</strong> destination = [2,3], k = 3
<strong>Output:</strong> "HHVVH"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>destination.length == 2</code></li>
	<li><code>1 &lt;= row, column &lt;= 15</code></li>
	<li><code>1 &lt;= k &lt;= nCr(row + column, row)</code>, where <code>nCr(a, b)</code> denotes <code>a</code> choose <code>b</code>​​​​​.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Combination

Given `destination: (row, column)`, we will have `column` `H` and `row` `V` in the result.

Let's denote `h = column`, `v = row` meaning the number of `H` and `V` left to pick, respectively. The result is of length `h + v`.

We pick the character one by one for the result.

For the first character, if we pick `H`, the rest of characters can form `c = nCr(h - 1 + v, v)` combinations.

If `k <= c`, it means that the result is one of these `c` combinations. So we should pick `H` here. We append `H` to the result and `--h`.

Otherwise, we should pick `V` instead, and do `--v` and `k -= c` (skip these `c` combinations).

We keep doing this until we made choice for all the `h + v` characters.

```cpp
// OJ: https://leetcode.com/problems/kth-smallest-instructions/
// Author: github.com/lzl124631x
// Time: O((H + V)^2)
// Space: O(1)
class Solution {
    int comb(int n, int r) {
        long ans = 1;
        for (int i = 1, j = n - r + 1; i <= r; ++i, ++j) ans = ans * j / i;
        return ans;
    }
public:
    string kthSmallestPath(vector<int>& A, int k) {
        int h = A[1], v = A[0], N = h + v;
        string s;
        for (int i = 0; i < N; ++i) {
            if (h) { // we have H available to pick
                int c = comb(h - 1 + v, v); // if we pick H at the current position, there will be `c` combinations for the rest of characters
                if (k <= c) { // k is covered within `c`, so we should pick H.
                    s += 'H';
                    --h;
                } else { // otherwise we should pick V
                    k -= c;
                    s += 'V';
                    --v;
                }
            } else { // no H left, have to pick V.
                s += 'V';
                --v;
            }
        }
        return s;
    }
};
```