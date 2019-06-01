// OJ: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Author: github.com/lzl124631x
// Time: O(C(N)) where N is the count of operators in `input` and C(N) is the Nth Catalan Number
// Space: O(C(N))
class Solution {
private:
    unordered_map<int, unordered_map<int, vector<int>>> m;
    vector<int> nums;
    vector<char> ops;
    vector<int> compute(int begin, int end) {
        if (!m[begin][end].empty()) return m[begin][end];
        if (begin + 1 == end) return m[begin][end] = { nums[begin] };
        vector<int> ans;
        for (int i = begin; i < end - 1; ++i) {
            auto as = compute(begin, i + 1), bs = compute(i + 1, end);
            for (auto a : as) {
                for (auto b : bs) {
                    switch (ops[i]) {
                        case '+': ans.push_back(a + b); break;
                        case '-': ans.push_back(a - b); break;
                        case '*': ans.push_back(a * b); break;
                    }
                }
            }
        }
        return m[begin][end] = ans;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        istringstream ss(input);
        while (true) {
            int num;
            ss >> num;
            nums.push_back(num);
            char c;
            if (ss >> c) ops.push_back(c);
            else break;
        }
        compute(0, nums.size());
        return m[0][nums.size()];
    }
};