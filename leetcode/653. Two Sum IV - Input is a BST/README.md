# [653. Two Sum IV - Input is a BST (Easy)](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

<p>Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

<b>Output:</b> True
</pre>
<p></p>


<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

<b>Output:</b> False
</pre>
<p></p>



**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [Two Sum II - Input array is sorted (Easy)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
* [Two Sum III - Data structure design (Easy)](https://leetcode.com/problems/two-sum-iii-data-structure-design/)

## Solution 1.

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