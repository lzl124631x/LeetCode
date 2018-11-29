# [752. Open the Lock (Medium)](https://leetcode.com/problems/open-the-lock/)

<p>
You have a lock in front of you with 4 circular wheels.  Each wheel has 10 slots: <code>'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'</code>.  The wheels can rotate freely and wrap around: for example we can turn <code>'9'</code> to be <code>'0'</code>, or <code>'0'</code> to be <code>'9'</code>.  Each move consists of turning one wheel one slot.
</p><p>
The lock initially starts at <code>'0000'</code>, a string representing the state of the 4 wheels.
</p><p>
You are given a list of <code>deadends</code> dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
</p><p>
Given a <code>target</code> representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> deadends = ["0201","0101","0102","1212","2002"], target = "0202"
<b>Output:</b> 6
<b>Explanation:</b>
A sequence of valid moves would be "0000" -&gt; "1000" -&gt; "1100" -&gt; "1200" -&gt; "1201" -&gt; "1202" -&gt; "0202".
Note that a sequence like "0000" -&gt; "0001" -&gt; "0002" -&gt; "0102" -&gt; "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> deadends = ["8888"], target = "0009"
<b>Output:</b> 1
<b>Explanation:</b>
We can turn the last wheel in reverse to move from "0000" -&gt; "0009".
</pre>
<p></p>

<p><b>Example 3:</b><br>
</p><pre><b>Input:</b> deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
<b>Output:</b> -1
<b>Explanation:</b>
We can't reach the target without getting stuck.
</pre>
<p></p>

<p><b>Example 4:</b><br>
</p><pre><b>Input:</b> deadends = ["0000"], target = "8888"
<b>Output:</b> -1
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The length of <code>deadends</code> will be in the range <code>[1, 500]</code>.</li>
<li><code>target</code> will not be in the list <code>deadends</code>.</li>
<li>Every string in <code>deadends</code> and the string <code>target</code> will be a string of 4 digits from the 10,000 possibilities <code>'0000'</code> to <code>'9999'</code>.</li>
</ol>
<p></p>

**Companies**:  
[Google](https://leetcode.com/company/google)

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
        int T = stoi(target), dist = 0;
        if (seen.find(0) != seen.end()) return -1;
        queue<int> q;
        q.push(0);
        seen.insert(0);
        while (q.size()) {
            int cnt = q.size();
            ++dist;
            while (cnt--) {
                int n = q.front();
                q.pop();
                for (int i = 1; i <= 1000; i *= 10) {
                    int d = n / i % 10;
                    int up = d == 9 ? n - 9 * i : n + i;
                    int down = d == 0 ? n + 9 * i : n - i;
                    if (up == T || down == T) return dist;
                    if (seen.find(up) == seen.end()) {
                        seen.insert(up);
                        q.push(up);
                    }
                    if (seen.find(down) == seen.end()) {
                        seen.insert(down);
                        q.push(down);
                    }
                }
            }
        }
        return -1;
    }
};
```