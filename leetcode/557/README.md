# [557. Reverse Words in a String III (Easy)](https://leetcode.com/problems/reverse-words-in-a-string-iii)

<p>Given a string <code>s</code>, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "Let's take LeetCode contest"
<strong>Output:</strong> "s'teL ekat edoCteeL tsetnoc"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "God Ding"
<strong>Output:</strong> "doG gniD"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>s</code> contains printable <strong>ASCII</strong> characters.</li>
	<li><code>s</code> does not contain any leading or trailing spaces.</li>
	<li>There is <strong>at least one</strong> word in <code>s</code>.</li>
	<li>All the words in <code>s</code> are separated by a single space.</li>
</ul>


**Companies**:
[Yandex](https://leetcode.com/company/yandex), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Bolt](https://leetcode.com/company/bolt), [Bloomberg](https://leetcode.com/company/bloomberg), [Paytm](https://leetcode.com/company/paytm), [Zappos](https://leetcode.com/company/zappos)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers), [String](https://leetcode.com/tag/string)

**Similar Questions**:
* [Reverse String II (Easy)](https://leetcode.com/problems/reverse-string-ii)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reverseWords(string s) {
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            int j = i;
            while (j < N && s[j] != ' ') ++j;
            int next = j;
            for (--j; i < j;) swap(s[i++], s[j--]);
            i = next;
        }
        return s;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0, begin = 0, N = s.size(); i <= N; ++i) {
            if (i == N || s[i] == ' ') {
                reverse(s.begin() + begin, s.begin() + i);
                begin = i + 1;
            }
        }
        return s;
    }
};
```