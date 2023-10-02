# [2108. Find First Palindromic String in the Array (Easy)](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/)

<p>Given an array of strings <code>words</code>, return <em>the first <strong>palindromic</strong> string in the array</em>. If there is no such string, return <em>an <strong>empty string</strong> </em><code>""</code>.</p>

<p>A string is <strong>palindromic</strong> if it reads the same forward and backward.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["abc","car","ada","racecar","cool"]
<strong>Output:</strong> "ada"
<strong>Explanation:</strong> The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["notapalindrome","racecar"]
<strong>Output:</strong> "racecar"
<strong>Explanation:</strong> The first and only string that is palindromic is "racecar".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["def","ghi"]
<strong>Output:</strong> ""
<strong>Explanation:</strong> There are no palindromic strings, so the empty string is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> consists only of lowercase English letters.</li>
</ul>


**Similar Questions**:
* [Valid Palindrome (Easy)](https://leetcode.com/problems/valid-palindrome/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(W)
class Solution {
public:
    string firstPalindrome(vector<string>& A) {
        for (auto &s : A) {
            string r(rbegin(s), rend(s));
            if (r == s) return s;
        }
        return "";
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
// Author: github.com/lzl124631x
// Time: O(NW)
// Space: O(1)
class Solution {
    bool isPalindrome(string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
    }
public:
    string firstPalindrome(vector<string>& A) {
        for (auto &s : A) {
            if (isPalindrome(s)) return s;
        }
        return "";
    }
};
```

## Discuss

https://leetcode.com/problems/find-first-palindromic-string-in-the-array/discuss/1635048/C%2B%2B-Straightforward