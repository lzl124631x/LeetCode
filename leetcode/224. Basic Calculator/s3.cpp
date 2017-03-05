class Solution {
private:
  vector<string> infixToSuffix(string s) {
    s += '#';
    int i = 0, N = s.size();
    vector<string> ans;
    stack<char> op;
    while (i < N) {
      while (i < N && s[i] == ' ') ++i;
      if (isdigit(s[i])) {
        int begin = i;
        while (i < N && isdigit(s[i])) ++i;
        ans.push_back(s.substr(begin, i - begin));
      } else {
        switch(s[i]) {
          case '+':
          case '-': {
            if (op.size() && (op.top() == '+' || op.top() == '-')) {
              ans.push_back(string { op.top() });
              op.pop();
            }
            op.push(s[i]);
            break;
          }
          case '(': op.push(s[i]); break;
          case '#':
          case ')': {
            while (op.size() && op.top() != '(') {
              ans.push_back(string { op.top() });
              op.pop();
            }
            if (op.size() && op.top() == '(') op.pop();
            break;
          }
        }
        ++i;
      }
    }
    return ans;
  }
  
  int evaluateSuffix(vector<string> v) {
    stack<int> st;
    st.push(0);
    for (string s : v) {
      if (isdigit(s[0])) {
        st.push(stoi(s));
      } else {
        int n = st.top();
        st.pop();
        switch(s[0]) {
          case '+': st.top() += n; break;
          case '-': st.top() -= n; break;
        }
      }
    }
    return st.top();
  }
public:
  int calculate(string s) {
    return evaluateSuffix(infixToSuffix(s));
  }
};