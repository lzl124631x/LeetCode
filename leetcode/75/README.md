# [75. Sort Colors (Medium)](https://leetcode.com/problems/sort-colors/)

<p>Given an array <code>nums</code> with <code>n</code> objects colored red, white, or blue, sort them <strong><a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a> </strong>so that objects of the same color are adjacent, with the colors in the order red, white, and blue.</p>

<p>We will use the integers <code>0</code>, <code>1</code>, and <code>2</code> to represent the color red, white, and blue, respectively.</p>

<p>You must solve this problem without using the library's sort function.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [2,0,2,1,1,0]
<strong>Output:</strong> [0,0,1,1,2,2]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [2,0,1]
<strong>Output:</strong> [0,1,2]
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> [0]
</pre><p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> [1]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>nums[i]</code> is <code>0</code>, <code>1</code>, or <code>2</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong>&nbsp;Could you come up with a one-pass algorithm using only&nbsp;constant extra space?</p>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Apple](https://leetcode.com/company/apple), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Nvidia](https://leetcode.com/company/nvidia), [Swiggy](https://leetcode.com/company/swiggy)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Sort List (Medium)](https://leetcode.com/problems/sort-list/)
* [Wiggle Sort (Medium)](https://leetcode.com/problems/wiggle-sort/)
* [Wiggle Sort II (Medium)](https://leetcode.com/problems/wiggle-sort-ii/)

## Solution 1. Count Sort

```cpp
// OJ: https://leetcode.com/problems/sort-colors/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3, 0);
        for (int n : nums) cnt[n]++;
        int i = 0;
        for (int j = 0; j < 3; ++j) {
            while (cnt[j]--) nums[i++] = j;
        }
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/sort-colors/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, g = 0, b = 0;
        for (int n : nums) {
            if (n == 0) {
                nums[b++] = 2;
                nums[g++] = 1;
                nums[r++] = 0;
            } else if (n == 1) {
                nums[b++] = 2;
                nums[g++] = 1;
            } else nums[b++] = 2;
        }
    }
};
```

## Solution 3.

[Dutch national flag problem](https://en.wikipedia.org/wiki/Dutch_national_flag_problem)

```cpp
// OJ: https://leetcode.com/problems/sort-colors/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/sort-colors/solution/
class Solution {
public:
    void sortColors(vector<int>& A) {
        int zero = 0, two = A.size() - 1;
        for (int i = 0; i <= two; ) {
            if (A[i] == 0) {
                swap(A[i++], A[zero++]);
            } else if (A[i] == 2) {
                swap(A[i], A[two--]);
            } else ++i;
        }
    }
};
```