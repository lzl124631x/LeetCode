# [1498. Number of Subsequences That Satisfy the Given Sum Condition (Medium)](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/)

<p>Given an array of integers <code>nums</code> and an integer <code>target</code>.</p>

<p>Return the number of <strong>non-empty</strong> subsequences of <code>nums</code> such that the sum of the minimum and maximum element on it is less or equal than <code>target</code>.</p>

<p>Since the answer&nbsp;may be too large,&nbsp;return it modulo&nbsp;10^9 + 7.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,5,6,7], target = 9
<strong>Output:</strong> 4
<strong>Explanation: </strong>There are 4 subsequences that satisfy the condition.
[3] -&gt; Min value + max value &lt;= target (3 + 3 &lt;= 9)
[3,5] -&gt; (3 + 5 &lt;= 9)
[3,5,6] -&gt; (3 + 6 &lt;= 9)
[3,6] -&gt; (3 + 6 &lt;= 9)
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,3,6,8], target = 10
<strong>Output:</strong> 6
<strong>Explanation: </strong>There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,3,4,6,7], target = 12
<strong>Output:</strong> 61
<strong>Explanation: </strong>There are 63 non-empty subsequences, two of them don't satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [5,2,4,1,7,6,8], target = 16
<strong>Output:</strong> 127
<strong>Explanation: </strong>All non-empty subset satisfy the condition (2^7 - 1) = 127</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^6</code></li>
	<li><code>1 &lt;= target &lt;= 10^6</code></li>
</ul>


**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1. Two pointers

Consider input `nums = [3,5,6,7], target = 9`.

For `3`, we can find the maximum number we can use which is `6`. So we get a subarray `[3,5,6]`. Then how many subsequences starting with this `3` we can form using this subarray? It should be `2^(len - 1) = 2^2 = 4` because out of `[5, 6]`, we just can choose to pick zero, one or two of them.

Then we consider the next element `5`, and the right bound should only decrease so that we can still sum up to `9`. So we can use two pointers, `i` scanning elements from left to right, and `j` starting from `N - 1` and scanning leftwards to find the maximum right boundary.

```cpp
// OJ: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int numSubseq(vector<int>& A, int target) {
        sort(begin(A), end(A));
        int N = A.size(), ans = 0, mod = 1e9 + 7;
        vector<int> p(N, 1);
        for (int i = 1; i < N; ++i) p[i] = p[i - 1] * 2 % mod;
        for (int i = 0, j = N - 1; i <= j; ++i) {
            while (i <= j && A[i] + A[j] > target) --j;
            if (i > j) break;
            ans = (ans + p[j - i]) % mod;
        }
        return ans;
    }
};
```

Or use fast pow.

```cpp
// OJ: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
int modpow(int base, int exp, int mod) {
    base %= mod;
    int ans = 1;
    for (; exp > 0; exp >>= 1, base = (long)base * base % mod) {
        if (exp & 1) ans = ((long)ans * base) % mod;
    }
    return ans;
}
class Solution {
public:
    int numSubseq(vector<int>& A, int target) {
        sort(begin(A), end(A));
        int N = A.size(), ans = 0, mod = 1e9 + 7;
        for (int i = 0, j = N - 1; i <= j; ++i) {
            while (i <= j && A[i] + A[j] > target) --j;
            if (i > j) break;
            ans = (ans + modpow(2, j - i, mod)) % mod;
        }
        return ans;
    }
};
```