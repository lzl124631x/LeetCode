// OJ: https://leetcode.com/problems/strobogrammatic-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    bool same(char a, char b) {
        return a == b && (a == '0' || a == '1' || a == '8');
    }
    bool match(char a, char b) {
        if (a > b) swap(a, b);
        return same(a, b) || (a == '6' && b == '9');
    }
public:
    bool isStrobogrammatic(string num) {
        int i = 0, j = num.size() - 1;
        for (; i <= j; ++i, --j) {
            if ((i != j && !match(num[i], num[j]))
               || (i == j && !same(num[i], num[j]))) return false;
        }
        return true;
    }
};