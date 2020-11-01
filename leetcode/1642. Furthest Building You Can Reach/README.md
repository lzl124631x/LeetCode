# [1642. Furthest Building You Can Reach (Medium)](https://leetcode.com/problems/furthest-building-you-can-reach/)

<p>You are given an integer array <code>heights</code> representing the heights of buildings, some <code>bricks</code>, and some <code>ladders</code>.</p>

<p>You start your journey from building <code>0</code> and move to the next building by possibly using bricks or ladders.</p>

<p>While moving from building <code>i</code> to building <code>i+1</code> (<strong>0-indexed</strong>),</p>

<ul>
	<li>If the current building's height is <strong>greater than or equal</strong> to the next building's height, you do <strong>not</strong> need a ladder or bricks.</li>
	<li>If the current building's height is <b>less than</b> the next building's height, you can either use <strong>one ladder</strong> or <code>(h[i+1] - h[i])</code> <strong>bricks</strong>.</li>
</ul>

<p><em>Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/27/q4.gif" style="width: 562px; height: 561px;">
<pre><strong>Input:</strong> heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
<strong>Output:</strong> 4
<strong>Explanation:</strong> Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 &gt;= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 &lt; 7.
- Go to building 3 without using ladders nor bricks since 7 &gt;= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 &lt; 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
<strong>Output:</strong> 7
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> heights = [14,3,19,3], bricks = 17, ladders = 0
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= heights.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= heights[i] &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= bricks &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= ladders &lt;= heights.length</code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Heap](https://leetcode.com/tag/heap/)

## Solution 1. DFS

Brute force DFS.

For each position where we need to climb, we try using brick and ladder, and log the maximum index we can reach.

```cpp
// OJ: https://leetcode.com/problems/furthest-building-you-can-reach/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
    int ans = 0;
    void dfs(vector<int> &H, int B, int L, int start) {
        if (ans == H.size() - 1) return;
        if (start == H.size() - 1) {
            ans = H.size() - 1;
            return;
        }
        for (int i = start; i < H.size(); ++i) {
            ans = max(ans, i);
            if (H[i] == 0) continue;
            if (B >= H[i]) dfs(H, B - H[i], L, i + 1);
            if (L) dfs(H, B, L - 1, i + 1);
            break;
        }
    }
public:
    int furthestBuilding(vector<int>& H, int B, int L) {
        for (int i = 0; i + 1 < H.size(); ++i) H[i] = max(0, H[i + 1] - H[i]);
        H.back() = 0;
        dfs(H, B, L, 0);
        return ans;
    }
}; 
```