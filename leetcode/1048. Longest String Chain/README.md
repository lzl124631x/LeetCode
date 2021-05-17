# [1048. Longest String Chain (Medium)](https://leetcode.com/problems/longest-string-chain/)

<p>Given a list of words, each word consists of English lowercase letters.</p>

<p>Let's say <code>word1</code> is a predecessor of <code>word2</code>&nbsp;if and only if we can add exactly one letter anywhere in <code>word1</code> to make it equal to <code>word2</code>.&nbsp; For example,&nbsp;<code>"abc"</code>&nbsp;is a predecessor of <code>"abac"</code>.</p>

<p>A <em>word chain&nbsp;</em>is a sequence of words <code>[word_1, word_2, ..., word_k]</code>&nbsp;with <code>k &gt;= 1</code>,&nbsp;where <code>word_1</code> is a predecessor of <code>word_2</code>, <code>word_2</code> is a predecessor of <code>word_3</code>, and so on.</p>

<p>Return the longest possible length of a word chain with words chosen from the given list of <code>words</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["a","b","ba","bca","bda","bdca"]</span>
<strong>Output: </strong><span id="example-output-1">4
<strong>Explanation</strong>: one of </span>the longest word chain is "a","ba","bda","bdca".
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 16</code></li>
	<li><code>words[i]</code> only consists of English lowercase letters.</li>
</ol>

<div>
<p>&nbsp;</p>
</div>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. Top-down DP

```cpp
// OJ: https://leetcode.com/problems/longest-string-chain/
// Author: github.com/lzl124631x
// Time: O(N * S^2)
// Space: O(NS)
class Solution {
    unordered_map<string, int> m; 
    int dp(const string &s) {
        if (m[s]) return m[s];
        if (s.size() == 1) return 1;
        int ans = 1;
        for (int i = 0; i < s.size(); ++i) {
            auto copy = s;
            copy.erase(begin(copy) + i);
            if (m.count(copy)) {
                ans = max(ans, 1 + dp(copy));
            }
        }
        return m[s] = ans;
    }
public:
    int longestStrChain(vector<string>& A) {
        for (auto &s : A) m[s] = 0;
        int ans = 0;
        for (const auto &[s, len] : m) {
            ans = max(ans, dp(s));
        }
        return ans;
    }
};
```

## Solution 2. Bottom-up DP

```cpp
// OJ: https://leetcode.com/problems/longest-string-chain/
// Author: github.com/lzl124631x
// Time: O(N * S^2)
// Space: O(NS)
class Solution {
public:
    int longestStrChain(vector<string>& A) {
        sort(begin(A), end(A), [](auto &a, auto &b) { return a.size() < b.size(); });
        unordered_map<string, int> dp;
        int ans = 1;
        for (auto &s : A) {
            dp[s] = 1;
            for (int i = 0; i < s.size(); ++i) {
                auto next = s.substr(0, i) + s.substr(i + 1);
                if (dp.count(next)) {
                    dp[s] = max(dp[s], dp[next] + 1);
                    ans = max(ans, dp[s]);
                }
            }
        }
        return ans;
    }
};
```