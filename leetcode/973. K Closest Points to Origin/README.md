# [973. K Closest Points to Origin (Easy)](https://leetcode.com/problems/k-closest-points-to-origin/)

<p>We have a list of <code>points</code>&nbsp;on the plane.&nbsp; Find the <code>K</code> closest points to the origin <code>(0, 0)</code>.</p>

<p>(Here, the distance between two points on a plane is the Euclidean distance.)</p>

<p>You may return the answer in any order.&nbsp; The&nbsp;answer is guaranteed to be unique (except for the order that it is in.)</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>points = <span id="example-input-1-1">[[1,3],[-2,2]]</span>, K = <span id="example-input-1-2">1</span>
<strong>Output: </strong><span id="example-output-1">[[-2,2]]</span>
<strong>Explanation: </strong>
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) &lt; sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong>points = <span id="example-input-2-1">[[3,3],[5,-1],[-2,4]]</span>, K = <span id="example-input-2-2">2</span>
<strong>Output: </strong><span id="example-output-2">[[3,3],[-2,4]]</span>
(The answer [[-2,4],[3,3]] would also be accepted.)
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= K &lt;= points.length &lt;= 10000</code></li>
	<li><code>-10000 &lt; points[i][0] &lt; 10000</code></li>
	<li><code>-10000 &lt; points[i][1] &lt; 10000</code></li>
</ol>
</div>
</div>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1. Sort

```cpp
// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
private:
    double dist(vector<int> &point) {
        return sqrt(pow(point[0], 2) + pow(point[1], 2));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [&](vector<int> &a, vector<int> &b) {
            return dist(a) < dist(b);
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
```

## Solution 2. Heap

Keep a min-heap of all elements and pop `K` times.

Heap creation takes `O(N)`. Popping an element takes `O(logN)` which we repeat `K` times.

```cpp
// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/lzl124631x
// Time: O(N + KlogN)
// Space: O(N)
class Solution {
    int dist(vector<int> &p) {
        return p[0] * p[0] + p[1] * p[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& A, int K) {
        auto cmp = [&](vector<int> &a, vector<int> &b) {
            return dist(a) > dist(b);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(begin(A), end(A), cmp);
        vector<vector<int>> ans;
        while (ans.size() < K) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};
```

## Solution 3. Heap

If the space is limited, we can keep a min-heap of size `K`.

We loop through each point:
* If the heap has less than `K` elements, push the point into heap.
* Otherwise, if the distance of the element is smaller than that of the heap top, we pop the heap top and push this point into heap.

In the end, all the elements left in the heap forms the answer.

```cpp
// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(K)
class Solution {
    int dist(const vector<int> &p) {
        return p[0] * p[0] + p[1] * p[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& A, int K) {
        auto cmp = [&](const vector<int> &a, const vector<int> &b) {
            return dist(a) < dist(b);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        for (auto & p : A) {
            if (q.size() == K) {
                if (dist(p) >= dist(q.top())) continue;
                q.pop();
            }
            q.push(p);
        }
        vector<vector<int>> ans;
        while (q.size()) {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};
```

## Solution 4. Quick Select

```cpp
// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    double dist(vector<int> &point) {
        return sqrt(pow(point[0], 2) + pow(point[1], 2));
    }
    int quickSelect(vector<vector<int>> &points, int start, int end) {
        int pivot = rand() % (end - start) + start, i = start, j = end - 1;
        double p = dist(points[pivot]);
        swap(points[start], points[pivot]);
        while (i < j) {
            while (i < j && dist(points[j]) >= p) --j;
            while (i < j && dist(points[i]) <= p) ++i;
            if (i < j) swap(points[i], points[j]);
        }
        swap(points[start], points[i]);
        return i;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int L = 0, R = points.size();
        while (L < R) {
            int M = quickSelect(points, L, R);
            if (M + 1 == K) break;
            if (M + 1 > K) R = M;
            else L = M + 1;
        }
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
```