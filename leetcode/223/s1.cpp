// OJ: https://leetcode.com/problems/rectangle-area
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
  int area(int a, int b, int c, int d) {
    return (c > a ? c - a : 0) * (d > b ? d - b : 0);
  }
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int a = max(A, E), b = max(B, F), c = min(C, G), d = min(D, H);
    return area(A, B, C, D) + area(E, F, G, H) - area(a, b, c, d);
  }
};