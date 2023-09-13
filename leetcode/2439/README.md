# [2439. Minimize Maximum of Array (Medium)](https://leetcode.com/problems/minimize-maximum-of-array)

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> comprising of <code>n</code> non-negative integers.</p>
<p>In one operation, you must:</p>
<ul>
	<li>Choose an integer <code>i</code> such that <code>1 &lt;= i &lt; n</code> and <code>nums[i] &gt; 0</code>.</li>
	<li>Decrease <code>nums[i]</code> by 1.</li>
	<li>Increase <code>nums[i - 1]</code> by 1.</li>
</ul>
<p>Return<em> the <strong>minimum</strong> possible value of the <strong>maximum</strong> integer of </em><code>nums</code><em> after performing <strong>any</strong> number of operations</em>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,7,1,6]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [10,1]
<strong>Output:</strong> 10
<strong>Explanation:</strong>
It is optimal to leave nums as is, and since 10 is the maximum value, we return 10.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == nums.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>

**Companies**:
[Oracle](https://leetcode.com/company/oracle), [Paytm](https://leetcode.com/company/paytm)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Maximum Candies Allocated to K Children (Medium)](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/)
* [Minimum Speed to Arrive on Time (Medium)](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/)
* [Minimum Time to Complete Trips (Medium)](https://leetcode.com/problems/minimum-time-to-complete-trips/)

## Solution 1. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/minimize-maximum-of-array
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minimizeArrayValue(vector<int>& A) {
        int L = 0, R = *max_element(begin(A), end(A));
        auto valid = [&](long long mx) {
            long long d = 0;
            for (long long n : A) {
                n += d;
                if (n > mx) return false;
                d = n - mx;
            }
            return true;
        };
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```

## Solution 2. Prefix Sum + Greedy

Since the value can only flow forward (left), for `A[0..i]`, assume its prefix sum is `sum[i]`, the best we can do is to distribute this `sum[i]` evenly into these `i+1` elements. So, the maximum is `ceil(sum[i] / (i+1))`.

We compute from left to right, and return the maximum of `ceil(sum[i] / (i+1))` as the answer.

```cpp
// OJ: https://leetcode.com/problems/minimize-maximum-of-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimizeArrayValue(vector<int>& A) {
        long long N = A.size(), ans = 0, sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            ans = max(ans, (sum + i) / (i + 1));
        }
        return ans;
    }
};
```