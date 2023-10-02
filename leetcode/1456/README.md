# [1456. Maximum Number of Vowels in a Substring of Given Length (Medium)](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)

<p>Given a string <code>s</code> and an integer <code>k</code>.</p>

<p>Return <em>the maximum number of vowel letters</em> in any substring of <code>s</code>&nbsp;with&nbsp;length <code>k</code>.</p>

<p><strong>Vowel letters</strong> in&nbsp;English are&nbsp;(a, e, i, o, u).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abciiidef", k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> The substring "iii" contains 3 vowel letters.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aeiou", k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> Any substring of length 2 contains 2 vowels.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "leetcode", k = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> "lee", "eet" and "ode" contain 2 vowels.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "rhythms", k = 4
<strong>Output:</strong> 0
<strong>Explanation:</strong> We can see that s doesn't have any vowel letters.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> s = "tryhard", k = 4
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10^5</code></li>
	<li><code>s</code>&nbsp;consists of lowercase English letters.</li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
</ul>

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1. Sliding window

We keep a sliding window of size `k`. Let `i` be the index of the new element getting into the window. We increment `cnt` if `s[i]` is vowel.

If `i >= k`, we need to pop `s[i - k]` out of the window and decrement `cnt` if `s[i - k]` is vowel. The answer is the maximum `cnt`.

```cpp
// OJ: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int cnt = 0, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i >= k) cnt -= isVowel(s[i - k]);
            cnt += isVowel(s[i]);
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```