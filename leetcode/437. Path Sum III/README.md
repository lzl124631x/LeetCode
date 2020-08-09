# [437. Path Sum III (Medium)](https://leetcode.com/problems/path-sum-iii/)

<p>You are given a binary tree in which each node contains an integer value.</p>

<p>Find the number of paths that sum to a given value.</p>

<p>The path does not need to start or end at the root or a leaf, but it must go downwards
(traveling only from parent nodes to child nodes).</p>

<p>The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

</p><p><b>Example:</b>
</p><pre>root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    <b>5</b>   <b>-3</b>
   <b>/</b> <b>\</b>    <b>\</b>
  <b>3</b>   <b>2</b>   <b>11</b>
 / \   <b>\</b>
3  -2   <b>1</b>

Return 3. The paths that sum to 8 are:

1.  5 -&gt; 3
2.  5 -&gt; 2 -&gt; 1
3. -3 -&gt; 11
</pre>
<p></p>

**Related Topics**:  
[Tree](https://leetcode.com/tag/tree/)

**Similar Questions**:
* [Path Sum (Easy)](https://leetcode.com/problems/path-sum/)
* [Path Sum II (Medium)](https://leetcode.com/problems/path-sum-ii/)
* [Path Sum IV (Medium)](https://leetcode.com/problems/path-sum-iv/)
* [Longest Univalue Path (Easy)](https://leetcode.com/problems/longest-univalue-path/)

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

## Solution 3. Pre-order Traversal with Hash Map

```cpp
// OJ: https://leetcode.com/problems/path-sum-iii/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/path-sum-iii/discuss/91878/17-ms-O(n)-java-Prefix-sum-method
class Solution {
    unordered_map<int, int> m; // map from the path sum (from root to the current node) to the corresponding count
    int dfs(TreeNode *root, int target, int sum) {
        if (!root) return 0;
        sum += root->val;
        int ans = m.count(sum - target) ? m[sum - target] : 0;
        m[sum]++; 
        ans += dfs(root->left, target, sum) + dfs(root->right, target, sum);
        if (--m[sum] == 0) m.erase(sum);
        return ans;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        m[0] = 1;
        return dfs(root, sum, 0);
    }
};
```