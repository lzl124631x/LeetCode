# [1231. Divide Chocolate (Hard)](https://leetcode.com/problems/divide-chocolate/)

<p>You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array&nbsp;<code>sweetness</code>.</p>

<p>You want to share the chocolate with your <code>k</code>&nbsp;friends so you start cutting the chocolate bar into <code>k + 1</code>&nbsp;pieces using&nbsp;<code>k</code>&nbsp;cuts, each piece consists of some <strong>consecutive</strong> chunks.</p>

<p>Being generous, you will eat the piece with the <strong>minimum total sweetness</strong> and give the other pieces to your friends.</p>

<p>Find the <strong>maximum total sweetness</strong> of the&nbsp;piece you can get by cutting the chocolate bar optimally.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> sweetness = [1,2,3,4,5,6,7,8,9], k = 5
<strong>Output:</strong> 6
<b>Explanation: </b>You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> sweetness = [5,6,7,8,9,1,2,3,4], k = 8
<strong>Output:</strong> 1
<b>Explanation: </b>There is only one way to cut the bar into 9 pieces.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> sweetness = [1,2,2,1,2,2,1,2,2], k = 2
<strong>Output:</strong> 5
<b>Explanation: </b>You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= k &lt; sweetness.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= sweetness[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Split Array Largest Sum (Hard)](https://leetcode.com/problems/split-array-largest-sum/)
* [Capacity To Ship Packages Within D Days (Medium)](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

## Solution 1. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/divide-chocolate/
// Author: github.com/lzl124631x
// Time: O(Nlog(M/(k+1))) where `N` is the length of `A` and `M` is the sum of elements in `A`.
// Space: O(1)
class Solution {
public:
    int maximizeSweetness(vector<int>& A, int k) {
        long N = A.size(), L = 0, R = accumulate(begin(A), end(A), 0L) / (k + 1);
        auto valid = [&](int goal) {
            for (int i = 0, sum = 0, cnt = 0; i < N; ++i) {
                sum += A[i];
                if (sum >= goal) {
                    sum = 0;
                    if (++cnt >= k + 1) return true;
                }
            }
            return false;
        };
        while (L <= R) {
            long M = (L + R) / 2;
            if (valid(M)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```