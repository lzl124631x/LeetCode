// Bucket Sort
// Time: O(N)
// Space: O(N)
class Solution {
public:
  string frequencySort(string s) {
    vector<int> cnt(256, 0);
    vector<string> bucket(s.size() + 1);
    for (char c : s) cnt[c]++;
    for (int i = 0; i < cnt.size(); ++i)
      for (int j = 0; j < cnt[i]; bucket[cnt[i]] += char(i), ++j);
    string ans;
    for (int i = bucket.size() - 1; i >= 0; ans += bucket[i], --i);
    return ans;
  }
};