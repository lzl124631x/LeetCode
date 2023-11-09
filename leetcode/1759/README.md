# [1759. Count Number of Homogenous Substrings (Medium)](https://leetcode.com/problems/count-number-of-homogenous-substrings)

<p>Given a string <code>s</code>, return <em>the number of <strong>homogenous</strong> substrings of </em><code>s</code><em>.</em> Since the answer may be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>A string is <strong>homogenous</strong> if all the characters of the string are the same.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abbcccaa&quot;
<strong>Output:</strong> 13
<strong>Explanation:</strong> The homogenous substrings are listed as below:
&quot;a&quot;   appears 3 times.
&quot;aa&quot;  appears 1 time.
&quot;b&quot;   appears 2 times.
&quot;bb&quot;  appears 1 time.
&quot;c&quot;   appears 3 times.
&quot;cc&quot;  appears 2 times.
&quot;ccc&quot; appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;xy&quot;
<strong>Output:</strong> 2
<strong>Explanation:</strong> The homogenous substrings are &quot;x&quot; and &quot;y&quot;.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;zzzzz&quot;
<strong>Output:</strong> 15
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase letters.</li>
</ul>

**Companies**:
[Virtu Financial](https://leetcode.com/company/virtu)

**Related Topics**:  
[Math](https://leetcode.com/tag/math), [String](https://leetcode.com/tag/string)

**Similar Questions**:
* [Consecutive Characters (Easy)](https://leetcode.com/problems/consecutive-characters)
* [Number of Substrings With Only 1s (Medium)](https://leetcode.com/problems/number-of-substrings-with-only-1s)
* [Sum of Subarray Ranges (Medium)](https://leetcode.com/problems/sum-of-subarray-ranges)
* [Count the Number of Good Subarrays (Medium)](https://leetcode.com/problems/count-the-number-of-good-subarrays)

**Hints**:
* A string of only 'a's of length k contains k choose 2 homogenous substrings.
* Split the string into substrings where each substring contains only one letter, and apply the formula on each substring's length.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-number-of-homogenous-substrings
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countHomogenous(string s) {
        long N = s.size(), cnt = 0, ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < N; ++i) {
            ++cnt;
            if (i == N - 1 || s[i + 1] != s[i]) {
                ans = (ans + cnt * (cnt + 1) / 2 % mod) % mod;
                cnt = 0;
            }
        }
        return ans;
    }
};
```