// OJ: https://leetcode.com/problems/rectangle-overlap
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (rec2[0] < rec1[2] && rec2[2] > rec1[0]
               && rec1[1] < rec2[3] && rec1[3] > rec2[1]);
    }
};