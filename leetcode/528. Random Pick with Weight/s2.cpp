// OJ: https://leetcode.com/problems/random-pick-with-weight/
// Author: github.com/lzl124631x
// Time: O(log(W))
// Space: O(W)
class Solution {
private:
    vector<int> bounds;
public:
    Solution(vector<int> w) {
        srand (time(NULL));
        int sum = 0;
        for (int i : w) bounds.push_back(sum += i);
    }
    
    int pickIndex() {
        int r = 1 + (rand() % bounds.back());
        int L = 0, R = bounds.size();
        while (L < R) {
            int M = (L + R) / 2;
            if (bounds[M] < r) L = M + 1;
            else R = M;
        }
        return L;
    }
};