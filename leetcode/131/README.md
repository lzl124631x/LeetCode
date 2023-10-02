# [131. Palindrome Partitioning (Medium)](https://leetcode.com/problems/palindrome-partitioning/)

<p>Given a string <code>s</code>, partition <code>s</code> such that every substring of the partition is a <strong>palindrome</strong>. Return all possible palindrome partitioning of <code>s</code>.</p>

<p>A <strong>palindrome</strong> string is a string that reads the same backward as forward.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s = "aab"
<strong>Output:</strong> [["a","a","b"],["aa","b"]]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s = "a"
<strong>Output:</strong> [["a"]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 16</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [tiktok](https://leetcode.com/company/tiktok), [ByteDance](https://leetcode.com/company/bytedance)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Palindrome Partitioning II (Hard)](https://leetcode.com/problems/palindrome-partitioning-ii/)
* [Palindrome Partitioning IV (Hard)](https://leetcode.com/problems/palindrome-partitioning-iv/)

## Solution 1. DFS

### Time complexity

In the worst case, `s` has all the same characters. If `s` is of length `N`, then there are `2^(N-1)` ways to partition it. For each partition, we also need to copy the strings over and testing if all its segments are palindromes, taking `O(N)` time. So overall the time complexity is `O(N * 2^N)`.

```cpp
// OJ: https://leetcode.com/problems/palindrome-partitioning/
// Author: github.com/lzl124631x
// Time: O(N *  2^N)
// Space: O(N) extra space
class Solution {
    vector<vector<string>> ans;
    vector<string> tmp;
    bool isPalindrome(string &s, int i, int j) {
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
    }
    void dfs(string &s, int start) {
        if (start == s.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (!isPalindrome(s, start, i)) continue;
            tmp.push_back(s.substr(start, i - start + 1));
            dfs(s, i + 1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};
```

## Solution 2. DP + DFS

We called `isPalindrome` to the same segment multiple times in Solution 1. We can precompute `isPalindrome` via DP taking `O(N^2)` time.

Since we still need to copy the strings over, there is still an `O(N)` time complexity for each partition.

```cpp
// OJ: https://leetcode.com/problems/palindrome-partitioning/
// Author: github.com/lzl124631x
// Time: O(N * 2^N)
// Space: O(N)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int N = s.size();
        vector<vector<bool>> dp(N, vector<bool>(N));
        vector<string> tmp;
        vector<vector<string>> ans;
        function<void(int)> dfs = [&](int i) {
            if (i == N) {
                ans.push_back(tmp);
                return;
            }
            for (int j = i; j < N; ++j) {
                if (!dp[i][j]) continue;
                tmp.push_back(s.substr(i, j - i + 1));
                dfs(j + 1);
                tmp.pop_back();
            }
        };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[j][i] = s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1]);
            }
        }
        dfs(0);
        return ans;
    }
};
```