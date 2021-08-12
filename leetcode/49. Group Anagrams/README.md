# [49. Group Anagrams (Medium)](https://leetcode.com/problems/group-anagrams/)

<p>Given an array of strings <code>strs</code>, group <strong>the anagrams</strong> together. You can return the answer in <strong>any order</strong>.</p>

<p>An <strong>Anagram</strong> is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> strs = ["eat","tea","tan","ate","nat","bat"]
<strong>Output:</strong> [["bat"],["nat","tan"],["ate","eat","tea"]]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> strs = [""]
<strong>Output:</strong> [[""]]
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> strs = ["a"]
<strong>Output:</strong> [["a"]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= strs.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= strs[i].length &lt;= 100</code></li>
	<li><code>strs[i]</code> consists of lower-case English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [eBay](https://leetcode.com/company/ebay), [Apple](https://leetcode.com/company/apple), [BlackRock](https://leetcode.com/company/blackrock), [Facebook](https://leetcode.com/company/facebook), [Paypal](https://leetcode.com/company/paypal), [Uber](https://leetcode.com/company/uber), [Yandex](https://leetcode.com/company/yandex), [Salesforce](https://leetcode.com/company/salesforce), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Twilio](https://leetcode.com/company/twilio), [Two Sigma](https://leetcode.com/company/two-sigma), [Google](https://leetcode.com/company/google), [VMware](https://leetcode.com/company/vmware), [Snapchat](https://leetcode.com/company/snapchat), [Splunk](https://leetcode.com/company/splunk), [Atlassian](https://leetcode.com/company/atlassian), [Citadel](https://leetcode.com/company/citadel)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sorting](https://leetcode.com/tag/sorting/)

**Similar Questions**:
* [Valid Anagram (Easy)](https://leetcode.com/problems/valid-anagram/)
* [Group Shifted Strings (Medium)](https://leetcode.com/problems/group-shifted-strings/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/group-anagrams/
// Author: github.com/lzl124631x
// Time: O(NWlogW)
// Space: O(NW)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& A) {
        unordered_map<string, vector<string>> m;
        for (auto &s : A) {
            auto key = s;
            sort(begin(key), end(key));
            m[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &[key, strs] : m) ans.push_back(strs);
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/group-anagrams/
// Author: github.com/lzl124631x
// Time: O(NWlogW)
// Space: O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& A) {
        unordered_map<string, int> m;
        vector<vector<string>> ans;
        for (auto &s : A) {
            auto key = s;
            sort(begin(key), end(key));
            if (!m.count(key)) {
                m[key] = ans.size();
                ans.emplace_back();
            }
            ans[m[key]].push_back(s);
        }
        return ans;
    }
};
```