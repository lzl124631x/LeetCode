// OJ: https://leetcode.com/problems/implement-stack-using-queues/
// Author: github.com/lzl124631x
// Time: O(N) for pop, O(1) for others
// Space: O(1)
class MyStack {
    queue<int> q;
    int t;
public:
    MyStack() {}
    void push(int x) {
        q.push(x);
        t = x;
    }
    int pop() {
        int n = q.size();
        while (--n) {
            int val = q.front();
            if (n == 1) t = val;
            q.push(val);
            q.pop();
        }
        int val = q.front();
        q.pop();
        return val;
    }
    int top() {
        return t;
    }
    bool empty() {
        return !q.size();
    }
};