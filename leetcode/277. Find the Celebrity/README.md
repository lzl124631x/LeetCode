# [277. Find the Celebrity (Medium)](https://leetcode.com/problems/find-the-celebrity/)

<p>Suppose you are at a party with <code>n</code> people labeled from <code>0</code> to <code>n - 1</code> and among them, there may exist one celebrity. The definition of a celebrity is that all the other <code>n - 1</code> people know the celebrity, but the celebrity does not know any of them.</p>

<p>Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).</p>

<p>You are given a helper function <code>bool knows(a, b)</code> that tells you whether A knows B. Implement a function <code>int findCelebrity(n)</code>. There will be exactly one celebrity if they are at the party.</p>

<p>Return <em>the celebrity's label if there is a celebrity at the party</em>. If there is no celebrity, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/01/19/g1.jpg" style="width: 224px; height: 145px;">
<pre><strong>Input:</strong> graph = [[1,1,0],[0,1,0],[1,1,1]]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/01/19/g2.jpg" style="width: 224px; height: 145px;">
<pre><strong>Input:</strong> graph = [[1,0,1],[1,1,0],[0,1,1]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no celebrity.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == graph.length</code></li>
	<li><code>n == graph[i].length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>graph[i][j]</code> is <code>0</code> or <code>1</code>.</li>
	<li><code>graph[i][i] == 1</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> If the maximum number of allowed calls to the API <code>knows</code> is <code>3 * n</code>, could you find a solution without exceeding the maximum number of calls?</p>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [LinkedIn](https://leetcode.com/company/linkedin), [Pinterest](https://leetcode.com/company/pinterest), [Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [Greedy](https://leetcode.com/tag/greedy/), [Graph](https://leetcode.com/tag/graph/), [Interactive](https://leetcode.com/tag/interactive/)

**Similar Questions**:
* [Find the Town Judge (Easy)](https://leetcode.com/problems/find-the-town-judge/)

## Solution 1.

There is at most one celebrity.

Each `know(i, j)` can help us eliminate a node. If `i` knows `j`, `i` must not be celebrity, and we should try `j` instead. If `i` doesn't know `j`, `j` must not be celebrity.

```cpp
// OJ: https://leetcode.com/problems/find-the-celebrity/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findCelebrity(int n) {
        vector<int> good(n, -1); // -1 unvisited, 0 not celebrity, 1 celebrity
        int ans = -1;
        function<bool(int)> dfs = [&](int i) -> bool {
            if (good[i] != -1) return good[i];
            for (int j = 0; j < n && good[i] == -1; ++j) { // check rule: I don't know anyone
                if (i == j) continue;
                if (knows(i, j)) { // If `i` knows any `j`, `i` is not the celebrity, try `j` instead
                    good[i] = 0;
                    if (dfs(j)) return true;
                } else { // If `i` doesn't know `j`, `j` is not the celebrity
                    good[j] = 0;
                }
            }
            if (good[i] == 0) return false;
            for (int j = 0; j < n && good[i] == -1; ++j) { // check rule: anyone knows me
                if (i == j) continue;
                if (!knows(j, i)) good[i] = 0;
            }
            if (good[i]) ans = i;
            return true;
        };
        for (int i = 0; i < n; ++i) {
            if (good[i] != -1) continue;
            if (dfs(i)) return ans;
        }
        return -1;
    }
};
```