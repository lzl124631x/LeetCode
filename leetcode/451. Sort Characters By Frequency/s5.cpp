// Bucket Sort
// Time: O(N)
// Space: O(1)
class Solution {
public:
  string frequencySort(string s) {
    vector<int> cnt(256, 0);
    vector<string> bucket(s.size() + 1);
    for (char c : s) cnt[c]++;
      for (int i = 0; i < cnt.size(); ++i) bucket[cnt[i]] += char(i);
    string ans;
    for (int i = bucket.size() - 1; i >= 0; --i)
      for (char c : bucket[i])
        for (int j = 0; j < i; ++j) ans += c;
    return ans;
  }
};