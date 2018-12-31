// OJ: https://leetcode.com/problems/count-the-repetitions/
// Author: github.com/lzl124631x
// Time: O(|s1| * n1) where |s1| is the length of s1
// Space: O(n1)
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_map<int, int> kToRepeatCount;
        unordered_map<int, int> nextIndexToK;
        kToRepeatCount[0] = 0;
        nextIndexToK[0] = 0;
        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    ++j;
                    if (j == s2.size()) {
                        j = 0;
                        ++cnt;
                    }
                }
            }
            if (nextIndexToK.find(j) != nextIndexToK.end()) {
                int start = nextIndexToK[j];
                int prefixCount = kToRepeatCount[start];
                int patternCount = (n1 - start) / (k - start) * (cnt - prefixCount);
                int suffixCount = kToRepeatCount[start + (n1 - start) % (k - start)] - prefixCount;
                return (prefixCount + patternCount + suffixCount) / n2;
            }
            kToRepeatCount[k] = cnt;
            nextIndexToK[j] = k;
        }
        return kToRepeatCount[n1] / n2;
    }
};