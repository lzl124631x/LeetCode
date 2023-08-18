# [621. Task Scheduler (Medium)](https://leetcode.com/problems/task-scheduler/)

<p>Given a characters array <code>tasks</code>, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.</p>

<p>However, there is a non-negative integer&nbsp;<code>n</code> that represents the cooldown period between&nbsp;two <b>same tasks</b>&nbsp;(the same letter in the array), that is that there must be at least <code>n</code> units of time between any two same tasks.</p>

<p>Return <em>the least number of units of times that the CPU will take to finish all the given tasks</em>.</p>

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
	<li><code>1 &lt;= task.length &lt;= 10<sup>4</sup></code></li>
	<li><code>tasks[i]</code> is upper-case English letter.</li>
	<li>The integer <code>n</code> is in the range <code>[0, 100]</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft), [Uber](https://leetcode.com/company/uber), [Amazon](https://leetcode.com/company/amazon), [Rubrik](https://leetcode.com/company/rubrik), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Rearrange String k Distance Apart (Hard)](https://leetcode.com/problems/rearrange-string-k-distance-apart/)
* [Reorganize String (Medium)](https://leetcode.com/problems/reorganize-string/)
* [Maximum Number of Weeks for Which You Can Work (Medium)](https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/)

## Solution 1. Greedy

Use a queue to simulate the cooldown process. Use a max heap to pick the character with the greatest count left.

```cpp
// OJ: https://leetcode.com/problems/task-scheduler/
// Author: github.com/lzl124631x
// Time: O(N + MlogC + K) where `M` is the length of `tasks`, `C` is the size of the character set, `K` is the number of idle CPU times used in the optimal solution.
// Space: O(N)
class Solution {
public:
    int leastInterval(vector<char>& A, int n) {
        if (n == 0) return A.size();
        int used = 0, cnt[26] = {}, ans = 0;
        auto cmp = [&](int a, int b) { return cnt[a] < cnt[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp); // max-cnt heap of tasks available to be executed.
        for (char c : A) cnt[c - 'A']++;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) pq.push(i);
        }
        queue<int> q; // `q` is a cool down queue of length n+1.
        for (int i = 0; i <= n; ++i) q.push(-1); // -1s in the cooldown queue are just placeholders, meaning no task was executed at that particular moment
        while (used < A.size()) {
            int c = q.front();
            q.pop();
            if (c != -1) pq.emplace(c); // if a task is popped from cooldown queue, this task can be used now.
            if (pq.size()) { // we have tasks available
                c = pq.top(); // greedily pick the task `c` with the max cnt
                pq.pop();
                ++used; // execute task `c`
                q.push(--cnt[c] > 0 ? c : -1); // push task `c` into cooldown queue if it still have remaining quota. Otherwise put a placeholder -1 into cooldown queue
            } else q.push(-1); // no tasks available. Put a placeholder into the cooldown queue.
            ++ans;
        }
        return ans;
    }
};
```

## Solution 2. Greedy

Let `time[i]` be the available time of task labelled by `'A' + i`.

We pick tasks for `tasks.length` time. Each time, we greedily pick the task with the earliest available time. In case of a tie, we pick the task with the greatest count left.

```cpp
// OJ: https://leetcode.com/problems/task-scheduler/
// Author: github.com/lzl124631x
// Time: O(MC) where M is the length of `tasks` and `C` is the size of the character set.
// Space: O(C)
class Solution {
public:
    int leastInterval(vector<char>& A, int n) {
        int cnt[26] = {}, time[26] = {}, ans = 0;
        for (char c : A) cnt[c - 'A']++;
        for (int i = 0; i < A.size(); ++i) {
            int k = -1;
            ++ans;
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] == 0) continue;
                if (time[j] < ans) time[j] = ans; // the available time for task `j` is at least the current time.
                if (k == -1 || time[j] < time[k] || (time[j] == time[k] && cnt[j] > cnt[k])) k = j; // we pick the task with the earliest available time. If the available times are the same, we pick the task with the greatest count left.
            }
            ans = time[k]; // jump to the available time of task labelled by `'A' + k`
            --cnt[k];
            time[k] += n + 1;
        }
        return ans;
    }
};
```

## Solution 3. Greedy

The key is to find out how many idles we need.

It's not hard to figure out that we need to do a greedy arrangment -- always arrange tasks with the greatest frequency first.

For example, we have the following tasks: 3A, 2B, 1C. And `n = 2`. We should arrange A, then B, and C.

```
// Arrange task A. `?` stands for empty slot
A ? ? A ? ? A
// Arrange task B and C. `#` stands for idle slot
A B C A B # A
```

The answer is the number of idle slots + number of tasks.

After arranging `A`, `A` separated slots into `partCnt = count(A) - 1 = 2` parts, each of which has length `n`. Now we know the number of empty slots `emptySlots = partCnt * n`. Then we can get how many tasks we have to put into those slots: `availableTasks = tasks.length - count(A)`.

If `emptySlots > availableTasks`, we don't have enough tasks to fill all the empty slots. We must use `idle = max(0, emptySlots - availableTasks)` idle slots.

Now consider a special case: what if there are more than one task with the greatest frequency? Example: 3A, 3B, 2C, 1D, `n = 3`.

```
// Arrange A
A ? ? ? A ? ? ? A
// Arrange B
A B ? ? A B ? ? A B
// We can encode this as
X ? ? X ? ? X
```

We can see that the only change is that each part has length `2` instead of `3` now.

Now we get the generalized equations:

```
partCnt = count(A) - 1
emptySlots = (n - num + 1) * partCnt // `num` is the count of tasks with the greatest frequency
availableTasks = tasks.length - count(A) * num
idleCnt = max(0, emptySlots - availableTasks)
answer = tasks.length + idleCnt
```

What if we have more than `n` tasks with the greatest frequency and we got `emptySlots` negative? Example: 3A, 3B, 3C, 3D, 2E, 1F, `n = 2`.

```
// Arrange A, B, C, D
A B C D | A B C D | A B C D
// Arrange E and F
A B C D E F | A B C D E | A B C D
```

We can see that, if we have greater than or equal to `n + 1` tasks with the greatest frequency, each part will be filled completely and there won't be empty slots. We can freely fill the rest tasks one by one in each part, because they automatically satisfies the `n` cooldown rule.

---

Test case: 
```
["A", "A", "A", "B", "B", "C", "C", "D", "D"]
2
```

```
// Arrange A
A ? ? | A ? ? | A
// Arrange B, C and D
A B C D | A B C D | A
```

```
partCnt = 3 - 1 = 2
emptySlots = (2 - 1 + 1) * 2 = 4 
availableTasks = 9 - 3 * 1 = 6
idleCnt = max(0, 4 - 6) = 0
answer = 9 + 0 = 0
```

```cpp
// OJ: https://leetcode.com/problems/task-scheduler/
// Author: github.com/lzl124631x
// Time: O(M) where M is the length of `tasks`
// Space: O(C)
// Ref: https://leetcode.com/problems/task-scheduler/discuss/104500/Java-O(n)-time-O(1)-space-1-pass-no-sorting-solution-with-detailed-explanation
class Solution {
public:
    int leastInterval(vector<char>& A, int n) {
        int cnt[26] = {}, maxCnt = 0, num = 0;
        for (int n : A) maxCnt = max(maxCnt, ++cnt[n - 'A']);
        for (int n : cnt) num += n == maxCnt;
        int partCnt = maxCnt - 1;
        int emptySlots = (n - num + 1) * partCnt;
        int availableTasks = A.size() - maxCnt * num;
        int idleCnt = max(0, emptySlots - availableTasks);
        return A.size() + idleCnt;
    }
};
```

## Solution 4. Greedy

Similar to solution 3, here we directly calculate the number of units of times.

Let `mxCnt` be the maximum frequency of `A[i]`. `mxCntFreq` be the number of unique tasks with `mxCnt` frequency.

We always greedily place the tasks with `mxCnt` frequency first.

For example, `A = "AAABBBC", n = 2`. `mxCnt = 3` and `mxCntFreq = 2`. We place `A` and `B` first.

```
A B - A B - A B
```

Then we place other tasks. In this case, we just need to place `C`.

```
A B C A B - A B
```

If `mxCntFreq >= n + 1`, it means that we can fill all the sections of length `n + 1` with `mxCnt` frequency tasks. We can place the other tasks between the sections without leaving any idle item.

If `mxCntFreq < n + 1`, we need to fill the `gap = (mxCnt - 1) * (n + 1 - mxCntFreq)` gaps with the other `otherFreq = A.size() - mxCntFreq * mxCnt` tasks. The answer is `mxCntFreq * mxCnt + max(otherFreq, gap)`.

```cpp
// OJ: https://leetcode.com/problems/task-scheduler/
// Author: github.com/lzl124631x
// Time: O(M) where M is the length of `tasks`
// Space: O(C)
class Solution {
public:
    int leastInterval(vector<char>& A, int n) {
        int cnt[26] = {};
        for (char c : A) cnt[c - 'A']++;
        int mxCnt = *max_element(begin(cnt), end(cnt)), mxCntFreq = 0;
        for (int n : cnt) mxCntFreq += n == mxCnt;
        if (mxCntFreq >= n + 1) return A.size();
        int ans = mxCntFreq * mxCnt, otherFreq = A.size() - ans, gap = (mxCnt - 1) * (n + 1 - mxCntFreq);
        return ans + max(otherFreq, gap);
    }
};
```