# [2743. Count Substrings Without Repeating Character (Medium)](https://leetcode.com/problems/count-substrings-without-repeating-character)

<p>You are given a string <code>s</code> consisting only of lowercase English letters. We call a substring <b>special</b> if it contains no character which has occurred at least twice (in other words, it does not contain a repeating character). Your task is to count the number of <b>special</b> substrings. For example, in the string <code>"pop"</code>, the substring <code>"po"</code> is a <strong>special</strong> substring, however, <code>"pop"</code> is not <strong>special</strong> (since <code>'p'</code> has occurred twice).</p>
<p>Return <em>the number of <b>special</b> substrings.</em></p>
<p>A <strong>substring</strong> is a contiguous sequence of characters within a string. For example, <code>"abc"</code> is a substring of <code>"abcd"</code>, but <code>"acd"</code> is not.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "abcd"
<strong>Output:</strong> 10
<strong>Explanation:</strong> Since each character occurs once, every substring is a special substring. We have 4 substrings of length one, 3 of length two, 2 of length three, and 1 substring of length four. So overall there are 4 + 3 + 2 + 1 = 10 special substrings.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "ooo"
<strong>Output:</strong> 3
<strong>Explanation:</strong> Any substring with a length of at least two contains a repeating character. So we have to count the number of substrings of length one, which is 3.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "abab"
<strong>Output:</strong> 7
<strong>Explanation:</strong> Special substrings are as follows (sorted by their start positions):
Special substrings of length 1: "a", "b", "a", "b"
Special substrings of length 2: "ab", "ba", "ab"
And it can be shown that there are no special substrings with a length of at least three. So the answer would be 4 + 3 = 7.</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters</li>
</ul>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

## Solution 1. Find Maximum Sliding Window

Use the Shrinkable Template

```cpp
// OJ: https://leetcode.com/problems/count-substrings-without-repeating-character
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int cnt[26] = {}, N = s.size(), unique = 0, ans = 0;
        for (int i = 0, j = 0; j < N; ++j) {
            unique += ++cnt[s[j] - 'a'] == 1;
            while (unique < j - i + 1) {
                unique -= --cnt[s[i++] - 'a'] == 0;
            }
            ans += j - i + 1;
        }
        return ans;
    }
};
```