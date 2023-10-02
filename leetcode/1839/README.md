# [1839. Longest Substring Of All Vowels in Order (Medium)](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/)

<p>A string is considered <strong>beautiful</strong> if it satisfies the following conditions:</p>

<ul>
	<li>Each of the 5 English vowels (<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, <code>'u'</code>) must appear <strong>at least once</strong> in it.</li>
	<li>The letters must be sorted in <strong>alphabetical order</strong> (i.e. all <code>'a'</code>s before <code>'e'</code>s, all <code>'e'</code>s before <code>'i'</code>s, etc.).</li>
</ul>

<p>For example, strings <code>"aeiou"</code> and <code>"aaaaaaeiiiioou"</code> are considered <strong>beautiful</strong>, but <code>"uaeio"</code>, <code>"aeoiu"</code>, and <code>"aaaeeeooo"</code> are <strong>not beautiful</strong>.</p>

<p>Given a string <code>word</code> consisting of English vowels, return <em>the <strong>length of the longest beautiful substring</strong> of </em><code>word</code><em>. If no such substring exists, return </em><code>0</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word = "aeiaaio<u>aaaaeiiiiouuu</u>ooaauuaeiu"
<strong>Output:</strong> 13
<b>Explanation:</b> The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word = "aeeeiiiioooauuu<u>aeiou</u>"
<strong>Output:</strong> 5
<b>Explanation:</b> The longest beautiful substring in word is "aeiou" of length 5.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> word = "a"
<strong>Output:</strong> 0
<b>Explanation:</b> There is no beautiful substring, so return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>word</code> consists of characters <code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, and <code>'u'</code>.</li>
</ul>


**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int i = 0, N = s.size(), ans = 0;
        string ch = "aeiou";
        while (i < N) {
            int start = i;
            bool valid = true;
            for (char c : ch) {
                int j = i;
                while (i < N && s[i] == c) ++i;
                valid = i > j;
                if (!valid) break;
            }
            if (valid) ans = max(ans, i - start);
            while (i < N && s[i] != 'a') ++i;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int N = s.size(), cnt = 1, len = 1, ans = 0;
        for (int i = 1; i != N; ++i) {
            if (s[i - 1] == s[i]) ++len;
            else if (s[i - 1] < s[i]) {
                ++len;
                ++cnt;
            } else {
                cnt = 1;
                len = 1;
            }
            if (cnt == 5) ans = max(ans, len);
        }
        return ans;
    }
};
```