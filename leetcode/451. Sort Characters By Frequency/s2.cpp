// 29ms, 2/28/2017
class Solution {
public:
  string frequencySort(string s) {
    sort(s.begin(), s.end());
    auto cmp = [](string &a, string &b) { return a.size() < b.size(); };
    priority_queue<string, vector<string>, decltype(cmp)> q(cmp);
    int i = 0;
    while (i < s.size()) {
      int j = i + 1;
      while (j < s.size() && s[j] == s[i]) ++j;
      q.push(s.substr(i, j - i));
      i = j;
    }
    string ans;
    while (q.size()) {
      ans += q.top();
      q.pop();
    }
    return ans;
  }
};