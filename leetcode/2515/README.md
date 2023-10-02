# [2515. Shortest Distance to Target String in a Circular Array (Easy)](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array)

<p>You are given a <strong>0-indexed</strong> <strong>circular</strong> string array <code>words</code> and a string <code>target</code>. A <strong>circular array</strong> means that the array's end connects to the array's beginning.</p>
<ul>
	<li>Formally, the next element of <code>words[i]</code> is <code>words[(i + 1) % n]</code> and the previous element of <code>words[i]</code> is <code>words[(i - 1 + n) % n]</code>, where <code>n</code> is the length of <code>words</code>.</li>
</ul>
<p>Starting from <code>startIndex</code>, you can move to either the next word or the previous word with <code>1</code> step at a time.</p>
<p>Return <em>the <strong>shortest</strong> distance needed to reach the string</em> <code>target</code>. If the string <code>target</code> does not exist in <code>words</code>, return <code>-1</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1
<strong>Output:</strong> 1
<strong>Explanation:</strong> We start from index 1 and can reach "hello" by
- moving 3 units to the right to reach index 4.
- moving 2 units to the left to reach index 4.
- moving 4 units to the right to reach index 0.
- moving 1 unit to the left to reach index 0.
The shortest distance to reach "hello" is 1.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
<strong>Output:</strong> 1
<strong>Explanation:</strong> We start from index 0 and can reach "leetcode" by
- moving 2 units to the right to reach index 3.
- moving 1 unit to the left to reach index 3.
The shortest distance to reach "leetcode" is 1.</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> words = ["i","eat","leetcode"], target = "ate", startIndex = 0
<strong>Output:</strong> -1
<strong>Explanation:</strong> Since "ate" does not exist in <code>words</code>, we return -1.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 100</code></li>
	<li><code>words[i]</code> and <code>target</code> consist of only lowercase English letters.</li>
	<li><code>0 &lt;= startIndex &lt; words.length</code></li>
</ul>

**Companies**:
[Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Defuse the Bomb (Easy)](https://leetcode.com/problems/defuse-the-bomb/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int closetTarget(vector<string>& A, string target, int startIndex) {
        int N = A.size(), ans = INT_MAX;
        for (int i = 0; i < N; ++i) {
            if (A[i] != target) continue;
            int d = abs(i - startIndex);
            ans = min({ans, d, N - d});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```