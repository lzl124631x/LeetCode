// OJ: https://leetcode.com/problems/construct-binary-tree-from-string
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(logN)
class Solution {
private:
  TreeNode* rec(string &s, int begin, int end, TreeNode *p) {
    if (begin >= end) return NULL;
    int i = begin;
    while (i < end && s[i] == '-' || isdigit(s[i])) ++i;
    TreeNode *node = new TreeNode(stoi(s.substr(begin, i - begin)));
    if (p) {
      if (!p->left) p->left = node;
      else p->right = node;
    }
    if ((begin = i) < end) {
      int leftCnt = 1;
      for (i = begin + 1; leftCnt && i < end; ++i) {
        if (s[i] == '(') ++leftCnt;
        else if (s[i] == ')') --leftCnt;
      }
      rec(s, begin + 1, i - 1, node);
      rec(s, i + 1, end - 1, node);
    }
    return node;
  }
public:
  TreeNode* str2tree(string s) {
    return rec(s, 0, s.size(), NULL);
  }
};