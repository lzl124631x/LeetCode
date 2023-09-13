# [2423. Remove Letter To Equalize Frequency (Easy)](https://leetcode.com/problems/remove-letter-to-equalize-frequency)

<p>You are given a <strong>0-indexed</strong> string <code>word</code>, consisting of lowercase English letters. You need to select <strong>one</strong> index and <strong>remove</strong> the letter at that index from <code>word</code> so that the <strong>frequency</strong> of every letter present in <code>word</code> is equal.</p>
<p>Return<em> </em><code>true</code><em> if it is possible to remove one letter so that the frequency of all letters in </em><code>word</code><em> are equal, and </em><code>false</code><em> otherwise</em>.</p>
<p><strong>Note:</strong></p>
<ul>
	<li>The <b>frequency</b> of a letter <code>x</code> is the number of times it occurs in the string.</li>
	<li>You <strong>must</strong> remove exactly one letter and cannot chose to do nothing.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> word = "abcc"
<strong>Output:</strong> true
<strong>Explanation:</strong> Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> word = "aazz"
<strong>Output:</strong> false
<strong>Explanation:</strong> We must delete a character, so either the frequency of "a" is 1 and the frequency of "z" is 2, or vice versa. It is impossible to make all present letters have equal frequency.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>2 &lt;= word.length &lt;= 100</code></li>
	<li><code>word</code> consists of lowercase English letters only.</li>
</ul>

**Companies**:
[tcs](https://leetcode.com/company/tcs)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Maximum Equal Frequency (Hard)](https://leetcode.com/problems/maximum-equal-frequency/)
* [Minimum Deletions to Make Character Frequencies Unique (Medium)](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)

## Solution 1.

1. only one unique character
2. one frequency = 1, and others are of the same frequency
3. one freq = `n+1`, and all other characters has frequency = `n`.

```cpp
// OJ: https://leetcode.com/problems/remove-letter-to-equalize-frequency
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool equalFrequency(string s) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        map<int, int> freq;
        for (int n : cnt) {
            if (n) freq[n]++;
        }
        return (freq.size() == 1 && freq.begin()->second == 1)
        || (freq.begin()->first == 1 && ((freq.begin()->second == 1 && freq.size() == 2) || freq.size() == 1))
        || (freq.begin()->first + 1 == freq.rbegin()->first && freq.rbegin()->second == 1);
    }
};
```