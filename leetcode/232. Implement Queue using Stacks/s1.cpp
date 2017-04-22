// OJ: https://leetcode.com/problems/implement-queue-using-stacks
// Author: github.com/lzl124631x
// Time: O(1) amortized.
// Space: O(1)
class MyQueue {
private:
  stack<int> sin, sout;
public:
  MyQueue() {}
  void push(int x) {
    sin.push(x);
  }
  int pop() {
    int val = peek();
    sout.pop();
    return val;
  }
  int peek() {
    if (sout.empty()) {
      while (sin.size()) {
        sout.push(sin.top());
        sin.pop();
      }
    }
    return sout.top();
  }
  bool empty() {
    return sin.empty() && sout.empty();
  }
};