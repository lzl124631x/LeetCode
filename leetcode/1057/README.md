# [1057. Campus Bikes (Medium)](https://leetcode.com/problems/campus-bikes)

<p>On a campus represented on the X-Y plane, there are <code>n</code> workers and <code>m</code> bikes, with <code>n &lt;= m</code>.</p>

<p>You are given an array <code>workers</code> of length <code>n</code> where <code>workers[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> is the position of the <code>i<sup>th</sup></code> worker. You are also given an array <code>bikes</code> of length <code>m</code> where <code>bikes[j] = [x<sub>j</sub>, y<sub>j</sub>]</code> is the position of the <code>j<sup>th</sup></code> bike. All the given positions are <strong>unique</strong>.</p>

<p>Assign a bike to each worker. Among the available bikes and workers, we choose the <code>(worker<sub>i</sub>, bike<sub>j</sub>)</code> pair with the shortest <strong>Manhattan distance</strong> between each other and assign the bike to that worker.</p>

<p>If there are multiple <code>(worker<sub>i</sub>, bike<sub>j</sub>)</code> pairs with the same shortest <strong>Manhattan distance</strong>, we choose the pair with <strong>the smallest worker index</strong>. If there are multiple ways to do that, we choose the pair with <strong>the smallest bike index</strong>. Repeat this process until there are no available workers.</p>

<p>Return <em>an array </em><code>answer</code><em> of length </em><code>n</code><em>, where </em><code>answer[i]</code><em> is the index (<strong>0-indexed</strong>) of the bike that the </em><code>i<sup>th</sup></code><em> worker is assigned to</em>.</p>

<p>The <strong>Manhattan distance</strong> between two points <code>p1</code> and <code>p2</code> is <code>Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/03/06/1261_example_1_v2.png" style="width: 376px; height: 366px;" />
<pre>
<strong>Input:</strong> workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
<strong>Output:</strong> [1,0]
<strong>Explanation:</strong> Worker 1 grabs Bike 0 as they are closest (without ties), and Worker 0 is assigned Bike 1. So the output is [1, 0].
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/03/06/1261_example_2_v2.png" style="width: 376px; height: 366px;" />
<pre>
<strong>Input:</strong> workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
<strong>Output:</strong> [0,2,1]
<strong>Explanation:</strong> Worker 0 grabs Bike 0 at first. Worker 1 and Worker 2 share the same distance to Bike 2, thus Worker 1 is assigned to Bike 2, and Worker 2 will take Bike 1. So the output is [0,2,1].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == workers.length</code></li>
	<li><code>m == bikes.length</code></li>
	<li><code>1 &lt;= n &lt;= m &lt;= 1000</code></li>
	<li><code>workers[i].length == bikes[j].length == 2</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt; 1000</code></li>
	<li><code>0 &lt;= x<sub>j</sub>, y<sub>j</sub> &lt; 1000</code></li>
	<li>All worker and bike locations are <strong>unique</strong>.</li>
</ul>


**Companies**:
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Greedy](https://leetcode.com/tag/greedy), [Sorting](https://leetcode.com/tag/sorting)

**Similar Questions**:
* [Campus Bikes II (Medium)](https://leetcode.com/problems/campus-bikes-ii)

**Hints**:
* <p>Sort the elements by distance. In case of a tie, sort them by the index of the worker. After that, if there are still ties, sort them by the index of the bike.</p>

<p>Can you do this in less than O(nlogn) time, where n is the total number of pairs between workers and bikes?</p>
* Loop the sorted elements and match each pair of worker and bike if the given worker and bike where not used.

## Solution 1. Sorting

```cpp
// OJ: https://leetcode.com/problems/campus-bikes/
// Author: github.com/lzl124631x
// Time: O(MNlog(MN))
// Space: O(MN)
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& W, vector<vector<int>>& B) {
        int N = W.size(), M = B.size();
        vector<array<int, 3>> v;
        auto dist = [](auto &a, auto &b) {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                v.push_back({dist(W[i], B[j]), i, j});
            }
        }
        vector<bool> used(M);
        sort(begin(v), end(v));
        vector<int> ans(N, -1);
        for (int i = 0, cnt = 0; i < v.size() && cnt < N; ++i) {
            if (used[v[i][2]] || ans[v[i][1]] != -1) continue;
            used[v[i][2]] = true;
            ans[v[i][1]] = v[i][2];
            ++cnt;
        }
        return ans;
    }
};
```

## Solution 2. Bucket Sort

Note that this problem is not asking an assignment with which the total Manhattan distance is minimized. It asked us to go through the pairs from shortest distance to longest distance, and choose the pairs in ascending order of worker index then in ascending order of bike index.

Take the example testcase for example, 

```
[[0,0],[2,1]]
[[1,2],[3,3]]
```

The total Manhattan distance of the answer is `2 + 6 = 8`, but assignment `0->0, 1->1` has total distance of `3 + 3 = 6`.

So, we can put the pairs in buckets where each bucket is the distance. Since we loop in ascending order of worker index then in ascending order of bike index, so everything is already sorted in the required way.

```cpp
// OJ: https://leetcode.com/problems/campus-bikes/
// Author: github.com/lzl124631x
// Time: O(NM + K) where `K` is the maximum Manhattan distance, which is 1998 in this problem
// Space: O(NM + K)
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& W, vector<vector<int>>& B) {
        int N = W.size(), M = B.size(), minDist = INT_MAX, cnt = 0;
        vector<array<int, 2>> v[1999];
        auto dist = [](auto &a, auto &b) {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int d = dist(W[i], B[j]);
                v[d].push_back({i, j});
                minDist = min(minDist, d);
            }
        }
        vector<bool> used(M);
        vector<int> ans(N, - 1);
        for (int d = minDist; d < 1999 && cnt < N; ++d) {
            for (auto &[w, b] : v[d]) {
                if (ans[w] != -1 || used[b]) continue;
                used[b] = true;
                ans[w] = b;
                ++cnt;
            }
        }
        return ans;
    }
};
```

## Solution 3. Priority Queue

The idea is similar to the priority queue solution to merging K sorted list.

For each worker, we maintain a list of bike indexes in ascending order of distance.

We maintain a priority queue of `N` elements each of which is a current bike index corresponding to a worker.

```cpp
// OJ: https://leetcode.com/problems/campus-bikes/
// Author: github.com/lzl124631x
// Time: O(NMlogM + MNlogN)
// Space: O(MN)
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& W, vector<vector<int>>& B) {
        int N = W.size(), M = B.size();
        vector<vector<array<int, 2>>> v(N, vector<array<int, 2>>(M));
        auto dist = [](auto &a, auto &b) {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                v[i][j] = { dist(W[i], B[j]), j };
            }
            sort(begin(v[i]), end(v[i]));
        }
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>> pq; // distance, workerIndex, bikeIndex, cursorIndex pointing to the next bikeIndex with greater or same distance to the current worker.
        for (int i = 0; i < N; ++i) pq.push({ v[i][0][0], i, v[i][0][1], 0 });
        vector<bool> used(M);
        vector<int> ans(N, -1);
        for (int i = 0; i < N; ) {
            auto [d, w, b, j] = pq.top();
            pq.pop();
            if (used[b]) {
                int nb = v[w][j + 1][1], nd = dist(W[w], B[nb]);
                pq.push({nd, w, nb, j + 1});
                continue;
            }
            used[b] = true;
            ans[w] = b;
            ++i;
        }
        return ans;
    }
};
```