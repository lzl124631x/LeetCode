# [2567. Minimum Score by Changing Two Elements (Medium)](https://leetcode.com/problems/minimum-score-by-changing-two-elements)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>.</p>
<ul>
	<li>The <strong>low</strong> score of <code><font face="monospace">nums</font></code> is the minimum value of <code>|nums[i]&nbsp;- nums[j]|</code> over all <code>0 &lt;= i &lt; j &lt; nums.length</code>.</li>
	<li>The <strong>high</strong> score of&nbsp;<code><font face="monospace">nums</font></code> is the maximum value of <code>|nums[i]&nbsp;- nums[j]|</code> over all <code>0 &lt;= i &lt; j &lt; nums.length</code>.</li>
	<li>The <strong>score</strong> of <code>nums</code> is the sum of the <strong>high</strong> and <strong>low</strong> scores of nums.</li>
</ul>
<p>To minimize the score of <code>nums</code>, we can change the value of <strong>at most two</strong> elements of <code>nums</code>.</p>
<p>Return <em>the <strong>minimum</strong> possible <strong>score</strong> after changing&nbsp;the value of <strong>at most two</strong> elements o</em>f <code>nums</code>.</p>
<p>Note that <code>|x|</code> denotes the absolute value of <code>x</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,4,3]
<strong>Output:</strong> 0
<strong>Explanation:</strong> Change value of nums[1] and nums[2] to 1 so that nums becomes [1,1,1]. Now, the value of <code>|nums[i] - nums[j]|</code> is always equal to 0, so we return 0 + 0 = 0.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,4,7,8,5]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Change nums[0] and nums[1] to be 6. Now nums becomes [6,6,7,8,5].
Our low score is achieved when i = 0 and j = 1, in which case |<code>nums[i] - nums[j]</code>| = |6 - 6| = 0.
Our high score is achieved when i = 3 and j = 4, in which case |<code>nums[i] - nums[j]</code>| = |8 - 5| = 3.
The sum of our high and low score is 3, which we can prove to be minimal.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>3 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-score-by-changing-two-elements
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minimizeSum(vector<int>& A) {
        sort(begin(A), end(A));
        return min({A.back() - A[2], A[A.size() - 3] - A[0], A[A.size() - 2] - A[1]});
    }
};
```