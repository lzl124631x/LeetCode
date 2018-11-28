# [270. Closest Binary Search Tree Value (Easy)](https://leetcode.com/problems/closest-binary-search-tree-value/)

<p>Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.</p>

<p><b>Note:</b></p>

<ul>
	<li>Given target value is a floating point.</li>
	<li>You are guaranteed to have only one unique value in the BST that is closest to the target.</li>
</ul>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

<strong>Output:</strong> 4
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Count Complete Tree Nodes (Medium)](https://leetcode.com/problems/count-complete-tree-nodes/)
* [Closest Binary Search Tree Value II (Hard)](https://leetcode.com/problems/closest-binary-search-tree-value-ii/)
* [Search in a Binary Search Tree (Easy)](https://leetcode.com/problems/search-in-a-binary-search-tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/closest-binary-search-tree-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        double dist = abs(target - root->val);
        if (dist < .5) return root->val;
        if (root->val < target) {
            if (!root->right) return root->val;
            int right = closestValue(root->right, target);
            return dist < abs(target - right) ? root->val : right;
        }
        if (!root->left) return root->val;
        int left = closestValue(root->left, target);
        return dist < abs(target - left) ? root->val : left;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/closest-binary-search-tree-value/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
// Ref: https://leetcode.com/problems/closest-binary-search-tree-value/discuss/70331/Clean-and-concise-java-solution
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int ans = root->val;
        while (root) {
            if (abs(target - root->val) < abs(target - ans)) ans = root->val;
            root = root->val > target ? root->left : root->right;
        }
        return ans;
    }
};
```