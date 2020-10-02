# [1306. Jump Game III (Medium)](https://leetcode.com/problems/jump-game-iii/)

<p>Given an array of non-negative integers <code>arr</code>, you are initially positioned at <code>start</code>&nbsp;index of the array. When you are at index <code>i</code>, you can jump&nbsp;to <code>i + arr[i]</code> or <code>i - arr[i]</code>, check if you can reach to <strong>any</strong> index with value 0.</p>

<p>Notice that you can not jump outside of the array at any time.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [4,2,3,0,3,1,2], start = 5
<strong>Output:</strong> true
<strong>Explanation:</strong> 
All possible ways to reach at index 3 with value 0 are: 
index 5 -&gt; index 4 -&gt; index 1 -&gt; index 3 
index 5 -&gt; index 6 -&gt; index 4 -&gt; index 1 -&gt; index 3 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [4,2,3,0,3,1,2], start = 0
<strong>Output:</strong> true 
<strong>Explanation: 
</strong>One possible way to reach at index 3 with value 0 is: 
index 0 -&gt; index 4 -&gt; index 1 -&gt; index 3
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [3,0,2,1,2], start = 2
<strong>Output:</strong> false
<strong>Explanation: </strong>There is no way to reach at index 1 with value 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 5 * 10^4</code></li>
	<li><code>0 &lt;= arr[i] &lt;&nbsp;arr.length</code></li>
	<li><code>0 &lt;= start &lt; arr.length</code></li>
</ul>


**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Graph](https://leetcode.com/tag/graph/)

**Similar Questions**:
* [Jump Game II (Hard)](https://leetcode.com/problems/jump-game-ii/)
* [Jump Game (Medium)](https://leetcode.com/problems/jump-game/)

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
        while (q.size()) {
            int i = q.front();
            q.pop();
            if (A[i] == 0) return true;
            if (A[i] < 0) continue;
            if (i + A[i] < A.size()) q.push(i + A[i]);
            if (i - A[i] >= 0) q.push(i - A[i]);
            A[i] *= -1;
        }
        return false;
    }
};
```