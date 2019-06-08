// OJ: https://leetcode.com/problems/letter-tile-possibilities/
// Author: github.com/lzl124631x
// Time: O(2^N)
// Space: O(N)
class Solution {
private:
    int ans = 0, cnts[26] = {};
    long long count(int n) {
        long long val = 1;
        for (int i = 1; i <= n; ++i) val *= i;
        return val;
    }
    void updateAns() {
        long long total = 0, div = 1;
        for (int i = 0; i < 26; ++i) {
            total += cnts[i];
            div *= count(cnts[i]);
        }
        ans += count(total) / div;
    }
    void compute(string &A, int begin) {
        if (begin == A.size()) {
            updateAns();
            return;
        }
        cnts[A[begin] - 'A']++;
        compute(A, begin + 1);
        cnts[A[begin] - 'A']--;
        do { ++begin; } while (begin < A.size() && A[begin] == A[begin - 1]);
        compute(A, begin);
    }
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        compute(tiles, 0);
        return ans - 1;
    }
};