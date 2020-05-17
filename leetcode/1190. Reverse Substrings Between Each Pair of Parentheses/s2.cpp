// OJ: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
// Ref: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/discuss/383670/JavaC%2B%2BPython-Why-not-O(N)
class Solution {
public:
    string reverseParentheses(string s) {
        int N = s.size();
        vector<int> open, pair(N);
        for (int i = 0; i < N; ++i) {
            if (s[i] == '(') open.push_back(i);
            else if (s[i] == ')') {
                int j = open.back();
                open.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string ans;
        for (int i = 0, d = 1; i < N; i += d) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                d = -d;
            } else ans += s[i];
        }
        return ans;
    }
};