# [12. Integer to Roman (Medium)](https://leetcode.com/problems/integer-to-roman/)

<p>Roman numerals are represented by seven different symbols:&nbsp;<code>I</code>, <code>V</code>, <code>X</code>, <code>L</code>, <code>C</code>, <code>D</code> and <code>M</code>.</p>

<pre><strong>Symbol</strong>       <strong>Value</strong>
I             1
V             5
X             10
L             50
C             100
D             500
M             1000</pre>

<p>For example,&nbsp;<code>2</code> is written as <code>II</code>&nbsp;in Roman numeral, just two one's added together. <code>12</code> is written as&nbsp;<code>XII</code>, which is simply <code>X + II</code>. The number <code>27</code> is written as <code>XXVII</code>, which is <code>XX + V + II</code>.</p>

<p>Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not <code>IIII</code>. Instead, the number four is written as <code>IV</code>. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as <code>IX</code>. There are six instances where subtraction is used:</p>

<ul>
	<li><code>I</code> can be placed before <code>V</code> (5) and <code>X</code> (10) to make 4 and 9.&nbsp;</li>
	<li><code>X</code> can be placed before <code>L</code> (50) and <code>C</code> (100) to make 40 and 90.&nbsp;</li>
	<li><code>C</code> can be placed before <code>D</code> (500) and <code>M</code> (1000) to make 400 and 900.</li>
</ul>

<p>Given an integer, convert it to a roman numeral.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = 3
<strong>Output:</strong> "III"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = 4
<strong>Output:</strong> "IV"
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = 9
<strong>Output:</strong> "IX"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> num = 58
<strong>Output:</strong> "LVIII"
<strong>Explanation:</strong> L = 50, V = 5, III = 3.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> num = 1994
<strong>Output:</strong> "MCMXCIV"
<strong>Explanation:</strong> M = 1000, CM = 900, XC = 90 and IV = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 3999</code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Roman to Integer (Easy)](https://leetcode.com/problems/roman-to-integer/)
* [Integer to English Words (Hard)](https://leetcode.com/problems/integer-to-english-words/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/integer-to-roman/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
    string symbols = "MDCLXVI";
    int values[7] = {1000,500,100,50,10,5,1};
public:
    string intToRoman(int num) {
        string ans;
        for (int i = 0; i < 7; i += 2) {
            int d = num / values[i];
            if (d == 0) continue;
            if (d <= 3) {
                while (d--) ans += symbols[i];
            } else if (d == 4) {
                ans += symbols[i];
                ans += symbols[i - 1];
            } else if (d == 5) {
                ans += symbols[i - 1];
            } else if (d <= 8) {
                ans += symbols[i - 1];
                for (int j = 5; j < d; ++j) ans += symbols[i];
            } else {
                ans += symbols[i];
                ans += symbols[i - 2];
            }
            num %= values[i];
        }
        return ans;
    }
};
```