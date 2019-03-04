# [702. Search in a Sorted Array of Unknown Size (Medium)](https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/)

<p>Given an&nbsp;integer array sorted in ascending order, write a function to search <code>target</code> in <code>nums</code>.&nbsp; If <code>target</code> exists, then return its index, otherwise return <code>-1</code>. <strong>However, the array size is unknown to you</strong>. You may only access the array using an <code>ArrayReader</code>&nbsp;interface, where&nbsp;<code>ArrayReader.get(k)</code> returns the element of the array at index <code>k</code>&nbsp;(0-indexed).</p>

<p>You may assume all integers in the array are less than&nbsp;<code>10000</code>, and if you access the array out of bounds, <code>ArrayReader.get</code> will return <code>2147483647</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <code>array</code> = [-1,0,3,5,9,12], <code>target</code> = 9
<strong>Output:</strong> 4
<strong>Explanation:</strong> 9 exists in <code>nums</code> and its index is 4
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <code>array</code> = [-1,0,3,5,9,12], <code>target</code> = 2
<strong>Output:</strong> -1
<strong>Explanation:</strong> 2 does not exist in <code>nums</code> so return -1</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li>You may assume that all elements in the array are unique.</li>
	<li>The value of each element in the array&nbsp;will be in the range <code>[-9999, 9999]</code>.</li>
</ol>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Binary Search (Easy)](https://leetcode.com/problems/binary-search/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int minVal = reader.get(0);
        int L = 0, R = 9999 - minVal;
        while (L <= R) {
            int M = (L + R) / 2;
            int val = reader.get(M);
            if (val == target) return M;
            if (val > target) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/discuss/151685/Shortest-and-cleanest-Java-solution-so-far
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int L, R = 1;
        while (reader.get(R) < target) R *= 2;
        L = R / 2;
        while (L <= R) {
            int M = (L + R) / 2;
            int val = reader.get(M);
            if (val == target) return M;
            if (val > target) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
};
```