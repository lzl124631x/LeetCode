# [1061. Lexicographically Smallest Equivalent String (Medium)](https://leetcode.com/problems/lexicographically-smallest-equivalent-string)

<p>You are given two strings of the same length <code>s1</code> and <code>s2</code> and a string <code>baseStr</code>.</p>
<p>We say <code>s1[i]</code> and <code>s2[i]</code> are equivalent characters.</p>
<ul>
	<li>For example, if <code>s1 = "abc"</code> and <code>s2 = "cde"</code>, then we have <code>'a' == 'c'</code>, <code>'b' == 'd'</code>, and <code>'c' == 'e'</code>.</li>
</ul>
<p>Equivalent characters follow the usual rules of any equivalence relation:</p>
<ul>
	<li><strong>Reflexivity:</strong> <code>'a' == 'a'</code>.</li>
	<li><strong>Symmetry:</strong> <code>'a' == 'b'</code> implies <code>'b' == 'a'</code>.</li>
	<li><strong>Transitivity:</strong> <code>'a' == 'b'</code> and <code>'b' == 'c'</code> implies <code>'a' == 'c'</code>.</li>
</ul>
<p>For example, given the equivalency information from <code>s1 = "abc"</code> and <code>s2 = "cde"</code>, <code>"acd"</code> and <code>"aab"</code> are equivalent strings of <code>baseStr = "eed"</code>, and <code>"aab"</code> is the lexicographically smallest equivalent string of <code>baseStr</code>.</p>
<p>Return <em>the lexicographically smallest equivalent string of </em><code>baseStr</code><em> by using the equivalency information from </em><code>s1</code><em> and </em><code>s2</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s1 = "parker", s2 = "morris", baseStr = "parser"
<strong>Output:</strong> "makkek"
<strong>Explanation:</strong> Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
The characters in each group are equivalent and sorted in lexicographical order.
So the answer is "makkek".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s1 = "hello", s2 = "world", baseStr = "hold"
<strong>Output:</strong> "hdld"
<strong>Explanation: </strong>Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
<strong>Output:</strong> "aauaaaaada"
<strong>Explanation:</strong> We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s1.length, s2.length, baseStr &lt;= 1000</code></li>
	<li><code>s1.length == s2.length</code></li>
	<li><code>s1</code>, <code>s2</code>, and <code>baseStr</code> consist of lowercase English letters.</li>
</ul>

**Companies**:
[Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Union Find](https://leetcode.com/tag/union-find/)

## Solution 1. Union Find

```cpp
// OJ: https://leetcode.com/problems/lexicographically-smallest-equivalent-string
// Author: github.com/lzl124631x
// Time: O(N + M)
// Space: O(1)
class Solution {
public:
    string smallestEquivalentString(string a, string b, string baseStr) {
        int id[26] = {};
        iota(begin(id), end(id), 0);
        function<int(int)> find = [&](int a) {
            return id[a] == a ? a : (id[a] = find(id[a]));
        };
        auto connect = [&](int a, int b) {
            int p = find(a), q = find(b);
            if (p > q) swap(p, q);
            id[q] = p;
        };
        for (int i = 0; i < a.size(); ++i) {
            connect(a[i] - 'a', b[i] - 'a');
        }
        for (char &c : baseStr) c = 'a' + find(c - 'a');
        return baseStr;
    }
};
```