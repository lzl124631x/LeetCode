# [2840. Check if Strings Can be Made Equal With Operations II (Medium)](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii)

<p>You are given two strings <code>s1</code> and <code>s2</code>, both of length <code>n</code>, consisting of <strong>lowercase</strong> English letters.</p>

<p>You can apply the following operation on <strong>any</strong> of the two strings <strong>any</strong> number of times:</p>

<ul>
	<li>Choose any two indices <code>i</code> and <code>j</code> such that <code>i &lt; j</code> and the difference <code>j - i</code> is <strong>even</strong>, then <strong>swap</strong> the two characters at those indices in the string.</li>
</ul>

<p>Return <code>true</code><em> if you can make the strings </em><code>s1</code><em> and </em><code>s2</code><em> equal, and&nbsp;</em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s1 = &quot;abcdba&quot;, s2 = &quot;cabdab&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = &quot;cbadba&quot;.
- Choose the indices i = 2, j = 4. The resulting string is s1 = &quot;cbbdaa&quot;.
- Choose the indices i = 1, j = 5. The resulting string is s1 = &quot;cabdab&quot; = s2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s1 = &quot;abe&quot;, s2 = &quot;bea&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> It is not possible to make the two strings equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == s1.length == s2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>s1</code> and <code>s2</code> consist only of lowercase English letters.</li>
</ul>


**Companies**:
[Citrix](https://leetcode.com/company/citrix)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table), [String](https://leetcode.com/tag/string), [Sorting](https://leetcode.com/tag/sorting)

**Hints**:
* <div class="_1l1MA">Characters in two positions can be swapped if and only if the two positions have the same parity.</div>
* <div class="_1l1MA">To be able to make the two strings equal, the characters at even and odd positions in the strings should be the same.</div>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkStrings(string s, string t) {
        int N = s.size(), cnt[2][26] = {};
        for (int i = 0; i < N; ++i) {
            cnt[i % 2][s[i] - 'a']++;
            cnt[i % 2][t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[0][i] || cnt[1][i]) return false;
        }
        return true;
    }
};
```