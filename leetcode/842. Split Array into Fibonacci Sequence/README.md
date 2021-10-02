# [842. Split Array into Fibonacci Sequence (Medium)](https://leetcode.com/problems/split-array-into-fibonacci-sequence/)

<p>You are given a string of digits <code>num</code>, such as <code>"123456579"</code>. We can split it into a Fibonacci-like sequence <code>[123, 456, 579]</code>.</p>

<p>Formally, a <strong>Fibonacci-like</strong> sequence is a list <code>f</code> of non-negative integers such that:</p>

<ul>
	<li><code>0 &lt;= f[i] &lt; 2<sup>31</sup></code>, (that is, each integer fits in a <strong>32-bit</strong> signed integer type),</li>
	<li><code>f.length &gt;= 3</code>, and</li>
	<li><code>f[i] + f[i + 1] == f[i + 2]</code> for all <code>0 &lt;= i &lt; f.length - 2</code>.</li>
</ul>

<p>Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece is the number <code>0</code> itself.</p>

<p>Return any Fibonacci-like sequence split from <code>num</code>, or return <code>[]</code> if it cannot be done.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = "123456579"
<strong>Output:</strong> [123,456,579]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = "11235813"
<strong>Output:</strong> [1,1,2,3,5,8,13]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = "112358130"
<strong>Output:</strong> []
<strong>Explanation:</strong> The task is impossible.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> num = "0123"
<strong>Output:</strong> []
<strong>Explanation:</strong> Leading zeroes are not allowed, so "01", "2", "3" is not valid.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> num = "1101111"
<strong>Output:</strong> [11,0,11,11]
<strong>Explanation:</strong> The output [11, 0, 11, 11] would also be accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num.length &lt;= 200</code></li>
	<li><code>num</code> contains only digits.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Backtracking](https://leetcode.com/tag/backtracking/)

**Similar Questions**:
* [Additive Number (Medium)](https://leetcode.com/problems/additive-number/)
* [Fibonacci Number (Easy)](https://leetcode.com/problems/fibonacci-number/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/split-array-into-fibonacci-sequence/
// Author: github.com/lzl124631x
// Time: O(N!)
// Space: O(N)
class Solution {
    vector<int> ans;
    bool dfs(string &s, int i) {
        if (i == s.size()) return ans.size() >= 3;
        for (int j = i; j < s.size(); ++j) {
            long n = stol(s.substr(i, j - i + 1));
            if (n > INT_MAX) return false;
            if (ans.size() >= 2) {
                long target = (long)ans.back() + ans[ans.size() - 2];
                if (target > INT_MAX) return false;
                if (n == target) {
                    ans.push_back(n);
                    if (dfs(s, j + 1)) return true;
                    ans.pop_back();
                    break;
                }
                if (n > target) break;
            } else {
                ans.push_back(n);
                if (dfs(s, j + 1)) return true;
                ans.pop_back();
            }
            if (s[i] == '0') return false;
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string s) {
        dfs(s, 0);
        return ans;
    }
};
```