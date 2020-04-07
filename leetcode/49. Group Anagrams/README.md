# [49. Group Anagrams (Medium)](https://leetcode.com/problems/group-anagrams/)

<p>Given an array of strings, group anagrams together.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> <code>["eat", "tea", "tan", "ate", "nat", "bat"]</code>,
<strong>Output:</strong>
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]</pre>

<p><strong>Note:</strong></p>

<ul>
	<li>All inputs will be in lowercase.</li>
	<li>The order of your output does not&nbsp;matter.</li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Valid Anagram (Easy)](https://leetcode.com/problems/valid-anagram/)
* [Group Shifted Strings (Medium)](https://leetcode.com/problems/group-shifted-strings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/group-anagrams/
// Author: github.com/lzl124631x
// Time: O(NK)
// Space: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& A) {
        unordered_map<string, int> m;
        vector<vector<string>> ans;
        for (auto &s : A) {
            auto p = s;
            sort(p.begin(), p.end());
            if (!m.count(p)) {
                m[p] = ans.size();
                ans.push_back({});
            }
            ans[m[p]].push_back(s);
        }
        return ans;
    }
};
```