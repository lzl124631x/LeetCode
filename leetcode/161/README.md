# [161. One Edit Distance (Medium)](https://leetcode.com/problems/one-edit-distance/)

<p>Given two strings <b><i>s</i></b>&nbsp;and <b><i>t</i></b>, determine if they are both one edit distance apart.</p>

<p><strong>Note:</strong>&nbsp;</p>

<p>There are 3 possiblities to satisify one edit distance apart:</p>

<ol>
	<li>Insert a&nbsp;character into <strong><em>s</em></strong>&nbsp;to get&nbsp;<strong><em>t</em></strong></li>
	<li>Delete a&nbsp;character from&nbsp;<strong><em>s</em></strong>&nbsp;to get&nbsp;<strong><em>t</em></strong></li>
	<li>Replace a character of&nbsp;<strong><em>s</em></strong>&nbsp;to get&nbsp;<strong><em>t</em></strong></li>
</ol>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <strong><em>s</em></strong> = "ab", <strong><em>t</em></strong> = "acb"
<strong>Output:</strong> true
<strong>Explanation:</strong> We can insert 'c' into <strong><em>s</em></strong>&nbsp;to get&nbsp;<strong><em>t.</em></strong>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <strong><em>s</em></strong> = "cab", <strong><em>t</em></strong> = "ad"
<strong>Output:</strong> false
<strong>Explanation:</strong> We cannot get <strong><em>t </em></strong>from <strong><em>s </em></strong>by only one step.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> <strong><em>s</em></strong> = "1203", <strong><em>t</em></strong> = "1213"
<strong>Output:</strong> true
<strong>Explanation:</strong> We can replace '0' with '1' to get&nbsp;<strong><em>t.</em></strong></pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Edit Distance (Hard)](https://leetcode.com/problems/edit-distance/)

## Solution 1.

Reuse the solution of [Edit Distance](https://leetcode.com/problems/edit-distance/)

```cpp
// OJ: https://leetcode.com/problems/one-edit-distance/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(min(M,N))
class Solution {
private:
    int editDistance(string &s, string &t) {
        if (s.size() < t.size()) swap(s, t);
        int M = s.size(), N = t.size();
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; ++i) dp[i] = i;
        for (int i = 1; i <= M; ++i) {
            int pre = dp[0];
            dp[0] = i;
            for (int j = 1; j <= N; ++j) {
                int tmp = dp[j];
                if (s[i - 1] == t[j - 1]) dp[j] = pre;
                else dp[j] = min(pre, min(dp[j - 1], dp[j])) + 1;
                pre = tmp;
            }
        }
        return dp[N];
    }
public:
    bool isOneEditDistance(string s, string t) {
        return editDistance(s, t) == 1;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/one-edit-distance/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() < t.size()) swap(s, t);
        if (s.size() - t.size() > 1) return false;
        int i = 0;
        while (i < t.size() && s[i] == t[i]) ++i;
        return s.size() > t.size() ? !s.compare(i + 1, string::npos, t, i)
                : (i != t.size() && !s.compare(i + 1, string::npos, t, i + 1));
    }
};
```