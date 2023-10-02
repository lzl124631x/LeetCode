# [1488. Avoid Flood in The City (Medium)](https://leetcode.com/problems/avoid-flood-in-the-city/)

<p>Your country has an infinite number of lakes. Initially, all the lakes are empty, but when it rains over the <code>nth</code> lake, the <code>nth</code> lake becomes full of water. If it rains over a lake which is <strong>full of water</strong>, there will be a <strong>flood</strong>. Your goal is to avoid the flood in any lake.</p>

<p>Given an integer array <code>rains</code> where:</p>

<ul>
	<li><code>rains[i] &gt; 0</code> means there will be rains over the <code>rains[i]</code> lake.</li>
	<li><code>rains[i] == 0</code> means there are no rains this day and you can choose <strong>one lake</strong> this day and <strong>dry it</strong>.</li>
</ul>

<p>Return <em>an array <code>ans</code></em> where:</p>

<ul>
	<li><code>ans.length == rains.length</code></li>
	<li><code>ans[i] == -1</code> if <code>rains[i] &gt; 0</code>.</li>
	<li><code>ans[i]</code> is the lake you choose to dry in the <code>ith</code> day&nbsp;if <code>rains[i] == 0</code>.</li>
</ul>

<p>If there are multiple valid answers return <strong>any</strong> of them. If it is impossible to avoid flood return <strong>an empty array</strong>.</p>

<p>Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an empty lake, nothing changes. (see example 4)</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> rains = [1,2,3,4]
<strong>Output:</strong> [-1,-1,-1,-1]
<strong>Explanation:</strong> After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day full lakes are [1,2,3]
After the fourth day full lakes are [1,2,3,4]
There's no day to dry any lake and there is no flood in any lake.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> rains = [1,2,0,0,2,1]
<strong>Output:</strong> [-1,-1,2,1,-1,-1]
<strong>Explanation:</strong> After the first day full lakes are [1]
After the second day full lakes are [1,2]
After the third day, we dry lake 2. Full lakes are [1]
After the fourth day, we dry lake 1. There is no full lakes.
After the fifth day, full lakes are [2].
After the sixth day, full lakes are [1,2].
It is easy that this scenario is flood-free. [-1,-1,1,2,-1,-1] is another acceptable scenario.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> rains = [1,2,0,1,2]
<strong>Output:</strong> []
<strong>Explanation:</strong> After the second day, full lakes are  [1,2]. We have to dry one lake in the third day.
After that, it will rain over lakes [1,2]. It's easy to prove that no matter which lake you choose to dry in the 3rd day, the other one will flood.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> rains = [69,0,0,0,69]
<strong>Output:</strong> [-1,69,1,1,-1]
<strong>Explanation:</strong> Any solution on one of the forms [-1,69,x,y,-1], [-1,x,69,y,-1] or [-1,x,y,69,-1] is acceptable where 1 &lt;= x,y &lt;= 10^9
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> rains = [10,20,20]
<strong>Output:</strong> []
<strong>Explanation:</strong> It will rain over lake 20 two consecutive days. There is no chance to dry any lake.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rains.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= rains[i] &lt;= 10^9</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1. Greedy + Heap

Consider input `[1, 2, 0, 2, 1, ...]`. At the first `0`, I'd greedily dry `2` instead of `1` because that's the first positive number following this `0`.

So my idea is that:
1. For each `A[i]`, compute `next[i]` which is the index of the next element equals `A[i]`. If there is no such element, `next[i] = -1`.
2. Maintain a set `s` storing the active lakes (i.e. the lakes waiting to be dried) and a min-root heap `pq` storing the next indexes of active lakes.
    1. If `A[i] > 0`:
        1. If `A[i]` is in `s`, it means that `A[i]` is already an active lake. We should return `{}`.
        2. If `next[i] == -1`, it means that it won't be filled again later, we can safely ignore it when drying, so just skip it.
        3. Otherwise, we need to add `A[i]` to `s` and add `next[i]` to `pq`.
    2. If `A[i] == 0`:
        1. If `pq.empty()`, it means that there is no active lakes, we can just arbitrarily dry some lake, say `1`.
        1. Otherwise, we should dry the active lake whose `next` index is smallest, i.e. `A[pq.top()]`. So `ans[i] = A[pq.top()]` and we can remove `A[pq.top()]` from `s` and pop the top from `pq`.

```cpp
// OJ: https://leetcode.com/problems/avoid-flood-in-the-city/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> avoidFlood(vector<int>& A) {
        int N = A.size();
        vector<int> ans(N, -1), next(N, -1);
        unordered_map<int, int> m;
        for (int i = 0; i < N; ++i) {
            if (A[i] == 0) continue;
            if (m.count(A[i])) next[m[A[i]]] = i;
            m[A[i]] = i;
        }
        unordered_set<int> s;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < N; ++i) {
            if (A[i] > 0) {
                if (s.count(A[i])) return {};
                if (next[i] == -1) continue;
                pq.push(next[i]);
                s.insert(A[i]);
            } else {
                if (pq.empty()) ans[i] = 1;
                else {
                    int j = pq.top();
                    pq.pop();
                    ans[i] = A[j];
                    s.erase(A[j]);
                }
            }
        }
        return ans;
    }
};
```

## Solution 2. Greedy

I came with this solution first in the context but instead of using `set::upper_bound` I used `std::upper_bound` which degrades to `O(N)` complexity on `set` :(

So remember! When doing `upper_bound `on `set`, must use `set::upper_bound`!

Use a set `s` to store the index of available `0`s. Use map to store the mapping from a active lake to its index.

If `A[i] == 0`, we just add it to `s` and set a dummy value `ans[i] = 1`. If might get overwritten later. If it's not overwritten, leaving this dummy value here is also correct.

If `A[i] > 0`, we first check if it exists in `m`:

* Only when the answer is yes, we need to find the smallest index in `s` that is greater than `m[A[i]]`. If there is no such index, we don't have available day to dry this lake, we should return `{}`. Otherwise, we dry `A[i]` using this index and erase this used index from `s`.
* No matter if it's yes or no, we need to set `m[A[i]] = i` to add this active lake.

```cpp
// OJ: https://leetcode.com/problems/avoid-flood-in-the-city/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> avoidFlood(vector<int>& A) {
        int N = A.size();
        vector<int> ans(N, -1);
        unordered_map<int, int> m;
        set<int> s;
        for (int i = 0; i < N; ++i) {
            if (A[i] > 0) {
                if (m.count(A[i])) {
                    auto it = s.upper_bound(m[A[i]]);
                    if (it == s.end()) return {};
                    ans[*it] = A[i];
                    s.erase(it);
                }
                m[A[i]] = i;
            } else {
                s.insert(i);
                ans[i] = 1;
            }
        }
        return ans;
    }
};
```