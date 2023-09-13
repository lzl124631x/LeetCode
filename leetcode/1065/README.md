# [1065. Index Pairs of a String (Easy)](https://leetcode.com/problems/index-pairs-of-a-string/)

<p>Given a string <code>text</code> and an array of strings <code>words</code>, return <em>an array of all index pairs </em><code>[i, j]</code><em> so that the substring </em><code>text[i...j]</code><em> is in <code>words</code></em>.</p>

<p>Return the pairs <code>[i, j]</code> in sorted order (i.e., sort them by their first coordinate, and in case of ties sort them by their second coordinate).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
<strong>Output:</strong> [[3,7],[9,13],[10,17]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> text = "ababa", words = ["aba","ab"]
<strong>Output:</strong> [[0,1],[0,2],[2,3],[2,4]]
<strong>Explanation:</strong> Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= text.length &lt;= 100</code></li>
	<li><code>1 &lt;= words.length &lt;= 20</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>text</code> and <code>words[i]</code> consist of lowercase English letters.</li>
	<li>All the strings of <code>words</code> are <strong>unique</strong>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Trie](https://leetcode.com/tag/trie/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/index-pairs-of-a-string/
// Author: github.com/lzl124631x
// Time: O((T-W) * (T+W) * N) where `T` is the length of `text`, `W` is the maximum length of word in `words`, and `N` is the length of `words`.
// Space: O(1) extra space
class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& A) {
        vector<vector<int>> ans;
        for (auto &s : A) {
            int i = text.find(s);
            while (i != string::npos) {
                ans.push_back({ i, i + (int)s.size() - 1 });
                i = text.find(s, i + 1);
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};
```