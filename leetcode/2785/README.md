# [2785. Sort Vowels in a String (Medium)](https://leetcode.com/problems/sort-vowels-in-a-string)

<p>Given a <strong>0-indexed</strong> string <code>s</code>, <strong>permute</strong> <code>s</code> to get a new string <code>t</code> such that:</p>

<ul>
	<li>All consonants remain in their original places. More formally, if there is an index <code>i</code> with <code>0 &lt;= i &lt; s.length</code> such that <code>s[i]</code> is a consonant, then <code>t[i] = s[i]</code>.</li>
	<li>The vowels must be sorted in the <strong>nondecreasing</strong> order of their <strong>ASCII</strong> values. More formally, for pairs of indices <code>i</code>, <code>j</code> with <code>0 &lt;= i &lt; j &lt; s.length</code> such that <code>s[i]</code> and <code>s[j]</code> are vowels, then <code>t[i]</code> must not have a higher ASCII value than <code>t[j]</code>.</li>
</ul>

<p>Return <em>the resulting string</em>.</p>

<p>The vowels are <code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, and <code>&#39;u&#39;</code>, and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;lEetcOde&quot;
<strong>Output:</strong> &quot;lEOtcede&quot;
<strong>Explanation:</strong> &#39;E&#39;, &#39;O&#39;, and &#39;e&#39; are the vowels in s; &#39;l&#39;, &#39;t&#39;, &#39;c&#39;, and &#39;d&#39; are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;lYmpH&quot;
<strong>Output:</strong> &quot;lYmpH&quot;
<strong>Explanation:</strong> There are no vowels in s (all characters in s are consonants), so we return &quot;lYmpH&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists only of letters of the&nbsp;English alphabet&nbsp;in <strong>uppercase and lowercase</strong>.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string), [Sorting](https://leetcode.com/tag/sorting)

**Similar Questions**:
* [Reverse Vowels of a String (Easy)](https://leetcode.com/problems/reverse-vowels-of-a-string)

**Hints**:
* Add all the vowels in an array and sort the array.
* Replace characters in string s if it's a vowel from the new array.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sort-vowels-in-a-string
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string sortVowels(string s) {
        vector<int> id;
        for (int i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) id.push_back(i);
        }
        sort(begin(id), end(id), [&](int a, int b) { return s[a] < s[b]; });
        string ans;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) ans += s[id[j++]];
            else ans += s[i];
        }
        return ans;
    }
};
```