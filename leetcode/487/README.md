# [487. Max Consecutive Ones II (Medium)](https://leetcode.com/problems/max-consecutive-ones-ii)

<p>Given a binary array <code>nums</code>, return <em>the maximum number of consecutive </em><code>1</code><em>&#39;s in the array if you can flip at most one</em> <code>0</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,0,1,1,0]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
- If we flip the first zero, nums becomes [1,1,1,1,0] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1] and we have 3 consecutive ones.
The max number of consecutive ones is 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,0,1,1,0,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
- If we flip the first zero, nums becomes [1,1,1,1,0,1] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1,1] and we have 4 consecutive ones.
The max number of consecutive ones is 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> What if the input numbers come in one by one as an infinite stream? In other words, you can&#39;t store all numbers coming from the stream as it&#39;s too large to hold in memory. Could you solve it efficiently?</p>


**Companies**:
[Yandex](https://leetcode.com/company/yandex), [Google](https://leetcode.com/company/google), [TikTok](https://leetcode.com/company/tiktok), [Zoom](https://leetcode.com/company/zoom)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Sliding Window](https://leetcode.com/tag/sliding-window)

**Similar Questions**:
* [Max Consecutive Ones (Easy)](https://leetcode.com/problems/max-consecutive-ones)
* [Max Consecutive Ones III (Medium)](https://leetcode.com/problems/max-consecutive-ones-iii)
* [All Divisions With the Highest Score of a Binary Array (Medium)](https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array)

## Solution 1. Sliding Window

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)".

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

## Discuss

https://leetcode.com/problems/max-consecutive-ones-ii/discuss/1499844/C%2B%2B-Sliding-Window-(%2B-Cheat-Sheet)