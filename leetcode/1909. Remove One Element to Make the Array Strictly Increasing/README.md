# [1909. Remove One Element to Make the Array Strictly Increasing (Easy)](https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/)

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code>, return <code>true</code> <em>if it can be made <strong>strictly increasing</strong> after removing <strong>exactly one</strong> element, or </em><code>false</code><em> otherwise. If the array is already strictly increasing, return </em><code>true</code>.</p>

<p>The array <code>nums</code> is <strong>strictly increasing</strong> if <code>nums[i - 1] &lt; nums[i]</code> for each index <code>(1 &lt;= i &lt; nums.length).</code></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,<u>10</u>,5,7]
<strong>Output:</strong> true
<strong>Explanation:</strong> By removing 10 at index 2 from nums, it becomes [1,2,5,7].
[1,2,5,7] is strictly increasing, so return true.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,1,2]
<strong>Output:</strong> false
<strong>Explanation:</strong>
[3,1,2] is the result of removing the element at index 0.
[2,1,2] is the result of removing the element at index 1.
[2,3,2] is the result of removing the element at index 2.
[2,3,1] is the result of removing the element at index 3.
No resulting array is strictly increasing, so return false.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> false
<strong>Explanation:</strong> The result of removing any element is [1,1].
[1,1] is not strictly increasing, so return false.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> true
<strong>Explanation:</strong> [1,2,3] is already strictly increasing, so return true.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


**Companies**:  
[eBay](https://leetcode.com/company/ebay)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    bool canBeIncreasing(vector<int>& A) {
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            bool good = true;
            int prev = 0;
            for (int j = 0; j < N && good; ++j) {
                if (i == j) continue;
                good = A[j] > prev;
                prev = A[j];
            }
            if (good) return true;
        }
        return false;
    }
};
```

## Solution 2.

When `A[i] <= A[i - 1]`, we need to delete either `A[i]` or `A[i - 1]`.

* If `A[i] > A[i - 2]`, we should delete `A[i - 1]`. Then let `prev = A[i]`.
* If `A[i] <= A[i - 2]`, we should delete `A[i]`. Then keep `prev = A[i - 1]`.

```cpp
// OJ: https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canBeIncreasing(vector<int>& A) {
        int N = A.size(), prev = A[0];
        bool used = false;
        for (int i = 1; i < N; ++i) {
            if (A[i] > prev) prev = A[i];
            else {
                if (used) return false;
                used = true;
                if (i - 2 < 0 || A[i - 2] < A[i]) prev = A[i];
            }
        }
        return true;
    }
};
```