# [1863. Sum of All Subset XOR Totals (Easy)](https://leetcode.com/problems/sum-of-all-subset-xor-totals/)

<p>The <strong>XOR total</strong> of an array is defined as the bitwise <code>XOR</code> of<strong> all its elements</strong>, or <code>0</code> if the array is<strong> empty</strong>.</p>

<ul>
	<li>For example, the <strong>XOR total</strong> of the array <code>[2,5,6]</code> is <code>2 XOR 5 XOR 6 = 1</code>.</li>
</ul>

<p>Given an array <code>nums</code>, return <em>the <strong>sum</strong> of all <strong>XOR totals</strong> for every <strong>subset</strong> of </em><code>nums</code>.&nbsp;</p>

<p><strong>Note:</strong> Subsets with the <strong>same</strong> elements should be counted <strong>multiple</strong> times.</p>

<p>An array <code>a</code> is a <strong>subset</strong> of an array <code>b</code> if <code>a</code> can be obtained from <code>b</code> by deleting some (possibly zero) elements of <code>b</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,3]
<strong>Output:</strong> 6
<strong>Explanation: </strong>The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,1,6]
<strong>Output:</strong> 28
<strong>Explanation: </strong>The 8 subsets of [5,1,6] are:
- The empty subset has an XOR total of 0.
- [5] has an XOR total of 5.
- [1] has an XOR total of 1.
- [6] has an XOR total of 6.
- [5,1] has an XOR total of 5 XOR 1 = 4.
- [5,6] has an XOR total of 5 XOR 6 = 3.
- [1,6] has an XOR total of 1 XOR 6 = 7.
- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,4,5,6,7,8]
<strong>Output:</strong> 480
<strong>Explanation:</strong> The sum of all XOR totals for every subset is 480.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 12</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 20</code></li>
</ul>


**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/), [Recursion](https://leetcode.com/tag/recursion/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/sum-of-all-subset-xor-totals/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
    int ans = 0;
    void dfs(vector<int> &A, int start, int val) {
        if (start == A.size()) {
            ans += val;
            return;
        }
        dfs(A, start + 1, val ^ A[start]);
        dfs(A, start + 1, val);
    }
public:
    int subsetXORSum(vector<int>& A) {
        dfs(A, 0, 0);
        return ans;
    }
};
```

## Solution 2. Brute Force

```cpp
// OJ: https://leetcode.com/problems/sum-of-all-subset-xor-totals/
// Author: github.com/lzl124631x
// Time: O(2^N * N)
// Space: O(1)
class Solution {
public:
    int subsetXORSum(vector<int>& A) {
        int ans = 0;
        for (int m = 1, end = (1 << A.size()); m < end; ++m) {
            int total = 0;
            for (int i = 0; i < A.size(); ++i) {
                if (m >> i & 1) total ^= A[i];
            }
            ans += total;
        }
        return ans;
    }
};
```

## Solution 3. Math

For the `i`th bit, assume there are `k` numbers whose `i`th bit is `1`.

* If `k == 0`, all the xor results will have `0` in the `i`th bit.
* If `k >= 1`, we can use the `k` `1`s to generate `comb(k, 1) + comb(k, 3) + comb(k, 5) + ... = 2^(k-1)` different ways to make the xor result `1`. For the rest `n - k` numbers, there are `2^(n-k)` ways to pick any of them. So in total there are `2^(k-1) * 2^(n-k) = 2^(n-1)` ways to get `1` as the xor result.

Note that `2^(n-1)` is irrelevant to `k`, so as long as `k >= 1` i.e. there is a number whose `i`th bit is `1`, the `i`th bit will contribute `(1 << i) * 2^(n-1)` to the result.

```cpp
// OJ: https://leetcode.com/problems/sum-of-all-subset-xor-totals/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int subsetXORSum(vector<int>& A) {
        int bits = 0;
        for (int n : A) bits |= n;
        return bits * pow(2, A.size() - 1);
    }
};
```