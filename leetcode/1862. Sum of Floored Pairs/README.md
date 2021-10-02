# [1862. Sum of Floored Pairs (Hard)](https://leetcode.com/problems/sum-of-floored-pairs/)

<p>Given an integer array <code>nums</code>, return the sum of <code>floor(nums[i] / nums[j])</code> for all pairs of indices <code>0 &lt;= i, j &lt; nums.length</code> in the array. Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>The <code>floor()</code> function returns the integer part of the division.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,5,9]
<strong>Output:</strong> 10
<strong>Explanation:</strong>
floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
floor(5 / 2) = 2
floor(9 / 2) = 4
floor(9 / 5) = 1
We calculate the floor of the division for every pair of indices in the array then sum them up.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [7,7,7,7,7,7,7]
<strong>Output:</strong> 49
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Rakuten](https://leetcode.com/company/rakuten)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1. Binary Search

**Intuition**: Sort the array `A`. For each `A[i]`, we can binary search `A[p] >= (k - 1) * A[i]` and `A[q] >= k * A[i]`, then all numbers `A[j]` with index in range `[p, q)` has `floor(A[j] / A[i]) = k - 1`.

**Algorithm**: 

1. Sort the array `A`. 
1. For each `A[i]`, first count the duplicate of `A[i]`. If we have `dup` duplicates, then they will add `dup^2` to the answer.
1. For the first `A[j] > A[i]`, let `div = A[j] / A[i]`, we use binary search to find the first `A[next] >= A[i] * (div + 1)`, then numbers `A[t]` where `t` is in `[j, next)` will have `floor(A[t] / A[i]) = div`. These numbers will add `(next - j) * div * dup` to the answer.

```cpp
// OJ: https://leetcode.com/problems/sum-of-floored-pairs/
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(1)
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& A) {
        long mod = 1e9 + 7, N = A.size(), ans = 0;
        sort(begin(A), end(A));
        for (int i = 0; i < N; ) {
            long j = i + 1;
            while (j < N && A[j] == A[j - 1]) ++j; // skip the duplicates of `A[i]`
            long dup = j - i;
            ans = (ans + dup * dup % mod) % mod; // the `dup` duplicates add `dup * dup` to the answer
            while (j < N) {
                long div = A[j] / A[i], bound = A[i] * (div + 1);
                long next = lower_bound(begin(A) + j, end(A), bound) - begin(A); // find the first number `A[next] >= A[i] * (div + 1)`
                ans = (ans + (next - j) * div % mod * dup % mod) % mod; // Each A[t] (j <= t < next) will add `div * dup` to the answer.
                j = next;
            }
            i += dup;
        }
        return ans;
    }
};
```

## Solution 2. Frequency Prefix Sum 

```
A:       [1,1,2,2,2,3,5,8,8]

          1,2,3,4,5,6,7,8
freq:    [2,3,1,0,1,0,0,2]

freq      1,2,3,4,5,6,7,8
prefix : [2,5,6,6,7,7,7,9]
sum
```

```cpp
// OJ: https://leetcode.com/problems/sum-of-floored-pairs/
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& A) {
        unordered_map<int, int> freq;
        long prefix[100001] = {};
        long mx = *max_element(begin(A), end(A)), ans = 0, mod = 1e9 + 7;
        for (int n : A) freq[n]++;
        for (int i = 1; i <= mx; ++i) {
            prefix[i] += prefix[i - 1];
            if (freq.count(i)) prefix[i] += freq[i];
        }
        for (auto &[n, cnt] : freq) {
            for (long i = 1; i <= mx / n; ++i) {
                ans = (ans + i * cnt % mod * (prefix[min(n * (i + 1) - 1, mx)] - prefix[n * i - 1]) % mod) % mod;
            }
        }
        return ans;
    }
};
```