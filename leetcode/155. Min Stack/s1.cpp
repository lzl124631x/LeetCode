// OJ: https://leetcode.com/problems/min-stack/
// Author: github.com/lzl124631x
// Time: O(1) for all
// Space: O(N)
class MinStack {
    stack<int> mn;
    stack<int> val;
public:
    MinStack() {}
    void push(int x) {
        val.push(x);
        if (mn.empty() || mn.top() >= x) mn.push(x);
    }
    void pop() {
        if (val.top() == mn.top()) mn.pop();
        val.pop();
    }
    int top() {
        return val.top();
    }
    int getMin() {
        return mn.top();
    }
};