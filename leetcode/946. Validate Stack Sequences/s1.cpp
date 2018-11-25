// OJ: https://leetcode.com/problems/validate-stack-sequences/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int p = 0;
        for (int i : pushed) {
            s.push(i);
            while (s.size() && s.top() == popped[p]) {
                s.pop();
                ++p;
            }
        }
        return s.empty();
    }
};