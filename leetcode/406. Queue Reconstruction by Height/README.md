# [406. Queue Reconstruction by Height (Medium)](https://leetcode.com/problems/queue-reconstruction-by-height/)

<p>Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers <code>(h, k)</code>, where <code>h</code> is the height of the person and <code>k</code> is the number of people in front of this person who have a height greater than or equal to <code>h</code>. Write an algorithm to reconstruct the queue.</p>

<p><b>Note:</b><br>
The number of people is less than 1,100.</p>
&nbsp;

<p><b>Example</b></p>

<pre>Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
</pre>

<p>&nbsp;</p>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Count of Smaller Numbers After Self (Hard)](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/queue-reconstruction-by-height
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
// Ref: https://discuss.leetcode.com/topic/60470/6-lines-concise-c
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        vector<vector<int>> ans;
        for (auto &p : people) ans.insert(ans.begin() + p[1], p);
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/queue-reconstruction-by-height
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
      return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
    });
    vector<vector<int>> ans;
    for (auto p : people) {
      int cnt = 0, i = 0;
      while (i < ans.size() && cnt < p[1]) cnt += (ans[i++][0] >= p[0]);
      ans.insert(ans.begin() + i, p);
    }
    return ans;
  }
};
```