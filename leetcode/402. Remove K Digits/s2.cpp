class Solution {
public:
  string removeKdigits(string num, int k) {
    stack<char> s;
    int N = num.size();
    for (int i = 0; i < N; ++i) {
      char c = num[i];
      while (!s.empty() && i < k + s.size() && s.top() > c) s.pop();
      if (s.size() < N - k) s.push(c);
    }
    string ans;
    while (!s.empty()) {
      ans.push_back(s.top());
      s.pop();
    };
    reverse(ans.begin(), ans.end());
    int i = 0;
    while (i < ans.size() && ans[i] == '0') ++i;
    return i == ans.size() ? "0" : ans.substr(i);
  }
};