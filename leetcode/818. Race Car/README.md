# [818. Race Car (Hard)](https://leetcode.com/problems/race-car/)

<p>Your car starts at position <code>0</code> and speed <code>+1</code> on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions <code>'A'</code> (accelerate) and <code>'R'</code> (reverse):</p>

<ul>
	<li>When you get an instruction <code>'A'</code>, your car does the following:

	<ul>
		<li><code>position += speed</code></li>
		<li><code>speed *= 2</code></li>
	</ul>
	</li>
	<li>When you get an instruction <code>'R'</code>, your car does the following:
	<ul>
		<li>If your speed is positive then <code>speed = -1</code></li>
		<li>otherwise <code>speed = 1</code></li>
	</ul>
	Your position stays the same.</li>
</ul>

<p>For example, after commands <code>"AAR"</code>, your car goes to positions <code>0 --&gt; 1 --&gt; 3 --&gt; 3</code>, and your speed goes to <code>1 --&gt; 2 --&gt; 4 --&gt; -1</code>.</p>

<p>Given a target position <code>target</code>, return <em>the length of the shortest sequence of instructions to get there</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> target = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The shortest instruction sequence is "AA".
Your position goes from 0 --&gt; 1 --&gt; 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> target = 6
<strong>Output:</strong> 5
<strong>Explanation:</strong> 
The shortest instruction sequence is "AAARA".
Your position goes from 0 --&gt; 1 --&gt; 3 --&gt; 7 --&gt; 7 --&gt; 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/race-car/
// Author: github.com/lzl124631x
// Time: O(?)
// Space: O(?)
// Ref: https://leetcode.com/problems/race-car/discuss/124312/Javascript-Python3-C%2B%2B-.-BFS-solutions
class Solution {
public:
    int racecar(int target) {
        queue<array<int, 2>> q;
        q.push({0, 1});
        unordered_map<int, unordered_set<int>> seen;
        seen[0].insert(1);
        int step = 0;
        while (true) {
            int cnt = q.size();
            while (cnt--) {
                auto [pos, speed] = q.front();
                q.pop();
                if (pos == target) return step;
                vector<array<int, 2>> cand;
                if (abs(target - (pos + speed)) < target) cand.push_back({ pos + speed, 2 * speed }); // Only continue moving in the current direction if doing so reduces the distance.
                cand.push_back({ pos, speed < 0 ? 1 : - 1 }); // reverse direction
                for (auto &[pos, speed] : cand) {
                    if (seen[pos].count(speed)) continue;
                    seen[pos].insert(speed);
                    q.push({pos, speed});
                }
            }
            ++step;
        }
        return -1;
    }
};
```