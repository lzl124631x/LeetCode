# [2083. Substrings That Begin and End With the Same Letter (Medium)](https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/)

<p>You are given a <strong>0-indexed</strong> string <code>s</code> consisting of only lowercase English letters. Return <em>the number of <strong>substrings</strong> in </em><code>s</code> <em>that begin and end with the <strong>same</strong> character.</em></p>

<p>A <strong>substring</strong> is a contiguous non-empty sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcba"
<strong>Output:</strong> 7
<strong>Explanation:</strong>
The substrings of length 1 that start and end with the same letter are: "a", "b", "c", "b", and "a".
The substring of length 3 that starts and ends with the same letter is: "bcb".
The substring of length 5 that starts and ends with the same letter is: "abcba".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abacad"
<strong>Output:</strong> 9
<strong>Explanation:</strong>
The substrings of length 1 that start and end with the same letter are: "a", "b", "a", "c", "a", and "d".
The substrings of length 3 that start and end with the same letter are: "aba" and "aca".
The substring of length 5 that starts and ends with the same letter is: "abaca".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "a"
<strong>Output:</strong> 1
<strong>Explanation:</strong>
The substring of length 1 that starts and ends with the same letter is: "a".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/), [Counting](https://leetcode.com/tag/counting/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Number of Good Pairs (Easy)](https://leetcode.com/problems/number-of-good-pairs/)
* [Sum of Beauty of All Substrings (Medium)](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/)
* [Count Pairs in Two Arrays (Medium)](https://leetcode.com/problems/count-pairs-in-two-arrays/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long ans = 0, cnt[26] = {};
        for (int i = 0; i < s.size(); ++i) {
            ans += ++cnt[s[i] - 'a'];
        }
        return ans;
    }
};
```