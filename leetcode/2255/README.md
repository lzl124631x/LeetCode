# [2255. Count Prefixes of a Given String (Easy)](https://leetcode.com/problems/count-prefixes-of-a-given-string/)

<p>You are given a string array <code>words</code> and a string <code>s</code>, where <code>words[i]</code> and <code>s</code> comprise only of <strong>lowercase English letters</strong>.</p>

<p>Return <em>the <strong>number of strings</strong> in</em> <code>words</code> <em>that are a <strong>prefix</strong> of</em> <code>s</code>.</p>

<p>A <strong>prefix</strong> of a string is a substring that occurs at the beginning of the string. A <b>substring</b> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["a","b","c","ab","bc","abc"], s = "abc"
<strong>Output:</strong> 3
<strong>Explanation:</strong>
The strings in words which are a prefix of s = "abc" are:
"a", "ab", and "abc".
Thus the number of strings in words which are a prefix of s is 3.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["a","a"], s = "aa"
<strong>Output:</strong> 2
<strong>Explanation:
</strong>Both of the strings are a prefix of s. 
Note that the same string can occur multiple times in words, and it should be counted each time.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length, s.length &lt;= 10</code></li>
	<li><code>words[i]</code> and <code>s</code> consist of lowercase English letters <strong>only</strong>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Check If a Word Occurs As a Prefix of Any Word in a Sentence (Easy)](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/)
* [Check If String Is a Prefix of Array (Easy)](https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/)
* [Counting Words With a Given Prefix (Easy)](https://leetcode.com/problems/counting-words-with-a-given-prefix/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-prefixes-of-a-given-string/
// Author: github.com/lzl124631x
// Time: O(NS) where `N` is length of `A`, and `S` is length of `s`
// Space: O(S)
class Solution {
public:
    int countPrefixes(vector<string>& A, string s) {
        int ans = 0;
        for (auto &w : A) {
            ans += !s.compare(0, w.size(), w);
        }
        return ans;
    }
};
```