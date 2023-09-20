# [437. Path Sum III (Medium)](https://leetcode.com/problems/path-sum-iii/)

<p>Given the <code>root</code> of a binary tree and an integer <code>targetSum</code>, return <em>the number of paths where the sum of the values&nbsp;along the path equals</em>&nbsp;<code>targetSum</code>.</p>

<p>The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/09/pathsum3-1-tree.jpg" style="width: 450px; height: 386px;">
<pre><strong>Input:</strong> root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
<strong>Output:</strong> 3
<strong>Explanation:</strong> The paths that sum to 8 are shown.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 1000]</code>.</li>
	<li><code>-10<sup>9</sup> &lt;= Node.val &lt;= 10<sup>9</sup></code></li>
	<li><code>-1000 &lt;= targetSum &lt;= 1000</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Bloomberg](https://leetcode.com/company/bloomberg), [Oracle](https://leetcode.com/company/oracle), [Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Path Sum (Easy)](https://leetcode.com/problems/path-sum/)
* [Path Sum II (Medium)](https://leetcode.com/problems/path-sum-ii/)
* [Path Sum IV (Medium)](https://leetcode.com/problems/path-sum-iv/)
* [Longest Univalue Path (Medium)](https://leetcode.com/problems/longest-univalue-path/)

## Solution 1. Post-order Traversal

```cpp
// OJ: https://leetcode.com/problems/path-sum-iii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N^2)
class Solution {
    int ans = 0;
    unordered_map<int, int> dfs(TreeNode *root, int sum) { // map of sums from the current node to a child node
        if (!root) return {};
        unordered_map<int, int> m{{root->val, 1}};
        auto left = dfs(root->left, sum), right = dfs(root->right, sum);
        for (auto &[val, cnt] : left) m[val + root->val] += cnt;
        for (auto &[val, cnt] : right) m[val + root->val] += cnt;
        if (m.count(sum)) ans += m[sum];
        return m;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ans;
    }
};
```

## Solution 2. Pre-order Traversal

```cpp
// OJ: https://leetcode.com/problems/path-sum-iii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(H)
class Solution {
private:
    int cnt = 0;
    void pathSum(TreeNode* root, int target, int sum) {
        if (!root) return;
        sum += root->val;
        if (sum == target) cnt++;
        pathSum(root->left, target, sum);
        pathSum(root->right, target, sum);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        pathSum(root, sum, 0);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return cnt;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/path-sum-iii/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(H)
class Solution {
private:
    int pathSum(TreeNode* root, int target, int sum) { // count the paths starting from an acestor node to the current node whose sum equals `target`.
        return root ? ((sum += root->val) == target) + pathSum(root->left, target, sum) + pathSum(root->right, target, sum) : 0;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        return root ? pathSum(root, sum, 0) + pathSum(root->left, sum) + pathSum(root->right, sum) : 0;
    }
}
```

## Solution 3. Pre-order Traversal with Prefix State Map

Note:
* Initially the map should have an entry `m[0] = 1` so that we can count those paths starting from root.
* `m[sum]++` should go after accessing `m[sum - targetSum]`, because `m` stores the frequencies of path sums of the **parent** paths, excluding the current path. One corner case to consider is `targetSum = 0`. In this case, `sum - targetSum == sum`, so if we do `m[sum]++` before accessing `m[sum - targetSum]`, we'll regard the path to the current node as a parent path, which is wrong.

```cpp
// OJ: https://leetcode.com/problems/path-sum-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method
class Solution {
    unordered_map<long long, int> m{{0,1}}; // map from the path sum (from root to a parent node) to the corresponding count
public:
    int pathSum(TreeNode* root, int targetSum, long long sum = 0) {
        if (!root) return 0;
        sum += root->val;
        int ans = m.count(sum - targetSum) ? m[sum - targetSum] : 0;
        m[sum]++; // note that we should do this increment after accessing `m[sum - targetSum]`. Example case: root=[1], targetSum=0
        ans += pathSum(root->left, targetSum, sum) + pathSum(root->right, targetSum, sum);
        if (--m[sum] == 0) m.erase(sum);
        return ans;
    }
};
```