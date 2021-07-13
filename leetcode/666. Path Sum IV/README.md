# [666. Path Sum IV (Medium)](https://leetcode.com/problems/path-sum-iv/)

<p>If the depth of a tree is smaller than <code>5</code>, then this tree can be represented by an array of three-digit integers. For each integer in this array:</p>

<ul>
	<li>The hundreds digit represents the depth <code>d</code> of this node where <code>1 &lt;= d &lt;= 4</code>.</li>
	<li>The tens digit represents the position <code>p</code> of this node in the level it belongs to where <code>1 &lt;= p &lt;= 8</code>. The position is the same as that in a full binary tree.</li>
	<li>The units digit represents the value <code>v</code> of this node where <code>0 &lt;= v &lt;= 9</code>.</li>
</ul>

<p>Given an array of <strong>ascending</strong> three-digit integers <code>nums</code> representing a binary tree with a depth smaller than <code>5</code>, return <em>the sum of all paths from the root towards the leaves</em>.</p>

<p>It is <strong>guaranteed</strong> that the given array represents a valid connected binary tree.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/30/pathsum4-1-tree.jpg" style="width: 212px; height: 183px;">
<pre><strong>Input:</strong> nums = [113,215,221]
<strong>Output:</strong> 12
<strong>Explanation:</strong> The tree that the list represents is shown.
The path sum is (3 + 5) + (3 + 1) = 12.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/30/pathsum4-2-tree.jpg" style="width: 132px; height: 183px;">
<pre><strong>Input:</strong> nums = [113,221]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The tree that the list represents is shown. 
The path sum is (3 + 1) = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 15</code></li>
	<li><code>110 &lt;= nums[i] &lt;= 489</code></li>
	<li><code>nums</code> represents a valid binary tree with depth less than <code>5</code>.</li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Path Sum (Easy)](https://leetcode.com/problems/path-sum/)
* [Path Sum II (Medium)](https://leetcode.com/problems/path-sum-ii/)
* [Binary Tree Maximum Path Sum (Hard)](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
* [Path Sum III (Medium)](https://leetcode.com/problems/path-sum-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/path-sum-iv/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n / 10] = n % 10;
        }
        int sum = 0;
        for (int n : nums) {
            int d = n / 100, p = n / 10 % 10, v = m[d * 10 + p];
            int left = (d + 1) * 10 + p * 2 - 1, right = left + 1;
            if (m.count(left)) m[left] += v;
            if (m.count(right)) m[right] += v;
            if (m.count(left) == 0 && m.count(right) == 0) sum += v;
        }
        return sum;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/path-sum-iv/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    int vals[33] = {[0 ... 32] = -1}, ans = 0;
    void dfs(int i, int sum) {
        if (vals[i] == -1) return;
        sum += vals[i];
        int left = 2 * i, right = 2 * i + 1;
        if (vals[left] == -1 && vals[right] == -1) {
            ans += sum;
            return;
        }
        dfs(left, sum);
        dfs(right, sum);
    }
public:
    int pathSum(vector<int>& A) {
        for (int n : A) {
            int lv = n / 100, index = n % 100 / 10, val = n % 10, i = (1 << (lv - 1)) - 1 + index;
            vals[i] = val;
        }
        dfs(1, 0);
        return ans;
    }
};
```