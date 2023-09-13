# [2354. Number of Excellent Pairs (Hard)](https://leetcode.com/problems/number-of-excellent-pairs)

<p>You are given a <strong>0-indexed</strong> positive integer array <code>nums</code> and a positive integer <code>k</code>.</p>
<p>A pair of numbers <code>(num1, num2)</code> is called <strong>excellent</strong> if the following conditions are satisfied:</p>
<ul>
	<li><strong>Both</strong> the numbers <code>num1</code> and <code>num2</code> exist in the array <code>nums</code>.</li>
	<li>The sum of the number of set bits in <code>num1 OR num2</code> and <code>num1 AND num2</code> is greater than or equal to <code>k</code>, where <code>OR</code> is the bitwise <strong>OR</strong> operation and <code>AND</code> is the bitwise <strong>AND</strong> operation.</li>
</ul>
<p>Return <em>the number of <strong>distinct</strong> excellent pairs</em>.</p>
<p>Two pairs <code>(a, b)</code> and <code>(c, d)</code> are considered distinct if either <code>a != c</code> or <code>b != d</code>. For example, <code>(1, 2)</code> and <code>(2, 1)</code> are distinct.</p>
<p><strong>Note</strong> that a pair <code>(num1, num2)</code> such that <code>num1 == num2</code> can also be excellent if you have at least <strong>one</strong> occurrence of <code>num1</code> in the array.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,1], k = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> The excellent pairs are the following:
- (3, 3). (3 AND 3) and (3 OR 3) are both equal to (11) in binary. The total number of set bits is 2 + 2 = 4, which is greater than or equal to k = 3.
- (2, 3) and (3, 2). (2 AND 3) is equal to (10) in binary, and (2 OR 3) is equal to (11) in binary. The total number of set bits is 1 + 2 = 3.
- (1, 3) and (3, 1). (1 AND 3) is equal to (01) in binary, and (1 OR 3) is equal to (11) in binary. The total number of set bits is 1 + 2 = 3.
So the number of excellent pairs is 5.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [5,1,1], k = 10
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no excellent pairs for this array.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= k &lt;= 60</code></li>
</ul>

**Companies**:
[epiFi](https://leetcode.com/company/epifi)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Binary Search](https://leetcode.com/tag/binary-search/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)

## Solution 1.

The inclusion-exclusion principle: $n(A\cup B) = n(A) + n(B) – n(A\cap B)$

So, $n(A⋃B) + n(A⋂B) = n(A) + n(B)$

The sum of the number of set bits in (num1 OR num2) and (num1 AND num2) is equal to the sum of the number of set bits in num1 and num2.


```cpp
// OJ: https://leetcode.com/problems/number-of-excellent-pairs
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long countExcellentPairs(vector<int>& A, int k) {
        unordered_set<int> s(begin(A), end(A));
        long long ans = 0, cnt[32] = {};
        for (int n : s) {
            int bits = __builtin_popcount(n), goal = max(0, k - bits);
            for (int i = goal; i < 32; ++i) ans += cnt[i] * 2;
            if (bits >= goal) ans++;
            cnt[bits]++;
        }
        return ans;
    }
};
```