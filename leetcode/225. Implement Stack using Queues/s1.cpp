// OJ: https://leetcode.com/problems/implement-stack-using-queues
// Author: github.com/lzl124631x
// Time: O(N) for push, O(1) for others
// Space: O(1)
class MyStack {
private:
  queue<int> q;
public:
  MyStack() {}
  void push(int x) {
    q.push(x);
    for (int i = 0; i < q.size() - 1; ++i) {
      q.push(q.front());
      q.pop();
    }
  }
  int pop() {
    int val = q.front();
    q.pop();
    return val;
  }
  int top() {
    return q.front();
  }
  bool empty() {
    return q.empty();
  }
};