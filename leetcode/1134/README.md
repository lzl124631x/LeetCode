# [1134. Armstrong Number (Easy)](https://leetcode.com/problems/armstrong-number/)

<p>Given an integer <code>n</code>, return <code>true</code> <em>if and only if it is an <strong>Armstrong number</strong></em>.</p>

<p>The <code>k</code>-digit number <code>n</code> is an Armstrong number if and only if the <code>k<sup>th</sup></code> power of each digit sums to <code>n</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 153
<strong>Output:</strong> true
<strong>Explanation:</strong> 153 is a 3-digit number, and 153 = 1<sup>3</sup> + 5<sup>3</sup> + 3<sup>3</sup>.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 123
<strong>Output:</strong> false
<strong>Explanation:</strong> 123 is a 3-digit number, and 123 != 1<sup>3</sup> + 2<sup>3</sup> + 3<sup>3</sup> = 36.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>8</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/armstrong-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(lgN)
class Solution {
public:
    bool isArmstrong(int n) {
        long sum = 0, target = n;
        vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        for (int d : digits) sum += pow(d, digits.size());
        return sum == target;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/armstrong-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isArmstrong(int n) {
        long sum = 0, cnt = log10(n) + 1, target = n;
        while (n) {
            sum += pow(n % 10, cnt);
            n /= 10;
        }
        return sum == target;
    }
};
```