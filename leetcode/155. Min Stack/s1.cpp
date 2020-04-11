// OJ: https://leetcode.com/problems/min-stack/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(N)
class MinStack {
    stack<int> s;
    stack<pair<int, int>> d; // cnt, val
public:
    MinStack() {}
    void push(int x) {
        s.push(x);
        if (d.empty() || x < d.top().second) d.emplace(s.size(), x);
    }
    void pop() {
        if (s.size() == d.top().first) d.pop();
        s.pop();
    }
    int top() {
        return s.top();
    }
    int getMin() {
        return d.top().second;
    }
};