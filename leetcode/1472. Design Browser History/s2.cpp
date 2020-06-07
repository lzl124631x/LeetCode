// OJ: https://leetcode.com/problems/design-browser-history/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(N)
class BrowserHistory {
    vector<string> A;
    int i = 0, sz = 1;
public:
    BrowserHistory(string homepage) {
        A.push_back(homepage);
    }
    void visit(string url) {
        sz = i + 2;
        if (A.size() < sz) A.push_back("");
        A[++i] = url;
    }
    string back(int steps) {
        return A[i = max(i - steps, 0)];
    }
    string forward(int steps) {
        return A[i = min(i + steps, sz - 1)];
    }
};