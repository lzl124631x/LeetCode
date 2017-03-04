// Time: O(N)
// Space: O(1)
class Solution {
public:
  string frequencySort(string s) {
    vector<int> cnt(256, 0);
    vector<int> ch(256, 0);
    iota(ch.begin(), ch.end(), 0);
    for (char c : s) cnt[c]++;
      sort(ch.begin(), ch.end(), [&cnt](int a, int b) { return cnt[a] > cnt[b]; });
    string ans;
    for (int i = 0; i < ch.size() && cnt[ch[i]]; ++i)
      for (int j = 0; j < cnt[ch[i]]; ans += ch[i], ++j);
    return ans;
  }
};