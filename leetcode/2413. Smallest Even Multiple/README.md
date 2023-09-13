# [2413. Smallest Even Multiple (Easy)](https://leetcode.com/problems/smallest-even-multiple)

<strong>positive</strong>
<code>n</code>
<em>the smallest positive integer that is a multiple of <strong>both</strong> </em>
<code>2</code>
<em> and </em>
<code>n</code>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> 10
<strong>Explanation:</strong> The smallest multiple of both 5 and 2 is 10.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 6
<strong>Output:</strong> 6
<strong>Explanation:</strong> The smallest multiple of both 6 and 2 is 6. Note that a number is a multiple of itself.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= n &lt;= 150</code></li>
</ul>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Number Theory](https://leetcode.com/tag/number-theory/)

**Similar Questions**:
* [Greatest Common Divisor of Strings (Easy)](https://leetcode.com/problems/greatest-common-divisor-of-strings/)
* [Three Divisors (Easy)](https://leetcode.com/problems/three-divisors/)
* [Find Greatest Common Divisor of Array (Easy)](https://leetcode.com/problems/find-greatest-common-divisor-of-array/)
* [Convert the Temperature (Easy)](https://leetcode.com/problems/convert-the-temperature/)
* [Minimum Cuts to Divide a Circle (Easy)](https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/smallest-even-multiple
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return n % 2 == 0 ? n : 2 * n;
    }
};
```