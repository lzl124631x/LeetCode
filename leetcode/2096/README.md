# [2096. Step-By-Step Directions From a Binary Tree Node to Another (Medium)](https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/)

<p>You are given the <code>root</code> of a <strong>binary tree</strong> with <code>n</code> nodes. Each node is uniquely assigned a value from <code>1</code> to <code>n</code>. You are also given an integer <code>startValue</code> representing the value of the start node <code>s</code>, and a different integer <code>destValue</code> representing the value of the destination node <code>t</code>.</p>

<p>Find the <strong>shortest path</strong> starting from node <code>s</code> and ending at node <code>t</code>. Generate step-by-step directions of such path as a string consisting of only the <strong>uppercase</strong> letters <code>'L'</code>, <code>'R'</code>, and <code>'U'</code>. Each letter indicates a specific direction:</p>

<ul>
	<li><code>'L'</code> means to go from a node to its <strong>left child</strong> node.</li>
	<li><code>'R'</code> means to go from a node to its <strong>right child</strong> node.</li>
	<li><code>'U'</code> means to go from a node to its <strong>parent</strong> node.</li>
</ul>

<p>Return <em>the step-by-step directions of the <strong>shortest path</strong> from node </em><code>s</code><em> to node</em> <code>t</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/15/eg1.png" style="width: 214px; height: 163px;">
<pre><strong>Input:</strong> root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
<strong>Output:</strong> "UURL"
<strong>Explanation:</strong> The shortest path is: 3 → 1 → 5 → 2 → 6.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/15/eg2.png" style="width: 74px; height: 102px;">
<pre><strong>Input:</strong> root = [2,1], startValue = 2, destValue = 1
<strong>Output:</strong> "L"
<strong>Explanation:</strong> The shortest path is: 2 → 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is <code>n</code>.</li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= Node.val &lt;= n</code></li>
	<li>All the values in the tree are <strong>unique</strong>.</li>
	<li><code>1 &lt;= startValue, destValue &lt;= n</code></li>
	<li><code>startValue != destValue</code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Tree](https://leetcode.com/tag/tree/), [Depth-First Search](https://leetcode.com/tag/depth-first-search/), [Binary Tree](https://leetcode.com/tag/binary-tree/)

**Similar Questions**:
* [Path Sum II (Medium)](https://leetcode.com/problems/path-sum-ii/)
* [Lowest Common Ancestor of a Binary Tree (Medium)](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
* [Binary Tree Paths (Easy)](https://leetcode.com/problems/binary-tree-paths/)
* [Find Distance in a Binary Tree (Medium)](https://leetcode.com/problems/find-distance-in-a-binary-tree/)

## Solution 1. DFS

```cpp
// OJ: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
public:
    string getDirections(TreeNode* root, int s, int d) {
        bool sm = false, dm = false; // `sm` = source node met
        int cnt = 0;
        string ans;
        function<void(TreeNode*, bool)> dfs = [&](TreeNode *root, bool isLeftChild) {
            if (cnt == 2 || !root) return; // If we've seen both nodes or the current node is NULL, skip
            int init = cnt;
            if (sm) ans += isLeftChild ? "L" : "R";
            else if (dm) ans += "U";
            if (root->val == s) {
                sm = true;
                ++cnt;
            } else if (root->val == d) {
                dm = true;
                ++cnt;
            }
            dfs(root->left, true);
            dfs(root->right, false);
            // When backtracking
            if (init == 0 && cnt == 1) { // If we met the first node
                if (sm) ans += "U"; // If it's source, add `U`
                else ans += isLeftChild ? "L" : "R"; // If it's dest, add `L/R`
            } else if (cnt == init && ans.size()) ans.pop_back(); // If the `cnt` doesn't change, the operation we did for this node is not useful.
        };
        dfs(root, false);
        if (ans.back() == 'U') reverse(begin(ans), end(ans));
        return ans;
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
    bool getPath(TreeNode *root, int val, string &ans) {
        if (!root) return false;
        if (root->val == val) return true;
        ans += 'L';
        if (getPath(root->left, val, ans)) return true;
        ans.back() = 'R';
        if (getPath(root->right, val, ans)) return true;
        ans.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int s, int d) {
        string a, b;
        getPath(root, s, a);
        getPath(root, d, b);
        int i = 0;
        while (i < a.size() && i < b.size() && a[i] == b[i]) ++i;
        return string(a.size() - i, 'U') + b.substr(i);
    }
};
```