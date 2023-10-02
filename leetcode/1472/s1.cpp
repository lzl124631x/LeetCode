// OJ: https://leetcode.com/problems/design-browser-history/
// Author: github.com/lzl124631x
// Time:
//      BrowserHistory, back, forward: O(1)
//      visit: O(N)
// Space: O(N)
class BrowserHistory {
    vector<string> A;
    int i = 0;
public:
    BrowserHistory(string homepage) {
        A.push_back(homepage);
    }
    void visit(string url) {
        A.resize(i + 1);
        A.push_back(url);
        ++i;
    }
    string back(int steps) {
        return A[i = max(i - steps, 0)];
    }
    string forward(int steps) {
        return A[i = min(i + steps, (int)A.size() - 1)];
    }
};