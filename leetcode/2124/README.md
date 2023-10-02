# [2124. Check if All A's Appears Before All B's (Easy)](https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/)

<p>Given a string <code>s</code> consisting of <strong>only</strong> the characters <code>'a'</code> and <code>'b'</code>, return <code>true</code> <em>if <strong>every</strong> </em><code>'a'</code> <em>appears before <strong>every</strong> </em><code>'b'</code><em> in the string</em>. Otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aaabbb"
<strong>Output:</strong> true
<strong>Explanation:</strong>
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abab"
<strong>Output:</strong> false
<strong>Explanation:</strong>
There is an 'a' at index 2 and a 'b' at index 1.
Hence, not every 'a' appears before every 'b' and we return false.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "bbb"
<strong>Output:</strong> true
<strong>Explanation:</strong>
There are no 'a's, hence, every 'a' appears before every 'b' and we return true.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s[i]</code> is either <code>'a'</code> or <code>'b'</code>.</li>
</ul>


**Similar Questions**:
* [Minimum Deletions to Make String Balanced (Medium)](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/)
* [Check if Array Is Sorted and Rotated (Easy)](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)
* [Check if Numbers Are Ascending in a Sentence (Easy)](https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkString(string s) {
        int i = 0, N = s.size();
        while (i < N && s[i] == 'a') ++i;
        while (i < N && s[i] == 'b') ++i;
        return i == N;
    }
};
```

## Solution 2.

Look for `ba` in the string.

```cpp
// OJ: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkString(string s) {
        for (int i = 1, N = s.size(); i < N; ++i) {
            if (s[i - 1] == 'b' && s[i] == 'a') return false;
        }
        return true;
    }
};
```