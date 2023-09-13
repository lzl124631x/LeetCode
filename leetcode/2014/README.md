# [2014. Longest Subsequence Repeated k Times (Hard)](https://leetcode.com/problems/longest-subsequence-repeated-k-times/)

<p>You are given a string <code>s</code> of length <code>n</code>, and an integer <code>k</code>. You are tasked to find the <strong>longest subsequence repeated</strong> <code>k</code> times in string <code>s</code>.</p>

<p>A <strong>subsequence</strong> is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.</p>

<p>A subsequence <code>seq</code> is <strong>repeated</strong> <code>k</code> times in the string <code>s</code> if <code>seq * k</code> is a subsequence of <code>s</code>, where <code>seq * k</code> represents a string constructed by concatenating <code>seq</code> <code>k</code> times.</p>

<ul>
	<li>For example, <code>"bba"</code> is repeated <code>2</code> times in the string <code>"bababcba"</code>, because the string <code>"bbabba"</code>, constructed by concatenating <code>"bba"</code> <code>2</code> times, is a subsequence of the string <code>"<strong><u>b</u></strong>a<strong><u>bab</u></strong>c<strong><u>ba</u></strong>"</code>.</li>
</ul>

<p>Return <em>the <strong>longest subsequence repeated</strong> </em><code>k</code><em> times in string </em><code>s</code><em>. If multiple such subsequences are found, return the <strong>lexicographically largest</strong> one. If there is no such subsequence, return an <strong>empty</strong> string</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="example 1" src="https://assets.leetcode.com/uploads/2021/08/30/longest-subsequence-repeat-k-times.png" style="width: 457px; height: 99px;">
<pre><strong>Input:</strong> s = "letsleetcode", k = 2
<strong>Output:</strong> "let"
<strong>Explanation:</strong> There are two longest subsequences repeated 2 times: "let" and "ete".
"let" is the lexicographically largest one.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "bb", k = 2
<strong>Output:</strong> "b"
<strong>Explanation:</strong> The longest subsequence repeated 2 times is "b".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "ab", k = 2
<strong>Output:</strong> ""
<strong>Explanation:</strong> There is no subsequence repeated 2 times. Empty string is returned.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> s = "bbabbabbbbabaababab", k = 3
<strong>Output:</strong> "bbbb"
<strong>Explanation:</strong> The longest subsequence "bbbb" is repeated 3 times in "<u>bb</u>a<u>bb</u>a<u>bbbb</u>a<u>b</u>aa<u>b</u>a<u>b</u>a<u>b</u>".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == s.length</code></li>
	<li><code>2 &lt;= n, k &lt;= 2000</code></li>
	<li><code>2 &lt;= n &lt; k * 8</code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/), [Greedy](https://leetcode.com/tag/greedy/), [Counting](https://leetcode.com/tag/counting/), [Enumeration](https://leetcode.com/tag/enumeration/)

**Similar Questions**:
* [Longest Substring with At Least K Repeating Characters (Medium)](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)


## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/longest-subsequence-repeated-k-times/
// Author: github.com/lzl124631x
// Time: O(26^(N/K) * N)
// Space: O(N/K)
class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int cnt[26] = {};
        string ans;
        auto isSubsequence = [&]() {
            int matched = 0, i = 0, j = 0, M = s.size(), N = ans.size();
            for (; i < M && matched < k; ++i) {
                if (s[i] == ans[j]) ++j;
                if (j == N) j = 0, matched++;
            }
            return matched == k;
        };
        function<bool(int)> dfs = [&](int len) {
            if (ans.size() == len) return true;
            for (int i = 25; i >= 0; --i) {
                if (cnt[i] == 0) continue;
                ans.push_back('a' + i);
                if (isSubsequence() && dfs(len)) return true;
                ans.pop_back();
            }
            return false;
        };
        for (char c : s) cnt[c - 'a']++;
        for (int &n : cnt) n /= k;
        int j = 0;
        for (int i = 0; i < s.size(); ++i) { // remove the characters in `s` that doesn't occurrs `k` times.
            if (cnt[s[i] - 'a']) s[j++] = s[i];
        }
        s.resize(j);
        for (int len = 7; len >= 1; --len) {
            if (dfs(len)) return ans;
        }
        return "";
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/longest-subsequence-repeated-k-times/
// Author: github.com/lzl124631x
// Time: O(26^(N/K) * N)
// Space: O(N/K)
class Solution {
    string ans;
    int cnt[26] = {};
    bool match(string &s, int k) {
        int i = 0, j = 0, M = s.size(), N = ans.size();
        for (; i < M && k; ++i) {
            if (s[i] != ans[j]) continue;
            ++j;
            if (j == N) j = 0, --k;
        }
        return k == 0;
    }
    bool dfs(string &s, int k, int len) {
        if (len == 0) return true;
        for (char c = 'z'; c >= 'a'; --c) {
            if (ans.size() && ans.back() == c) continue;
            int used = min(len, cnt[c - 'a']);
            for (int i = 0; i < used; ++i) ans.push_back(c);
            while (ans.size() && ans.back() == c) {
                if (match(s, k) && dfs(s, k, len - used)) return true;
                --used;
                ans.pop_back();
            }
        }
        return false;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        for (char c : s) cnt[c - 'a']++;
        for (int &n : cnt) n /= k;
        for (int len = s.size() / k; len >= 1; --len) {
            if (dfs(s, k, len)) return ans;
        }
        return "";
    }
};
```

## Solution 2. BFS

```cpp
// OJ: https://leetcode.com/problems/longest-subsequence-repeated-k-times/
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(?)
// Ref: https://leetcode.com/problems/longest-subsequence-repeated-k-times/discuss/1472755/short-solutionApriori-algorithm-and-BFS-beat-100
class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q{{""}};
        unordered_set<string> valid{""};
        string ans;
        while (q.size()) {
            auto x = q.front();
            q.pop();
            for (char c = 'a'; c <= 'z'; ++c) {
                auto y = x + c;
                auto suffix = y.substr(1);
                if (valid.count(suffix) == 0) continue; // suffix must be also valid.
                int matched = 0, i = 0, j = 0;
                for (; i < s.size() && matched < k; ++i) {
                    if (s[i] == y[j]) ++j;
                    if (j == y.size()) j = 0, ++matched;
                }
                if (matched == k) {
                    ans = y;
                    q.push(y);
                    valid.insert(y);
                }
            }
        }
        return ans;
    }
};
```