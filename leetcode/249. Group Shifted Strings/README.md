# [249. Group Shifted Strings (Medium)](https://leetcode.com/problems/group-shifted-strings/)

<p>Given a string, we can "shift" each of its letter to its successive letter, for example: <code>"abc" -&gt; "bcd"</code>. We can keep "shifting" which forms the sequence:</p>

<pre>"abc" -&gt; "bcd" -&gt; ... -&gt; "xyz"</pre>

<p>Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.</p>

<p><b>Example:</b></p>

<pre><b>Input:</b> <code>["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],</code>
<b>Output:</b> 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
</pre>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Group Anagrams (Medium)](https://leetcode.com/problems/group-anagrams/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/group-shifted-strings/
// Author: github.com/lzl124631x
// Time: O(S) where S is size of all the contents in `strings`.
// Space: O(K) where K is the length of output array.
class Solution {
private:
    string getKey(string s) {
        if (s.empty()) return "";
        int d = s[0] - 'a';
        for (int i = 0; i < s.size(); ++i) s[i] = 'a' + (s[i] - 'a' - d + 26) % 26;
        return s;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (auto s : strings) m[getKey(s)].push_back(s);
        vector<vector<string>> ans;
        for (auto &p : m) ans.push_back(p.second);
        return ans;
    }
};
```