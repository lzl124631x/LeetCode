# [1654. Minimum Jumps to Reach Home (Medium)](https://leetcode.com/problems/minimum-jumps-to-reach-home/)

<p>A certain bug's home is on the x-axis at position <code>x</code>. Help them get there from position <code>0</code>.</p>

<p>The bug jumps according to the following rules:</p>

<ul>
	<li>It can jump exactly <code>a</code> positions <strong>forward</strong> (to the right).</li>
	<li>It can jump exactly <code>b</code> positions <strong>backward</strong> (to the left).</li>
	<li>It cannot jump backward twice in a row.</li>
	<li>It cannot jump to any <code>forbidden</code> positions.</li>
</ul>

<p>The bug may jump forward <strong>beyond</strong> its home, but it <strong>cannot jump</strong> to positions numbered with <strong>negative</strong> integers.</p>

<p>Given an array of integers <code>forbidden</code>, where <code>forbidden[i]</code> means that the bug cannot jump to the position <code>forbidden[i]</code>, and integers <code>a</code>, <code>b</code>, and <code>x</code>, return <em>the minimum number of jumps needed for the bug to reach its home</em>. If there is no possible sequence of jumps that lands the bug on position <code>x</code>, return <code>-1.</code></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 jumps forward (0 -&gt; 3 -&gt; 6 -&gt; 9) will get the bug home.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
<strong>Output:</strong> -1
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
<strong>Output:</strong> 2
<strong>Explanation:</strong> One jump forward (0 -&gt; 16) then one jump backward (16 -&gt; 7) will get the bug home.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= forbidden.length &lt;= 1000</code></li>
	<li><code>1 &lt;= a, b, forbidden[i] &lt;= 2000</code></li>
	<li><code>0 &lt;= x &lt;= 2000</code></li>
	<li>All the elements in <code>forbidden</code> are distinct.</li>
	<li>Position <code>x</code> is not forbidden.</li>
</ul>


**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-jumps-to-reach-home
// Author: github.com/lzl124631x
// Time: O()
// Space: O()
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int g = __gcd(a,b);
        if((x % g) != 0) {
            return -1;
        }
        int vis[6001], ban[2001];
        memset(vis, 0, sizeof(vis));
        memset(ban, 0, sizeof(ban));
        for(int v : forbidden) {
            vis[v] = 1;
            ban[v] = 1;
        }
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
        q.emplace(0, 0);
        while(q.size()) {
            auto [steps, node] = q.top();
            q.pop();
            if(a >= b && node > x) {
                continue;
            }
            if(node == x) {
                return steps;
            }
            if(!vis[node]) {
                vis[node] = 1;
                if(node + a <= 6000 && !vis[node + a]) {
                    q.emplace(steps + 1, node + a);
                }
                if(node + a - b <= 6000 && node + a - b >= 0 && !vis[node + a - b] && !(node + a <= 2000 && ban[node + a])) {
                    q.emplace(steps + 2, node + a - b);
                }
            }
        }
        return -1;
    }
};
```