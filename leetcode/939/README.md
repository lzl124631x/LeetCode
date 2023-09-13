# [939. Minimum Area Rectangle (Medium)](https://leetcode.com/problems/transpose-matrix/)

Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

**Example 1:**

**Input:** \[\[1,1\],\[1,3\],\[3,1\],\[3,3\],\[2,2\]\]  
**Output:** 4

**Example 2:**

**Input:** \[\[1,1\],\[1,3\],\[3,1\],\[3,3\],\[4,1\],\[4,3\]\]  
**Output:** 2

**Note**:

1.  `1 <= points.length <= 500`
2.  `0 <= points[i][0] <= 40000`
3.  `0 <= points[i][1] <= 40000`
4.  All points are distinct.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/transpose-matrix/
// Author: github.com/lzl124631x
// Time: O(N^2logN)
//   * each point is visited only once with another point -> O(N^2)
//   * ys2.find(y) -> O(logN)
// Space: O(N)
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans = INT_MAX;
        unordered_map<int, set<int>> m;
        for (auto &p : points) m[p[0]].insert(p[1]);
        for (auto i = m.begin(); i != m.end(); ++i) {
            auto &ys1 = i->second;
            for (auto j = next(i); j != m.end(); ++j) {
                auto &ys2 = j->second;
                int xDist = abs(i->first - j->first);
                int prevY = INT_MIN;
                int minYDist = INT_MAX;
                for (auto &y : ys1) {
                    if (ys2.find(y) == ys2.end()) continue;
                    if (prevY != INT_MIN) {
                        minYDist = min(minYDist, y - prevY);
                    }
                    prevY = y;
                }
                if (minYDist != INT_MAX) ans = min(ans, xDist * minYDist);
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
```