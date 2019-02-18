# [333. Largest BST Subtree (Medium)](https://leetcode.com/problems/largest-bst-subtree/)

<p>Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.</p>

<p><b>Note:</b><br>
A subtree must include all of its descendants.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input: </strong>[10,5,15,1,8,null,7]

   10 
   / \ 
<font color="red">  5</font>  15 
<font color="red"> / \</font>   \ 
<font color="red">1   8</font>   7

<strong>Output:</strong> 3
<strong>Explanation: </strong>The Largest BST Subtree in this case is the highlighted one.
             The return value is the subtree's size, which is 3.
</pre>

<p><b>Follow up:</b><br>
Can you figure out ways to solve it with O(n) time complexity?</p>


**Companies**:  
[Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-bst-subtree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
    bool postorder(TreeNode *root, int &minVal, int &maxVal, int &largestBSTSize) {
        if (!root) {
            largestBSTSize = 0;
            return true;
        }
        int leftMin, leftMax, leftCnt, rightMin, rightMax, rightCnt;
        bool left = postorder(root->left, leftMin, leftMax, leftCnt);
        bool right = postorder(root->right, rightMin, rightMax, rightCnt);
        if (left && right && (!leftCnt || root->val > leftMax) && (!rightCnt || root->val < rightMin)) {
            minVal = leftCnt ? leftMin : root->val;
            maxVal = rightCnt ? rightMax : root->val;
            largestBSTSize = leftCnt + rightCnt + 1;
            return true;
        }
        largestBSTSize = max(1, max(leftCnt, rightCnt));
        return false;
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        int minVal, maxVal, largestBSTSize;
        postorder(root, minVal, maxVal, largestBSTSize);
        return largestBSTSize;
    }
};
```