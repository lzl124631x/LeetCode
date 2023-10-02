# [833. Find And Replace in String (Medium)](https://leetcode.com/problems/find-and-replace-in-string/)

<p>To some string <code>s</code>, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).</p>

<p>Each replacement operation has <code>3</code> parameters: a starting index <code>i</code>, a source word <code>x</code> and a target word <code>y</code>. The rule is that if <code><font face="monospace">x</font></code> starts at position <code>i</code> in the <strong>original</strong> <strong>string</strong> <strong><code>S</code></strong>, then we will replace that occurrence of <code>x</code> with <code>y</code>. If not, we do nothing.</p>

<p>For example, if we have <code>s = "abcd"</code> and we have some replacement operation <code>i = 2, x = "cd", y = "ffff"</code>, then because <code>"cd"</code> starts at position <code><font face="monospace">2</font></code> in the original string <code>s</code>, we will replace it with <code>"ffff"</code>.</p>

<p>Using another example on <code>s = "abcd"</code>, if we have both the replacement operation <code>i = 0, x = "ab", y = "eee"</code>, as well as another replacement operation <code>i = 2, x = "ec", y = "ffff"</code>, this second operation does nothing because in the original string <code>s[2] = 'c'</code>, which doesn't match <code>x[0] = 'e'</code>.</p>

<p>All these operations occur simultaneously. It's guaranteed that there won't be any overlap in replacement: for example, <code>s = "abc", indexes = [0, 1], sources = ["ab","bc"]</code> is not a valid test case.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcd", indexes = [0, 2], sources = ["a", "cd"], targets = ["eee", "ffff"]
<strong>Output:</strong> "eeebffff"
<strong>Explanation:</strong>
"a" starts at index 0 in s, so it's replaced by "eee".
"cd" starts at index 2 in s, so it's replaced by "ffff".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abcd", indexes = [0, 2], sources = ["ab","ec"], targets = ["eee","ffff"]
<strong>Output:</strong> "eeecd"
<strong>Explanation:</strong>
"ab" starts at index 0 in s, so it's replaced by "eee".
"ec" doesn't starts at index 2 in the <strong>original</strong> s, so we do nothing.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
	<li><code>0 &lt;= indexes.length &lt;= 100</code></li>
	<li><code>0 &lt;= indexes[i] &lt; s.length</code></li>
	<li><code>sources.length == indexes.length</code></li>
	<li><code>targets.length == indexes.length</code></li>
	<li><code>1 &lt;= sources[i].length, targets[i].length &lt;= 50</code></li>
	<li><code>sources[i]</code> and <code>targets[i]</code> consist of only lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-and-replace-in-string/
// Author: github.com/lzl124631x
// Time: O(S + NlogN) where N is the length of `indexes`
// Space: O(N)
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string ans;
        vector<int> ids(indexes.size());
        iota(begin(ids), end(ids), 0);
        sort(begin(ids), end(ids), [&](int a, int b) { return indexes[a] < indexes[b]; });
        int j = S.size() - 1;
        for (int k = indexes.size() - 1; k >= 0; --k) {
            int i = ids[k];
            int end = indexes[i] + sources[i].size();
            while (j >= end) ans += S[j--];
            if (S.substr(indexes[i], sources[i].size()) == sources[i]) {
                reverse(targets[i].begin(), targets[i].end());
                ans += targets[i];
                j = indexes[i] - 1;
            } else {
                while (j >= indexes[i]) ans += S[j--];
            }
        }
        while (j >= 0) ans += S[j--];
        reverse(begin(ans), end(ans));
        return ans;
    }
};
```