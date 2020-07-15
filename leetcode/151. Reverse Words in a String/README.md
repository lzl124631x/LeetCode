# [151. Reverse Words in a String (Medium)](https://leetcode.com/problems/reverse-words-in-a-string/)

<p>Given an input string, reverse the string word by word.</p>

<p><strong>Example:&nbsp;&nbsp;</strong></p>

<pre><strong>Input:</strong> "<code>the sky is blue</code>",
<strong>Output:&nbsp;</strong>"<code>blue is sky the</code>".
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li>A word is defined as a sequence of non-space characters.</li>
	<li>Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.</li>
	<li>You need to reduce multiple spaces between two words to a single space in the reversed string.</li>
</ul>

<p><strong>Follow up:&nbsp;</strong>For C programmers, try to solve it <em>in-place</em> in <em>O</em>(1) space.</p>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Bloomberg](https://leetcode.com/company/bloomberg), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Nvidia](https://leetcode.com/company/nvidia), [Cisco](https://leetcode.com/company/cisco)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Reverse Words in a String II (Medium)](https://leetcode.com/problems/reverse-words-in-a-string-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reverse-words-in-a-string/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(1)
class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, j = 0;
        while (j < s.size()) {
            while (j < s.size() && s[j] == ' ') ++j;
            if (i != 0 && j != s.size()) s[i++] = ' ';
            while (j < s.size() && s[j] != ' ') s[i++] = s[j++];
        }
        s.erase(i);
        i = j = 0;
        while (i < s.size()) {
            j = i;
            while (j < s.size() && s[j] != ' ') ++j;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        reverse(s.begin(), s.end());
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/reverse-words-in-a-string/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        for (int i = s.size() - 1; i >= 0;) {
            while (i >= 0 && s[i] == ' ') --i;
            if (i < 0) break;
            if (ans.size()) ans += ' ';
            int j = i;
            while (j >= 0 && s[j] != ' ') --j;
            for (int k = j + 1; k <= i; ++k) ans += s[k];
            i = j;
        }
        return ans;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/reverse-words-in-a-string/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string word, ans;
        while (ss >> word) {
            reverse(word.begin(), word.end());
            if (ans.size()) ans += ' '; 
            ans += word;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

## Solution 4.

```cpp
// OJ: https://leetcode.com/problems/reverse-words-in-a-string/
// Author: github.com/lzl124631x
// Time: O(S)
// Space: O(S)
class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string word, ans;
        while (ss >> word) {
            if (ans.size()) word += " ";
            ans = word + ans;
        }
        return ans;
    }
};
```