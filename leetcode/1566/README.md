# [1566. Detect Pattern of Length M Repeated K or More Times (Easy)](https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times)

<p>Given an array of positive integers <code>arr</code>,&nbsp; find a pattern of length <code>m</code> that is repeated <code>k</code> or more times.</p>

<p>A <strong>pattern</strong> is a subarray (consecutive sub-sequence) that consists of one or more values, repeated multiple times <strong>consecutively </strong>without overlapping. A pattern is defined by its length and the number of repetitions.</p>

<p>Return&nbsp;<code>true</code>&nbsp;<em>if there exists a pattern of length</em>&nbsp;<code>m</code>&nbsp;<em>that is repeated</em>&nbsp;<code>k</code>&nbsp;<em>or more times, otherwise return</em>&nbsp;<code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,4,4,4,4], m = 1, k = 3
<strong>Output:</strong> true
<strong>Explanation: </strong>The pattern <strong>(4)</strong> of length 1 is repeated 4 consecutive times. Notice that pattern can be repeated k or more times but not less.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,1,2,1,1,1,3], m = 2, k = 2
<strong>Output:</strong> true
<strong>Explanation: </strong>The pattern <strong>(1,2)</strong> of length 2 is repeated 2 consecutive times. Another valid pattern <strong>(2,1) is</strong> also repeated 2 times.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,1,2,1,3], m = 2, k = 3
<strong>Output:</strong> false
<strong>Explanation: </strong>The pattern (1,2) is of length 2 but is repeated only 2 times. There is no pattern of length 2 that is repeated 3 or more times.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,3,1,2], m = 2, k = 2
<strong>Output:</strong> false
<strong>Explanation: </strong>Notice that the pattern (1,2) exists twice but not consecutively, so it doesn't count.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> arr = [2,2,2,2], m = 2, k = 3
<strong>Output:</strong> false
<strong>Explanation: </strong>The only pattern of length 2 is (2,2) however it's repeated only twice. Notice that we do not count overlapping repetitions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= arr.length &lt;= 100</code></li>
	<li><code>1 &lt;= arr[i] &lt;= 100</code></li>
	<li><code>1 &lt;= m&nbsp;&lt;= 100</code></li>
	<li><code>2 &lt;= k&nbsp;&lt;= 100</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
// Author: github.com/lzl124631x
// Time: O(NMK)
// Space: O(1)
class Solution {
public:
    bool containsPattern(vector<int>& A, int m, int k) {
        int N = A.size();
        if (m * k > A.size()) return false;
        for (int i = 0; i <= N - m * k; ++i) {
            bool valid = true;
            for (int j = 1; j < k && valid; ++j) {
                for (int x = 0; x < m && valid; ++x) {
                    if (A[i + m * j + x] != A[i + x]) valid = false;
                }
            }
            if (valid) return true;
        }
        return false;
    }
};
```