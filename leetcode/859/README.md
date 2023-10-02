# [859. Buddy Strings (Easy)](https://leetcode.com/problems/buddy-strings)

<p>Given two strings <code>s</code> and <code>goal</code>, return <code>true</code><em> if you can swap two letters in </em><code>s</code><em> so the result is equal to </em><code>goal</code><em>, otherwise, return </em><code>false</code><em>.</em></p>

<p>Swapping letters is defined as taking two indices <code>i</code> and <code>j</code> (0-indexed) such that <code>i != j</code> and swapping the characters at <code>s[i]</code> and <code>s[j]</code>.</p>

<ul>
	<li>For example, swapping at indices <code>0</code> and <code>2</code> in <code>"abcd"</code> results in <code>"cbad"</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "ab", goal = "ba"
<strong>Output:</strong> true
<strong>Explanation:</strong> You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "ab", goal = "ab"
<strong>Output:</strong> false
<strong>Explanation:</strong> The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "aa", goal = "aa"
<strong>Output:</strong> true
<strong>Explanation:</strong> You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, goal.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>s</code> and <code>goal</code> consist of lowercase letters.</li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Determine if Two Strings Are Close (Medium)](https://leetcode.com/problems/determine-if-two-strings-are-close/)
* [Check if One String Swap Can Make Strings Equal (Medium)](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)
* [Make Number of Distinct Characters Equal (Medium)](https://leetcode.com/problems/make-number-of-distinct-characters-equal/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/buddy-strings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        int cnts[26] = {0}, first = -1, second = -1;
        bool hasDup = false;
        for (int i = 0; i < A.size(); ++i) {
            if (++cnts[A[i] - 'a'] == 2) hasDup = true;
            if (A[i] == B[i]) continue;
            if (first == -1) first = i;
            else if (second == -1) second = i;
            else return false;
        }
        return (first != -1 && second != -1 && A[first] == B[second] && A[second] == B[first])
            || (first == -1 && second == -1 && hasDup);
    }
};
```