# [2414. Length of the Longest Alphabetical Continuous Substring (Medium)](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring)

<p>An <strong>alphabetical continuous string</strong> is a string consisting of consecutive letters in the alphabet. In other words, it is any substring of the string <code>"abcdefghijklmnopqrstuvwxyz"</code>.</p>
<ul>
	<li>For example, <code>"abc"</code> is an alphabetical continuous string, while <code>"acb"</code> and <code>"za"</code> are not.</li>
</ul>
<p>Given a string <code>s</code> consisting of lowercase letters only, return the <em>length of the <strong>longest</strong> alphabetical continuous substring.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "abacaba"
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 4 distinct continuous substrings: "a", "b", "c" and "ab".
"ab" is the longest continuous substring.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcde"
<strong>Output:</strong> 5
<strong>Explanation:</strong> "abcde" is the longest continuous substring.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of only English lowercase letters.</li>
</ul>

**Companies**:
[TikTok](https://leetcode.com/company/tiktok)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Longest Consecutive Sequence (Medium)](https://leetcode.com/problems/longest-consecutive-sequence/)
* [Arithmetic Slices (Medium)](https://leetcode.com/problems/arithmetic-slices/)
* [Max Consecutive Ones (Easy)](https://leetcode.com/problems/max-consecutive-ones/)
* [Maximum Number of Vowels in a Substring of Given Length (Medium)](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)
* [Number of Zero-Filled Subarrays (Medium)](https://leetcode.com/problems/number-of-zero-filled-subarrays/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 0, N = s.size();
        for (int i = 0; i < N; ) {
            int start = i++;
            while (i < N && s[i] == s[i - 1] + 1) ++i;
            ans = max(ans, i - start);
        }
        return ans;
    }
};
```