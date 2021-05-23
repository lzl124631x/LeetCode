# [1871. Jump Game VII (Medium)](https://leetcode.com/problems/jump-game-vii/)

<p>You are given a <strong>0-indexed</strong> binary string <code>s</code> and two integers <code>minJump</code> and <code>maxJump</code>. In the beginning, you are standing at index <code>0</code>, which is equal to <code>'0'</code>. You can move from index <code>i</code> to index <code>j</code> if the following conditions are fulfilled:</p>

<ul>
	<li><code>i + minJump &lt;= j &lt;= min(i + maxJump, s.length - 1)</code>, and</li>
	<li><code>s[j] == '0'</code>.</li>
</ul>

<p>Return <code>true</code><i> if you can reach index </i><code>s.length - 1</code><i> in </i><code>s</code><em>, or </em><code>false</code><em> otherwise.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "<u>0</u>11<u>0</u>1<u>0</u>", minJump = 2, maxJump = 3
<strong>Output:</strong> true
<strong>Explanation:</strong>
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "01101110", minJump = 2, maxJump = 3
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
	<li><code>s[0] == '0'</code></li>
	<li><code>1 &lt;= minJump &lt;= maxJump &lt; s.length</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/), [Line Sweep](https://leetcode.com/tag/line-sweep/)

**Similar Questions**:
* [Jump Game II (Medium)](https://leetcode.com/problems/jump-game-ii/)
* [Jump Game (Medium)](https://leetcode.com/problems/jump-game/)
* [Jump Game III (Medium)](https://leetcode.com/problems/jump-game-iii/)
* [Jump Game IV (Hard)](https://leetcode.com/problems/jump-game-iv/)
* [Jump Game V (Hard)](https://leetcode.com/problems/jump-game-v/)
* [Jump Game VI (Medium)](https://leetcode.com/problems/jump-game-vi/)
* [Jump Game VII (Medium)](https://leetcode.com/problems/jump-game-vii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/jump-game-vii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(maxJump - minJump)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s.back() == '1') return false;
        queue<int> q;
        int j = 0, prev = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (i - prev > maxJump) return false;
            if (s[i] == '1') continue;
            j = max(j, i - maxJump);
            while (i - j >= minJump) {
                if (s[j] == '0') q.push(j);
                ++j;
            }
            while (q.size() && i - q.front() > maxJump) q.pop();
            if (q.empty()) s[i] = '1'; // mark this position as non-reachable.
            else prev = i;
        }
        return q.size();
    }
};
```