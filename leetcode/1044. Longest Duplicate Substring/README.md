# [1044. Longest Duplicate Substring (Hard)](https://leetcode.com/problems/longest-duplicate-substring/)

<p>Given a string <code>S</code>, consider all <em>duplicated substrings</em>: (contiguous) substrings of S that occur 2 or more times.&nbsp; (The occurrences&nbsp;may overlap.)</p>

<p>Return <strong>any</strong> duplicated&nbsp;substring that has the longest possible length.&nbsp; (If <code>S</code> does not have a duplicated substring, the answer is <code>""</code>.)</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"banana"</span>
<strong>Output: </strong><span id="example-output-1">"ana"</span>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"abcd"</span>
<strong>Output: </strong><span id="example-output-2">""</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>2 &lt;= S.length &lt;= 10^5</code></li>
	<li><code>S</code> consists of lowercase English letters.</li>
</ol>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Search + Rabin Karp

```cpp
// OJ: https://leetcode.com/problems/longest-duplicate-substring/
// Author: github.com/lzl124631x
// Time: O(N^2logN)
// Space: O(N)
class Solution {
    typedef long long LL;
    string getDup(string &S, int len) {
        unordered_map<LL, vector<int>> m;
        LL h = S[0], p = 1, d = 128, mod = 1e9 + 7;
        for (int i = 1; i < len; ++i) {
            h = (h * d + S[i]) % mod;
            p = (p * d) % mod;
        }
        m[h].push_back(0);
        for (int i = len; i < S.size(); ++i) {
            h = ((h - S[i - len] * p) * d + S[i]) % mod;
            if (h < 0) h += mod;
            if (m.count(h)) {
                auto s = S.substr(i - len + 1, len);
                for (int start : m[h]) {
                    if (S.substr(start, len) == s) return s;
                }
            }
            m[h].push_back(i - len + 1);
        }
        return "";
    }
public:
    string longestDupSubstring(string S) {
        int L = 0, R = S.size() - 1;
        string ans;
        while (L <= R) {
            int M = (L + R) / 2;
            auto s = getDup(S, M);
            if (s.size()) {
                L = M + 1;
                ans = s;
            } else R = M - 1;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/longest-duplicate-substring/
// Author: github.com/lzl124631x
// Time: O(N^2 * logN)
// Space: O(N)
// Ref: https://leetcode.com/problems/longest-duplicate-substring/discuss/695101/C%2B%2B-short-O(n-log(n))-solution-with-std%3A%3Aunordered_setlessstd%3A%3Astring_viewgreater
class Solution {
public:
    string longestDupSubstring(string S) {
        int N = S.size(), L = 0, R = N - 1;
        string_view ans;
        while (L <= R) {
            unordered_set<string_view> s;
            int M = (L + R) / 2;
            bool found = false;
            for (int i = 0; i <= N - M; ++i) {
                const auto [it, inserted] = s.emplace(S.data() + i, M);
                if (!inserted) {
                    found = true;
                    ans = *it;
                    break;
                }
            }
            if (found) L = M + 1;
            else R = M - 1;
        }
        return {ans.begin(), ans.end()};
    }
};
```