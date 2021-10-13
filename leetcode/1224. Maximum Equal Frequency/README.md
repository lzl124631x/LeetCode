# [1224. Maximum Equal Frequency (Hard)](https://leetcode.com/problems/maximum-equal-frequency/)

<p>Given an array <code>nums</code>&nbsp;of positive integers, return the longest possible length of an array prefix of <code>nums</code>, such that it is possible to remove <strong>exactly one</strong> element from this prefix so that every number that has appeared in it will have the same number of occurrences.</p>

<p>If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,2,1,1,5,3,3,5]
<strong>Output:</strong> 7
<strong>Explanation:</strong> For the subarray [2,2,1,1,5,3,3] of length 7, if we remove nums[4]=5, we will get [2,2,1,1,3,3], so that each number will appear exactly twice.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
<strong>Output:</strong> 13
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,2,2,2]
<strong>Output:</strong> 5
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [10,2,8,9,3,8,1,5,2,3,7,6]
<strong>Output:</strong> 8
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[American Express](https://leetcode.com/company/american-express)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1. Frequency Map

```cpp
// OJ: https://leetcode.com/problems/maximum-equal-frequency/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int maxEqualFreq(vector<int>& A) {
        unordered_map<int, int> cnt;
        map<int, int> freq;
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            int c = ++cnt[A[i]];
            if (c - 1 > 0) {
                if (--freq[c - 1] == 0) freq.erase(c - 1);
            }
            ++freq[c];
            if (freq.size() == 2) {
                auto &[a, ca] = *freq.begin();
                auto &[b, cb] = *freq.rbegin();
                if ((b == a + 1 && cb == 1) || (a == 1 && ca == 1)) ans = i + 1;
            } else if (freq.size() == 1) {
                auto &[a, ca] = *freq.begin();
                if (a == 1 || ca == 1) ans = i + 1;
            }
        }
        return ans;
    }
};
```