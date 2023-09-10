# [2848. Points That Intersect With Cars (Easy)](https://leetcode.com/problems/points-that-intersect-with-cars)

<p>You are given a <strong>0-indexed</strong> 2D integer array <code>nums</code> representing the coordinates of the cars parking on a number line. For any index <code>i</code>, <code>nums[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> where <code>start<sub>i</sub></code> is the starting point of the <code>i<sup>th</sup></code> car and <code>end<sub>i</sub></code> is the ending point of the <code>i<sup>th</sup></code> car.</p>
<p>Return <em>the number of integer points on the line that are covered with <strong>any part</strong> of a car.</em></p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [[3,6],[1,5],[4,7]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> All the points from 1 to 7 intersect at least one car, therefore the answer would be 7.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [[1,3],[5,8]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> Points intersecting at least one car are 1, 2, 3, 5, 6, 7, 8. There are a total of 7 points, therefore the answer would be 7.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>nums[i].length == 2</code></li>
	<li><code><font face="monospace">1 &lt;= start<sub>i</sub>&nbsp;&lt;= end<sub>i</sub>&nbsp;&lt;= 100</font></code></li>
</ul>

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)
* [Meeting Rooms (Easy)](https://leetcode.com/problems/meeting-rooms/)
* [Meeting Rooms II (Medium)](https://leetcode.com/problems/meeting-rooms-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/points-that-intersect-with-cars
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& A) {
        sort(begin(A), end(A));
        int start = INT_MIN, end = INT_MIN, ans = 0;
        for (auto &c : A) {
            if (c[0] <= end) {
                end = max(end, c[1]);
            } else {
                if (end != INT_MIN) ans += end - start + 1;
                start = c[0];
                end = c[1];
            }
        }
        return ans + end - start + 1;
    }
};
```

## Solution 2. Difference Array

```cpp
// OJ: https://leetcode.com/problems/points-that-intersect-with-cars
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(D) where D is the range of A[i]
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& A) {
        int diff[102] = {}, ans = 0;
        for (auto &c : A) {
            diff[c[0]]++;
            diff[c[1] + 1]--;
        }
        for (int i = 1, d = 0; i <= 100; ++i) {
            d += diff[i];
            ans += d > 0;
        }
        return ans;
    }
};
```