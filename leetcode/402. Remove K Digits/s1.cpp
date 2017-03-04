class Solution {
public:
  string removeKdigits(string num, int k) {
    if (num.size() == k) return "0";
    string ans;
    int len = num.size() - k;
    for (int i = 0; i < num.size(); ++i) {
      if (ans.empty() || !k) ans.push_back(num[i]);
      else if (ans.back() <= num[i]) {
        if (ans.size() == len) --k;
        else ans.push_back(num[i]);
      } else {
        while (k && ans.size() && ans.back() > num[i]) { ans.pop_back(); --k; }
        ans.push_back(num[i]);
      }
    }
    auto begin = ans.find_first_not_of('0');
    return begin == string::npos ? "0" : ans.substr(begin);
  }
};