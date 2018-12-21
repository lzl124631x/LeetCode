# [247. Strobogrammatic Number II (Medium)](https://leetcode.com/problems/strobogrammatic-number-ii/)

<p>A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).</p>

<p>Find all strobogrammatic numbers that are of length = n.</p>

<p><b>Example:</b></p>

<pre><b>Input:</b>  n = 2
<b>Output:</b> <code>["11","69","88","96"]</code>
</pre>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Strobogrammatic Number (Easy)](https://leetcode.com/problems/strobogrammatic-number/)
* [Strobogrammatic Number III (Hard)](https://leetcode.com/problems/strobogrammatic-number-iii/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/strobogrammatic-number-ii/
// Author: github.com/lzl124631x
// Time: O(5^(N/2))
// Space: O(N)
class Solution {
private:
    char pairs[5][2] = { { '0', '0' }, { '1', '1' }, { '6', '9' }, { '8', '8' }, { '9', '6' }};
    vector<string> ans;
    void dfs(int start, int n, string &tmp) {
        if (start == (n + 1) / 2) {
            ans.push_back(tmp);
            return;
        }
        for (auto &p : pairs) {
            if (start == 0 && n != 1 && p[0] == '0') continue;
            if (start == n / 2 && n % 2 && p[0] != p[1]) continue;
            tmp[start] = p[0];
            tmp[n - start - 1] = p[1];
            dfs(start + 1, n, tmp);
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        string tmp(n, '\0');
        dfs(0, n, tmp);
        return ans;
    }
};
```