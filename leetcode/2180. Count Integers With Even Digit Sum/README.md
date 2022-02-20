# [2180. Count Integers With Even Digit Sum (Easy)](https://leetcode.com/problems/count-integers-with-even-digit-sum/)

<p>Given a positive integer <code>num</code>, return <em>the number of positive integers <strong>less than or equal to</strong></em> <code>num</code> <em>whose digit sums are <strong>even</strong></em>.</p>

<p>The <strong>digit sum</strong> of a positive integer is the sum of all its digits.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = 4
<strong>Output:</strong> 2
<strong>Explanation:</strong>
The only integers less than or equal to 4 whose digit sums are even are 2 and 4.    
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = 30
<strong>Output:</strong> 14
<strong>Explanation:</strong>
The 14 integers less than or equal to 30 whose digit sums are even are
2, 4, 6, 8, 11, 13, 15, 17, 19, 20, 22, 24, 26, and 28.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 1000</code></li>
</ul>


**Similar Questions**:
* [Sum of Digits of String After Convert (Easy)](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/contest/weekly-contest-281/problems/count-integers-with-even-digit-sum/
// Author: github.com/lzl124631x
// Time: O(NlgN)
// Space: O(1)
class Solution {
public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; ++i) {
            int n = i, sum = 0;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            ans += sum % 2 == 0;
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/count-integers-with-even-digit-sum/discuss/1784735