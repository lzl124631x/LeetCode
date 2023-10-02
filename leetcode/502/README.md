# [502. IPO (Hard)](https://leetcode.com/problems/ipo/)

<p>Suppose LeetCode will start its <strong>IPO</strong> soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the <strong>IPO</strong>. Since it has limited resources, it can only finish at most <code>k</code> distinct projects before the <strong>IPO</strong>. Help LeetCode design the best way to maximize its total capital after finishing at most <code>k</code> distinct projects.</p>

<p>You are given <code>n</code> projects where the <code>i<sup>th</sup></code> project has a pure profit <code>profits[i]</code> and a minimum capital of <code>capital[i]</code> is needed to start it.</p>

<p>Initially, you have <code>w</code> capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.</p>

<p>Pick a list of <strong>at most</strong> <code>k</code> distinct projects from given projects to <strong>maximize your final capital</strong>, and return <em>the final maximized capital</em>.</p>

<p>The answer is guaranteed to fit in a 32-bit signed integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= w &lt;= 10<sup>9</sup></code></li>
	<li><code>n == profits.length</code></li>
	<li><code>n == capital.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= profits[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= capital[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/ipo/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& P, vector<int>& C) {
        vector<int> id(P.size());
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return C[a] < C[b]; });
        auto cmp = [&](int a, int b) { return P[a] < P[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0, j = 0; i < k; ++i) {
            while (j < id.size() && w >= C[id[j]]) {
                pq.push(id[j]);
                ++j;
            }
            if (pq.empty()) break;
            int p = pq.top();
            pq.pop();
            w += P[p];
        }
        return w;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/ipo/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    typedef pair<int, int> PII;
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        auto capCmp = [](auto &a, auto &b) { return a.first > b.first; };
        auto proCmp = [](auto &a, auto &b) { return a.second < b.second; };
        priority_queue<PII, vector<PII>, decltype(capCmp)> cap(capCmp);
        priority_queue<PII, vector<PII>, decltype(proCmp)> pro(proCmp);
        for (int i = 0; i < Profits.size(); ++i) cap.push({ Capital[i], Profits[i] });
        while (k--) {
            while (cap.size() && cap.top().first <= W) {
                pro.push(cap.top());
                cap.pop();
            }
            if (pro.empty()) return W;
            W += pro.top().second;
            pro.pop();
        }
        return W;
    }
};
```