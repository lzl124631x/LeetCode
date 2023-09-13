# [524. Longest Word in Dictionary through Deleting (Medium)](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)

<p>Given a string <code>s</code> and a string array <code>dictionary</code>, return <em>the longest string in the dictionary that can be formed by deleting some of the given string characters</em>. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
<strong>Output:</strong> "apple"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abpcplea", dictionary = ["a","b","c"]
<strong>Output:</strong> "a"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>1 &lt;= dictionary.length &lt;= 1000</code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 1000</code></li>
	<li><code>s</code> and <code>dictionary[i]</code> consist of lowercase English letters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Longest Word in Dictionary (Medium)](https://leetcode.com/problems/longest-word-in-dictionary/)

## Solution 1. Two Pointers

```cpp
// OJ: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
// Author: github.com/lzl124631x
// Time: O(MNW)
// Space: O(1)
class Solution {
public:
    string findLongestWord(string s, vector<string>& A) {
        string ans;
        auto valid = [](string &a, string &b) {
            int i = 0, j = 0, M = a.size(), N = b.size();
            if (M > N) return false;
            for (; i < M; ++i, ++j) {
                while (j < N && b[j] != a[i]) ++j;
                if (j == N) return false;
            }
            return true;
        };
        for (auto &w : A) {
            if (w.size() >= ans.size() && valid(w, s) && (w.size() > ans.size() || w < ans)) ans = w; 
        }
        return ans;
    }
};
```