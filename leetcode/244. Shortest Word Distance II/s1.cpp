// OJ: https://leetcode.com/problems/shortest-word-distance-ii/
// Author: github.com/lzl124631x
// Time:
//     * WordDistance: O(N)
//     * shortest: O(N)
// Space: O(N)
class WordDistance {
private:
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            m[words[i]].push_back(i);
        }
    }
    int shortest(string word1, string word2) {
        auto &a = m[word1], &b = m[word2];
        int i = 0, j = 0, dist = INT_MAX;
        while (i < a.size() && j < b.size() && dist > 1) {
            dist = min(dist, abs(a[i] - b[j]));
            if (a[i] > b[j]) ++j;
            else ++i;
        }
        return dist;
    }
};