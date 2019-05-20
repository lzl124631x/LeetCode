// OJ: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
private:
    unordered_map<int, int> m;
    int find(int num) {
        if (num < 2) return 0;
        if (m.find(num) != m.end()) return m[num];
        int k = log2(num), p = pow(2, k);
        int ans = find(p - 1);
        if (num > p / 2 * 3 - 1) ans += num - p / 2 * 3 + 1 + find(p / 2 - 1);
        else ans += find(num - p);
        return m[num] = ans;
    }
public:
    int findIntegers(int num) {
        return num + 1 - find(num);
    }
};