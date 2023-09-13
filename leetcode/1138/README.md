# [1138. Alphabet Board Path (Medium)](https://leetcode.com/problems/alphabet-board-path/)

<p>On an alphabet board, we start at position <code>(0, 0)</code>, corresponding to character&nbsp;<code>board[0][0]</code>.</p>

<p>Here, <code>board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]</code>, as shown in the diagram below.</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/07/28/azboard.png" style="width: 250px; height: 317px;"></p>

<p>We may make the following moves:</p>

<ul>
	<li><code>'U'</code> moves our position up one row, if the position exists on the board;</li>
	<li><code>'D'</code> moves our position down one row, if the position exists on the board;</li>
	<li><code>'L'</code> moves our position left one column, if the position exists on the board;</li>
	<li><code>'R'</code> moves our position right one column, if the position exists on the board;</li>
	<li><code>'!'</code>&nbsp;adds the character <code>board[r][c]</code> at our current position <code>(r, c)</code>&nbsp;to the&nbsp;answer.</li>
</ul>

<p>(Here, the only positions that exist on the board are positions with letters on them.)</p>

<p>Return a sequence of moves that makes our answer equal to <code>target</code>&nbsp;in the minimum number of moves.&nbsp; You may return any path that does so.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> target = "leet"
<strong>Output:</strong> "DDR!UURRR!!DDD!"
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> target = "code"
<strong>Output:</strong> "RR!DDRR!UUL!R!"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target.length &lt;= 100</code></li>
	<li><code>target</code> consists only of English lowercase letters.</li>
</ul>

**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/alphabet-board-path/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string alphabetBoardPath(string target) {
        int x = 0, y = 0;
        string ans;
        for (char c : target) {
            int p = (c - 'a') / 5, q = (c - 'a') % 5;
            while (x != p || y != q) {
                if (q >= y) {
                    if (p > x) {
                        ++x;
                        ans += 'D';
                    } else if (p < x) {
                        --x;
                        ans += 'U';
                    } else {
                        ++y;
                        ans += 'R';
                    }
                } else {
                    --y;
                    ans += 'L';
                }
            }
            ans += '!';
        }
        return ans;
    }
};
```