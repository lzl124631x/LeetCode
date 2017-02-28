// 19ms, 2/28/2017
class Solution {
public:
  string frequencySort(string s) {
    vector<char> v;
    vector<int> m(256, 0);
    for (char c : s) {
      if (!m[c]) v.push_back(c);
      m[c]++;
    }
    sort(v.begin(), v.end(), [&](char a, char b) { return m[a] > m[b]; });
    string ret;
    for (char c : v) {
      for (int i = m[c]; i > 0; --i) {
        ret.push_back(c);
      }
    }
    return ret;
  }
};