# [2586. Count the Number of Vowel Strings in Range (Easy)](https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range)

<p>You are given a <strong>0-indexed</strong> array of string <code>words</code> and two integers <code>left</code> and <code>right</code>.</p>
<p>A string is called a <strong>vowel string</strong> if it starts with a vowel character and ends with a vowel character where vowel characters are <code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, and <code>'u'</code>.</p>
<p>Return <em>the number of vowel strings </em><code>words[i]</code><em> where </em><code>i</code><em> belongs to the inclusive range </em><code>[left, right]</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> words = ["are","amy","u"], left = 0, right = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
- "are" is a vowel string because it starts with 'a' and ends with 'e'.
- "amy" is not a vowel string because it does not end with a vowel.
- "u" is a vowel string because it starts with 'u' and ends with 'u'.
The number of vowel strings in the mentioned range is 2.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
- "aeo" is a vowel string because it starts with 'a' and ends with 'o'.
- "mu" is not a vowel string because it does not start with a vowel.
- "ooo" is a vowel string because it starts with 'o' and ends with 'o'.
- "artro" is a vowel string because it starts with 'a' and ends with 'o'.
The number of vowel strings in the mentioned range is 3.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>words[i]</code> consists of only lowercase English letters.</li>
	<li><code>0 &lt;= left &lt;= right &lt; words.length</code></li>
</ul>

**Companies**:
[PayPal](https://leetcode.com/company/paypal)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int vowelStrings(vector<string>& A, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            ans += isVowel(A[i][0]) && isVowel(A[i].back());
        }
        return ans;
    }
};
```