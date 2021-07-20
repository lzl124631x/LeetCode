# [973. K Closest Points to Origin (Medium)](https://leetcode.com/problems/k-closest-points-to-origin/)

<p>Given an array of <code>points</code> where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents a point on the <strong>X-Y</strong> plane and an integer <code>k</code>, return the <code>k</code> closest points to the origin <code>(0, 0)</code>.</p>

<p>The distance between two points on the <strong>X-Y</strong> plane is the Euclidean distance (i.e., <code>√(x<sub>1</sub> - x<sub>2</sub>)<sup>2</sup> + (y<sub>1</sub> - y<sub>2</sub>)<sup>2</sup></code>).</p>

<p>You may return the answer in <strong>any order</strong>. The answer is <strong>guaranteed</strong> to be <strong>unique</strong> (except for the order that it is in).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg" style="width: 400px; height: 400px;">
<pre><strong>Input:</strong> points = [[1,3],[-2,2]], k = 1
<strong>Output:</strong> [[-2,2]]
<strong>Explanation:</strong>
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) &lt; sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> points = [[3,3],[5,-1],[-2,4]], k = 2
<strong>Output:</strong> [[3,3],[-2,4]]
<strong>Explanation:</strong> The answer [[-2,4],[3,3]] would also be accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= points.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt; x<sub>i</sub>, y<sub>i</sub> &lt; 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [DoorDash](https://leetcode.com/company/doordash), [Google](https://leetcode.com/company/google), [LinkedIn](https://leetcode.com/company/linkedin), [Microsoft](https://leetcode.com/company/microsoft), [Uber](https://leetcode.com/company/uber), [ByteDance](https://leetcode.com/company/bytedance), [Apple](https://leetcode.com/company/apple), [Asana](https://leetcode.com/company/asana)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Geometry](https://leetcode.com/tag/geometry/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Quickselect](https://leetcode.com/tag/quickselect/)

**Similar Questions**:
* [Kth Largest Element in an Array (Medium)](https://leetcode.com/problems/kth-largest-element-in-an-array/)
* [Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)
* [Top K Frequent Words (Medium)](https://leetcode.com/problems/top-k-frequent-words/)
* [Find Nearest Point That Has the Same X or Y Coordinate (Easy)](https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/)

## Solution 1. Sort

```cpp
// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
private:
    int dist(vector<int> &p) {
        return p[0] * p[0]  + p[1] * p[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), [&](auto &a, auto &b) { return dist(a) < dist(b); });
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

If the space is limited, we can keep a max-heap of size `K`.

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

Or

```cpp
// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/lzl124631x
// Time: O(NlogK)
// Space: O(K)
class Solution {
private:
    int dist(vector<int> &p) {
        return p[0] * p[0]  + p[1] * p[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& A, int K) {
        auto cmp = [&](int a, int b) { return dist(A[a]) < dist(A[b]); };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < A.size(); ++i) {
            pq.push(i);
            if (pq.size() > K) pq.pop();
        }
        vector<vector<int>> ans;
        while (pq.size()) {
            ans.push_back(A[pq.top()]);
            pq.pop();
        }
        return ans;
    }
};
```

## Solution 4. Quick Select

```cpp
// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/lzl124631x
// Time: O(N) on average, O(N^2) in the worst case
// Space: O(1)
class Solution {
    int dist(vector<int> &p) {
        return p[0] * p[0]  + p[1] * p[1];
    }
    int quickSelect(vector<vector<int>> &A, int L, int R) {
        int i = L, j = L, pivotIndex = L + rand() % (R - L + 1), pivot = dist(A[pivotIndex]);
        swap(A[pivotIndex], A[R]);
        for (; i < R; ++i) {
            if (dist(A[i]) < pivot) swap(A[j++], A[i]);
        }
        swap(A[j], A[R]);
        return j;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& A, int k) {
        int L = 0, R = A.size() - 1;
        while (L < R) {
            int M = quickSelect(A, L, R);
            if (M + 1 == k) break;
            if (M + 1 > k) R = M - 1;
            else L = M + 1;
        }
        return vector<vector<int>>(begin(A), begin(A) + k);
    }
};
```