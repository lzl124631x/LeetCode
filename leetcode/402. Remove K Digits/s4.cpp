class Solution {
public:
  string removeKdigits(string num, int k) {
    string ans;
    int n = k;
    for (char c : num) {
      while (ans.size() && n && c < ans.back()) { --n; ans.pop_back(); }
      if (ans.size() < num.size() - k) ans.push_back(c);
      else --n;
    }
    auto begin = ans.find_first_not_of('0');
    return begin == string::npos ? "0" : ans.substr(begin);
  }
};