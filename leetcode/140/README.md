# [140. Word Break II (Hard)](https://leetcode.com/problems/word-break-ii)

<p>Given a string <code>s</code> and a dictionary of strings <code>wordDict</code>, add spaces in <code>s</code> to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in <strong>any order</strong>.</p>

<p><strong>Note</strong> that the same word in the dictionary may be reused multiple times in the segmentation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;catsanddog&quot;, wordDict = [&quot;cat&quot;,&quot;cats&quot;,&quot;and&quot;,&quot;sand&quot;,&quot;dog&quot;]
<strong>Output:</strong> [&quot;cats and dog&quot;,&quot;cat sand dog&quot;]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;pineapplepenapple&quot;, wordDict = [&quot;apple&quot;,&quot;pen&quot;,&quot;applepen&quot;,&quot;pine&quot;,&quot;pineapple&quot;]
<strong>Output:</strong> [&quot;pine apple pen apple&quot;,&quot;pineapple pen apple&quot;,&quot;pine applepen apple&quot;]
<strong>Explanation:</strong> Note that you are allowed to reuse a dictionary word.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;catsandog&quot;, wordDict = [&quot;cats&quot;,&quot;dog&quot;,&quot;sand&quot;,&quot;and&quot;,&quot;cat&quot;]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
	<li><code>1 &lt;= wordDict[i].length &lt;= 10</code></li>
	<li><code>s</code> and <code>wordDict[i]</code> consist of only lowercase English letters.</li>
	<li>All the strings of <code>wordDict</code> are <strong>unique</strong>.</li>
	<li>Input is generated in a way that the length of the answer doesn&#39;t exceed&nbsp;10<sup>5</sup>.</li>
</ul>


**Companies**:
[Bloomberg](https://leetcode.com/company/bloomberg), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft), [Uber](https://leetcode.com/company/uber), [Grammarly](https://leetcode.com/company/grammarly), [Adobe](https://leetcode.com/company/adobe), [Snapchat](https://leetcode.com/company/snapchat), [Audible](https://leetcode.com/company/audible), [Twitter](https://leetcode.com/company/twitter), [Dropbox](https://leetcode.com/company/dropbox)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [String](https://leetcode.com/tag/string), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Backtracking](https://leetcode.com/tag/backtracking), [Trie](https://leetcode.com/tag/trie), [Memoization](https://leetcode.com/tag/memoization)

**Similar Questions**:
* [Word Break (Medium)](https://leetcode.com/problems/word-break)
* [Concatenated Words (Hard)](https://leetcode.com/problems/concatenated-words)

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

Or use Trie

```cpp
// OJ: https://leetcode.com/problems/word-break-ii
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N + D)
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
    vector<string> wordBreak(string s, vector<string>& A) {
        vector<string> ans, tmp;
        TrieNode root;
        for (auto &w : A) addWord(&root, w);
        int N = s.size();
        function<void(int)> dfs = [&](int i) {
            if (i == N) {
                string line;
                for (auto &w : tmp) {
                    if (line.size()) line += ' ';
                    line += w;
                }
                ans.push_back(line);
                return;
            }
            auto node = &root;
            int start = i;
            while (i < N && node->next[s[i] - 'a']) {
                node = node->next[s[i] - 'a'];
                ++i;
                if (node->end) {
                    tmp.push_back(s.substr(start, i - start));
                    dfs(i);
                    tmp.pop_back();
                }
            }
        };
        dfs(0);
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