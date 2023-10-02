# [2063. Vowels of All Substrings (Medium)](https://leetcode.com/problems/vowels-of-all-substrings/)

<p>Given a string <code>word</code>, return <em>the <strong>sum of the number of vowels</strong> (</em><code>'a'</code>, <code>'e'</code><em>,</em> <code>'i'</code><em>,</em> <code>'o'</code><em>, and</em> <code>'u'</code><em>)</em> <em>in every substring of </em><code>word</code>.</p>

<p>A <strong>substring</strong> is a contiguous (non-empty) sequence of characters within a string.</p>

<p><strong>Note:</strong> Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word = "aba"
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
- "b" has 0 vowels in it
- "a", "ab", "ba", and "a" have 1 vowel each
- "aba" has 2 vowels in it
Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word = "abc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
- "a", "ab", and "abc" have 1 vowel each
- "b", "bc", and "c" have 0 vowels each
Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3. </pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> word = "ltcd"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no vowels in any substring of "ltcd".</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> word = "noosabasboosa"
<strong>Output:</strong> 237
<strong>Explanation:</strong> There are a total of 237 vowels in all the substrings.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> consists of lowercase English letters.</li>
</ul>


**Similar Questions**:
* [Number of Substrings Containing All Three Characters (Medium)](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)

## Solution 1.

If `s[i]` is vowel, there are `(i + 1) * (N - i)` substrings that contain `s[i]` where `i + 1` and `N - i` are the number of possible left and right end points of the substrings, respectively.

```cpp
// OJ: https://leetcode.com/problems/vowels-of-all-substrings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
public:
    long long countVowels(string s) {
        long long N = s.size(), ans = 0;
        for (long long i = 0; i < N; ++i) {
            if (!isVowel(s[i])) continue;
            ans += (i + 1) * (N - i);
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/vowels-of-all-substrings/discuss/1563756/C%2B%2B-O(N)-Time