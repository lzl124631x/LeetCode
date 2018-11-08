// OJ: https://leetcode.com/problems/4sum-ii
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
private:
    void sum(vector<int> &A, vector<int> &B, map<int, int> &m) {
        for (auto a : A) {
            for (auto b : B) m[a + b]++;
        }
    }
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> a, b;
        sum(A, B, a);
        sum(C, D, b);
        auto i = a.begin();
        auto j = b.rbegin();
        int ans = 0;
        while (i != a.end() && j != b.rend()) {
            if (i->first + j->first == 0) {
                ans += i->second * j->second;
                ++i;
                ++j;
            } else if (i->first + j->first < 0) ++i;
            else ++j;
        }
        return ans;
    }
};