# [2223. Sum of Scores of Built Strings (Hard)](https://leetcode.com/problems/sum-of-scores-of-built-strings)

<p>You are <strong>building</strong> a string <code>s</code> of length <code>n</code> <strong>one</strong> character at a time, <strong>prepending</strong> each new character to the <strong>front</strong> of the string. The strings are labeled from <code>1</code> to <code>n</code>, where the string with length <code>i</code> is labeled <code>s<sub>i</sub></code>.</p>

<ul>
	<li>For example, for <code>s = &quot;abaca&quot;</code>, <code>s<sub>1</sub> == &quot;a&quot;</code>, <code>s<sub>2</sub> == &quot;ca&quot;</code>, <code>s<sub>3</sub> == &quot;aca&quot;</code>, etc.</li>
</ul>

<p>The <strong>score</strong> of <code>s<sub>i</sub></code> is the length of the <strong>longest common prefix</strong> between <code>s<sub>i</sub></code> and <code>s<sub>n</sub></code> (Note that <code>s == s<sub>n</sub></code>).</p>

<p>Given the final string <code>s</code>, return<em> the <strong>sum</strong> of the <strong>score</strong> of every </em><code>s<sub>i</sub></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;babab&quot;
<strong>Output:</strong> 9
<strong>Explanation:</strong>
For s<sub>1</sub> == &quot;b&quot;, the longest common prefix is &quot;b&quot; which has a score of 1.
For s<sub>2</sub> == &quot;ab&quot;, there is no common prefix so the score is 0.
For s<sub>3</sub> == &quot;bab&quot;, the longest common prefix is &quot;bab&quot; which has a score of 3.
For s<sub>4</sub> == &quot;abab&quot;, there is no common prefix so the score is 0.
For s<sub>5</sub> == &quot;babab&quot;, the longest common prefix is &quot;babab&quot; which has a score of 5.
The sum of the scores is 1 + 0 + 3 + 0 + 5 = 9, so we return 9.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;azbazbzaz&quot;
<strong>Output:</strong> 14
<strong>Explanation:</strong> 
For s<sub>2</sub> == &quot;az&quot;, the longest common prefix is &quot;az&quot; which has a score of 2.
For s<sub>6</sub> == &quot;azbzaz&quot;, the longest common prefix is &quot;azb&quot; which has a score of 3.
For s<sub>9</sub> == &quot;azbazbzaz&quot;, the longest common prefix is &quot;azbazbzaz&quot; which has a score of 9.
For all other s<sub>i</sub>, the score is 0.
The sum of the scores is 2 + 3 + 9 = 14, so we return 14.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string), [Binary Search](https://leetcode.com/tag/binary-search), [Rolling Hash](https://leetcode.com/tag/rolling-hash), [Suffix Array](https://leetcode.com/tag/suffix-array), [String Matching](https://leetcode.com/tag/string-matching), [Hash Function](https://leetcode.com/tag/hash-function)

**Similar Questions**:
* [Longest Happy Prefix (Hard)](https://leetcode.com/problems/longest-happy-prefix)

**Hints**:
* Each s_i is a suffix of the string s, so consider algorithms that can determine the longest prefix that is also a suffix.
* Could you use the Z array from the Z algorithm to find the score of each s_i?

## Solution 1. LPS (KMP)

Calculate `lps` (longest prefix and suffix) first.

Let `cnt[i]` be the number of times `s[i]` appears in matched prefixes. Initially `cnt[i]` are all `1`s.

For `s[i]`, we use its `lps[i]` to find `s[j] (j = lps[i] - 1)`. If `s[j]` appears in `cnt[j]` prefixes, then `s[i]` can also show up in `cnt[j]` prefixes, plus the entire string which corresponds to the initial value 1.

For example:

```
s     =   b a b x b a b ...
index =   0 1 2 3 4 5 6 ...
lps   =   0 0 1 0 1 2 3 ...
cnt   =   1 1 2 1 2 2 3 ...
```

For the `b` at index `2`, since its `lps` is `1`, we look at `s[0]` and its `cnt[0]=1`. `cnt[0]=1` means that the first `b` shows up in one prefix -- the entire string. Since `s[0]` shows up in one prefix starting from `s[0]`, we know `s[2]` must also show up in at least one prefix starting from `s[2]`. `s[2]` also shows up in the entire string. So `cnt[2] = cnt[0] + 1`.

For the `b` at index `6`, since its `lps` is `3`, we look at `s[2]` and its `cnt[2]=2`. `cnt[2]=2` means that `s[2]` shows up in two prefixes, `s[0:]` and `s[2:]`. And we know `s[6]` shows up in two prefixes, `s[4:]` and `s[6:]`. `s[6]` also shows up in the entire string. So `cnt[6] = cnt[2] + 1`

```cpp
// OJ: https://leetcode.com/problems/sum-of-scores-of-built-strings
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    long long sumScores(string s) {
        long long N = s.size(), j = 0, ans = 0;
        vector<int> lps(N), cnt(N, 1);
        for (int i = 1; i < N; ++i) {
            while (j > 0 && s[i] != s[j]) j = lps[j - 1];
            j += s[i] == s[j];
            lps[i] = j;
        }
        for (int i = 0; i < N; ++i) {
            if (lps[i]) cnt[i] += cnt[lps[i] - 1];
        }
        return accumulate(begin(cnt), end(cnt), 0LL);
    }
};
```