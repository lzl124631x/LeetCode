# [2800. Shortest String That Contains Three Strings (Medium)](https://leetcode.com/problems/shortest-string-that-contains-three-strings)

Given three strings <code>a</code>, <code>b</code>, and <code>c</code>, your task is to find a string that has the<strong> minimum</strong> length and contains all three strings as <strong>substrings</strong>.
<p>If there are multiple such strings, return the<em> </em><strong>lexicographically<em> </em>smallest </strong>one.</p>

<p>Return <em>a string denoting the answer to the problem.</em></p>

<p><strong>Notes</strong></p>

<ul>
	<li>A string <code>a</code> is <strong>lexicographically smaller</strong> than a string <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, string <code>a</code> has a letter that appears <strong>earlier </strong>in the alphabet than the corresponding letter in <code>b</code>.</li>
	<li>A <strong>substring</strong> is a contiguous sequence of characters within a string.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> a = &quot;abc&quot;, b = &quot;bca&quot;, c = &quot;aaa&quot;
<strong>Output:</strong> &quot;aaabca&quot;
<strong>Explanation:</strong>  We show that &quot;aaabca&quot; contains all the given strings: a = ans[2...4], b = ans[3..5], c = ans[0..2]. It can be shown that the length of the resulting string would be at least 6 and &quot;aaabca&quot; is the lexicographically smallest one.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> a = &quot;ab&quot;, b = &quot;ba&quot;, c = &quot;aba&quot;
<strong>Output:</strong> &quot;aba&quot;
<strong>Explanation: </strong>We show that the string &quot;aba&quot; contains all the given strings: a = ans[0..1], b = ans[1..2], c = ans[0..2]. Since the length of c is 3, the length of the resulting string would be at least 3. It can be shown that &quot;aba&quot; is the lexicographically smallest one.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= a.length, b.length, c.length &lt;= 100</code></li>
	<li><code>a</code>, <code>b</code>, <code>c</code> consist only of lowercase English letters.</li>
</ul>


**Companies**:
[DE Shaw](https://leetcode.com/company/de-shaw)

**Related Topics**:  
[String](https://leetcode.com/tag/string), [Greedy](https://leetcode.com/tag/greedy), [Enumeration](https://leetcode.com/tag/enumeration)

**Similar Questions**:
* [Shortest Common Supersequence  (Hard)](https://leetcode.com/problems/shortest-common-supersequence)

**Hints**:
* Think about how you can generate all possible strings that contain all three input strings as substrings. Can you come up with an efficient algorithm to do this?
* Check all permutations of the words a, b, and c. For each permutation, begin by appending some letters to the end of the first word to form the second word. Then, proceed to add more letters to generate the third word.

## Solution 1.

Try each permuation of `a, b, c`.

For a given permutation `x, y, z`, we try start from `x`, then append `y`, then append `z`.

```cpp
// OJ: https://leetcode.com/problems/shortest-string-that-contains-three-strings
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    string merge(const string &a, const string &b) {
        int A = a.size(), B = b.size();
        if (a.find(b) == string::npos) {
            int len = min(A - 1, B - 1);
            for (; len >= 1; --len) {
                if (a.substr(A - len) == b.substr(0, len)) break;
            }
            return a + b.substr(len);
        }
        return a;
    }
    string merge(const string &a, const string &b, const string &c) {
        return merge(merge(a, b), c);
    }
public:
    string minimumString(string a, string b, string c) {
        string ans;
        for (auto &s : { merge(a, b, c), merge(a, c, b), merge(b, a, c), merge(b, c, a), merge(c, a, b), merge(c, b, a)}) {
            if (ans.empty() || s.size() < ans.size() || (s.size() == ans.size() && s < ans)) ans = s;
        }
        return ans;
    }
};
```