// OJ: https://leetcode.com/problems/gray-code
// Auther: github.com/lzl124631x
// Time: O(2^N)
// Space: O(2^N)
class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> ans { 0 };
    unordered_set<int> s { 0 };
    int code = 0;
    n = pow(2, n);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 32; ++j) {
        code ^= (1 << j);
        if (!s.count(code)) break;
        code ^= (1 << j);
      }
      s.insert(code);
      ans.push_back(code);
    }
    return ans;
  }
};