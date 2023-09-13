# [485. Max Consecutive Ones (Easy)](https://leetcode.com/problems/max-consecutive-ones/)

<p>Given a binary array <code>nums</code>, return <em>the maximum number of consecutive </em><code>1</code><em>'s in the array</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,0,1,1,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,0,1,1,0,1]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Max Consecutive Ones II (Medium)](https://leetcode.com/problems/max-consecutive-ones-ii/)
* [Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)
* [Consecutive Characters (Easy)](https://leetcode.com/problems/consecutive-characters/)
* [Longer Contiguous Segments of Ones than Zeros (Easy)](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/)

## Solution 1. Greedy

```cpp
// OJ: https://leetcode.com/problems/max-consecutive-ones/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& A) {
        int ans = 0, cnt = 0;
        for (int n : A) {
            if (n) ans = max(ans, ++cnt);
            else cnt = 0;
        }
        return ans;
    }
};
```