# [351. Android Unlock Patterns (Medium)](https://leetcode.com/problems/android-unlock-patterns)

<p>Android devices have a special lock screen with a <code>3 x 3</code> grid of dots. Users can set an &quot;unlock pattern&quot; by connecting the dots in a specific sequence, forming a series of joined line segments where each segment&#39;s endpoints are two consecutive dots in the sequence. A sequence of <code>k</code> dots is a <strong>valid</strong> unlock pattern if both of the following are true:</p>

<ul>
	<li>All the dots in the sequence are <strong>distinct</strong>.</li>
	<li>If the line segment connecting two consecutive dots in the sequence passes through the <strong>center</strong> of any other dot, the other dot <strong>must have previously appeared</strong> in the sequence. No jumps through the center non-selected dots are allowed.
	<ul>
		<li>For example, connecting dots <code>2</code> and <code>9</code> without dots <code>5</code> or <code>6</code> appearing beforehand is valid because the line from dot <code>2</code> to dot <code>9</code> does not pass through the center of either dot <code>5</code> or <code>6</code>.</li>
		<li>However, connecting dots <code>1</code> and <code>3</code> without dot <code>2</code> appearing beforehand is invalid because the line from dot <code>1</code> to dot <code>3</code> passes through the center of dot <code>2</code>.</li>
	</ul>
	</li>
</ul>

<p>Here are some example valid and invalid unlock patterns:</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/android-unlock.png" style="width: 418px; height: 128px;" /></p>

<ul>
	<li>The 1st pattern <code>[4,1,3,6]</code> is invalid because the line connecting dots <code>1</code> and <code>3</code> pass through dot <code>2</code>, but dot <code>2</code> did not previously appear in the sequence.</li>
	<li>The 2nd pattern <code>[4,1,9,2]</code> is invalid because the line connecting dots <code>1</code> and <code>9</code> pass through dot <code>5</code>, but dot <code>5</code> did not previously appear in the sequence.</li>
	<li>The 3rd pattern <code>[2,4,1,3,6]</code> is valid because it follows the conditions. The line connecting dots <code>1</code> and <code>3</code> meets the condition because dot <code>2</code> previously appeared in the sequence.</li>
	<li>The 4th pattern <code>[6,5,4,1,9,2]</code> is valid because it follows the conditions. The line connecting dots <code>1</code> and <code>9</code> meets the condition because dot <code>5</code> previously appeared in the sequence.</li>
</ul>

<p>Given two integers <code>m</code> and <code>n</code>, return <em>the <strong>number of unique and valid unlock patterns</strong> of the Android grid lock screen that consist of <strong>at least</strong> </em><code>m</code><em> keys and <strong>at most</strong> </em><code>n</code><em> keys.</em></p>

<p>Two unlock patterns are considered <strong>unique</strong> if there is a dot in one sequence that is not in the other, or the order of the dots is different.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> m = 1, n = 1
<strong>Output:</strong> 9
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> m = 1, n = 2
<strong>Output:</strong> 65
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= m, n &lt;= 9</code></li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming), [Backtracking](https://leetcode.com/tag/backtracking)

## Solution 1. Backtracking

```cpp
// OJ: https://leetcode.com/problems/android-unlock-patterns
// Author: github.com/lzl124631x
// Time: O(9! * 9)
// Space: O(9)
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        bool used[9] = {};
        int ans = 0;
        auto cross = [&](int i, int j) {
            if (i == 4 || j == 4) return false;
            if (i % 2 == 0 && j % 2 == 0) return !used[(i + j) / 2];
            if (i % 2 == 1 && j % 2 == 1 && i + j == 8) return !used[4];
            return false;
        };
        function<void(int, int, int)> dfs = [&](int i, int len, int prev) {
            if (i == len) {
                ++ans;
                return;
            }
            for (int j = 0; j < 9; ++j) {
                if (used[j]) continue;
                if (i > 0 && cross(prev, j)) continue;
                used[j] = true;
                dfs(i + 1, len, j);
                used[j] = false;
            }
        };
        for (int len = m; len <= n; ++len) {
            dfs(0, len, -1);
        }
        return ans;
    }
};
```