// OJ: https://leetcode.com/problems/random-pick-with-weight/
// Author: github.com/lzl124631x
// Time: O(W)
// Space: O(W)
class Solution {
private:
    int sum;
    vector<int> w;
public:
    Solution(vector<int> w): w(w) {
        srand (time(NULL));
        sum = accumulate(w.begin(), w.end(), 0);
    }
    
    int pickIndex() {
        int r = rand() % sum;
        for (int i = 0; i < w.size(); ++i) {
            r -= w[i];
            if (r < 0) return i;
        }
    }
};