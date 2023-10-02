# [1704. Determine if String Halves Are Alike (Easy)](https://leetcode.com/problems/determine-if-string-halves-are-alike/)

<p>You are given a string <code>s</code> of even length. Split this string into two halves of equal lengths, and let <code>a</code> be the first half and <code>b</code> be the second half.</p>

<p>Two strings are <strong>alike</strong> if they have the same number of vowels (<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, <code>'u'</code>, <code>'A'</code>, <code>'E'</code>, <code>'I'</code>, <code>'O'</code>, <code>'U'</code>). Notice that <code>s</code> contains uppercase and lowercase letters.</p>

<p>Return <code>true</code><em> if </em><code>a</code><em> and </em><code>b</code><em> are <strong>alike</strong></em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "book"
<strong>Output:</strong> true
<strong>Explanation:</strong>&nbsp;a = "b<u>o</u>" and b = "<u>o</u>k". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "textbook"
<strong>Output:</strong> false
<strong>Explanation:</strong>&nbsp;a = "t<u>e</u>xt" and b = "b<u>oo</u>k". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "MerryChristmas"
<strong>Output:</strong> false
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "AbCdEfGh"
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s.length</code> is even.</li>
	<li><code>s</code> consists of <strong>uppercase and lowercase</strong> letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/determine-if-string-halves-are-alike/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    int count(string s) {
        int cnt = 0;
        for (char c : s) {
            c = tolower(c);
            cnt += c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }
        return cnt;
    }
public:
    bool halvesAreAlike(string s) {
        return count(s.substr(0, s.size() / 2)) == count(s.substr(s.size() / 2));
    }
};
```

Or 

```cpp
// OJ: https://leetcode.com/problems/determine-if-string-halves-are-alike/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int count(string &s, int begin, int end) {
        int cnt = 0;
        for (int i = begin; i < end; ++i) {
            char c = tolower(s[i]);
            cnt += c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }
        return cnt;
    }
public:
    bool halvesAreAlike(string s) {
        return count(s, 0, s.size() / 2) == count(s, s.size() / 2, s.size());
    }
};
```