# [2062. Count Vowel Substrings of a String (Easy)](https://leetcode.com/problems/count-vowel-substrings-of-a-string/)

<p>A <strong>substring</strong> is a contiguous (non-empty) sequence of characters within a string.</p>

<p>A <strong>vowel substring</strong> is a substring that <strong>only</strong> consists of vowels (<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, and <code>'u'</code>) and has <strong>all five</strong> vowels present in it.</p>

<p>Given a string <code>word</code>, return <em>the number of <strong>vowel substrings</strong> in</em> <code>word</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word = "aeiouu"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The vowel substrings of word are as follows (underlined):
- "<strong><u>aeiou</u></strong>u"
- "<strong><u>aeiouu</u></strong>"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word = "unicornarihan"
<strong>Output:</strong> 0
<strong>Explanation:</strong> Not all 5 vowels are present, so there are no vowel substrings.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> word = "cuaieuouac"
<strong>Output:</strong> 7
<strong>Explanation:</strong> The vowel substrings of word are as follows (underlined):
- "c<strong><u>uaieuo</u></strong>uac"
- "c<strong><u>uaieuou</u></strong>ac"
- "c<strong><u>uaieuoua</u></strong>c"
- "cu<strong><u>aieuo</u></strong>uac"
- "cu<strong><u>aieuou</u></strong>ac"
- "cu<strong><u>aieuoua</u></strong>c"
- "cua<strong><u>ieuoua</u></strong>c"</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> word = "bbaeixoubb"
<strong>Output:</strong> 0
<strong>Explanation:</strong> The only substrings that contain all five vowels also contain consonants, so there are no vowel substrings.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code> consists of lowercase English letters only.</li>
</ul>


**Similar Questions**:
* [Number of Matching Subsequences (Medium)](https://leetcode.com/problems/number-of-matching-subsequences/)
* [Subarrays with K Different Integers (Hard)](https://leetcode.com/problems/subarrays-with-k-different-integers/)
* [Number of Substrings With Only 1s (Medium)](https://leetcode.com/problems/number-of-substrings-with-only-1s/)
* [Longest Substring Of All Vowels in Order (Medium)](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/count-vowel-substrings-of-a-string/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
public:
    int countVowelSubstrings(string s) {
        int ans = 0, N = s.size();
        unordered_map<char, int> cnt;
        for (int i = 0; i < N; ++i) {
            cnt.clear();
            for (int j = i; j < N && isVowel(s[j]); ++j) {
                cnt[s[j]]++;
                if (cnt.size() == 5) ++ans;
            }
        }
        return ans;
    }
};
```

## Solution 2. Sliding Window

Check out "[C++ Maximum Sliding Window Cheatsheet Template!](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)"

Function `atMost(s, goal)` returns the number of substrings that has at most `goal` number of unique vowels. The answer is `atMost(s, 5) - atMost(s, 4)`.

```cpp
// OJ: https://leetcode.com/problems/count-vowel-substrings-of-a-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    int atMost(string &s, int goal) {
        int ans = 0, i = 0, j = 0, N = s.size();
        unordered_map<char, int> cnt;
        for (; j < N; ++j) {
            if (!isVowel(s[j])) {
                i = j + 1;
                cnt.clear();
                continue;
            }
            cnt[s[j]]++;
            for (; cnt.size() > goal; ++i) {
                if (--cnt[s[i]] == 0) cnt.erase(s[i]);
            }
            ans += j - i + 1; // this window [i, j] is the maximum window ending at `s[j]` that has at most `goal` number of unique vowels.
        }
        return ans;
    }
public:
    int countVowelSubstrings(string s) {
        return atMost(s, 5) - atMost(s, 4);
    }
};
```

## Discuss

https://leetcode.com/problems/count-vowel-substrings-of-a-string/discuss/1563765/C%2B%2B-O(N)-Time-Sliding-Window