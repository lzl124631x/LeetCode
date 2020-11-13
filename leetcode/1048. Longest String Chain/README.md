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

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-string-chain/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int longestStrChain(vector<string>& A) {
        int N = A.size(), ans = 1;
        vector<int> id(N), len(N, 1);
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return A[a].size() < A[b].size(); });
        vector<array<int, 26>> cnts(N);
        map<int, vector<int>> m;
        for (int i = 0; i < N; ++i) {
            for (char c : A[i]) cnts[i][c - 'a']++;
            m[A[i].size()].push_back(i);
        }
        for (auto &[cnt, ids] : m) {
            if (m.count(cnt - 1) == 0) continue;
            for (int i : ids) {
                for (int j : m[cnt - 1]) {
                    int diff = 0;
                    for (int k = 0; k < 26; ++k) {
                        diff += abs(cnts[i][k] - cnts[j][k]);
                        if (diff > 1) break;
                    }
                    if (diff == 1) len[i] = max(len[i], len[j] + 1);
                }
                ans = max(ans, len[i]);
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/longest-string-chain/
// Author: github.com/lzl124631x
// Time: O(NSS)
// Space: O(NS)
// Ref: https://leetcode.com/problems/longest-string-chain/discuss/294890/C%2B%2BJavaPython-DP-Solution
class Solution {
public:
    int longestStrChain(vector<string>& A) {
        auto cmp = [](string &a, string &b) { return a.size() < b.size(); };
        sort(begin(A), end(A), cmp);
        unordered_map<string, int> dp;
        int ans = 1;
        for (auto &s : A) {
            for (int i = 0; i < s.size(); ++i) {
                dp[s] = max(dp[s], dp[s.substr(0, i) + s.substr(i + 1)] + 1);
                ans = max(ans, dp[s]);
            }
        }
        return ans;
    }
};
```