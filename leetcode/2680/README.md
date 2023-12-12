# [2680. Maximum OR (Medium)](https://leetcode.com/problems/maximum-or)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code> and an integer <code>k</code>. In an operation, you can choose an element and multiply it by <code>2</code>.</p>

<p>Return <em>the maximum possible value of </em><code>nums[0] | nums[1] | ... | nums[n - 1]</code> <em>that can be obtained after applying the operation on nums at most </em><code>k</code><em> times</em>.</p>

<p>Note that <code>a | b</code> denotes the <strong>bitwise or</strong> between two integers <code>a</code> and <code>b</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [12,9], k = 1
<strong>Output:</strong> 30
<strong>Explanation:</strong> If we apply the operation to index 1, our new array nums will be equal to [12,18]. Thus, we return the bitwise or of 12 and 18, which is 30.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [8,1,2], k = 2
<strong>Output:</strong> 35
<strong>Explanation:</strong> If we apply the operation twice on index 0, we yield a new array of [32,1,2]. Thus, we return 32|1|2 = 35.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 15</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Greedy](https://leetcode.com/tag/greedy), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Prefix Sum](https://leetcode.com/tag/prefix-sum)

**Hints**:
* The optimal solution should apply all the k operations on a single number.
* Calculate the prefix or and the suffix or and perform k operations over each element, and maximize the answer.

## Solution 1.

1. The optimal solution should apply all the k operations on a single number.
2. Calculate the prefix or and the suffix or and perform k operations over each element, and maximize the answer.

Proof of point 1:

We know that we should greedily pick some numbers whose highest bits are as high as possible and shift them. If there are multiple numbers having the same highest bit, and we moved one of them. Which number we should move in the next round? Must be this number that we just moved.

```cpp
// OJ: https://leetcode.com/problems/maximum-or
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long maximumOr(vector<int>& A, int K) {
        long long N = A.size(), ans = 0, pre = 0;
        vector<long long> suf(N + 1);
        for (int i = N - 1; i >= 0; --i) suf[i] = suf[i + 1] | A[i];
        for (int i = 0; i < N; ++i) {
            ans = max(ans, pre | suf[i + 1] | ((long long)A[i] << K));
            pre |= A[i];
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/maximum-or
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long maximumOr(vector<int>& A, int k) {
        long long cnt[32] = {}, all = 0, ans = 0;
        for (int n : A) {
            for (int i = 0; i < 32; ++i) cnt[i] += (n >> i & 1);
            all |= n;
        }
        for (int n : A) {
            int other = 0;
            for (int i = 0; i < 32; ++i) {
                if (cnt[i] - (n >> i & 1) > 0) other |= (1 << i);
            }
            ans = max(ans, other | ((long long)n << k));
        }
        return ans;
    }
};
```