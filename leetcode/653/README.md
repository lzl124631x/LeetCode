# [653. Two Sum IV - Input is a BST (Easy)](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

<p>Given the <code>root</code> of a Binary Search Tree and a target number <code>k</code>, return <em><code>true</code> if there exist two elements in the BST such that their sum is equal to the given target</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/sum_tree_1.jpg" style="width: 562px; height: 322px;">
<pre><strong>Input:</strong> root = [5,3,6,2,4,null,7], k = 9
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/21/sum_tree_2.jpg" style="width: 562px; height: 322px;">
<pre><strong>Input:</strong> root = [5,3,6,2,4,null,7], k = 28
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> root = [2,1,3], k = 4
<strong>Output:</strong> true
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> root = [2,1,3], k = 1
<strong>Output:</strong> false
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> root = [2,1,3], k = 3
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>4</sup>&nbsp;&lt;= Node.val &lt;= 10<sup>4</sup></code></li>
	<li><code>root</code> is guaranteed to be a <strong>valid</strong> binary search tree.</li>
	<li><code>-10<sup>5</sup>&nbsp;&lt;= k &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Breadth-First Search](https://leetcode.com/tag/breadth-first-search/), [Binary Search Tree](https://leetcode.com/tag/binary-search-tree/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Two Sum II - Input array is sorted (Easy)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
* [Two Sum III - Data structure design (Easy)](https://leetcode.com/problems/two-sum-iii-data-structure-design/)
* [Two Sum BSTs (Medium)](https://leetcode.com/problems/two-sum-bsts/)

## Solution 1.

For each node with value `num` (`2 * num != target`), find if `target - num` is in the BST.

This solution is good when the BST is balanced, i.e. `H = logN`. But when the BST is skewed, this solution degrades to `O(N^2)` time complexity and `O(N)` space.

```cpp
// OJ: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/solution/
// Author: github.com/lzl124631x
// Time: O(NH)
// Space: O(H)
class Solution {
    bool dfs(TreeNode *root, int k, int mn = INT_MIN, int mx = INT_MAX) {
        if (!root || root->val <= mn || root->val >= mx) return false;
        if (root->val == k) return true;
        return root->val < k ? dfs(root->right, k, root->val, mx) : dfs(root->left, k, mn, root->val);
    }
    bool find(TreeNode *root, int k, TreeNode *from) {
        if (!root) return false;
        if (2 * root->val != k && dfs(from, k - root->val)) return true;
        return find(root->left, k, from) || find(root->right, k, from);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return find(root, k, root);
    }
};
```

## Solution 2. Preorder Traversal + Unordered Set

This solution doesn't leverage the nature of the BST. It's a two sum solution using an `unordered_set`.

```cpp
// OJ: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    unordered_set<int> s;
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (s.count(k - root->val)) return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
```

## Solution 2. Inorder Traversal + Two Pointers

```cpp
// OJ: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    vector<int> v;
    void inorder(TreeNode *root) {
        if (!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int i = 0, j = v.size() - 1;
        while (i < j) {
            int sum = v[i] + v[j];
            if (sum == k) return true;
            if (sum > k) --j;
            else ++i;
        }
        return false;
    }
};
```