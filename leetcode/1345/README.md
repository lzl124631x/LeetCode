# [1345. Jump Game IV (Hard)](https://leetcode.com/problems/jump-game-iv)

<p>Given an array of&nbsp;integers <code>arr</code>, you are initially positioned at the first index of the array.</p>
<p>In one step you can jump from index <code>i</code> to index:</p>
<ul>
	<li><code>i + 1</code> where:&nbsp;<code>i + 1 &lt; arr.length</code>.</li>
	<li><code>i - 1</code> where:&nbsp;<code>i - 1 &gt;= 0</code>.</li>
	<li><code>j</code> where: <code>arr[i] == arr[j]</code> and <code>i != j</code>.</li>
</ul>
<p>Return <em>the minimum number of steps</em> to reach the <strong>last index</strong> of the array.</p>
<p>Notice that you can not jump outside of the array at any time.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> arr = [100,-23,-23,404,100,23,23,23,3,404]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You need three jumps from index 0 --&gt; 4 --&gt; 3 --&gt; 9. Note that index 9 is the last index of the array.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> arr = [7]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Start index is the last index. You do not need to jump.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> arr = [7,6,9,6,9,6,9,7]
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can jump directly from index 0 to index 7 which is last index of the array.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>8</sup> &lt;= arr[i] &lt;= 10<sup>8</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Jump Game VII (Medium)](https://leetcode.com/problems/jump-game-vii/)
* [Jump Game VIII (Medium)](https://leetcode.com/problems/jump-game-viii/)
* [Maximum Number of Jumps to Reach the Last Index (Medium)](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/)

## Solution 1. BFS

Since we are looking for the shortest distance, BFS should be our first option.

```cpp
// OJ: https://leetcode.com/problems/jump-game-iv/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minJumps(vector<int>& A) {
        unordered_map<int, vector<int>> m;
        int N = A.size(), step = 0;
        for (int i = 0; i < N; ++i) m[A[i]].push_back(i);
        vector<bool> seen(N);
        seen[0] = true;
        queue<int> q{{0}};
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int u = q.front();
                q.pop();
                if (u == N - 1) return step;
                if (u - 1 >= 0 && !seen[u - 1]) {
                    q.push(u - 1);
                    seen[u - 1] = true;
                }
                if (u + 1 < N && !seen[u + 1]) {
                    q.push(u + 1);
                    seen[u + 1] = true;
                }
                if (m.count(A[u])) {
                    for (int v : m[A[u]]) {
                        if (seen[v]) continue;
                        seen[v] = true;
                        q.push(v);
                    }
                    m.erase(A[u]); // Note that we should remove this set of nodes since there is no point revisiting them later.
                }
            }
            ++step;
        }
        return -1;
    }
};
```