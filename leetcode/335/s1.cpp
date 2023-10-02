// https://discuss.leetcode.com/topic/38014/java-oms-with-explanation
// 3 cases of self-crossing
// 1. 4th x 1st.
// 2. 5th x 1st.
// 3. 6th x 1st.
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int N = x.size();
        if (N <= 3) return false;
        for (int i = 3; i < N; ++i) {
            if ((x[i] >= x[i - 2] && x[i - 1] <= x[i - 3])
            || (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2])
            || (i >= 5 && x[i - 2] - x[i - 4] >= 0 && x[i] >= x[i - 2] - x[i - 4] && x[i - 1] >= x[i - 3] - x[i - 5] && x[i - 1] <= x[i - 3])
            ) return true; 
        }
        return false;
    }
};