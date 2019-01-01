// OJ: https://leetcode.com/problems/quad-tree-intersection/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1->isLeaf) return quadTree1->val ? quadTree1 : quadTree2;
        if (quadTree2->isLeaf) return quadTree2->val ? quadTree2 : quadTree1;
        auto tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
        auto tr = intersect(quadTree1->topRight, quadTree2->topRight);
        auto bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        auto br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        int val = tl->val;
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf
            && val == tr->val && val == bl->val && val == br->val) {
            delete tl;
            delete tr;
            delete bl;
            delete br;
            return new Node(val, true, NULL, NULL, NULL, NULL);
        }
        return new Node(false, false, tl, tr, bl, br);
    }
};