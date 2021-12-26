# [2119. A Number After a Double Reversal (Easy)](https://leetcode.com/problems/a-number-after-a-double-reversal/)

<p><strong>Reversing</strong> an integer means to reverse all its digits.</p>

<ul>
	<li>For example, reversing <code>2021</code> gives <code>1202</code>. Reversing <code>12300</code> gives <code>321</code> as the <strong>leading zeros are not retained</strong>.</li>
</ul>

<p>Given an integer <code>num</code>, <strong>reverse</strong> <code>num</code> to get <code>reversed1</code>, <strong>then reverse</strong> <code>reversed1</code> to get <code>reversed2</code>. Return <code>true</code> <em>if</em> <code>reversed2</code> <em>equals</em> <code>num</code>. Otherwise return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = 526
<strong>Output:</strong> true
<strong>Explanation:</strong> Reverse num to get 625, then reverse 625 to get 526, which equals num.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = 1800
<strong>Output:</strong> false
<strong>Explanation:</strong> Reverse num to get 81, then reverse 81 to get 18, which does not equal num.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = 0
<strong>Output:</strong> true
<strong>Explanation:</strong> Reverse num to get 0, then reverse 0 to get 0, which equals num.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10<sup>6</sup></code></li>
</ul>


**Similar Questions**:
* [Reverse Integer (Medium)](https://leetcode.com/problems/reverse-integer/)
* [Reverse Bits (Easy)](https://leetcode.com/problems/reverse-bits/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/a-number-after-a-double-reversal/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
    int reverse(int n) {
        int r = 0;
        while (n) {
            r = 10 * r + n % 10;
            n /= 10;
        }
        return r;
    }
public:
    bool isSameAfterReversals(int num) {
        return reverse(reverse(num)) == num;
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/a-number-after-a-double-reversal/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isSameAfterReversals(int num) {
        return !num || num % 10;
    }
};
```