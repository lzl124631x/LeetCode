// OJ: https://leetcode.com/problems/advantage-shuffle/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector<int> copy(B.begin(), B.end());
        sort(B.begin(), B.end());
        unordered_map<int, queue<int>> m;
        queue<int> leftover;
        int i = 0;
        for (int a : A) {
            if (a > B[i]) m[B[i++]].push(a);
            else leftover.push(a);
        }
        vector<int> ans;
        for (int b : copy) {
            if (m[b].size()) {
                ans.push_back(m[b].front());
                m[b].pop();
            } else {
                ans.push_back(leftover.front());
                leftover.pop();
            }
        }
        return ans;
    }
};