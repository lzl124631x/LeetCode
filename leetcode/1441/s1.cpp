// OJ: https://leetcode.com/contest/weekly-contest-188/problems/build-an-array-with-stack-operations/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<string> buildArray(vector<int>& A, int n) {
        vector<string> ans;
        int i = 1, j = 0;
        while (j < A.size()) {
            while (i != A[j]) {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++i;
            } 
            ans.push_back("Push");
            ++i;
            ++j;
        }
        return ans;
    }
};