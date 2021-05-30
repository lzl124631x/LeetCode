# [1167. Minimum Cost to Connect Sticks (Medium)](https://leetcode.com/problems/minimum-cost-to-connect-sticks/)

<p>You have some number of sticks with positive integer lengths. These lengths are given as an array&nbsp;<code>sticks</code>, where&nbsp;<code>sticks[i]</code>&nbsp;is the length of the&nbsp;<code>i<sup>th</sup></code>&nbsp;stick.</p>

<p>You can connect any two sticks of lengths <code>x</code> and <code>y</code> into one stick&nbsp;by paying a cost of <code>x + y</code>. You must connect&nbsp;all the sticks until there is only one stick remaining.</p>

<p>Return&nbsp;<em>the minimum cost of connecting all the given sticks into one stick in this way</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> sticks = [2,4,3]
<strong>Output:</strong> 14
<strong>Explanation:</strong>&nbsp;You start with sticks = [2,4,3].
1. Combine sticks 2 and 3 for a cost of 2 + 3 = 5. Now you have sticks = [5,4].
2. Combine sticks 5 and 4 for a cost of 5 + 4 = 9. Now you have sticks = [9].
There is only one stick left, so you are done. The total cost is 5 + 9 = 14.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> sticks = [1,8,3,5]
<strong>Output:</strong> 30
<strong>Explanation:</strong> You start with sticks = [1,8,3,5].
1. Combine sticks 1 and 3 for a cost of 1 + 3 = 4. Now you have sticks = [4,8,5].
2. Combine sticks 4 and 5 for a cost of 4 + 5 = 9. Now you have sticks = [9,8].
3. Combine sticks 9 and 8 for a cost of 9 + 8 = 17. Now you have sticks = [17].
There is only one stick left, so you are done. The total cost is 4 + 9 + 17 = 30.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> sticks = [5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is only one stick, so you don't need to do anything. The total cost is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code><span>1 &lt;= sticks.length &lt;= 10<sup>4</sup></span></code></li>
	<li><code><span>1 &lt;= sticks[i] &lt;= 10<sup>4</sup></span></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Minimum Cost to Merge Stones (Hard)](https://leetcode.com/problems/minimum-cost-to-merge-stones/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-cost-to-connect-sticks/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int connectSticks(vector<int>& A) {
        priority_queue<int, vector<int>, greater<>> pq;
        for (int n : A) pq.push(n);
        int ans = 0;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a + b);
            ans += a + b;
        }
        return ans;
    }
};
```