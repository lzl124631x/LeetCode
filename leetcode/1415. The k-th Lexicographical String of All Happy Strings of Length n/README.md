# [1415. The k-th Lexicographical String of All Happy Strings of Length n (Medium)](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/)

<p>A <strong>happy string</strong> is a string that:</p>

<ul>
	<li>consists only of letters of the set <code>['a', 'b', 'c']</code>.</li>
	<li><code>s[i] != s[i + 1]</code>&nbsp;for all values of <code>i</code> from <code>1</code> to <code>s.length - 1</code> (string is 1-indexed).</li>
</ul>

<p>For example, strings <strong>"abc", "ac", "b"</strong> and <strong>"abcbabcbcb"</strong> are all happy strings and strings <strong>"aa", "baa"</strong> and&nbsp;<strong>"ababbc"</strong> are not happy strings.</p>

<p>Given two integers <code>n</code> and <code>k</code>, consider a list of all happy strings of length <code>n</code> sorted in lexicographical order.</p>

<p>Return <em>the kth string</em> of this list or return an <strong>empty string</strong>&nbsp;if there are less than <code>k</code> happy strings of length <code>n</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 1, k = 3
<strong>Output:</strong> "c"
<strong>Explanation:</strong> The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1, k = 4
<strong>Output:</strong> ""
<strong>Explanation:</strong> There are only 3 happy strings of length 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 3, k = 9
<strong>Output:</strong> "cab"
<strong>Explanation:</strong> There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 2, k = 7
<strong>Output:</strong> ""
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> n = 10, k = 100
<strong>Output:</strong> "abacbabacb"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
</ul>

<div id="vidyowebrtcscreenshare_is_installed">&nbsp;</div>

**Related Topics**:  
[Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1. Naive Solution

```cpp
// OJ: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
// Author: github.com/lzl124631x
// Time: O(3^N)
// Space: O(1)
class Solution {
    string addOne(string &s) {
        int i = s.size() - 1;
        for (; i >= 0; --i) {
            if (s[i] == 'c') {
                s[i] = 'a';
                continue;
            }
            s[i]++;
            break;
        }
        return i == -1 ? (s = "") : s;
    }
    bool valid(string &s) {
        int i = s.size() - 1;
        for (; i > 0; --i) {
            if (s[i] == s[i - 1]) return false;
        }
        return true;
    }
    string next(string &s) {
        do {
            addOne(s);
        } while (s != "" && !valid(s));
        return s;
    }
public:
    string getHappyString(int n, int k) {
        string ans;
        for (int i = 0; i < n; ++i) ans.push_back(i % 2 == 0 ? 'a' : 'b');
        while (--k) {
            ans = next(ans);
            if (ans == "") return "";
        }
        return ans;
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
// Author: github.com/lzl124631x
// Time: O(3^N). It should be smaller than O(3^N) since there are cases skipped earlier, but should be greater than O(NK).
// Space: O(NK)
// Ref: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/discuss/585557/C%2B%2B-Straightforward-DFS.-Skip-appending-same-char.
class Solution {
    vector<string> ans;
    void dfs(string &cur, int n, int k) {
        if (ans.size() == k) return;
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            if (cur.size() && cur.back() == 'a' + i) continue;
            cur.push_back('a' + i);
            dfs(cur, n, k);
            cur.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        string cur;
        dfs(cur, n, k);
        return ans.size() == k ? ans.back() : "";
    }
};
```