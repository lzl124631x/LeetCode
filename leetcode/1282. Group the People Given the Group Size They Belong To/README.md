# [1282. Group the People Given the Group Size They Belong To (Medium)](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/)

<p>There are <code>n</code> people whose <strong>IDs</strong> go from <code>0</code> to <code>n - 1</code> and each person belongs <strong>exactly</strong> to one&nbsp;group. Given the array&nbsp;<code>groupSizes</code> of length <code>n</code> telling the group size each person belongs to, return the groups there are and the people's&nbsp;<strong>IDs</strong> each group includes.</p>

<p>You can return any solution in any order and the same applies for IDs. Also, it is guaranteed that there exists at least one solution.&nbsp;</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> groupSizes = [3,3,3,3,3,1,3]
<strong>Output:</strong> [[5],[0,1,2],[3,4,6]]
<b>Explanation:</b> 
Other possible solutions are [[2,1,6],[5],[0,4,3]] and [[5],[0,6,2],[4,3,1]].
</pre>

<p><strong>Example 2:</strong></p>

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


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

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