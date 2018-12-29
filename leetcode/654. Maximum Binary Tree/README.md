# [654. Maximum Binary Tree (Medium)](https://leetcode.com/problems/maximum-binary-tree/)

<p>
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
</p><ol>
<li>The root is the maximum number in the array. </li>
<li>The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.</li>
<li>The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.</li> 
</ol>
<p></p>

<p>
Construct the maximum tree by the given array and output the root node of this tree.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> [3,2,1,6,0,5]
<b>Output:</b> return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
</pre>
<p></p>

<p><b>Note:</b><br>
</p><ol>
<li>The size of the given array will be in the range [1,1000].</li>
</ol>
<p></p>

**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/maximum-binary-tree/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    TreeNode *build(vector<int> &nums, int start, int end) {
        if (start >= end) return NULL;
        if (start + 1 == end) return new TreeNode(nums[start]);
        int best = start;
        for (int i = start; i < end; ++i) {
            if (nums[i] > nums[best]) best = i;
        }
        auto node = new TreeNode(nums[best]);
        node->left = build(nums, start, best);
        node->right = build(nums, best + 1, end);
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size());
    }
};
```