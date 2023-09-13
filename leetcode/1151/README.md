# [1151. Minimum Swaps to Group All 1's Together (Medium)](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together)

<p>Given a&nbsp;binary array <code>data</code>, return&nbsp;the minimum number of swaps required to group all <code>1</code>’s present in the array together in <strong>any place</strong> in the array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> data = [1,0,1,0,1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There are 3 ways to group all 1's together:
[1,1,1,0,0] using 1 swap.
[0,1,1,1,0] using 2 swaps.
[0,0,1,1,1] using 1 swap.
The minimum is 1.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> data = [0,0,0,1,0]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Since there is only one 1 in the array, no swaps are needed.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> data = [1,0,1,0,1,0,0,1,1,0,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> One possible solution that uses 3 swaps is [0,0,0,0,0,1,1,1,1,1,1].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= data.length &lt;= 10<sup>5</sup></code></li>
	<li><code>data[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Uber](https://leetcode.com/company/uber), [Expedia](https://leetcode.com/company/expedia)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Minimum Adjacent Swaps for K Consecutive Ones (Hard)](https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/)
* [Minimum Swaps to Group All 1's Together II (Medium)](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/)
* [Time Needed to Rearrange a Binary String (Medium)](https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/)

## Solution 1. Fixed-length Sliding Window

```cpp
// OJ: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minSwaps(vector<int>& A) {
        int total = accumulate(begin(A), end(A), 0), N = A.size(), one = 0, ans = N;
        for (int i = 0; i < N; ++i) {
            one += A[i];
            if (i - total >= 0) one -= A[i - total];
            ans = min(ans, total - one);
        }
        return ans;
    }
};
```