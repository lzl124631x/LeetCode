# [647. Palindromic Substrings (Medium)](https://leetcode.com/problems/palindromic-substrings/)

<p>Given a string <code>s</code>, return <em>the number of <strong>palindromic substrings</strong> in it</em>.</p>

<p>A string is a <strong>palindrome</strong> when it reads the same backward as forward.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within the string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> Three palindromic strings: "a", "b", "c".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aaa"
<strong>Output:</strong> 6
<strong>Explanation:</strong> Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Salesforce](https://leetcode.com/company/salesforce), [Docusign](https://leetcode.com/company/docusign), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Palindromic Substring (Medium)](https://leetcode.com/problems/longest-palindromic-substring/)
* [Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/palindromic-substrings/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size(), ans = N; // initially all the single characters are counted
        for (int i = 0; i < N; ++i) { // odd length
            for (int j = 1; i - j >= 0 && i + j < N && s[i - j] == s[i + j]; ++j) ++ans;
        }
        for (int i = 1; i < N; ++i) { // even length
            for (int j = 0; i - j - 1 >= 0 && i + j < N && s[i - j - 1] == s[i + j]; ++j) ++ans;
        }
        return ans;
    }
};
```

## Solution 2. Manacher

```cpp
// OJ: https://leetcode.com/problems/palindromic-substrings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int countSubstrings(string s) {
        string t = "^*";
        for (char c : s) {
            t += c;
            t += '*';
        }
        t += '$';
        int N = s.size(), M = t.size();
        vector<int> r(M);
        r[1] = 1;
        int j = 1, ans = 0;
        for (int i = 2; i <= 2 * N; ++i) {
            int cur = j + r[j] > i ? min(r[2 * j - i], j + r[j] - i) : 1;
            while (t[i - cur] == t[i + cur]) ++cur;
            if (i + cur > j + r[j]) j = i;
            r[i] = cur;
            ans += r[i] / 2;
        }
        return ans;
    }
};
```