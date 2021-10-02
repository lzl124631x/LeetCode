# [487. Max Consecutive Ones II (Medium)](https://leetcode.com/problems/max-consecutive-ones-ii/)

<p>Given a binary array <code>nums</code>, return <em>the maximum number of consecutive </em><code>1</code><em>'s in the array if you can flip at most one</em> <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,0,1,1,0]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Flip the first zero will get the maximum number of consecutive 1s. After flipping, the maximum number of consecutive 1s is 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,0,1,1,0,1]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?</p>


**Companies**:  
[Zillow](https://leetcode.com/company/zillow), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Max Consecutive Ones (Easy)](https://leetcode.com/problems/max-consecutive-ones/)
* [Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii/)

## Solution 1. Sliding Window

Shrinkable Sliding Window:

```cpp
// OJ: https://leetcode.com/problems/max-consecutive-ones-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& A) {
        int zero = 0, i = 0, j = 0, N = A.size(), ans = 0;
        while (j < N) {
            zero += A[j++] == 0;
            while (zero > 1) zero -= A[i++] == 0;
            ans = max(ans, j - i);
        }
        return ans;
    }
};
```

Non-shrinkable Sliding Window:

```cpp
// OJ: https://leetcode.com/problems/max-consecutive-ones-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& A) {
        int zero = 0, i = 0, j = 0, N = A.size();
        while (j < N) {
            zero += A[j++] == 0;
            if (zero > 1) zero -= A[i++] == 0;
        }
        return j - i;
    }
};
```