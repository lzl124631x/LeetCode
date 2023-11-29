# [2947. Count Beautiful Substrings I (Medium)](https://leetcode.com/problems/count-beautiful-substrings-i)

<p>You are given a string <code>s</code> and a positive integer <code>k</code>.</p>

<p>Let <code>vowels</code> and <code>consonants</code> be the number of vowels and consonants in a string.</p>

<p>A string is <strong>beautiful</strong> if:</p>

<ul>
	<li><code>vowels == consonants</code>.</li>
	<li><code>(vowels * consonants) % k == 0</code>, in other terms the multiplication of <code>vowels</code> and <code>consonants</code> is divisible by <code>k</code>.</li>
</ul>

<p>Return <em>the number of <strong>non-empty beautiful substrings</strong> in the given string</em> <code>s</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p><strong>Vowel letters</strong> in English are <code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, and <code>&#39;u&#39;</code>.</p>

<p><strong>Consonant letters</strong> in English are every letter except vowels.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;baeyh&quot;, k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 beautiful substrings in the given string.
- Substring &quot;b<u>aeyh</u>&quot;, vowels = 2 ([&quot;a&quot;,e&quot;]), consonants = 2 ([&quot;y&quot;,&quot;h&quot;]).
You can see that string &quot;aeyh&quot; is beautiful as vowels == consonants and vowels * consonants % k == 0.
- Substring &quot;<u>baey</u>h&quot;, vowels = 2 ([&quot;a&quot;,e&quot;]), consonants = 2 ([&quot;b&quot;,&quot;y&quot;]). 
You can see that string &quot;baey&quot; is beautiful as vowels == consonants and vowels * consonants % k == 0.
It can be shown that there are only 2 beautiful substrings in the given string.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;abba&quot;, k = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are 3 beautiful substrings in the given string.
- Substring &quot;<u>ab</u>ba&quot;, vowels = 1 ([&quot;a&quot;]), consonants = 1 ([&quot;b&quot;]). 
- Substring &quot;ab<u>ba</u>&quot;, vowels = 1 ([&quot;a&quot;]), consonants = 1 ([&quot;b&quot;]).
- Substring &quot;<u>abba</u>&quot;, vowels = 2 ([&quot;a&quot;,&quot;a&quot;]), consonants = 2 ([&quot;b&quot;,&quot;b&quot;]).
It can be shown that there are only 3 beautiful substrings in the given string.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;bcdf&quot;, k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no beautiful substrings in the given string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>1 &lt;= k &lt;= 1000</code></li>
	<li><code>s</code> consists of only English lowercase letters.</li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string), [Enumeration](https://leetcode.com/tag/enumeration), [Prefix Sum](https://leetcode.com/tag/prefix-sum)

**Hints**:
* Iterate over all substrings and maintain the frequencies of vowels and consonants.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-beautiful-substrings-i
// Author: github.com/lzl124631x
// Time: O(sqrt(N) * N)
// Space: O(1)
class Solution {
    bool isVowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }
public:
    int beautifulSubstrings(string s, int k) {
        int N = s.size(), ans = 0;
        for (int L = 4 * k; true; L += 4 * k) {
            int len = sqrt(L), vowel = 0;
            if (len > N) break;
            if (len * len != L || len % 2) continue;
            for (int i = 0; i < N; ++i) {
                vowel += isVowel(s[i]);
                if (i - len >= 0) vowel -= isVowel(s[i - len]);
                if (i >= len - 1 && vowel == len / 2) ++ans;
            }
        }
        return ans;
    }
};
```