# [30. Substring with Concatenation of All Words (Hard)](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)

<p>You are given a string <code>s</code> and an array of strings <code>words</code> of <strong>the same length</strong>. Return&nbsp;all starting indices of substring(s) in <code>s</code>&nbsp;that is a concatenation of each word in <code>words</code> <strong>exactly once</strong>, <strong>in any order</strong>,&nbsp;and <strong>without any intervening characters</strong>.</p>

<p>You can return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "barfoothefoobarman", words = ["foo","bar"]
<strong>Output:</strong> [0,9]
<strong>Explanation:</strong> Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
<strong>Output:</strong> []
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
<strong>Output:</strong> [6,9,12]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists of lower-case English letters.</li>
	<li><code>1 &lt;= words.length &lt;= 5000</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 30</code></li>
	<li><code>words[i]</code>&nbsp;consists of lower-case English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Minimum Window Substring (Hard)](https://leetcode.com/problems/minimum-window-substring/)

## Solution 1. Fixed-length Sliding Window

```cpp
// OJ: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author: github.com/lzl124631x
// Time: O(MNL) where `M` is length of `A[i]`, `N` is length of `s`, and `L` is length of `A`.
// Space: O(ML)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& A) {
        int N = s.size(), M = A[0].size(), len = M * A.size();
        unordered_map<string, int> cnt, tmp;
        for (auto &w : A) cnt[w]++;
        vector<int> ans;
        for (int start = 0; start < M; ++start) {
            tmp.clear();
            int matched = 0;
            for (int i = start; i < N; i += M) {
                auto w = s.substr(i, M);
                if (cnt.count(w) && ++tmp[w] <= cnt[w]) matched++;
                if (i - len >= 0) {
                    auto rm = s.substr(i - len, M);
                    if (cnt.count(rm) && --tmp[rm] < cnt[rm]) matched--;
                }
                if (matched == A.size()) ans.push_back(i - len + M);
            }
        }
        return ans;
    }
};
```

## Solution 2. Backtracking

```cpp
// OJ: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// Author: github.com/lzl124631x
// Time: O(MNL)
// Space: O(ML)
class Solution {
private:
public:
    vector<int> findSubstring(string s, vector<string>& A) {
        if (A.empty()) return {};
        int L = A.size(), M = A[0].size(), last = s.size() - M * L;
        unordered_map<string, int> cnt;
        for (auto &w : A) ++cnt[w];
        vector<int> ans;
        function<bool(int, int)> dfs = [&](int i, int seen) {
            if (seen == L) return true;
            int &c = cnt[s.substr(i, M)];
            if (!c) return false;
            c--;
            bool ans = dfs(i + M, seen + 1);
            c++;
            return ans;
        };
        for (int i = 0; i <= last; ++i) {
            if (dfs(i, 0)) ans.push_back(i);
        }
        return ans;
    }
};
```