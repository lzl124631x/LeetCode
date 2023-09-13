# [436. Find Right Interval (Medium)](https://leetcode.com/problems/find-right-interval/)

<p>Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.</p>

<p>For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.</p>

<p><b>Note:</b></p>

<ol>
	<li>You may assume the interval's end point is always bigger than its start point.</li>
	<li>You may assume none of these intervals have the same start point.</li>
</ol>

<p>&nbsp;</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b> [ [1,2] ]

<b>Output:</b> [-1]

<b>Explanation:</b> There is only one interval in the collection, so it outputs -1.
</pre>

<p>&nbsp;</p>

<p><b>Example 2:</b></p>

<pre><b>Input:</b> [ [3,4], [2,3], [1,2] ]

<b>Output:</b> [-1, 0, 1]

<b>Explanation:</b> There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.
</pre>

<p>&nbsp;</p>

<p><b>Example 3:</b></p>

<pre><b>Input:</b> [ [1,4], [2,3], [3,4] ]

<b>Output:</b> [-1, 2, -1]

<b>Explanation:</b> There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.
</pre>

<p><strong>NOTE:</strong>&nbsp;input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.</p>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Data Stream as Disjoint Intervals (Hard)](https://leetcode.com/problems/data-stream-as-disjoint-intervals/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/find-right-interval/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& A) {
        int N = A.size();
        vector<int> id(N), ans;
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return A[a][0] < A[b][0]; });
        for (auto &i : A) {
            auto j = lower_bound(begin(id), end(id), i[1], [&](int idx, int val) { return A[idx][0] < val; });
            ans.push_back(j == end(id) ? -1 : *j);
        }
        return ans;
    }
};
```

Or manually write the binary search.

```cpp
// OJ: https://leetcode.com/problems/find-right-interval/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& A) {
        int N = A.size();
        vector<int> id(N), ans;
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return A[a][0] < A[b][0]; });
        for (auto &i : A) {
            int L = 0, R = N - 1;
            while (L <= R) {
                int M = (L + R) / 2;
                if (A[id[M]][0] < i[1]) L = M + 1;
                else R = M - 1;
            }
            ans.push_back(L == N ? -1 : id[L]);
        }
        return ans;
    }
};
```