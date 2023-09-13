# [2729. Check if The Number is Fascinating (Easy)](https://leetcode.com/problems/check-if-the-number-is-fascinating)

<p>You are given an integer <code>n</code> that consists of exactly <code>3</code> digits.</p>

<p>We call the number <code>n</code> <strong>fascinating</strong> if, after the following modification, the resulting number contains all the digits from <code>1</code> to <code>9</code> <strong>exactly</strong> once and does not contain any <code>0</code>'s:</p>

<ul>
	<li><strong>Concatenate</strong> <code>n</code> with the numbers <code>2 * n</code> and <code>3 * n</code>.</li>
</ul>

<p>Return <code>true</code><em> if </em><code>n</code><em> is fascinating, or </em><code>false</code><em> otherwise</em>.</p>

<p><strong>Concatenating</strong> two numbers means joining them together. For example, the concatenation of <code>121</code> and <code>371</code> is <code>121371</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 192
<strong>Output:</strong> true
<strong>Explanation:</strong> We concatenate the numbers n = 192 and 2 * n = 384 and 3 * n = 576. The resulting number is 192384576. This number contains all the digits from 1 to 9 exactly once.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 100
<strong>Output:</strong> false
<strong>Explanation:</strong> We concatenate the numbers n = 100 and 2 * n = 200 and 3 * n = 300. The resulting number is 100200300. This number does not satisfy any of the conditions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>100 &lt;= n &lt;= 999</code></li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-the-number-is-fascinating
// Author: github.com/lzl124631x
// Time: O(D) where D is the number of digits of N
// Space: O(D)
class Solution {
public:
    bool isFascinating(int n) {
        auto s = to_string(n) + to_string(2 * n) + to_string(3 * n);
        int cnt[10] = {};
        for (char c : s) {
            if (c == '0') return false;
            if (++cnt[c - '0'] > 1) return false;
        }
        return true;
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/check-if-the-number-is-fascinating
// Author: github.com/lzl124631x
// Time: O(D) where D is the number of digits of N
// Space: O(DlogD)
cclass Solution {
public:
    bool isFascinating(int n) {
        auto s = to_string(n) + to_string(2 * n) + to_string(3 * n);
        sort(begin(s), end(s));
        return s == "123456789";
    }
};
```