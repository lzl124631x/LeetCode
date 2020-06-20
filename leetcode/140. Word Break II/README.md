# [140. Word Break II (Hard)](https://leetcode.com/problems/word-break-ii/)

<p>Given a <strong>non-empty</strong> string <em>s</em> and a dictionary <em>wordDict</em> containing a list of <strong>non-empty</strong> words, add spaces in <em>s</em> to construct a sentence where each word is a valid dictionary word.&nbsp;Return all such possible sentences.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>The same word in the dictionary may be reused multiple times in the segmentation.</li>
	<li>You may assume the dictionary does not contain duplicate words.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:
</strong>s = "<code>catsanddog</code>"
wordDict = <code>["cat", "cats", "and", "sand", "dog"]</code>
<strong>Output:
</strong><code>[
&nbsp; "cats and dog",
&nbsp; "cat sand dog"
]</code>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:
</strong>s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
<strong>Output:
</strong>[
&nbsp; "pine apple pen apple",
&nbsp; "pineapple pen apple",
&nbsp; "pine applepen apple"
]
<strong>Explanation:</strong> Note that you are allowed to reuse a dictionary word.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:
</strong>s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
<strong>Output:
</strong>[]</pre>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Pinterest](https://leetcode.com/company/pinterest)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Word Break (Medium)](https://leetcode.com/problems/word-break/)
* [Concatenated Words (Hard)](https://leetcode.com/problems/concatenated-words/)

## Solution 1. Backtracking

The DFS idea is not hard to come up with. One optimization we should think about is that if we already know we can't reach the end from `S[i]`, then when later we come to `S[i]` we should backtrack directly instead of wasting computation.

```cpp
// OJ: https://leetcode.com/problems/word-break-ii
// Author: github.com/lzl124631x
// Time: O(2^M) where M is the max length of string in wordDict.
// Space: O(C) where C is the length sum of wordDict
class Solution {
    int maxLen = 0;
    unordered_set<string> ws;
    vector<int> m;
    vector<string> ans;
    bool dfs(string &s, int i, string tmp) {
        if (i == s.size()) {
            ans.push_back(tmp);
            return true; 
        }
        if (m[i] == 0) return m[i];
        m[i] = 0;
        for (int j = min((int)s.size(), i + maxLen); j > i; --j) {
            auto sub = s.substr(i, j - i);
            if (ws.count(sub) && dfs(s, j, tmp.size() ? tmp + " " + sub : sub)) m[i] = 1;
        }
        return m[i];
    }
public:
    vector<string> wordBreak(string s, vector<string>& dict) {
        ws = { dict.begin(), dict.end() };
        for (auto &w : dict) maxLen = max(maxLen, (int)w.size());
        m.assign(s.size(), -1); // -1 = unvisited, 0 = can not reach end, 1 = can reach end.
        dfs(s, 0, "");
        return ans;
    }
};
```