# [247. Strobogrammatic Number II (Medium)](https://leetcode.com/problems/strobogrammatic-number-ii/)

<p>Given an integer <code>n</code>, return all the <strong>strobogrammatic numbers</strong> that are of length <code>n</code>. You may return the answer in <strong>any order</strong>.</p>

<p>A <strong>strobogrammatic number</strong> is a number that looks the same when rotated <code>180</code> degrees (looked at upside down).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> ["11","69","88","96"]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> ["0","1","8"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 14</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Recursion](https://leetcode.com/tag/recursion/)

**Similar Questions**:
* [Strobogrammatic Number (Easy)](https://leetcode.com/problems/strobogrammatic-number/)
* [Strobogrammatic Number III (Hard)](https://leetcode.com/problems/strobogrammatic-number-iii/)
* [Sum of k-Mirror Numbers (Hard)](https://leetcode.com/problems/sum-of-k-mirror-numbers/)

## Solution 1. DFS

The strobogrammatic numbers are very sparse, so looping through all the n-digit numbers and test if they are strobogrammatic number is inefficient. We should try generating them.

We can use recursion/DFS/backtracking. In each recursion, we fill the `i`th digit (`[0,n/2]`), and fill the corresponding `j = n-1-i`th digit.

```cpp
// OJ: https://leetcode.com/problems/strobogrammatic-number-ii/
// Author: github.com/lzl124631x
// Time: O(5^(N/2))
// Space: O(N)
const char pairs[5][2] = {{'0','0'},{'1','1'},{'8','8'},{'6','9'},{'9','6'}};
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        string s(n, '0');
        vector<string> ans;
        function<void(int)> dfs = [&](int i) {
            if (i == (n + 1) / 2) {
                ans.push_back(s);
                return;
            }
            int j = n - 1 - i;
            for (auto &[a, b] : pairs) {
                if (i == j && a != b) continue;
                if (i == 0 && n > 1 && a == '0') continue;
                s[i] = a;
                s[j] = b;
                dfs(i + 1);
            }
        };
        dfs(0);
        return ans;
    }
};
```