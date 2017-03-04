class Solution {
public:
  string removeKdigits(string num, int k) {
    string ans;
    for (int i = 0; i < num.size(); ++i) {
      while (i < k + ans.size() && ans.size() && ans.back() > num[i]) ans.pop_back();
      if (ans.size() < num.size() - k) ans.push_back(num[i]);
    }
    auto begin = ans.find_first_not_of('0');
    return begin == string::npos ? "0" : ans.substr(begin);
  }
};