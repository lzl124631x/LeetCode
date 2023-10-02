# [1048. Longest String Chain (Medium)](https://leetcode.com/problems/longest-string-chain)

<p>You are given an array of <code>words</code> where each word consists of lowercase English letters.</p>

<p><code>word<sub>A</sub></code> is a <strong>predecessor</strong> of <code>word<sub>B</sub></code> if and only if we can insert <strong>exactly one</strong> letter anywhere in <code>word<sub>A</sub></code> <strong>without changing the order of the other characters</strong> to make it equal to <code>word<sub>B</sub></code>.</p>

<ul>
	<li>For example, <code>&quot;abc&quot;</code> is a <strong>predecessor</strong> of <code>&quot;ab<u>a</u>c&quot;</code>, while <code>&quot;cba&quot;</code> is not a <strong>predecessor</strong> of <code>&quot;bcad&quot;</code>.</li>
</ul>

<p>A <strong>word chain</strong><em> </em>is a sequence of words <code>[word<sub>1</sub>, word<sub>2</sub>, ..., word<sub>k</sub>]</code> with <code>k &gt;= 1</code>, where <code>word<sub>1</sub></code> is a <strong>predecessor</strong> of <code>word<sub>2</sub></code>, <code>word<sub>2</sub></code> is a <strong>predecessor</strong> of <code>word<sub>3</sub></code>, and so on. A single word is trivially a <strong>word chain</strong> with <code>k == 1</code>.</p>

<p>Return <em>the <strong>length</strong> of the <strong>longest possible word chain</strong> with words chosen from the given list of </em><code>words</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;a&quot;,&quot;b&quot;,&quot;ba&quot;,&quot;bca&quot;,&quot;bda&quot;,&quot;bdca&quot;]
<strong>Output:</strong> 4
<strong>Explanation</strong>: One of the longest word chains is [&quot;a&quot;,&quot;<u>b</u>a&quot;,&quot;b<u>d</u>a&quot;,&quot;bd<u>c</u>a&quot;].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;xbc&quot;,&quot;pcxbcf&quot;,&quot;xb&quot;,&quot;cxbc&quot;,&quot;pcxbc&quot;]
<strong>Output:</strong> 5
<strong>Explanation:</strong> All the words can be put in a word chain [&quot;xb&quot;, &quot;xb<u>c</u>&quot;, &quot;<u>c</u>xbc&quot;, &quot;<u>p</u>cxbc&quot;, &quot;pcxbc<u>f</u>&quot;].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> words = [&quot;abcd&quot;,&quot;dbqca&quot;]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The trivial word chain [&quot;abcd&quot;] is one of the longest word chains.
[&quot;abcd&quot;,&quot;dbqca&quot;] is not a valid word chain because the ordering of the letters is changed.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 1000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 16</code></li>
	<li><code>words[i]</code> only consists of lowercase English letters.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Lucid](https://leetcode.com/company/lucid), [TikTok](https://leetcode.com/company/tiktok), [MathWorks](https://leetcode.com/company/mathworks), [Bloomberg](https://leetcode.com/company/bloomberg), [Facebook](https://leetcode.com/company/facebook), [Oracle](https://leetcode.com/company/oracle), [ByteDance](https://leetcode.com/company/bytedance), [Flipkart](https://leetcode.com/company/flipkart), [Apple](https://leetcode.com/company/apple), [Two Sigma](https://leetcode.com/company/two-sigma), [Wix](https://leetcode.com/company/wix)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Two Pointers](https://leetcode.com/tag/two-pointers), [String](https://leetcode.com/tag/string), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming)

**Hints**:
* Instead of adding a character, try deleting a character to form a chain in reverse.
* For each word in order of length, for each word2 which is word with one character removed, length[word2] = max(length[word2], length[word] + 1).

## Solution 1. Top-down DP

For each string, if we check its neighbor by adding a letter, there will be `(S + 1) * 26` possible neighbors. If we check its neighbor by removing a letter, there will be `S` neighbors.

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
        for (auto &s : A) {
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