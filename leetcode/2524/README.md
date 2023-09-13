# [2524. Maximum Frequency Score of a Subarray (Hard)](https://leetcode.com/problems/maximum-frequency-score-of-a-subarray)

<p>You are given an integer array <code>nums</code> and a <strong>positive</strong> integer <code>k</code>.</p>
<p>The <strong>frequency score</strong> of an array is the sum of the <strong>distinct</strong> values in the array raised to the power of their <strong>frequencies</strong>, taking the sum <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>
<ul>
	<li>For example, the frequency score of the array <code>[5,4,5,7,4,4]</code> is <code>(4<sup>3</sup> + 5<sup>2</sup> + 7<sup>1</sup>) modulo (10<sup>9</sup> + 7) = 96</code>.</li>
</ul>
<p>Return <em>the <strong>maximum</strong> frequency score of a <strong>subarray</strong> of size </em><code>k</code><em> in </em><code>nums</code>. You should maximize the value under the modulo and not the actual value.</p>
<p>A <strong>subarray</strong> is a contiguous part of an array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,1,2,1,2], k = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> The subarray [2,1,2] has a frequency score equal to 5. It can be shown that it is the maximum frequency score we can have.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,1,1,1,1], k = 4
<strong>Output:</strong> 1
<strong>Explanation:</strong> All the subarrays of length 4 have a frequency score equal to 1.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>

**Companies**:
[PayPal](https://leetcode.com/company/paypal)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1. Fixed-length Sliding Window

```cpp
// OJ: https://leetcode.com/problems/maximum-frequency-score-of-a-subarray
// Author: github.com/lzl124631x
// Time: O(N * sqrt(N))
// Space: O(N)
class Solution {
public:
    int maxFrequencyScore(vector<int>& A, int k) {
        long N = A.size(), ans = 0, sum = 0, mod = 1e9 + 7;
        unordered_map<int, int> cnt;
        auto score = [&](long base, long e) {
            if (e == 0) return 0L;
            long ans = 1;
            while (e) {
                if (e & 1) ans = ans * base % mod;
                base = base * base % mod;
                e >>= 1;
            }
            return ans;
        };
        for (int i = 0; i < N; ++i) {
            int a = A[i], fa = cnt[A[i]]++;
            sum = (sum - score(a, fa) + score(a, fa + 1) + mod) % mod;
            if (i - k >= 0) {
                int b = A[i - k], fb = cnt[A[i - k]]--;
                sum = (sum - score(b, fb) + score(b, fb - 1) + mod) % mod;
            }
            if (i >= k - 1) ans = max(ans, sum);
        }
        return ans;
    }
};
```