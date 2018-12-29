# [821. Shortest Distance to a Character (Easy)](https://leetcode.com/problems/shortest-distance-to-a-character/)

<p>Given a string <code>S</code>&nbsp;and a character <code>C</code>, return an array of integers representing the shortest distance from the character <code>C</code> in the string.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> S = "loveleetcode", C = 'e'
<strong>Output:</strong> [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>S</code> string length is&nbsp;in&nbsp;<code>[1, 10000].</code></li>
	<li><code>C</code>&nbsp;is a single character, and guaranteed to be in string <code>S</code>.</li>
	<li>All letters in <code>S</code> and <code>C</code> are lowercase.</li>
</ol>


**Companies**:  
[Bloomberg](https://leetcode.com/company/bloomberg)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shortest-distance-to-a-character/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int N = S.size(), prevJ;
        vector<int> ans(N);
        for (int i = 0, j = -1; i < N; ++i) {
            if (i > j) {
                prevJ = j;
                do { ++j; } while (j < N && S[j] != C);
            }
            ans[i] = min(j == N ? INT_MAX : j - i, prevJ == -1 ? INT_MAX : i - prevJ);
        }
        return ans;
    }
};
```