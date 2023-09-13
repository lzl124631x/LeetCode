# [2555. Maximize Win From Two Segments (Medium)](https://leetcode.com/problems/maximize-win-from-two-segments)

<p>There are some prizes on the <strong>X-axis</strong>. You are given an integer array <code>prizePositions</code> that is <strong>sorted in non-decreasing order</strong>, where <code>prizePositions[i]</code> is the position of the <code>i<sup>th</sup></code> prize. There could be different prizes at the same position on the line. You are also given an integer <code>k</code>.</p>
<p>You are allowed to select two segments with integer endpoints. The length of each segment must be <code>k</code>. You will collect all prizes whose position falls within at least one of the two selected segments (including the endpoints of the segments). The two selected segments may intersect.</p>
<ul>
	<li>For example if <code>k = 2</code>, you can choose segments <code>[1, 3]</code> and <code>[2, 4]</code>, and you will win any prize <font face="monospace">i</font> that satisfies <code>1 &lt;= prizePositions[i] &lt;= 3</code> or <code>2 &lt;= prizePositions[i] &lt;= 4</code>.</li>
</ul>
<p>Return <em>the <strong>maximum</strong> number of prizes you can win if you choose the two segments optimally</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> prizePositions = [1,1,2,2,3,3,5], k = 2
<strong>Output:</strong> 7
<strong>Explanation:</strong> In this example, you can win all 7 prizes by selecting two segments [1, 3] and [3, 5].
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> prizePositions = [1,2,3,4], k = 0
<strong>Output:</strong> 2
<strong>Explanation:</strong> For this example, <strong>one choice</strong> for the segments is <code>[3, 3]</code> and <code>[4, 4],</code> and you will be able to get <code>2</code> prizes. 
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= prizePositions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= prizePositions[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>9</sup> </code></li>
	<li><code>prizePositions</code> is sorted in non-decreasing order.</li>
</ul>
<p>&nbsp;</p>

**Companies**:
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Best Time to Buy and Sell Stock III (Hard)](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)
* [Two Best Non-Overlapping Events (Medium)](https://leetcode.com/problems/two-best-non-overlapping-events/)

## Solution 1. Find Maximum Sliding Window

```cpp
// OJ: https://leetcode.com/problems/maximize-win-from-two-segments
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maximizeWin(vector<int>& A, int k) {
        int N = A.size(), ans = 0;
        vector<int> right(N + 1);
        for (int i = N - 1, j = N - 1; i >= 0; --i) {
            while (A[j] > A[i] + k) --j;
            right[i] = max(right[i + 1], j - i + 1);
        }
        for (int i = 0, j = 0; i < N; ++i) {
            while (j < N && A[j] <= A[i] + k) ++j;
            ans = max(ans, j - i + right[j]);
        }
        return ans;
    }
};
```