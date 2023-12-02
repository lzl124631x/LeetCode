# [1662. Check If Two String Arrays are Equivalent (Easy)](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent)

<p>Given two string arrays <code>word1</code> and <code>word2</code>, return<em> </em><code>true</code><em> if the two arrays <strong>represent</strong> the same string, and </em><code>false</code><em> otherwise.</em></p>

<p>A string is <strong>represented</strong> by an array if the array elements concatenated <strong>in order</strong> forms the string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> word1 = [&quot;ab&quot;, &quot;c&quot;], word2 = [&quot;a&quot;, &quot;bc&quot;]
<strong>Output:</strong> true
<strong>Explanation:</strong>
word1 represents string &quot;ab&quot; + &quot;c&quot; -&gt; &quot;abc&quot;
word2 represents string &quot;a&quot; + &quot;bc&quot; -&gt; &quot;abc&quot;
The strings are the same, so return true.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> word1 = [&quot;a&quot;, &quot;cb&quot;], word2 = [&quot;ab&quot;, &quot;c&quot;]
<strong>Output:</strong> false
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> word1  = [&quot;abc&quot;, &quot;d&quot;, &quot;defg&quot;], word2 = [&quot;abcddefg&quot;]
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= word1[i].length, word2[i].length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= sum(word1[i].length), sum(word2[i].length) &lt;= 10<sup>3</sup></code></li>
	<li><code>word1[i]</code> and <code>word2[i]</code> consist of lowercase letters.</li>
</ul>


**Companies**:
[Apple](https://leetcode.com/company/apple), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [String](https://leetcode.com/tag/string)

**Similar Questions**:
* [Check if an Original String Exists Given Two Encoded Strings (Hard)](https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings)

**Hints**:
* Concatenate all strings in the first array into a single string in the given order, the same for the second array.
* Both arrays represent the same string if and only if the generated strings are the same.

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(A + B)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& A, vector<string>& B) {
        string a, b;
        for (auto &x : A) a += x;
        for (auto &x : B) b += x;
        return a == b;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
// Author: github.com/lzl124631x
// Time: O(A + B)
// Space: O(1)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& A, vector<string>& B) {
        int i = 0, a = 0, j = 0, b = 0;
        while (i < A.size() && j < B.size()) {
            if (A[i][a] != B[j][b]) return false;
            if (++a >= A[i].size()) ++i, a = 0;
            if (++b >= B[j].size()) ++j, b = 0;
        }
        return i == A.size() && j == B.size();
    }
};
```