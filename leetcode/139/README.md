# [139. Word Break (Medium)](https://leetcode.com/problems/word-break)

<p>Given a string <code>s</code> and a dictionary of strings <code>wordDict</code>, return <code>true</code> if <code>s</code> can be segmented into a space-separated sequence of one or more dictionary words.</p>
<p><strong>Note</strong> that the same word in the dictionary may be reused multiple times in the segmentation.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "leetcode", wordDict = ["leet","code"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because "leetcode" can be segmented as "leet code".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "applepenapple", wordDict = ["apple","pen"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 300</code></li>
	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
	<li><code>1 &lt;= wordDict[i].length &lt;= 20</code></li>
	<li><code>s</code> and <code>wordDict[i]</code> consist of only lowercase English letters.</li>
	<li>All the strings of <code>wordDict</code> are <strong>unique</strong>.</li>
</ul>

**Companies**:
[Salesforce](https://leetcode.com/company/salesforce), [Apple](https://leetcode.com/company/apple), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Trie](https://leetcode.com/tag/trie/), [Memoization](https://leetcode.com/tag/memoization/)

**Similar Questions**:
* [Word Break II (Hard)](https://leetcode.com/problems/word-break-ii/)
* [Extra Characters in a String (Medium)](https://leetcode.com/problems/extra-characters-in-a-string/)

## Solution 1. DP Bottom-up

Let `dp[i+1]` be true if `s[0..i)]` can be segmented using `wordDict`.

```
dp[0] = true
dp[i+1] = true if dp[j] && s[j..i] is in dict
          where 0 <= i < N, 0 <= j <= i
```

```cpp
// OJ: https://leetcode.com/problems/word-break/
// Author: github.com/lzl124631x
// Time: O(S^3)
// Space: O(S + W)
class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> st(begin(dict), end(dict));
        int N = s.size();
        vector<bool> dp(N + 1);
        dp[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < i && !dp[i]; ++j) {
                dp[i] = dp[j] && st.count(s.substr(j, i - j));
            }
        }
        return dp[N];
    }
};
```

Minor optimization which won't check substrings whose lengths haven't shown up in the dictionary.

```cpp
// OJ: https://leetcode.com/problems/word-break/
// Author: github.com/lzl124631x
// Time: O(S^3)
// Space: O(S + W)
class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> st(begin(dict), end(dict));
        int N = s.size(), minLen = INT_MAX, maxLen = 0;
        for (auto &w : dict) {
            minLen = min(minLen, (int)w.size());
            maxLen = max(maxLen, (int)w.size());
        }
        vector<bool> dp(N + 1, false);
        dp[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int len = minLen; len <= maxLen && i - len >= 0 && !dp[i]; ++len) {
                dp[i] = dp[i - len] && st.count(s.substr(i - len, len));
            }
        }
        return dp[N];
    }
};
```

## Solution 2. DP Top-down

```cpp
// OJ: https://leetcode.com/problems/word-break/
// Author: github.com/lzl124631x
// Time: O(S^3)
// Space: O(S + W)
class Solution {
    unordered_set<string> st;
    vector<int> m;
    bool dp(string &s, int i) {
        if (i == s.size()) return true;
        if (m[i] != -1) return m[i];
        m[i] = 0;
        for (int j = i + 1; j <= s.size() && m[i] != 1; ++j) {
            if (!dp(s, j) || st.count(s.substr(i, j - i)) == 0) continue;
            m[i] = 1;
        }
        return m[i];
    }
public:
    bool wordBreak(string s, vector<string>& dict) {
        m.assign(s.size(), -1);
        st = { begin(dict), end(dict) };
        return dp(s, 0);
    }
};
```

Minor optimization which won't check substrings whose lengths haven't shown up in the dictionary.

```cpp
// OJ: https://leetcode.com/problems/word-break/
// Author: github.com/lzl124631x
// Time: O(S^3)
// Space: O(S + W)
class Solution {
    unordered_set<string> st;
    int minLen = INT_MAX, maxLen = 0;
    vector<int> m;
    bool dp(string &s, int i) {
        if (i == s.size()) return true;
        if (m[i] != -1) return m[i];
        m[i] = 0;
        for (int len = minLen; len <= maxLen && i + len <= s.size() && m[i] != 1; ++len) {
            if (!dp(s, i + len) || st.count(s.substr(i, len)) == 0) continue;
            m[i] = 1;
        }
        return m[i];
    }
public:
    bool wordBreak(string s, vector<string>& dict) {
        m.assign(s.size(), -1);
        for (auto &w : dict) {
            st.insert(w);
            maxLen = max(maxLen, (int)w.size());
            minLen = min(minLen, (int)w.size());
        }
        return dp(s, 0);
    }
};
```

## Solution 3. DP Bottom-up + Trie

Let `dp[i]` be whether `s[i..N-1]` can be formed by dictionary `A`.

`dp[i] = dp[j+1] (i <= j)` if `s[i..j]` is in dictionary.

We can use Trie to check if a substring `s[i..j]` is in dictionary.

```cpp
// OJ: https://leetcode.com/problems/word-break
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
    void addWord(TrieNode *node, string &s) {
        for (char c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->end = true;
    }
public:
    bool wordBreak(string s, vector<string>& A) {
        TrieNode root;
        for (auto &w : A) addWord(&root, w);
        int N = s.size();
        vector<int> dp(N + 1, -1);
        dp[N] = 1;
        function<bool(int)> dfs = [&](int i) {
            if (dp[i] != -1) return dp[i];
            auto node = &root;
            dp[i] = 0;
            for (int j = i; j < N && node->next[s[j] - 'a']; ++j) {
                node = node->next[s[j] - 'a'];
                if (node->end) dp[i] = dfs(j + 1);
                if (dp[i]) break;
            }
            return dp[i];
        };
        return dfs(0);
    }
};
```