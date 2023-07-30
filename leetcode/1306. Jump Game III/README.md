# [1306. Jump Game III (Medium)](https://leetcode.com/problems/jump-game-iii)

<p>Given an array of non-negative integers <code>arr</code>, you are initially positioned at <code>start</code>&nbsp;index of the array. When you are at index <code>i</code>, you can jump&nbsp;to <code>i + arr[i]</code> or <code>i - arr[i]</code>, check if you can reach to <strong>any</strong> index with value 0.</p>
<p>Notice that you can not jump outside of the array at any time.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> arr = [4,2,3,0,3,1,2], start = 5
<strong>Output:</strong> true
<strong>Explanation:</strong> 
All possible ways to reach at index 3 with value 0 are: 
index 5 -&gt; index 4 -&gt; index 1 -&gt; index 3 
index 5 -&gt; index 6 -&gt; index 4 -&gt; index 1 -&gt; index 3 
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> arr = [4,2,3,0,3,1,2], start = 0
<strong>Output:</strong> true 
<strong>Explanation: 
</strong>One possible way to reach at index 3 with value 0 is: 
index 0 -&gt; index 4 -&gt; index 1 -&gt; index 3
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> arr = [3,0,2,1,2], start = 2
<strong>Output:</strong> false
<strong>Explanation: </strong>There is no way to reach at index 1 with value 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;&nbsp;arr.length</code></li>
	<li><code>0 &lt;= start &lt; arr.length</code></li>
</ul>

**Companies**:
[Pinterest](https://leetcode.com/company/pinterest), [Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/)

**Similar Questions**:
* [Jump Game II (Medium)](https://leetcode.com/problems/jump-game-ii/)
* [Jump Game (Medium)](https://leetcode.com/problems/jump-game/)
* [Jump Game VII (Medium)](https://leetcode.com/problems/jump-game-vii/)
* [Jump Game VIII (Medium)](https://leetcode.com/problems/jump-game-viii/)
* [Maximum Number of Jumps to Reach the Last Index (Medium)](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/jump-game-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool canReach(vector<int>& A, int start) {
        if (start < 0 || start >= A.size() || A[start] < 0) return false;
        if (A[start] == 0) return true;
        A[start] *= -1;
        return canReach(A, start + A[start]) || canReach(A, start - A[start]);
    }
};
```

## Solution 2. BFS

```cpp
// OJ: https://leetcode.com/problems/jump-game-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool canReach(vector<int>& A, int start) {
        queue<int> q;
        q.push(start);
        A[start] *= -1;
        while (q.size()) {
            int i = q.front();
            q.pop();
            if (A[i] == 0) return true;
            int d = -A[i];
            if (i + d < A.size() && A[i + d] >= 0) {
                A[i + d] *= -1;
                q.push(i + d);
            }
            if (i - d >= 0 && A[i - d] >= 0) {
                A[i - d] *= -1;
                q.push(i - d);
            }
        }
        return false;
    }
};
```