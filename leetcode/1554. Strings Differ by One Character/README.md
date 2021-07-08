# [1554. Strings Differ by One Character (Medium)](https://leetcode.com/problems/strings-differ-by-one-character/)

<p>Given a list&nbsp;of strings <code>dict</code> where all the strings are of the same length.</p>

<p>Return <code>True</code> if there are 2 strings that only differ by 1 character in the same index, otherwise&nbsp;return <code>False</code>.</p>

<p><strong>Follow up:&nbsp;</strong>Could you solve this problem in O(n*m) where n is the length of <code>dict</code> and m is the length of each string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> dict = ["abcd","acbd", "aacd"]
<strong>Output:</strong> true
<strong>Explanation:</strong> Strings "a<strong>b</strong>cd" and "a<strong>a</strong>cd" differ only by one character in the index 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> dict = ["ab","cd","yz"]
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> dict = ["abcd","cccc","abyd","abab"]
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>Number of characters in <code>dict &lt;= 10^5</code></li>
	<li><code>dict[i].length == dict[j].length</code></li>
	<li><code>dict[i]</code> should be unique.</li>
	<li><code>dict[i]</code> contains only lowercase English letters.</li>
</ul>


**Companies**:  
[Airbnb](https://leetcode.com/company/airbnb)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Rolling Hash](https://leetcode.com/tag/rolling-hash/), [Hash Function](https://leetcode.com/tag/hash-function/)

## Solution 1. Set

```cpp
// OJ: https://leetcode.com/problems/strings-differ-by-one-character/
// Author: github.com/lzl124631x
// Time: O(NM^2)
// Space: O(N)
class Solution {
public:
    bool differByOne(vector<string>& A) {
        unordered_set<string> s(begin(A), end(A));
        for (auto str : s) {
            for (int i = 0; i < str.size(); ++i) {
                char c = str[i];
                for (int j = 0; j < 26; ++j) {
                    if (c == 'a' + j) continue;
                    str[i] = 'a' + j;
                    if (s.count(str)) return true;
                }
                str[i] = c;
            }
        }
        return false;
    }
};
```

## Solution 2. Rabin Karp

```cpp
// OJ: https://leetcode.com/problems/strings-differ-by-one-character/
// Author: github.com/lzl124631x
// Time: O(NM)
// Space: O(N)
class Solution {
    typedef unsigned long long ULL;
public:
    bool differByOne(vector<string>& A) {
        ULL d = 16777619, p = 1, N = A.size(), M = A[0].size();
        vector<ULL> h(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                h[i] = h[i] * d + A[i][j];
            }
        }
        for (int i = M - 1; i >= 0; --i, p *= d) {
            unordered_set<ULL> s;
            for (int j = 0; j < N; ++j) {
                ULL n = h[j] - A[j][i] * p;
                if (s.count(n)) return true;
                s.insert(n);
            }
        }
        return false;
    }
};
```