# [2367. Number of Arithmetic Triplets (Easy)](https://leetcode.com/problems/number-of-arithmetic-triplets)

<p>You are given a <strong>0-indexed</strong>, <strong>strictly increasing</strong> integer array <code>nums</code> and a positive integer <code>diff</code>. A triplet <code>(i, j, k)</code> is an <strong>arithmetic triplet</strong> if the following conditions are met:</p>
<ul>
	<li><code>i &lt; j &lt; k</code>,</li>
	<li><code>nums[j] - nums[i] == diff</code>, and</li>
	<li><code>nums[k] - nums[j] == diff</code>.</li>
</ul>
<p>Return <em>the number of unique <strong>arithmetic triplets</strong>.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [0,1,4,6,7,10], diff = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong>
(1, 2, 4) is an arithmetic triplet because both 7 - 4 == 3 and 4 - 1 == 3.
(2, 4, 5) is an arithmetic triplet because both 10 - 7 == 3 and 7 - 4 == 3. 
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6,7,8,9], diff = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong>
(0, 2, 4) is an arithmetic triplet because both 8 - 6 == 2 and 6 - 4 == 2.
(1, 3, 5) is an arithmetic triplet because both 9 - 7 == 2 and 7 - 5 == 2.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>3 &lt;= nums.length &lt;= 200</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 200</code></li>
	<li><code>1 &lt;= diff &lt;= 50</code></li>
	<li><code>nums</code> is <strong>strictly</strong> increasing.</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Enumeration](https://leetcode.com/tag/enumeration/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [3Sum (Medium)](https://leetcode.com/problems/3sum/)
* [Number of Unequal Triplets in Array (Easy)](https://leetcode.com/problems/number-of-unequal-triplets-in-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-arithmetic-triplets
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int arithmeticTriplets(vector<int>& A, int diff) {
        int N = A.size(), ans = 0;
        unordered_set<int> s(begin(A), end(A));
        for (int n : A) {
            ans += s.count(n + diff) && s.count(n + 2 * diff);
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/number-of-arithmetic-triplets
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int arithmeticTriplets(vector<int>& A, int diff) {
        int N = A.size(), ans = 0, i = 0, j = 1, k = 2;
        for (; i < N; ++i) {
            while (j < N && A[j] < A[i] + diff) ++j;
            while (k < N && A[k] < A[i] + 2 * diff) ++k;
            if (j < N && k < N && A[j] == A[i] + diff && A[k] == A[i] + 2 * diff) ++ans;
        }
        return ans;
    }
};
```