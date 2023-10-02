# [1763. Longest Nice Substring (Easy)](https://leetcode.com/problems/longest-nice-substring/)

<p>A string <code>s</code> is <strong>nice</strong> if, for every letter of the alphabet that <code>s</code> contains, it appears <strong>both</strong> in uppercase and lowercase. For example, <code>"abABB"</code> is nice because <code>'A'</code> and <code>'a'</code> appear, and <code>'B'</code> and <code>'b'</code> appear. However, <code>"abA"</code> is not because <code>'b'</code> appears, but <code>'B'</code> does not.</p>

<p>Given a string <code>s</code>, return <em>the longest <strong>substring</strong> of <code>s</code> that is <strong>nice</strong>. If there are multiple, return the substring of the <strong>earliest</strong> occurrence. If there are none, return an empty string</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "YazaAay"
<strong>Output:</strong> "aAa"
<strong>Explanation: </strong>"aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
"aAa" is the longest nice substring.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "Bb"
<strong>Output:</strong> "Bb"
<strong>Explanation:</strong> "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "c"
<strong>Output:</strong> ""
<strong>Explanation:</strong> There are no nice substrings.</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "dDzeE"
<strong>Output:</strong> "dD"
<strong>Explanation: </strong>Both "dD" and "eE" are the longest nice substrings.
As there are multiple longest nice substrings, return "dD" since it occurs earlier.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of uppercase and lowercase English letters.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1. Brute force

```cpp
// OJ: https://leetcode.com/problems/longest-nice-substring/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
    bool nice(string &s) {
        int up[26] = {}, low[26] = {};
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') up[c - 'A'] = 1;
            else low[c - 'a'] = 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (up[i] ^ low[i]) return false;
        }
        return true;
    }
public:
    string longestNiceSubstring(string s) {
        int N = s.size();
        for (int len = N; len >= 2; --len) {
            for (int i = 0; i <= N - len; ++i) {
                auto sub = s.substr(i, len);
                if (nice(sub)) return sub;
            }
        }
        return "";
    }
};
```

## Solution 2. Divide and Conquer

### Time complexity

The depth of the recursion is at most 26 levels, each of which we use a letter to split the windows.

In each recursion, we traverse the string in `O(N)` time. Even though we take substring, each letter is at most copied once, so overall each recursion is still `O(N)`.

So the overall time complexity is `O(26N) = O(N)`.

```cpp
// OJ: https://leetcode.com/problems/longest-nice-substring/
// Author: github.com/lzl124631x
// Time: O(N), the depth of the recursion is at most 26.
// Space: O(N)
class Solution {
    string ans;
public:
    string longestNiceSubstring(string s) {
        int state[26] = {};
        for (char c : s) {
            if (isupper(c)) state[c - 'A'] |= 2;
            else state[c - 'a'] |= 1;
        }
        int i = 0, N = s.size();
        while (i < N) {
            int j = i;
            while (j < N && state[tolower(s[j]) - 'a'] == 3) ++j; // find the window only contain characters that in state 3, i.e. having both upper and lower case
            int len = j - i;
            if (len == N) { // this string itself is nice, update the answer
                ans = s;
                break;
            }
            if (len > ans.size()) longestNiceSubstring(s.substr(i, len)); // handle this window recursively. The recursion is at most 26 levels.
            while (j < N && state[tolower(s[j]) - 'a'] != 3) ++j;
            i = j;
        } 
        return ans;
    }
};
```