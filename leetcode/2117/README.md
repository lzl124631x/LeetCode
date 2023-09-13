# [2117. Abbreviating the Product of a Range (Hard)](https://leetcode.com/problems/abbreviating-the-product-of-a-range)

<p>You are given two positive integers <code>left</code> and <code>right</code> with <code>left &lt;= right</code>. Calculate the <strong>product</strong> of all integers in the <strong>inclusive</strong> range <code>[left, right]</code>.</p>
<p>Since the product may be very large, you will <strong>abbreviate</strong> it following these steps:</p>
Count all <strong>trailing</strong> zeros in the product and <strong>remove</strong> them. Let us denote this count as <code>C</code>.

<ul>
    <li>For example, there are <code>3</code> trailing zeros in <code>1000</code>, and there are <code>0</code> trailing zeros in <code>546</code>.</li>
</ul>
Denote the remaining number of digits in the product as <code>d</code>. If <code>d &gt; 10</code>, then express the product as <code>&lt;pre&gt;...&lt;suf&gt;</code> where <code>&lt;pre&gt;</code> denotes the <strong>first</strong> <code>5</code> digits of the product, and <code>&lt;suf&gt;</code> denotes the <strong>last</strong> <code>5</code> digits of the product <strong>after</strong> removing all trailing zeros. If <code>d &lt;= 10</code>, we keep it unchanged.
<ul>
    <li>For example, we express <code>1234567654321</code> as <code>12345...54321</code>, but <code>1234567</code> is represented as <code>1234567</code>.</li>
</ul>
Finally, represent the product as a <strong>string</strong> <code>"&lt;pre&gt;...&lt;suf&gt;eC"</code>.
<ul>
    <li>For example, <code>12345678987600000</code> will be represented as <code>"12345...89876e5"</code>.</li>
</ul>
<p>Return <em>a string denoting the <strong>abbreviated product</strong> of all integers in the <strong>inclusive</strong> range</em> <code>[left, right]</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> left = 1, right = 4
<strong>Output:</strong> "24e0"
<strong>Explanation:</strong> The product is 1 × 2 × 3 × 4 = 24.
There are no trailing zeros, so 24 remains the same. The abbreviation will end with "e0".
Since the number of digits is 2, which is less than 10, we do not have to abbreviate it further.
Thus, the final representation is "24e0".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> left = 2, right = 11
<strong>Output:</strong> "399168e2"
<strong>Explanation:</strong> The product is 39916800.
There are 2 trailing zeros, which we remove to get 399168. The abbreviation will end with "e2".
The number of digits after removing the trailing zeros is 6, so we do not abbreviate it further.
Hence, the abbreviated product is "399168e2".
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> left = 371, right = 375
<strong>Output:</strong> "7219856259e3"
<strong>Explanation:</strong> The product is 7219856259000.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= left &lt;= right &lt;= 10<sup>4</sup></code></li>
</ul>

**Companies**:
[Avalara](https://leetcode.com/company/avalara)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Factorial Trailing Zeroes (Medium)](https://leetcode.com/problems/factorial-trailing-zeroes/)
* [Maximum Trailing Zeros in a Cornered Path (Medium)](https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/)
* [Find All Good Indices (Medium)](https://leetcode.com/problems/find-all-good-indices/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/abbreviating-the-product-of-a-range
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/abbreviating-the-product-of-a-range/solutions/1647115/modulo-and-double/
class Solution {
public:
    string abbreviateProduct(int left, int right) {
        long long suff = 1, c = 0, total = 0, max_suff = 100000000000; // total is the total number of digits (including trailing 0s), max_suff for getting the last 11 
        double pref = 1.0;
        for (int i = left; i <= right; ++i) {
            pref *= i;
            suff *= i;
            while (pref >= 100000) {
                pref /= 10;
                total = total == 0 ? 6 : total + 1; 
            }
            while (suff % 10 == 0) {
                suff /= 10;
                ++c;
            }
            suff %= max_suff;
        }
        string s = to_string(suff);
        return to_string((int)pref) + (total - c <= 10 ? "" : "...") 
                + (total - c < 5 ? "" : s.substr(s.size() - min(5LL, total - c - 5))) + "e" + to_string(c);
    }
};
```