# [57. Insert Interval (Hard)](https://leetcode.com/problems/insert-interval/)

<p>Given a set of <em>non-overlapping</em> intervals, insert a new interval into the intervals (merge if necessary).</p>

<p>You may assume that the intervals were initially sorted according to their start times.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> intervals = [[1,3],[6,9]], newInterval = [2,5]
<strong>Output:</strong> [[1,5],[6,9]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> intervals = <code>[[1,2],[3,5],[6,7],[8,10],[12,16]]</code>, newInterval = <code>[4,8]</code>
<strong>Output:</strong> [[1,2],[3,10],[12,16]]
<strong>Explanation:</strong> Because the new interval <code>[4,8]</code> overlaps with <code>[3,5],[6,7],[8,10]</code>.</pre>

<p><strong>NOTE:</strong>&nbsp;input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.</p>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [Merge Intervals (Medium)](https://leetcode.com/problems/merge-intervals/)
* [Range Module (Hard)](https://leetcode.com/problems/range-module/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/insert-interval/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s = newInterval[0], e = newInterval[1];
        vector<vector<int>> ans;
        for (auto &intv : intervals) {
            if (s > e) ans.push_back(intv);
            else if (intv[0] > e) { 
                ans.push_back({ s, e });
                s = e + 1;
                ans.push_back(intv);
            } else if (intv[1] < s) ans.push_back(intv);
            else {
                s = min(s, intv[0]);
                e = max(e, intv[1]);
            }
        }
        if (s <= e) ans.push_back({ s, e });
        return ans;
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/insert-interval/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s = newInterval[0], e = newInterval[1], pos = 0;
        vector<vector<int>> ans;
        for (auto &intv : intervals) {
            if (intv[1] < s) {
                ans.push_back(intv);
                ++pos;
            } else if (intv[0] > e) ans.push_back(intv);
            else {
                s = min(s, intv[0]);
                e = max(e, intv[1]);
            }
        }
        ans.insert(begin(ans) + pos, { s, e });
        return ans;
    }
};
```