// OJ: https://leetcode.com/problems/queries-on-a-permutation-with-key/
// Author: github.com/lzl124631x
// Time: O(MN)
// Space: O(M)
class Solution {
public:
    vector<int> processQueries(vector<int>& Q, int m) {
        int N = Q.size();
        vector<int> v(m), ans;
        for (int i = 0; i < m; ++i) v[i] = i+1;
        for (int q : Q) {
            int i = 0;
            for (; i < m && v[i] != q; ++i);
            ans.push_back(i);
            for (int j = i; j > 0; --j) v[j] = v[j - 1];
            v[0] = q;
        }
        return ans;
    }
};