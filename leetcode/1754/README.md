# [1754. Largest Merge Of Two Strings (Medium)](https://leetcode.com/problems/largest-merge-of-two-strings/)

<p>You are given two strings <code>word1</code> and <code>word2</code>. You want to construct a string <code>merge</code> in the following way: while either <code>word1</code> or <code>word2</code> are non-empty, choose <strong>one</strong> of the following options:</p>

<ul>
	<li>If <code>word1</code> is non-empty, append the <strong>first</strong> character in <code>word1</code> to <code>merge</code> and delete it from <code>word1</code>.

	<ul>
		<li>For example, if <code>word1 = "abc" </code>and <code>merge = "dv"</code>, then after choosing this operation, <code>word1 = "bc"</code> and <code>merge = "dva"</code>.</li>
	</ul>
	</li>
	<li>If <code>word2</code> is non-empty, append the <strong>first</strong> character in <code>word2</code> to <code>merge</code> and delete it from <code>word2</code>.
	<ul>
		<li>For example, if <code>word2 = "abc" </code>and <code>merge = ""</code>, then after choosing this operation, <code>word2 = "bc"</code> and <code>merge = "a"</code>.</li>
	</ul>
	</li>
</ul>

<p>Return <em>the lexicographically <strong>largest</strong> </em><code>merge</code><em> you can construct</em>.</p>

<p>A string <code>a</code> is lexicographically larger than a string <code>b</code> (of the same length) if in the first position where <code>a</code> and <code>b</code> differ, <code>a</code> has a character strictly larger than the corresponding character in <code>b</code>. For example, <code>"abcd"</code> is lexicographically larger than <code>"abcc"</code> because the first position they differ is at the fourth character, and <code>d</code> is greater than <code>c</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> word1 = "cabaa", word2 = "bcaaa"
<strong>Output:</strong> "cbcabaaaaa"
<strong>Explanation:</strong> One way to get the lexicographically largest merge is:
- Take from word1: merge = "c", word1 = "abaa", word2 = "bcaaa"
- Take from word2: merge = "cb", word1 = "abaa", word2 = "caaa"
- Take from word2: merge = "cbc", word1 = "abaa", word2 = "aaa"
- Take from word1: merge = "cbca", word1 = "baa", word2 = "aaa"
- Take from word1: merge = "cbcab", word1 = "aa", word2 = "aaa"
- Append the remaining 5 a's from word1 and word2 at the end of merge.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> word1 = "abcabc", word2 = "abdcaba"
<strong>Output:</strong> "abdcabcabcaba"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word1.length, word2.length &lt;= 3000</code></li>
	<li><code>word1</code> and <code>word2</code> consist only of lowercase English letters.</li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Suffix Array](https://leetcode.com/tag/suffix-array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-merge-of-two-strings/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string largestMerge(string word1, string word2) {
        priority_queue<string> q;
        q.push(word1);
        q.push(word2);
        string ans;
        while (q.size()) {
            auto s = q.top();
            q.pop();
            ans += s[0];
            if (s.size() > 1) q.push(s.substr(1));
        }
        return ans;
    }
};
```

## TODO

find better solution