// OJ: https://leetcode.com/problems/optimal-division/
// Author: github.com/lzl124631x
// Time: O(N^3)
// Space: O(N^3)
class Pair {
private:
    bool isNum;
    int num;
    Pair *numerator, *denominator;
    float val;
public:
    Pair(int n) : isNum(true), num(n), val(n) {}
    Pair(Pair* n, Pair* d) : isNum(false), numerator(n), denominator(d), val(numerator->val / denominator->val) {}
    float value() { return val; }
    string toString() {
        if (isNum) return to_string(num);
        string ans;
        ans = numerator->toString() + "/";
        if (!denominator->isNum) ans += "(";
        ans += denominator->toString();
        if (!denominator->isNum) ans += ")";
        return ans;
    }
};
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        unordered_map<int, unordered_map<int, Pair*>> great, small;
        for (int i = 0; i < nums.size(); ++i)
            great[i][i + 1] = small[i][i + 1] = new Pair(nums[i]);
        for (int len = 2; len <= nums.size(); ++len) {
            for (int i = 0; i < nums.size() - len + 1; ++i) {
                Pair *greatest = NULL, *smallest = NULL;
                for (int j = i + 1; j < i + len; ++j) {
                    if (!greatest || greatest->value() < great[i][j]->value() / small[j][i + len]->value()) {
                        greatest = new Pair(great[i][j], small[j][i + len]);
                    }
                    if (!smallest || smallest->value() > small[i][j]->value() / great[j][i + len]->value()) {
                        smallest = new Pair(small[i][j], great[j][i + len]);
                    }
                }
                great[i][i + len] = greatest;
                small[i][i + len] = smallest;
            }
        }
        return great[0][nums.size()]->toString();
    }
};