# [1424. Diagonal Traverse II (Medium)](https://leetcode.com/problems/diagonal-traverse-ii)

<p>Given a 2D integer array <code>nums</code>, return <em>all elements of </em><code>nums</code><em> in diagonal order as shown in the below images</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/08/sample_1_1784.png" style="width: 158px; height: 143px;" />
<pre>
<strong>Input:</strong> nums = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [1,4,2,7,5,3,8,6,9]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/04/08/sample_2_1784.png" style="width: 230px; height: 177px;" />
<pre>
<strong>Input:</strong> nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
<strong>Output:</strong> [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= sum(nums[i].length) &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i][j] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:
[Facebook](https://leetcode.com/company/facebook), [VMware](https://leetcode.com/company/vmware), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Sorting](https://leetcode.com/tag/sorting), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue)

**Hints**:
* Notice that numbers with equal sums of row and column indexes belong to the same diagonal.
* Store them in tuples (sum, row, val), sort them, and then regroup the answer.

## Solution 1.

At each level, we can use two iteractors to scan the elements, the first one is the scanning iterator, and the second one is the end iterator.

When the scanning iterator meets the end iterator, this array is exhausted.

So we can use a list of iterator pairs, for each level:
* if there are new arrays to scan, add its `begin` and `end` iterator into the list
* For iterator pairs in the list, visit each of them and add the corresponding elements to the result.
* We add the updated iterator pair into the end of the list if the array is not exhausted.

```cpp
// OJ: https://leetcode.com/problems/diagonal-traverse-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    typedef vector<int>::iterator iter;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& A) {
        vector<int> ans;
        int i = 0, N = A.size();
        list<pair<iter, iter>> q;
        while (i < N || q.size()) {
            if (i < N) {
                q.emplace_front(A[i].begin(), A[i].end());
                ++i;
            }
            int cnt = q.size();
            while (cnt--) {
                auto p = q.front();
                q.pop_front();
                ans.push_back(*p.first);
                p.first++;
                if (p.first != p.second) q.emplace_back(p.first, p.second);
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/diagonal-traverse-ii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& A) {
        vector<vector<int>> tmp;
        vector<int> ans;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[i].size(); ++j) {
                if (i + j == tmp.size()) tmp.emplace_back();
                tmp[i + j].push_back(A[i][j]);
            }
        }
        for (auto &row : tmp) {
            for (auto it = rbegin(row); it != rend(row); ++it) {
                ans.push_back(*it);
            }
        }
        return ans;
    }
};
```