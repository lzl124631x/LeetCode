// OJ: https://leetcode.com/problems/bulb-switcher-iii/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int numTimesAllBlue(vector<int>& A) {
        int N = A.size(), ans = 0, on = 0, blue = 0;
        vector<int> v(N, 0);
        for (int n : A) {
            int i = n - 1;
            v[i] = 1;
            on++;
            while (i < N && v[i] > 0 && (i == 0 || v[i - 1] == 2)) {
                if (v[i] == 1) blue++;
                v[i++] = 2;
            } 
            if (on == blue) ++ans;
        }
        return ans;
    }
};