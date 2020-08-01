# [520. Detect Capital (Easy)](https://leetcode.com/problems/detect-capital/)

<p>Given a word, you need to judge whether the usage of capitals in it is right or not.</p>

<p>We define the usage of capitals in a word to be right when one of the following cases holds:</p>

<ol>
	<li>All letters in this word are capitals, like "USA".</li>
	<li>All letters in this word are not capitals, like "leetcode".</li>
	<li>Only the first letter in this word is capital, like "Google".</li>
</ol>
Otherwise, we define that this word doesn't use capitals in a right way.

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> "USA"
<b>Output:</b> True
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> "FlaG"
<b>Output:</b> False
</pre>

<p>&nbsp;</p>

<p><b>Note:</b> The input will be a non-empty word consisting of uppercase and lowercase latin letters.</p>


**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/detect-capital/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.size() < 2) return true;
        bool a = isupper(word[0]), b = isupper(word[1]), upper = a && b;
        if (!a && b) return false;
        for (int i = 2; i < word.size(); ++i) {
            if (isupper(word[i]) > 0 != upper) return false;
        }
        return true;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/detect-capital/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (char c : word) cnt += isupper(c) > 0;
        return !cnt || cnt == word.size() || cnt == 1 && isupper(word[0]);
    }
};
```