# [1424. Diagonal Traverse II (Medium)](https://leetcode.com/problems/diagonal-traverse-ii/)

Given a list of lists of integers,&nbsp;<code>nums</code>,&nbsp;return all elements of <code>nums</code> in diagonal order as shown in the below images.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/04/08/sample_1_1784.png" style="width: 158px; height: 143px;"></strong></p>

<pre><strong>Input:</strong> nums = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [1,4,2,7,5,3,8,6,9]
</pre>

<p><strong>Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/04/08/sample_2_1784.png" style="width: 230px; height: 177px;"></strong></p>

<pre><strong>Input:</strong> nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
<strong>Output:</strong> [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [[1,2,3],[4],[5,6,7],[8],[9,10,11]]
<strong>Output:</strong> [1,4,2,5,3,8,6,9,7,10,11]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> nums = [[1,2,3,4,5,6]]
<strong>Output:</strong> [1,2,3,4,5,6]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10^5</code></li>
	<li><code>1 &lt;= nums[i].length &lt;=&nbsp;10^5</code></li>
	<li><code>1 &lt;= nums[i][j] &lt;= 10^9</code></li>
	<li>There at most <code>10^5</code> elements in <code>nums</code>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

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
        unordered_map<int, vector<int>> m;
        int N = A.size(), maxKey = 0, cnt = 0;
        for (int i = N - 1; i >= 0; --i) {
            int M = A[i].size();
            cnt += M;
            for (int j = M - 1; j >= 0; --j) {
                m[i + j].push_back(A[i][j]);
                maxKey = max(maxKey, i + j);
            }
        }
        vector<int> ans;
        ans.reserve(cnt);
        for (int i = 0; i <= maxKey; ++i) {
            for (int n : m[i]) ans.push_back(n);
        }
        return ans;
    }
};
```