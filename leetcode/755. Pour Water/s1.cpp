// OJ: https://leetcode.com/problems/pour-water/
// Author: github.com/lzl124631x
// Time: O(VN)
// Space: O(1)
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        while (V--) {
            int leftMin = K;
            for (int i = K - 1; i >= 0; --i) {
                if (heights[i] < heights[leftMin]) leftMin = i;
                if (heights[i] > heights[leftMin]) break;
            }
            if (leftMin != K) {
                heights[leftMin]++;
                continue;
            }
            int rightMin = K;
            for (int i = K + 1; i < heights.size(); ++i) {
                if (heights[i] < heights[rightMin]) rightMin = i;
                if (heights[i] > heights[rightMin]) break;
            }
            if (rightMin != K) {
                heights[rightMin]++;
                continue;
            }
            heights[K]++;
        }
        return heights;
    }
};