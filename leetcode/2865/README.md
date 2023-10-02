# [2865. Beautiful Towers I (Medium)](https://leetcode.com/problems/beautiful-towers-i)

<p>You are given a <strong>0-indexed</strong> array <code>maxHeights</code> of <code>n</code> integers.</p>

<p>You are tasked with building <code>n</code> towers in the coordinate line. The <code>i<sup>th</sup></code> tower is built at coordinate <code>i</code> and has a height of <code>heights[i]</code>.</p>

<p>A configuration of towers is <strong>beautiful</strong> if the following conditions hold:</p>

<ol>
	<li><code>1 &lt;= heights[i] &lt;= maxHeights[i]</code></li>
	<li><code>heights</code> is a <strong>mountain</strong> array.</li>
</ol>

<p>Array <code>heights</code> is a <strong>mountain</strong> if there exists an index <code>i</code> such that:</p>

<ul>
	<li>For all <code>0 &lt; j &lt;= i</code>, <code>heights[j - 1] &lt;= heights[j]</code></li>
	<li>For all <code>i &lt;= k &lt; n - 1</code>, <code>heights[k + 1] &lt;= heights[k]</code></li>
</ul>

<p>Return <em>the <strong>maximum possible sum of heights</strong> of a beautiful configuration of towers</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> maxHeights = [5,3,4,1,1]
<strong>Output:</strong> 13
<strong>Explanation:</strong> One beautiful configuration with a maximum sum is heights = [5,3,3,1,1]. This configuration is beautiful since:
- 1 &lt;= heights[i] &lt;= maxHeights[i]  
- heights is a mountain of peak i = 0.
It can be shown that there exists no other beautiful configuration with a sum of heights greater than 13.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> maxHeights = [6,5,3,9,2,7]
<strong>Output:</strong> 22
<strong>Explanation:</strong> One beautiful configuration with a maximum sum is heights = [3,3,3,9,2,2]. This configuration is beautiful since:
- 1 &lt;= heights[i] &lt;= maxHeights[i]
- heights is a mountain of peak i = 3.
It can be shown that there exists no other beautiful configuration with a sum of heights greater than 22.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> maxHeights = [3,2,5,5,2,3]
<strong>Output:</strong> 18
<strong>Explanation:</strong> One beautiful configuration with a maximum sum is heights = [2,2,5,5,2,2]. This configuration is beautiful since:
- 1 &lt;= heights[i] &lt;= maxHeights[i]
- heights is a mountain of peak i = 2. 
Note that, for this configuration, i = 3 can also be considered a peak.
It can be shown that there exists no other beautiful configuration with a sum of heights greater than 18.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == maxHeights &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= maxHeights[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Salesforce](https://leetcode.com/company/salesforce)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Stack](https://leetcode.com/tag/stack), [Monotonic Stack](https://leetcode.com/tag/monotonic-stack)

**Similar Questions**:
* [Valid Mountain Array (Easy)](https://leetcode.com/problems/valid-mountain-array)
* [Minimum Number of Removals to Make Mountain Array (Hard)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array)
* [Maximum Number of Books You Can Take (Hard)](https://leetcode.com/problems/maximum-number-of-books-you-can-take)

**Hints**:
* Try all the possible indices <code>i</code> as the peak.
* If <code>i</code> is the peak, start from <code>heights[i] = maxHeights[i]</code>, and <code>heights[j] = max(maxHeights[j], heights[j + 1])</code> for <code>0 <= j < i </code>
* If <code>i</code> is the peak, start from <code>heights[i] = maxHeights[i]</code>, and heights[j] = max(maxHeights[j], heights[j - 1]) for <code>i < j < heights.size()</code>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/beautiful-towers-i
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& A) {
        long long N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            long long sum = A[i];
            for (int j = i - 1, val = A[i]; j >= 0; --j) {
                val = min(val, A[j]);
                sum += val;
            }
            for (int j = i + 1, val = A[i]; j < N; ++j) {
                val = min(val, A[j]);
                sum += val;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
```