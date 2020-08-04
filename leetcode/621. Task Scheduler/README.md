# [621. Task Scheduler (Medium)](https://leetcode.com/problems/task-scheduler/)

<p>You are given a char array representing tasks CPU need to do. It contains capital letters A to Z where each letter represents a different task. Tasks could be done without the original order of the array. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.</p>

<p>However, there is a non-negative integer&nbsp;<code>n</code> that represents the cooldown period between&nbsp;two <b>same tasks</b>&nbsp;(the same letter in the array), that is that there must be at least <code>n</code> units of time between any two same tasks.</p>

<p>You need to return the <b>least</b> number of units of times that the CPU will take to finish all the given tasks.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> tasks = ["A","A","A","B","B","B"], n = 2
<strong>Output:</strong> 8
<strong>Explanation:</strong> 
A -&gt; B -&gt; idle -&gt; A -&gt; B -&gt; idle -&gt; A -&gt; B
There is at least 2 units of time between any two same tasks.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> tasks = ["A","A","A","B","B","B"], n = 0
<strong>Output:</strong> 6
<strong>Explanation:</strong> On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
<strong>Output:</strong> 16
<strong>Explanation:</strong> 
One possible solution is
A -&gt; B -&gt; C -&gt; A -&gt; D -&gt; E -&gt; A -&gt; F -&gt; G -&gt; A -&gt; idle -&gt; idle -&gt; A -&gt; idle -&gt; idle -&gt; A
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of tasks is in the range <code>[1, 10000]</code>.</li>
	<li>The integer <code>n</code> is in the range <code>[0, 100]</code>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/), [Queue](https://leetcode.com/tag/queue/)

**Similar Questions**:
* [Rearrange String k Distance Apart (Hard)](https://leetcode.com/problems/rearrange-string-k-distance-apart/)
* [Reorganize String (Medium)](https://leetcode.com/problems/reorganize-string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/task-scheduler/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int leastInterval(vector<char>& A, int n) {
        int cnt[26] = {}, time[26] = {}, ans = 0;
        for (int n : A) cnt[n - 'A']++;
        for (int i = 0; i < A.size(); ++i) {
            int k = -1;
            ++ans;
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] == 0) continue;
                if (time[j] < ans) time[j] = ans;
                if (k == -1 || time[j] < time[k] || (time[j] == time[k] && cnt[j] > cnt[k])) k = j;
            }
            ans = time[k];
            --cnt[k];
            time[k] += n + 1;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/task-scheduler/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/task-scheduler/discuss/104500/Java-O(n)-time-O(1)-space-1-pass-no-sorting-solution-with-detailed-explanation
class Solution {
public:
    int leastInterval(vector<char>& A, int n) {
        int cnt[26] = {}, maxCnt = 0, num = 0;
        for (int n : A) maxCnt = max(maxCnt, ++cnt[n - 'A']);
        for (int n : cnt) num += n == maxCnt;
        int partCnt = maxCnt - 1;
        int slots = (n - num + 1) * partCnt;
        int idleCnt = max(0, slots - ((int)A.size() - maxCnt * num));
        return A.size() + idleCnt;
    }
};
```