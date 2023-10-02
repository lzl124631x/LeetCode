# [97. Interleaving String (Medium)](https://leetcode.com/problems/interleaving-string)

<p>Given strings <code>s1</code>, <code>s2</code>, and <code>s3</code>, find whether <code>s3</code> is formed by an <strong>interleaving</strong> of <code>s1</code> and <code>s2</code>.</p>
<p>An <strong>interleaving</strong> of two strings <code>s</code> and <code>t</code> is a configuration where <code>s</code> and <code>t</code> are divided into <code>n</code> and <code>m</code> <span data-keyword="substring-nonempty" datakeyword="substring-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><div class="popover-wrapper inline-block" data-headlessui-state=""><div><div id="headlessui-popover-button-:r61:" aria-expanded="false" data-headlessui-state=""><div>substrings</div></div><div style="position: fixed; z-index: 9999; inset: 0px auto auto 0px; transform: translate(62px, 279px);"></div></div></div></span> respectively, such that:</p>
<ul>
	<li><code>s = s<sub>1</sub> + s<sub>2</sub> + ... + s<sub>n</sub></code></li>
	<li><code>t = t<sub>1</sub> + t<sub>2</sub> + ... + t<sub>m</sub></code></li>
	<li><code>|n - m| &lt;= 1</code></li>
	<li>The <strong>interleaving</strong> is <code>s<sub>1</sub> + t<sub>1</sub> + s<sub>2</sub> + t<sub>2</sub> + s<sub>3</sub> + t<sub>3</sub> + ...</code> or <code>t<sub>1</sub> + s<sub>1</sub> + t<sub>2</sub> + s<sub>2</sub> + t<sub>3</sub> + s<sub>3</sub> + ...</code></li>
</ul>
<p><strong>Note:</strong> <code>a + b</code> is the concatenation of strings <code>a</code> and <code>b</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg" style="width: 561px; height: 203px;">
<pre><strong>Input:</strong> s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
<strong>Output:</strong> true
<strong>Explanation:</strong> One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
<strong>Output:</strong> false
<strong>Explanation:</strong> Notice how it is impossible to interleave s2 with any other string to obtain s3.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> s1 = "", s2 = "", s3 = ""
<strong>Output:</strong> true
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>0 &lt;= s1.length, s2.length &lt;= 100</code></li>
	<li><code>0 &lt;= s3.length &lt;= 200</code></li>
	<li><code>s1</code>, <code>s2</code>, and <code>s3</code> consist of lowercase English letters.</li>
</ul>
<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve it using only <code>O(s2.length)</code> additional memory space?</p>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. DP Top-down (DFS + Memo)

```cpp
// OJ: https://leetcode.com/problems/interleaving-string/
// Author: github.com/lzl124631x
// Time: O(2^(M+N))
// Space: O(MN)
class Solution {
    int M, N;
    vector<vector<int>> m;
    int dfs(string &a, string &b, string &c, int i, int j) {
        if (i == M && j == N) return 1;
        if (m[i][j] != 0) return m[i][j];
        int val = -1;
        if (i < M && a[i] == c[i + j]) val = dfs(a, b, c, i + 1, j);
        if (val != 1 && j < N && b[j] == c[i + j]) val = dfs(a, b, c, i, j + 1);
        return m[i][j] = val;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        M = s1.size(), N = s2.size();
        if (M + N != s3.size()) return false;
        m.assign(M + 1, vector<int>(N + 1));
        return dfs(s1, s2, s3, 0, 0) == 1;
    }
};
```

## Solution 2. DP Bottom-up

Let `dp[i][j]` be whether `a[0..(i-1)]` and `b[0..(j-1)]` can form `c[0..(i+j-1)]`.

```
dp[i][j] =    (i-1 >= 0 && a[i-1] == c[i+j-1] && dp[i-1][j])
           || (j-1 >= 0 && b[j-1] == c[i+j-1] && dp[i][j-1])

dp[0][0] = true
```

```cpp
// OJ: https://leetcode.com/problems/interleaving-string/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(MN)
class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        int M = a.size(), N = b.size();
        if (c.size() != M + N) return false;
        vector<vector<bool>> dp(M + 1, vector<bool>(N + 1));
        dp[0][0] = true;
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 && j == 0) continue;
                dp[i][j] = (i >= 1 && a[i - 1] == c[i + j - 1] && dp[i - 1][j])
                        || (j >= 1 && b[j - 1] == c[i + j - 1] && dp[i][j - 1]);
            }
        }
        return dp[M][N];
    }
};
```

## Solution 3. DP with Space Optimization

Since `dp[i][j]` is only dependent on `dp[i-1][j]` and `dp[i][j-1]`, we can reduce the `dp` array from 2D to 1D.

```cpp
// OJ: https://leetcode.com/problems/interleaving-string/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        int M = a.size(), N = b.size();
        if (c.size() != M + N) return false;
        vector<bool> dp(N + 1);
        dp[0] = true;
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j <= N; ++j) {
                if (i == 0 && j == 0) continue;
                dp[j] = (i >= 1 && a[i - 1] == c[i + j - 1] && dp[j]) || (j >= 1 && b[j - 1] == c[i + j - 1] && dp[j - 1]);
            }
        }
        return dp[N];
    }
};
```