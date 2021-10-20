# [873. Length of Longest Fibonacci Subsequence (Medium)](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/)

<p>A sequence <code>x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>n</sub></code> is <em>Fibonacci-like</em> if:</p>

<ul>
	<li><code>n &gt;= 3</code></li>
	<li><code>x<sub>i</sub> + x<sub>i+1</sub> == x<sub>i+2</sub></code> for all <code>i + 2 &lt;= n</code></li>
</ul>

<p>Given a <b>strictly increasing</b> array <code>arr</code> of positive integers forming a sequence, return <em>the <strong>length</strong> of the longest Fibonacci-like subsequence of</em> <code>arr</code>. If one does not exist, return <code>0</code>.</p>

<p>A <strong>subsequence</strong> is derived from another sequence <code>arr</code> by deleting any number of elements (including none) from <code>arr</code>, without changing the order of the remaining elements. For example, <code>[3, 5, 8]</code> is a subsequence of <code>[3, 4, 5, 6, 7, 8]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,3,4,5,6,7,8]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The longest subsequence that is fibonacci-like: [1,2,3,5,8].</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,3,7,11,12,14,18]
<strong>Output:</strong> 3
<strong>Explanation</strong>:<strong> </strong>The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>1 &lt;= arr[i] &lt; arr[i + 1] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Baidu](https://leetcode.com/company/baidu)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Fibonacci Number (Easy)](https://leetcode.com/problems/fibonacci-number/)

## Solution 1. Hash Table

Because of the exponential growth of these terms, there are at most 43 terms in any Fibonacci-like subsequence that has maximum value `<= 1e9`.


```cpp
// OJ: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
// Author: github.com/lzl124631x
// Time: O(N^2 * logM) where N is the length of `A` and `M` is the maximum value of `A`
// Space: O(N)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> s(begin(A), end(A));
        int ans = 0, N = A.size();
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int a = A[i], b = A[j], len = 2, next = a + b;
                while (s.count(next)) {
                    a = b;
                    b = next;
                    next = a + b;
                    ++len;
                }
                if (len > 2) ans = max(ans, len);
            }
        }
        return ans;
    }
};
```