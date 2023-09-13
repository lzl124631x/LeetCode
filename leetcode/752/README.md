# [752. Open the Lock (Medium)](https://leetcode.com/problems/open-the-lock/)

<p>You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: <code>'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'</code>. The wheels can rotate freely and wrap around: for example we can turn <code>'9'</code> to be <code>'0'</code>, or <code>'0'</code> to be <code>'9'</code>. Each move consists of turning one wheel one slot.</p>

<p>The lock initially starts at <code>'0000'</code>, a string representing the state of the 4 wheels.</p>

<p>You are given a list of <code>deadends</code> dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.</p>

<p>Given a <code>target</code> representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> deadends = ["0201","0101","0102","1212","2002"], target = "0202"
<strong>Output:</strong> 6
<strong>Explanation:</strong>
A sequence of valid moves would be "0000" -&gt; "1000" -&gt; "1100" -&gt; "1200" -&gt; "1201" -&gt; "1202" -&gt; "0202".
Note that a sequence like "0000" -&gt; "0001" -&gt; "0002" -&gt; "0102" -&gt; "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> deadends = ["8888"], target = "0009"
<strong>Output:</strong> 1
<strong>Explanation:</strong>
We can turn the last wheel in reverse to move from "0000" -&gt; "0009".
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
<strong>Output:</strong> -1
Explanation:
We can't reach the target without getting stuck.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> deadends = ["0000"], target = "8888"
<strong>Output:</strong> -1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;deadends.length &lt;= 500</code></li>
	<li><code><font face="monospace">deadends[i].length == 4</font></code></li>
	<li><code><font face="monospace">target.length == 4</font></code></li>
	<li>target <strong>will not be</strong> in the list <code>deadends</code>.</li>
	<li><code>target</code> and <code>deadends[i]</code> consist of digits only.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google), [Amazon](https://leetcode.com/company/amazon), [Citadel](https://leetcode.com/company/citadel)

**Related Topics**:  
[Breadth-first Search](https://leetcode.com/tag/breadth-first-search/)

## Solution 1. BFS

As we are looking for the shortest distance, BFS is perfect for this problem. (Don't use DFS otherwise you'll always need to traverse every combination.)

Turn string "0000" ~ "9999" to numbers. Start from `0`, and use BFS to try to reach `target`.

```cpp
// OJ: https://leetcode.com/problems/open-the-lock/
// Author: github.com/lzl124631x
// Time: O(A^N) where A is the number of digits in our alphabet,
//                    N is the number of digits in the lock.
// Space: O(A^N)
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<int> seen;
        for (auto &d : deadends) seen.insert(stoi(d));
        if (seen.count(0)) return -1;
        seen.insert(0);
        int T = stoi(target), step = 0;
        queue<int> q{{0}};
        while (q.size()) {
            int cnt = q.size();
            while (cnt--) {
                int n = q.front();
                q.pop();
                if (n == T) return step;
                for (int i = 1; i <= 1000; i *= 10) {
                    int d = n / i % 10;
                    for (int j = -1; j <= 1; j += 2) {
                        int next = n - i * d + (d + j + 10) % 10 * i;
                        if (seen.count(next)) continue;
                        seen.insert(next);
                        q.push(next);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
```