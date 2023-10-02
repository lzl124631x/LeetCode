# [438. Find All Anagrams in a String (Medium)](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

<p>Given two strings <code>s</code> and <code>p</code>, return <em>an array of all the start indices of </em><code>p</code><em>'s anagrams in </em><code>s</code>. You may return the answer in <strong>any order</strong>.</p>

<p>An <strong>Anagram</strong> is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "cbaebabacd", p = "abc"
<strong>Output:</strong> [0,6]
<strong>Explanation:</strong>
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abab", p = "ab"
<strong>Output:</strong> [0,1,2]
<strong>Explanation:</strong>
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, p.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>s</code> and <code>p</code> consist of lowercase English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg), [Snapchat](https://leetcode.com/company/snapchat), [Google](https://leetcode.com/company/google), [Expedia](https://leetcode.com/company/expedia), [Facebook](https://leetcode.com/company/facebook), [Yandex](https://leetcode.com/company/yandex), [Oracle](https://leetcode.com/company/oracle), [Redfin](https://leetcode.com/company/redfin)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Valid Anagram (Easy)](https://leetcode.com/problems/valid-anagram/)
* [Permutation in String (Medium)](https://leetcode.com/problems/permutation-in-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Author: github.com/lzl124631x
// Time: O(M + RN) where `R` is the range of characters
// Space: O(R)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int target[26] = {}, cnt[26] = {};
        for (char c : p) target[c - 'a']++;
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            cnt[s[i] - 'a']++;
            if (i >= p.size()) cnt[s[i - p.size()] - 'a']--;
            int j = 0;
            for (; j < 26 && target[j] == cnt[j]; ++j);
            if (j == 26) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Author: github.com/lzl124631x
// Time: O(M + RN) where `R` is the range of characters
// Space: O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int cnt[26] = {};
        for (char c : p) cnt[c - 'a']++;
        vector<int> ans;
        for (int i = 0, N = s.size(), M = p.size(); i < N; ++i) {
            cnt[s[i] - 'a']--;
            if (i - M >= 0) cnt[s[i - M] - 'a']++;
            int j = 0;
            while (j < 26 && cnt[j] == 0) ++j;
            if (j == 26) ans.push_back(i - M + 1);
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(R) where `R` is the range of characters
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int cnt[26] = {}, matched = 0;
        for (char c : p) cnt[c - 'a']++;
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            if (--cnt[s[i] - 'a'] >= 0) ++matched;
            if (i >= p.size() && ++cnt[s[i - p.size()] - 'a'] > 0) --matched;
            if (matched == p.size()) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};
```