# [2707. Extra Characters in a String (Medium)](https://leetcode.com/problems/extra-characters-in-a-string)

<p>You are given a <strong>0-indexed</strong> string <code>s</code> and a dictionary of words <code>dictionary</code>. You have to break <code>s</code> into one or more <strong>non-overlapping</strong> substrings such that each substring is present in <code>dictionary</code>. There may be some <strong>extra characters</strong> in <code>s</code> which are not present in any of the substrings.</p>
<p>Return <em>the <strong>minimum</strong> number of extra characters left over if you break up </em><code>s</code><em> optimally.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> s = "leetscode", dictionary = ["leet","code","leetcode"]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s = "sayhelloworld", dictionary = ["hello","world"]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>1 &lt;= dictionary.length &lt;= 50</code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 50</code></li>
	<li><code>dictionary[i]</code>&nbsp;and <code>s</code> consists of only lowercase English letters</li>
	<li><code>dictionary</code> contains distinct words</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Trie](https://leetcode.com/tag/trie/)

**Similar Questions**:
* [Word Break (Medium)](https://leetcode.com/problems/word-break/)

## Solution 1. Trie + Bottom-up DP

```cpp
// OJ: https://leetcode.com/problems/extra-characters-in-a-string
// Author: github.com/lzl124631x
// Time: O(DL + N^2) where D is the length of dictionary, L is the maximum length of words in dictionary,
//                      N is the length of S.
// Space: O(DL)
struct TrieNode {
    TrieNode *next[26] = {};
    bool end = false;
};
class Solution {
    void addWord(TrieNode *node, string &s) {
        for (char c : s) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();
            node = node->next[c - 'a'];
        }
        node->end = true;
    }
public:
    int minExtraChar(string s, vector<string>& A) {
        TrieNode root;
        for (auto &s : A) addWord(&root, s);
        int N = s.size(), ans = N;
        vector<int> dp(N + 1, INT_MAX);
        dp[N] = 0;
        for (int i = N - 1; i >= 0; --i) {
            auto node = &root;
            int j = i;
            while (j < N && node->next[s[j] - 'a']) {
                node = node->next[s[j] - 'a'];
                dp[i] = min(dp[i], (node->end ? 0 : j - i + 1) + dp[j + 1]);
                ++j;
            }
            if (dp[i] == INT_MAX) dp[i] = dp[i + 1] + 1;
        }
        return dp[0];
    }
};
```

## Solution 2. Unordered Set + Top-down DP

```cpp
// OJ: https://leetcode.com/problems/extra-characters-in-a-string
// Author: github.com/lzl124631x
// Time: O(DL + N^2)
// Space: O(DL + N)
class Solution {
public:
    int minExtraChar(string s, vector<string>& A) {
        unordered_set<string> dict(begin(A), end(A));
        int N = s.size();
        vector<int> m(N, INT_MAX);
        function<int(int)> dfs = [&](int start) {
            if (start == N) return 0;
            if (m[start] != INT_MAX) return m[start];
            m[start] = 1 + dfs(start + 1);
            for (int i = start; i < N; ++i) {
                auto sub = s.substr(start, i - start + 1);
                if (dict.count(sub)) m[start] = min(m[start], dfs(i + 1));
            }
            return m[start];
        };
        return dfs(0);
    }
};
```