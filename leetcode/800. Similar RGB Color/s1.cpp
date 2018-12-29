// OJ: https://leetcode.com/problems/similar-rgb-color/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
    const string digits = "0123456789abcdef";
public:
    string similarRGB(string color) {
        string ans = "#";
        for (int i = 0; i < 3; ++i) {
            char a = color[1 + i * 2], b = color[2 + i * 2];
            int hex1 = stoi(color.substr(1 + i * 2, 2), nullptr, 16);
            int best = 0, bestSim = INT_MIN;
            for (int j = 0; j < 16; ++j) {
                int hex2 = j * 16 + j;
                int sim = -pow(hex1 - hex2, 2);
                if (sim > bestSim) {
                    bestSim = sim;
                    best = j;
                }
            }
            char c = digits[best];
            ans += c;
            ans += c;
        }
        return ans;
    }
};