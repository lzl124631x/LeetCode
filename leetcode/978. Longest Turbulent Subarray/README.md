# [978. Longest Turbulent Subarray (Medium)](https://leetcode.com/problems/longest-turbulent-subarray/)

<p>Given an integer array <code>arr</code>, return <em>the length of a maximum size turbulent subarray of</em> <code>arr</code>.</p>

<p>A subarray is <strong>turbulent</strong> if the comparison sign flips between each adjacent pair of elements in the subarray.</p>

<p>More formally, a subarray <code>[arr[i], arr[i + 1], ..., arr[j]]</code> of <code>arr</code> is said to be turbulent if and only if:</p>

<ul>
	<li>For <code>i &lt;= k &lt; j</code>:

	<ul>
		<li><code>arr[k] &gt; arr[k + 1]</code> when <code>k</code> is odd, and</li>
		<li><code>arr[k] &lt; arr[k + 1]</code> when <code>k</code> is even.</li>
	</ul>
	</li>
	<li>Or, for <code>i &lt;= k &lt; j</code>:
	<ul>
		<li><code>arr[k] &gt; arr[k + 1]</code> when <code>k</code> is even, and</li>
		<li><code>arr[k] &lt; arr[k + 1]</code> when <code>k</code> is odd.</li>
	</ul>
	</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [9,4,2,10,7,8,8,1,9]
<strong>Output:</strong> 5
<strong>Explanation:</strong> arr[1] &gt; arr[2] &lt; arr[3] &gt; arr[4] &lt; arr[5]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [4,8,12,16]
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [100]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Maximum Subarray (Easy)](https://leetcode.com/problems/maximum-subarray/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/longest-turbulent-subarray/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int inc = 1, dec = 1, N = A.size(), ans = 1;
        for (int i = 1; i < N; ++i) {
            if (A[i] == A[i - 1]) inc = dec = 1;
            else if (A[i] > A[i - 1]) {
                inc = dec + 1;
                dec = 1;
            } else {
                dec = inc + 1;
                inc = 1;
            }
            ans = max({ ans, inc, dec });
        }
        return ans;
    }
};
```