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

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/word-break-ii/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N + D)
class Solution {
    vector<string> ans, tmp;
    unordered_set<string> st;
    void dfs(string &s, int i) {
        if (i == s.size()) {
            string n;
            for (auto &t : tmp) {
                n += (n.size() ? " " : "") + t;
            }
            ans.push_back(n);
        }
        for (int j = i + 1; j <= s.size(); ++j) {
            auto sub = s.substr(i, j - i);
            if (st.count(sub) == 0) continue;
            tmp.push_back(sub);
            dfs(s, j);
            tmp.pop_back();
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& dict) {
        st = unordered_set<string>(begin(dict), end(dict));
        dfs(s, 0);
        return ans;
    }
};
```

## Solution 2. Backtracking

One optimization is that we can store `dp[i]` meaning if we can reach the end from index `i`. If we know that we can't from `i`, we can skip it.

```cpp
// OJ: https://leetcode.com/problems/word-break-ii/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N + D)
class Solution {
    vector<string> ans, tmp;
    unordered_set<string> st;
    vector<int> dp; // -1 unvisited, 0 can't reach end, 1 can reach end
    bool dfs(string &s, int i) {
        if (i == s.size()) {
            string n;
            for (auto &t : tmp) {
                n += (n.size() ? " " : "") + t;
            }
            ans.push_back(n);
            return true;
        }
        for (int j = i + 1; j <= s.size(); ++j) {
            if (dp[j] == 0) continue;
            auto sub = s.substr(i, j - i);
            if (st.count(sub) == 0) continue;
            tmp.push_back(sub);
            if (dfs(s, j)) dp[i] = 1;
            tmp.pop_back();
        }
        return dp[i];
    }
public:
    vector<string> wordBreak(string s, vector<string>& dict) {
        st = unordered_set<string>(begin(dict), end(dict));
        dp.assign(s.size() + 1, -1);
        dp[s.size()] = 1;
        dfs(s, 0);
        return ans;
    }
};
```