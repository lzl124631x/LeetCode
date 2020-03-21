// OJ: https://leetcode.com/problems/cinema-seat-allocation/
// Author: github.com/lzl124631x
// Time: O(SlogS)
// Space: O(1)
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& A) {
        sort(A.begin(), A.end());
        int ans = 2 * n, i = 0, N = A.size();
        while (i < N) {
            vector<int> v(4,1);
            int j = i;
            for (;j < N && A[i][0] == A[j][0];++j) {
                if (A[j][1] == 1 || A[j][1] == 10) continue;
                v[A[j][1]/2-1] = 0;
            }
            int c = 0;
            if (v[0] && v[1]) ++c;
            if (v[2] && v[3]) ++c;
            if (!c && v[1] && v[2]) ++c;
            i = j;
            ans -= 2 - c;
        }
        return ans;
    }
};