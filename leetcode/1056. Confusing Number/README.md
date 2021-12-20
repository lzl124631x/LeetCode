# [1056. Confusing Number (Easy)](https://leetcode.com/problems/confusing-number/)

<p>A <strong>confusing number</strong> is a number that when rotated <code>180</code> degrees becomes a different number with <strong>each digit valid</strong>.</p>

<p>We can rotate digits of a number by <code>180</code> degrees to form new digits.</p>

<ul>
	<li>When <code>0</code>, <code>1</code>, <code>6</code>, <code>8</code>, and <code>9</code> are rotated <code>180</code> degrees, they become <code>0</code>, <code>1</code>, <code>9</code>, <code>8</code>, and <code>6</code> respectively.</li>
	<li>When <code>2</code>, <code>3</code>, <code>4</code>, <code>5</code>, and <code>7</code> are rotated <code>180</code> degrees, they become <strong>invalid</strong>.</li>
</ul>

<p>Note that after rotating a number, we can ignore leading zeros.</p>

<ul>
	<li>For example, after rotating <code>8000</code>, we have <code>0008</code> which is considered as just <code>8</code>.</li>
</ul>

<p>Given an integer <code>n</code>, return <code>true</code><em> if it is a <strong>confusing number</strong>, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/03/23/1268_1.png" style="width: 281px; height: 121px;">
<pre><strong>Input:</strong> n = 6
<strong>Output:</strong> true
<strong>Explanation:</strong> We get 9 after rotating 6, 9 is a valid number, and 9 != 6.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/03/23/1268_2.png" style="width: 312px; height: 121px;">
<pre><strong>Input:</strong> n = 89
<strong>Output:</strong> true
<strong>Explanation:</strong> We get 68 after rotating 89, 86 is a valid number and 86 != 89.
</pre>

<p><strong>Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/03/26/1268_3.png" style="width: 301px; height: 121px;">
<pre><strong>Input:</strong> n = 11
<strong>Output:</strong> false
<strong>Explanation:</strong> We get 11 after rotating 11, 11 is a valid number but the value remains the same, thus 11 is not a confusing number
</pre>

<p><strong>Example 4:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/03/23/1268_4.png" style="width: 302px; height: 121px;">
<pre><strong>Input:</strong> n = 25
<strong>Output:</strong> false
<strong>Explanation:</strong> We get an invalid number after rotating 25.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Strobogrammatic Number (Easy)](https://leetcode.com/problems/strobogrammatic-number/)
* [Confusing Number II (Hard)](https://leetcode.com/problems/confusing-number-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/confusing-number/
// Author: github.com/lzl124631x
// Time: O(lgN)
// Space: O(1)
class Solution {
public:
    bool confusingNumber(int n) {
        int m[10] = {0,1,-1,-1,-1,-1,9,-1,8,6}, r = 0, num = n;
        while (n) {
            if (m[n % 10] == -1) return false;
            r = r * 10 + m[n % 10];
            n /= 10;
        }
        return num != r;
    }
};
```