# [278. First Bad Version (Easy)](https://leetcode.com/problems/first-bad-version/)

<p>You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.</p>

<p>Suppose you have <code>n</code> versions <code>[1, 2, ..., n]</code> and you want to find out the first bad one, which causes all the following ones to be bad.</p>

<p>You are given an API <code>bool isBadVersion(version)</code> which returns whether <code>version</code> is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 5, bad = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong>
call isBadVersion(3) -&gt; false
call isBadVersion(5)&nbsp;-&gt; true
call isBadVersion(4)&nbsp;-&gt; true
Then 4 is the first bad version.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1, bad = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= bad &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Interactive](https://leetcode.com/tag/interactive/)

**Similar Questions**:
* [Find First and Last Position of Element in Sorted Array (Medium)](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
* [Search Insert Position (Easy)](https://leetcode.com/problems/search-insert-position/)
* [Guess Number Higher or Lower (Easy)](https://leetcode.com/problems/guess-number-higher-or-lower/)

## Solution 1. Binary Search (L <= R)

```cpp
// OJ: https://leetcode.com/problems/first-bad-version/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1, R = n;
        while (L <= R) {
            int M = L + (R - L) / 2;
            if (isBadVersion(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```

## Solution 2. Binary Search (L < R)

```cpp
// OJ: https://leetcode.com/problems/first-bad-version/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        int L = 1, R = n;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (isBadVersion(M)) R = M;
            else L = M + 1;
        }
        return L;
    }
};
```