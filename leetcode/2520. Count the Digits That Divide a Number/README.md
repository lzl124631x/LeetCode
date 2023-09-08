# [2520. Count the Digits That Divide a Number (Easy)](https://leetcode.com/problems/count-the-digits-that-divide-a-number)

<p>Given an integer <code>num</code>, return <em>the number of digits in <code>num</code> that divide </em><code>num</code>.</p>
<p>An integer <code>val</code> divides <code>nums</code> if <code>nums % val == 0</code>.</p>
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> num = 7
<strong>Output:</strong> 1
<strong>Explanation:</strong> 7 divides itself, hence the answer is 1.
</pre>
<p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> num = 121
<strong>Output:</strong> 2
<strong>Explanation:</strong> 121 is divisible by 1, but not 2. Since 1 occurs twice as a digit, we return 2.
</pre>
<p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> num = 1248
<strong>Output:</strong> 4
<strong>Explanation:</strong> 1248 is divisible by all of its digits, hence the answer is 4.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>9</sup></code></li>
	<li><code>num</code> does not contain <code>0</code> as one of its digits.</li>
</ul>

**Companies**:
[tcs](https://leetcode.com/company/tcs)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Happy Number (Easy)](https://leetcode.com/problems/happy-number/)
* [Self Dividing Numbers (Easy)](https://leetcode.com/problems/self-dividing-numbers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-the-digits-that-divide-a-number
// Author: github.com/lzl124631x
// Time: O(lgN)
// Space: O(1)
class Solution {
public:
    int countDigits(int n) {
        int m = n, ans = 0;
        while (m) {
            ans += n % (m % 10) == 0;
            m /= 10;
        }
        return ans;
    }
};
```