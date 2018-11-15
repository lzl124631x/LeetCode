// https://leetcode.com/problems/basic-calculator
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
  stack<int> num;
  stack<char> op;
  void eval(bool popLeftParen) {
    while (op.size() && op.top() != '(') {
      int n = num.top();
      num.pop();
      switch (op.top()) {
        case '+': num.top() += n; break;
        case '-': num.top() -= n; break;
      }
      op.pop();
    }
    if (popLeftParen) op.pop();
  }
public:
  int calculate(string s) {
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') continue;
      if (isdigit(s[i])) {
        int begin = i;
        while (i + 1 < s.size() && isdigit(s[i + 1])) ++i;
        num.push(stoi(s.substr(begin, i - begin + 1)));
      } else {
        switch(s[i]) {
          case '+':
          case '-': eval(false);
          // fall through
          case '(': op.push(s[i]); break;
          case ')': eval(true); break;
        }
      }
    }
    eval(false);
    return num.top();
  }
};