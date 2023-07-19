# [2315. Count Asterisks (Easy)](https://leetcode.com/problems/count-asterisks)

<p>You are given a string <code>s</code>, where every <strong>two</strong> consecutive vertical bars <code>'|'</code> are grouped into a <strong>pair</strong>. In other words, the 1<sup>st</sup> and 2<sup>nd</sup> <code>'|'</code> make a pair, the 3<sup>rd</sup> and 4<sup>th</sup> <code>'|'</code> make a pair, and so forth.</p>
<p>Return <em>the number of </em><code>'*'</code><em> in </em><code>s</code><em>, <strong>excluding</strong> the </em><code>'*'</code><em> between each pair of </em><code>'|'</code>.</p>
<p><strong>Note</strong> that each <code>'|'</code> will belong to <strong>exactly</strong> one pair.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "l|*e*et|c**o|*de|"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The considered characters are underlined: "<u>l</u>|*e*et|<u>c**o</u>|*de|".
The characters between the first and second '|' are excluded from the answer.
Also, the characters between the third and fourth '|' are excluded from the answer.
There are 2 asterisks considered. Therefore, we return 2.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "iamprogrammer"
<strong>Output:</strong> 0
<strong>Explanation:</strong> In this example, there are no asterisks in s. Therefore, we return 0.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "yo|uar|e**|b|e***au|tifu|l"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The considered characters are underlined: "<u>yo</u>|uar|<u>e**</u>|b|<u>e***au</u>|tifu|<u>l</u>". There are 5 asterisks considered. Therefore, we return 5.</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of lowercase English letters, vertical bars <code>'|'</code>, and asterisks <code>'*'</code>.</li>
	<li><code>s</code> contains an <strong>even</strong> number of vertical bars <code>'|'</code>.</li>
</ul>

**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-asterisks
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0, N = s.size(), i = 0;
        for (; i < N; ) {
            while (i < N && s[i] != '|') {
                ans += s[i] == '*';
                ++i;
            }
            ++i;
            while (i < N && s[i] != '|') ++i;
            ++i;
        }
        return ans;
    }
};
```