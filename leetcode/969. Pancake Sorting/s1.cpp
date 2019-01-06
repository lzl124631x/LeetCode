// OJ: https://leetcode.com/problems/pancake-sorting
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        for (int i = A.size(); i > 0; --i) {
            int j = i - 1;
            for (; j >= 0 && A[j] != i; --j);
            reverse(A.begin(), A.begin() + j + 1);
            ans.push_back(j + 1);
            reverse(A.begin(), A.begin() + i);
            ans.push_back(i);
        }
        return ans;
    }
};