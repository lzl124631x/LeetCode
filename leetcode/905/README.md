# [905. Sort Array By Parity (Easy)](https://leetcode.com/problems/sort-array-by-parity/)

<p>Given an integer array <code>nums</code>, move all the even integers at the beginning of the array followed by all the odd integers.</p>

<p>Return <em><strong>any array</strong> that satisfies this condition</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,2,4]
<strong>Output:</strong> [2,4,3,1]
<strong>Explanation:</strong> The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 5000</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Sort Even and Odd Indices Independently (Easy)](https://leetcode.com/problems/sort-even-and-odd-indices-independently/)
* [Largest Number After Digit Swaps by Parity (Easy)](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/)

## Solution 1. STL

```cpp
// OJ: https://leetcode.com/problems/sort-array-by-parity/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(begin(A), end(A), [](int a, int b) { return a % 2 < b % 2; });
        return A;
    }
};
```

## Solution 2. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/sort-array-by-parity/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int i = 0, j = A.size() - 1; i < j; ++i, --j) {
            while (i < j && A[i] % 2 == 0) ++i;
            while (i < j && A[j] % 2 != 0) --j;
            if (i < j) swap(A[i], A[j]);
        }
        return A;
    }
};
```