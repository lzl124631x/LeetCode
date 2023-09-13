# [258. Add Digits (Easy)](https://leetcode.com/problems/add-digits/)

<p>Given an integer <code>num</code>, repeatedly add all its digits until the result has only one digit, and return it.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = 38
<strong>Output:</strong> 2
<strong>Explanation:</strong> The process is
38 --&gt; 3 + 8 --&gt; 11
11 --&gt; 1 + 1 --&gt; 2 
Since 2 has only one digit, return it.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = 0
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you do it without any loop/recursion in <code>O(1)</code> runtime?</p>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Simulation](https://leetcode.com/tag/simulation/), [Number Theory](https://leetcode.com/tag/number-theory/)

**Similar Questions**:
* [Happy Number (Easy)](https://leetcode.com/problems/happy-number/)
* [Sum of Digits in the Minimum Number (Easy)](https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/)
* [Sum of Digits of String After Convert (Easy)](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/)
* [Minimum Sum of Four Digit Number After Splitting Digits (Easy)](https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/)

## Solution 1. 

The value we're asked to compute is the so-called [Digital Root](https://en.wikipedia.org/wiki/Digital_root).

```cpp
// OJ: https://leetcode.com/problems/add-digits/
// Author: github.com/lzl124631x
// Time: O(lgN)
// Space: O(1)
class Solution {
public:
    int addDigits(int n) {
        while (n > 9) {
            int next = 0;
            for (; n; n /= 10) next += n % 10;
            n = next;
        }
        return n;
    }
};
```

## Solution 2.

See explanation in https://leetcode.com/problems/add-digits/solution/.

```cpp
// OJ: https://leetcode.com/problems/add-digits/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int addDigits(int num) {
        return num ? (num % 9 ? num % 9 : 9) : 0;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/add-digits/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int addDigits(int num) {
        return num ? 1 + (num - 1) % 9 : 0;
    }
};
```