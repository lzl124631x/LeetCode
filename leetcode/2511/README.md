# [2511. Maximum Enemy Forts That Can Be Captured (Easy)](https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured)

<p>You are given a <strong>0-indexed</strong> integer array <code>forts</code> of length <code>n</code> representing the positions of several forts. <code>forts[i]</code> can be <code>-1</code>, <code>0</code>, or <code>1</code> where:</p>
<ul>
	<li><code>-1</code> represents there is <strong>no fort</strong> at the <code>i<sup>th</sup></code> position.</li>
	<li><code>0</code> indicates there is an <strong>enemy</strong> fort at the <code>i<sup>th</sup></code> position.</li>
	<li><code>1</code> indicates the fort at the <code>i<sup>th</sup></code> the position is under your command.</li>
</ul>
<p>Now you have decided to move your army from one of your forts at position <code>i</code> to an empty position <code>j</code> such that:</p>
<ul>
	<li><code>0 &lt;= i, j &lt;= n - 1</code></li>
	<li>The army travels over enemy forts <strong>only</strong>. Formally, for all <code>k</code> where <code>min(i,j) &lt; k &lt; max(i,j)</code>, <code>forts[k] == 0.</code></li>
</ul>
<p>While moving the army, all the enemy forts that come in the way are <strong>captured</strong>.</p>
<p>Return<em> the <strong>maximum</strong> number of enemy forts that can be captured</em>. In case it is <strong>impossible</strong> to move your army, or you do not have any fort under your command, return <code>0</code><em>.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> forts = [1,0,0,-1,0,0,0,0,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong>
- Moving the army from position 0 to position 3 captures 2 enemy forts, at 1 and 2.
- Moving the army from position 8 to position 3 captures 4 enemy forts.
Since 4 is the maximum number of enemy forts that can be captured, we return 4.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> forts = [0,0,1,-1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Since no enemy fort can be captured, 0 is returned.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= forts.length &lt;= 1000</code></li>
	<li><code>-1 &lt;= forts[i] &lt;= 1</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

**Similar Questions**:
* [Max Consecutive Ones (Easy)](https://leetcode.com/problems/max-consecutive-ones/)
* [Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)

## Solution 1.

Count the 0's between 1 and -1

```cpp
// OJ: https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int captureForts(vector<int>& A) {
        int ans = 0, N = A.size();
        for (int i = 0; i < N;) {
            if (A[i] == 0) {
                ++i;
                continue;
            }
            int start = i++;
            while (i < N && A[i] == 0) ++i;
            if (i < N && A[i] == -A[start]) {
                ans = max(ans, i - start - 1);
            }
        }
        return ans;
    }
};
```