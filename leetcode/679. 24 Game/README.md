# [679. 24 Game (Hard)](https://leetcode.com/problems/24-game/)

<p>You are given an integer array <code>cards</code> of length <code>4</code>. You have four cards, each containing a number in the range <code>[1, 9]</code>. You should arrange the numbers on these cards in a mathematical expression using the operators <code>['+', '-', '*', '/']</code> and the parentheses <code>'('</code> and <code>')'</code> to get the value 24.</p>

<p>You are restricted with the following rules:</p>

<ul>
	<li>The division operator <code>'/'</code> represents real division, not integer division.

	<ul>
		<li>For example, <code>4 / (1 - 2 / 3) = 4 / (1 / 3) = 12</code>.</li>
	</ul>
	</li>
	<li>Every operation done is between two numbers. In particular, we cannot use <code>'-'</code> as a unary operator.
	<ul>
		<li>For example, if <code>cards = [1, 1, 1, 1]</code>, the expression <code>"-1 - 1 - 1 - 1"</code> is <strong>not allowed</strong>.</li>
	</ul>
	</li>
	<li>You cannot concatenate numbers together
	<ul>
		<li>For example, if <code>cards = [1, 2, 1, 2]</code>, the expression <code>"12 + 12"</code> is not valid.</li>
	</ul>
	</li>
</ul>

<p>Return <code>true</code> if you can get such expression that evaluates to <code>24</code>, and <code>false</code> otherwise.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> cards = [4,1,8,7]
<strong>Output:</strong> true
<strong>Explanation:</strong> (8-4) * (7-1) = 24
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> cards = [1,2,1,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>cards.length == 4</code></li>
	<li><code>1 &lt;= cards[i] &lt;= 9</code></li>
</ul>


**Companies**:  
[Uber](https://leetcode.com/company/uber), [Bloomberg](https://leetcode.com/company/bloomberg), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Backtracking](https://leetcode.com/tag/backtracking/)

## Solution 1. DP

```cpp
// OJ: https://leetcode.com/problems/24-game/
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(?)
class Solution {
    bool judge(vector<int> &A) {
        unordered_set<double> dp[4][4] = {};
        for (int i = 0; i < 4; ++i) dp[i][i].insert(A[i]);
        for (int i = 2; i >= 0; --i) {
            for (int j = i + 1; j < 4; ++j) {
                for (int k = i; k < j; ++k) {
                    for (double a : dp[i][k]) {
                        for (double b : dp[k + 1][j]) {
                            dp[i][j].insert(a + b);
                            dp[i][j].insert(a - b);
                            dp[i][j].insert(a * b);
                            if (b) dp[i][j].insert(a / b);
                        }
                    }
                }
            }
        }
        for (double n : dp[0][3]) {
            if (abs(n - 24) < 1e-6) return true;
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& A) {
        sort(begin(A), end(A));
        do {
            if (judge(A)) return true;
        } while (next_permutation(begin(A), end(A)));
        return false;
    }
};
```