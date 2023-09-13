# [2229. Check if an Array Is Consecutive (Easy)](https://leetcode.com/problems/check-if-an-array-is-consecutive/)

<p>Given an integer array <code>nums</code>, return <code>true</code> <em>if </em><code>nums</code><em> is <strong>consecutive</strong>, otherwise return </em><code>false</code><em>.</em></p>

<p>An array is <strong>consecutive </strong>if it contains every number in the range <code>[x, x + n - 1]</code> (<strong>inclusive</strong>), where <code>x</code> is the minimum number in the array and <code>n</code> is the length of the array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,4,2]
<strong>Output:</strong> true
<strong>Explanation:</strong>
The minimum value is 1 and the length of nums is 4.
All of the values in the range [x, x + n - 1] = [1, 1 + 4 - 1] = [1, 4] = (1, 2, 3, 4) occur in nums.
Therefore, nums is consecutive.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,3]
<strong>Output:</strong> false
<strong>Explanation:</strong>
The minimum value is 1 and the length of nums is 2.
The value 2 in the range [x, x + n - 1] = [1, 1 + 2 - 1], = [1, 2] = (1, 2) does not occur in nums.
Therefore, nums is not consecutive.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,5,4]
<strong>Output:</strong> true
<strong>Explanation:</strong>
The minimum value is 3 and the length of nums is 3.
All of the values in the range [x, x + n - 1] = [3, 3 + 3 - 1] = [3, 5] = (3, 4, 5) occur in nums.
Therefore, nums is consecutive.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Turbot](https://leetcode.com/company/turbot)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Binary Tree Longest Consecutive Sequence (Medium)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/)
* [Binary Tree Longest Consecutive Sequence II (Medium)](https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/)
* [Consecutive Characters (Easy)](https://leetcode.com/problems/consecutive-characters/)

## Solution 1. Sorting

```cpp
// OJ: https://leetcode.com/problems/check-if-an-array-is-consecutive/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isConsecutive(vector<int>& A) {
        sort(begin(A), end(A));
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] != A[i - 1] + 1) return false;
        }
        return  true;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/check-if-an-array-is-consecutive/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isConsecutive(vector<int>& A) {
        int mn = *min_element(begin(A), end(A));
        vector<bool> seen(A.size());
        for (int n : A) {
            n -= mn;
            if (n < 0 || n >= A.size() || seen[n]) return false;
            seen[n] = true;
        }
        return true;
    }
};
```

## Discuss

https://leetcode.com/problems/check-if-an-array-is-consecutive/discuss/1943451/