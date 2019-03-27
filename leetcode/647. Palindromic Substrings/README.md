# [647. Palindromic Substrings (Medium)](https://leetcode.com/problems/palindromic-substrings/)

<p>Given a string, your task is to count how many palindromic substrings in this string.</p>

<p>The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> "abc"
<b>Output:</b> 3
<b>Explanation:</b> Three palindromic strings: "a", "b", "c".
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> "aaa"
<b>Output:</b> 6
<b>Explanation:</b> Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
</pre>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The input string length won't exceed 1000.</li>
</ol>

<p>&nbsp;</p>


**Companies**:  
[Pure Storage](https://leetcode.com/company/pure-storage), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Coursera](https://leetcode.com/company/coursera), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Palindromic Substring (Medium)](https://leetcode.com/problems/longest-palindromic-substring/)
* [Longest Palindromic Subsequence (Medium)](https://leetcode.com/problems/longest-palindromic-subsequence/)
* [Palindromic Substrings (Medium)](https://leetcode.com/problems/palindromic-substrings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/palindromic-substrings/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size(), ans = N;
        for (int i = 1; i + 1 < N; ++i) {
            for (int j = 1; i - j >= 0 && i + j < N && s[i - j] == s[i + j]; ++j, ++ans);
        }
        for (int i = 0; i + 1 < N; ++i) {
            for (int j = 0; i - j >= 0 && i + 1 + j < N && s[i - j] == s[i + 1 + j]; ++j, ++ans);
        }
        return ans;
    }
};
```