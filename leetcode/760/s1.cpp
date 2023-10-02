// OJ: https://leetcode.com/problems/find-anagram-mappings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> m;
        for (int i = 0; i < B.size(); ++i) m[B[i]] = i;
        vector<int> ans;
        for (int n : A) ans.push_back(m[n]);
        return ans;
    }
};