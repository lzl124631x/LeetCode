# [559. Maximum Depth of N-ary Tree (Easy)](https://leetcode.com/problems/maximum-depth-of-n-ary-tree/)

<p>Given a n-ary tree, find its maximum depth.</p>

<p>The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.</p>

<p>For example, given a <code>3-ary</code> tree:</p>
&nbsp;

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png" style="width: 100%; max-width: 300px;"></p>

<p>&nbsp;</p>

<p>We should return its max depth, which is 3.</p>

<p>&nbsp;</p>

<p><b>Note:</b></p>

<ol>
	<li>The depth of the tree is at most <code>1000</code>.</li>
	<li>The total number of nodes is at most <code>5000</code>.</li>
</ol>


## Solution 1. Recursive

```cpp
// OJ: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;
        int maxd = 0;
        for (auto ch : root->children) {
            maxd = max(maxd, maxDepth(ch));
        }
        return 1 + maxd;
    }
};
```