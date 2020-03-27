// OJ: https://leetcode.com/problems/validate-binary-tree-nodes/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n);
        for (int i = 0; i < n; ++i) {
            int L = leftChild[i], R = rightChild[i];
            if (L != -1 && indegree[L]++) return false; // if the indegree is more than 1, return false
            if (R != -1 && indegree[R]++) return false;
        }
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (indegree[i]) continue;
            if (root != -1) return false; // if more than one node with 0 indegree, return false
            root = i;
        }
        return root != -1 && (n == 1 || leftChild[root] != -1 || rightChild[root] != -1); // root must exist, and the root must have out-degree unless there is only one node
    }
};