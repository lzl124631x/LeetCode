 # [1911. Maximum Alternating Subsequence Sum (Medium)](https://leetcode.com/problems/maximum-alternating-subsequence-sum/)

<p>The <strong>alternating sum</strong> of a <strong>0-indexed</strong> array is defined as the <strong>sum</strong> of the elements at <strong>even</strong> indices <strong>minus</strong> the <strong>sum</strong> of the elements at <strong>odd</strong> indices.</p>

<ul>
	<li>For example, the alternating sum of <code>[4,2,5,3]</code> is <code>(4 + 5) - (2 + 3) = 4</code>.</li>
</ul>

<p>Given an array <code>nums</code>, return <em>the <strong>maximum alternating sum</strong> of any subsequence of </em><code>nums</code><em> (after <strong>reindexing</strong> the elements of the subsequence)</em>.</p>

<ul>
</ul>

<p>A <strong>subsequence</strong> of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, <code>[2,7,4]</code> is a subsequence of <code>[4,<u>2</u>,3,<u>7</u>,2,1,<u>4</u>]</code> (the underlined elements), while <code>[2,4,2]</code> is not.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [<u>4</u>,<u>2</u>,<u>5</u>,3]
<strong>Output:</strong> 7
<strong>Explanation:</strong> It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,6,7,<u>8</u>]
<strong>Output:</strong> 8
<strong>Explanation:</strong> It is optimal to choose the subsequence [8] with alternating sum 8.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [<u>6</u>,2,<u>1</u>,2,4,<u>5</u>]
<strong>Output:</strong> 10
<strong>Explanation:</strong> It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Quince](https://leetcode.com/company/quince)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP

**Intuition**: The brute force way is enumerating all the `2^N` subsequences which has lots of repetitive computation. Given the first `i + 1` elements `A[0...i]`, the greatest alternating sum is a fixed value, we can memoize it and keep extending `i`. So we should use Dynamic Programming.

**Algorithm**:

Let `dp[i+1][0]` and `dp[i+1][1]` be the maximum alternating subsequence sum of the first `i + 1` elements `A[0...i]` where `A[i]` is even-indexed and odd-indexed, respectively.

```
dp[i+1][0] = max(
                    dp[i][1] + A[i],  // if we pick A[i] as the last even-indexed number
                    dp[i][0]          // otherwise
                )
dp[i+1][1] = max(
                    dp[i][0] - A[i],  // if we pick A[i] as the last odd-indexed number
                    dp[i][1]          // otherwise
                )

dp[0][0] = dp[0][1] = 0
```

The answer must has odd number of elements, so must be `dp[N][0]`.

Since `dp[i+1][?]` is only dependent on `dp[i][?]`, instead of using an `N x 2` array, we can simply using a `1 x 2` array to store the DP values.

```cpp
// OJ: https://leetcode.com/contest/biweekly-contest-55/problems/maximum-alternating-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    typedef long long LL;
public:
    long long maxAlternatingSum(vector<int>& A) {
        LL N = A.size(), dp[2] = {};
        for (int i = 0; i < N; ++i) {
            LL next[2] = {};
            next[0] = max(dp[1] + A[i], dp[0]);
            next[1] = max(dp[0] - A[i], dp[1]);
            swap(next, dp);
        }
        return dp[0];
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/maximum-alternating-subsequence-sum/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& A) {
        long long even = 0, odd = 0;
        for (int n : A) {
            long long o = even - n, e = odd + n;
            even = max(even, e);
            odd = max(odd, o);
        }
        return even; 
    }
};
```