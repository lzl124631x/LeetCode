# [1282. Group the People Given the Group Size They Belong To (Medium)](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to)

<p>There are <code>n</code> people&nbsp;that are split into some unknown number of groups. Each person is labeled with a&nbsp;<strong>unique ID</strong>&nbsp;from&nbsp;<code>0</code>&nbsp;to&nbsp;<code>n - 1</code>.</p>
<p>You are given an integer array&nbsp;<code>groupSizes</code>, where <code>groupSizes[i]</code>&nbsp;is the size of the group that person&nbsp;<code>i</code>&nbsp;is in. For example, if&nbsp;<code>groupSizes[1] = 3</code>, then&nbsp;person&nbsp;<code>1</code>&nbsp;must be in a&nbsp;group of size&nbsp;<code>3</code>.</p>
<p>Return&nbsp;<em>a list of groups&nbsp;such that&nbsp;each person&nbsp;<code>i</code>&nbsp;is in a group of size&nbsp;<code>groupSizes[i]</code></em>.</p>
<p>Each person should&nbsp;appear in&nbsp;<strong>exactly one group</strong>,&nbsp;and every person must be in a group. If there are&nbsp;multiple answers, <strong>return any of them</strong>. It is <strong>guaranteed</strong> that there will be <strong>at least one</strong> valid solution for the given input.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> groupSizes = [3,3,3,3,3,1,3]
<strong>Output:</strong> [[5],[0,1,2],[3,4,6]]
<b>Explanation:</b> 
The first group is [5]. The size is 1, and groupSizes[5] = 1.
The second group is [0,1,2]. The size is 3, and groupSizes[0] = groupSizes[1] = groupSizes[2] = 3.
The third group is [3,4,6]. The size is 3, and groupSizes[3] = groupSizes[4] = groupSizes[6] = 3.
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> groupSizes = [2,1,3,3,3,2]
<strong>Output:</strong> [[1],[0,5],[2,3,4]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>groupSizes.length == n</code></li>
	<li><code>1 &lt;= n&nbsp;&lt;= 500</code></li>
	<li><code>1 &lt;=&nbsp;groupSizes[i] &lt;= n</code></li>
</ul>

**Companies**:
[C3 IoT](https://leetcode.com/company/c3-iot), [Apple](https://leetcode.com/company/apple), [Roblox](https://leetcode.com/company/roblox)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Maximum Number of Groups With Increasing Length (Hard)](https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& A) {
        unordered_map<int, vector<int>> m; // a map from group size to the group members
        vector<vector<int>> ans;
        for (int i = 0; i < A.size(); ++i) {
            m[A[i]].push_back(i);
            if (m[A[i]].size() == A[i]) { // if this group is full, add it into answer
                ans.push_back(m[A[i]]);
                m[A[i]].clear();
            }
        }
        return ans;
    }
};
```

## Solution 2.

The worst case for space complexity analysis is where we have the input in the form of `[1, 2, 2, 3, 3, 3, ...]`. Assume there are `k` distinct sizes, then `k * (k + 1) / 2 = N`, so the space complexity is `O(sqrt(N))`.

```cpp
// OJ: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(sqrt(N))
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& A) {
        unordered_map<int, int> m; // a map from group size to the corresponding index in answer
        vector<vector<int>> ans;
        for (int i = 0; i < A.size(); ++i) {
            int sz = A[i];
            if (m.count(sz) == 0 || ans[m[sz]].size() == sz) {
                m[sz] = ans.size();
                ans.emplace_back();
            }
            ans[m[sz]].push_back(i);
        }
        return ans;
    }
};
```