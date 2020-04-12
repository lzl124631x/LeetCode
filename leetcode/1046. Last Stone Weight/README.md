# [1046. Last Stone Weight (Easy)](https://leetcode.com/problems/last-stone-weight/)

<p>We have a collection of stones, each stone&nbsp;has a positive integer weight.</p>

<p>Each turn, we choose the two <strong>heaviest</strong>&nbsp;stones&nbsp;and smash them together.&nbsp; Suppose the stones have weights <code>x</code> and <code>y</code> with <code>x &lt;= y</code>.&nbsp; The result of this smash is:</p>

<ul>
	<li>If <code>x == y</code>, both stones are totally destroyed;</li>
	<li>If <code>x != y</code>, the stone of weight <code>x</code> is totally destroyed, and the stone of weight <code>y</code> has new weight <code>y-x</code>.</li>
</ul>

<p>At the end, there is at most 1 stone left.&nbsp; Return the weight of this stone (or 0 if there are no stones left.)</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>[2,7,4,1,8,1]
<strong>Output: </strong>1
<strong>Explanation: </strong>
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= stones.length &lt;= 30</code></li>
	<li><code>1 &lt;= stones[i] &lt;= 1000</code></li>
</ol>


**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Max-root Heap

```cpp
// OJ: https://leetcode.com/problems/last-stone-weight/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int lastStoneWeight(vector<int>& A) {
        priority_queue<int> pq(begin(A), end(A));
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a - b);
        }
        return pq.top();
    }
};
```