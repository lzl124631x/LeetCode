class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (string t : tokens) {
      if (isdigit(t.back())) s.push(stoi(t));
      else {
        int n = s.top();
        s.pop();
        switch(t[0]) {
          case '+': s.top() += n; break;
          case '-': s.top() -= n; break;
          case '*': s.top() *= n; break;
          case '/': s.top() /= n; break;
        }
      }
    }
    return s.top();
  }
};