# [139. Word Break (Medium)](https://leetcode.com/problems/word-break/)

<p>Given a <strong>non-empty</strong> string <em>s</em> and a dictionary <em>wordDict</em> containing a list of <strong>non-empty</strong> words, determine if <em>s</em> can be segmented into a space-separated sequence of one or more dictionary words.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>The same word in the dictionary may be reused multiple times in the segmentation.</li>
	<li>You may assume the dictionary does not contain duplicate words.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "leetcode", wordDict = ["leet", "code"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because <code>"leetcode"</code> can be segmented as <code>"leet code"</code>.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "applepenapple", wordDict = ["apple", "pen"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because <code>"</code>applepenapple<code>"</code> can be segmented as <code>"</code>apple pen apple<code>"</code>.
&nbsp;            Note that you are allowed to reuse a dictionary word.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
<strong>Output:</strong> false
</pre>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Word Break II (Hard)](https://leetcode.com/problems/word-break-ii/)

## Solution 1. DP Bottom-up

Let `dp[i]` be true if `s[0..(i-1)]` can be segmented using `wordDict`.

```
dp[0] = true
dp[i] = true if dp[j] && s[j..i] is in dict
        where i is in [1, S], j is in [0, i)
```

```cpp
// OJ: https://leetcode.com/problems/word-break/
// Author: github.com/lzl124631x
// Time: O(S^3)
// Space: O(S + W)
class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> ws(dict.begin(), dict.end());
        int N = s.size();
        vector<bool> dp(N + 1);
        dp[0] = true;
        for (int i = 1; i <= N; ++i) {
            for (int j = i - 1; j >= 0 && !dp[i]; --j) {
                if (!dp[j] || !ws.count(s.substr(j, i - j))) continue;
                dp[i] = true;
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
    unordered_set<string> ws;
    vector<int> m;
    bool dp(string &s, int i) {
        if (i == s.size()) return true;
        if (m[i] != -1) return m[i];
        m[i] = 0;
        for (int j = s.size(); j > i && m[i] != 1; --j) {
            if (!dp(s, j) || ws.count(s.substr(i, j - i)) == 0) continue;
            m[i] = 1;
        }
        return m[i];
    }
public:
    bool wordBreak(string s, vector<string>& dist) {
        ws = { dist.begin(), dist.end() };
        m.assign(s.size(), -1);
        return dp(s, 0);
    }
};
```