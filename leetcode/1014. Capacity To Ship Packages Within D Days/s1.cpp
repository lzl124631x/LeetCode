// OJ: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Author: github.com/lzl124631x
// Time: O(W * L) where W is the sum of all weights, and L is the length of `weights`.
// Space: O(1)
class Solution {
private:
    bool ok(vector<int>& weights, int D, int capacity) {
        int d = 1, c = 0;
        for (int w : weights) {
            if (c + w > capacity) {
                c = 0;
                ++d;
                if (d > D) return false;
            }
            c += w;
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0, maxVal = 0;
        for (int w : weights) {
            sum += w;
            maxVal = max(maxVal, w);
        }
        int capacity = max((sum + D - 1) / D, maxVal);
        while (!ok(weights, D, capacity)) capacity++;
        return capacity;
    }
};