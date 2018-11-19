// OJ: https://leetcode.com/problems/image-overlap/
// Author: github.com/lzl124631x
// Time: O(N^2+AB) where A and B are the counts of 1s in image `A` and `B`.
// Space: O(N^2+AB)
// Ref: https://leetcode.com/problems/image-overlap/discuss/130623/C%2B%2BJavaPython-Straight-Forward
class Solution {
private:
    vector<int> flatten(vector<vector<int>>& A) {
        int N = A.size();
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] == 1) ans.push_back(i * 100 + j);
            }
        }
        return ans;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        auto va = flatten(A), vb = flatten(B);
        unordered_map<int, int> m;
        for (int i : va) {
            for (int j : vb) {
                m[i - j]++;
            }
        }
        int ans = 0;
        for (auto p : m) ans = max(ans, p.second);
        return ans;
    }
};