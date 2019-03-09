# [680. Valid Palindrome II (Easy)](https://leetcode.com/problems/valid-palindrome-ii/)

<p>
Given a non-empty string <code>s</code>, you may delete <b>at most</b> one character.  Judge whether you can make it a palindrome.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "aba"
<b>Output:</b> True
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "abca"
<b>Output:</b> True
<b>Explanation:</b> You could delete the character 'c'.
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The string will only contain lowercase characters a-z.
The maximum length of the string is 50000.</li>
</ol>
<p></p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Yahoo](https://leetcode.com/company/yahoo)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Valid Palindrome (Easy)](https://leetcode.com/problems/valid-palindrome/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/valid-palindrome-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1, del = 1;
        for (; i < j; ++i, --j) {
            if (s[i] == s[j]) continue;
            if (isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1)) return true;
            return false;
        }
        return true;
    }
};
```