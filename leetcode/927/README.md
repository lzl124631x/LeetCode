# [927. Three Equal Parts (Hard)](https://leetcode.com/problems/three-equal-parts/)

<p>You are given an array <code>arr</code> which consists of only zeros and ones, divide the array into <strong>three non-empty parts</strong> such that all of these parts represent the same binary value.</p>

<p>If it is possible, return any <code>[i, j]</code> with <code>i + 1 &lt; j</code>, such that:</p>

<ul>
	<li><code>arr[0], arr[1], ..., arr[i]</code> is the first part,</li>
	<li><code>arr[i + 1], arr[i + 2], ..., arr[j - 1]</code> is the second part, and</li>
	<li><code>arr[j], arr[j + 1], ..., arr[arr.length - 1]</code> is the third part.</li>
	<li>All three parts have equal binary values.</li>
</ul>

<p>If it is not possible, return <code>[-1, -1]</code>.</p>

<p>Note that the entire part is used when considering what binary value it represents. For example, <code>[1,1,0]</code> represents <code>6</code> in decimal, not <code>3</code>. Also, leading zeros <strong>are allowed</strong>, so <code>[0,1,1]</code> and <code>[1,1]</code> represent the same value.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> arr = [1,0,1,0,1]
<strong>Output:</strong> [0,3]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> arr = [1,1,0,1,1]
<strong>Output:</strong> [-1,-1]
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> arr = [1,1,0,0,1]
<strong>Output:</strong> [0,2]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>arr[i]</code> is <code>0</code> or <code>1</code></li>
</ul>


**Companies**:  
[Hotstar](https://leetcode.com/company/hotstar)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/three-equal-parts/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int sum = accumulate(begin(A), end(A), 0);
        if (sum % 3) return {-1,-1};
        if (sum == 0) return {0, (int)A.size() - 1};
        sum /= 3; 
        int last = A.size() - 1;
        while (A[last] == 0) --last;
        int trailingZeros = A.size() - last - 1, firstBegin = 0;
        while (A[firstBegin] == 0) ++firstBegin;
        int firstEnd = firstBegin, cnt = 0;
        while (cnt < sum) cnt += A[firstEnd++];
        for (int i = 0; i < trailingZeros; ++i, ++firstEnd);
        int j = firstEnd, i = firstBegin;
        while (A[j] == 0) ++j;
        while (i < firstEnd && A[i] == A[j]) ++i, ++j;
        if (i < firstEnd) return {-1, -1};
        int secondEnd = j;
        while (A[j] == 0) ++j;
        i = firstBegin;
        while (i < firstEnd && A[i] == A[j]) ++i, ++j;
        if (i < firstEnd) return {-1, -1};
        return {firstEnd - 1, secondEnd};
    }
};
```