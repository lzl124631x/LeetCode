# [1044. Longest Duplicate Substring (Hard)](https://leetcode.com/problems/longest-duplicate-substring/)

<p>Given a string <code>s</code>, consider all <em>duplicated substrings</em>: (contiguous) substrings of s that occur 2 or more times.&nbsp;The occurrences&nbsp;may overlap.</p>

<p>Return <strong>any</strong> duplicated&nbsp;substring that has the longest possible length.&nbsp;If <code>s</code> does not have a duplicated substring, the answer is <code>""</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "banana"
<strong>Output:</strong> "ana"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "abcd"
<strong>Output:</strong> ""
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lowercase English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Binary Search](https://leetcode.com/tag/binary-search/), [Sliding Window](https://leetcode.com/tag/sliding-window/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Suffix Array](https://leetcode.com/tag/suffix-array/), [Hash Function](https://leetcode.com/tag/hash-function/)

## Solution 1. Binary Search + Rabin Karp

Without hash conflict check

```cpp
// OJ: https://leetcode.com/problems/longest-duplicate-substring/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    int findDup(string &s, int len) {
        unordered_set<unsigned long long> st;
        unsigned long long d = 16777619, h = 0, p = 1;
        for (int i = 0; i < s.size(); ++i) {
            h = h * d + s[i];
            if (i < len) p *= d;
            else h -= s[i - len] * p;
            if (i >= len - 1) {
                if (st.count(h)) return i - len + 1;
                st.insert(h);
            }
        }
        return -1;
    }
public:
    string longestDupSubstring(string s) {
        int L = 0, R = s.size() - 1, start = 0;
        while (L < R) {
            int M = (L + R + 1) / 2, i = findDup(s, M);
            if (i != -1) {
                L = M;
                start = i;
            } else R = M - 1;
        }
        return s.substr(start, L);
    }
};
```

Or with hash conflict check.

```cpp
// OJ: https://leetcode.com/problems/longest-duplicate-substring/
// Author: github.com/lzl124631x
// Time: average O(NlogN), worst O(N^2 * logN)
// Space: O(N)
class Solution {
    int findDup(string &s, int len) {
        unordered_map<unsigned long long, vector<int>> m;
        unsigned long long h = 0, p = 1, d = 16777619;
        for (int i = 0; i < s.size(); ++i) {
            h = h * d + s[i];
            if (i < len) p *= d;
            else h -= s[i - len] * p;
            if (i >= len - 1) {
                if (m.count(h)) {
                    for (int k : m[h]) {
                        int j = 0;
                        for (; j < len && s[k + j] == s[i - len + 1 + j]; ++j);
                        if (j == len) return k;
                    } 
                }
                m[h].push_back(i - len + 1);
            }
        }
        return -1;
    }
public:
    string longestDupSubstring(string S) {
        int L = 0, R = S.size(), start = 0;
        while (L < R) {
            int M = (L + R + 1) / 2, i = findDup(S, M);
            if (i != -1) {
                L = M;
                start = i;
            } else R = M - 1;
        }
        return S.substr(start, L);
    }
};
```

Or precompute the hashes and pow values.

```cpp
// OJ: https://leetcode.com/problems/longest-duplicate-substring/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
const int maxN = 30001;
class Solution {
    typedef unsigned long long ULL;
    ULL p[maxN], h[maxN], N, d = 16777619;
    ULL hash(int begin, int end) {
        return h[end] - h[begin] * p[end - begin];
    }
    int findDup(string &s, int len) {
        unordered_set<ULL> st;
        for (int i = 0; i + len <= N; ++i) {
            ULL x = hash(i, i + len);
            if (st.count(x)) return i;
            st.insert(x);
        }
        return -1;
    }
public:
    string longestDupSubstring(string s) {
        N = s.size();
        p[0] = 1;
        for (int i = 0; i < N; ++i) {
            p[i + 1] = p[i] * d;
            h[i + 1] = h[i] * d + s[i];
        }
        int L = 0, R = N - 1, start = 0;
        while (L < R) {
            int M = L + R + 1 >> 1, i = findDup(s, M);
            if (i != -1) {
                start = i;
                L = M;
            } else R = M - 1;
        }
        return s.substr(start, L);
    }
};
```

## Solution 2. Binary Search + String View

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