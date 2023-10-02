// OJ: https://leetcode.com/problems/n-repeated-element-in-size-2n-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/discuss/208317/C%2B%2B-4-lines-O(n)-or-O-(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
      for (int i = 0; i < A.size() - 2; ++i) {
          if (A[i + 1] == A[i + 2]) return A[i + 1];
          if (A[i] == A[i + 1] || A[i] == A[i + 2]) return A[i];
      }
      return A[0]; 
    }
};