// OJ: https://leetcode.com/problems/add-bold-tag-in-string
// Author: github.com/lzl124631x
// Time: O(DWK)
//    where D is size of dict, W is average length of words in dict
//    K is average occurrence of words in s.
// Space: O(N)
class Solution {
private:
  void setMask(vector<int> &mask, int from, int to) {
    for (int i = from; i < to; ++i) mask[i] = 1;
  }
public:
  string addBoldTag(string s, vector<string>& dict) {
    vector<int> mask(s.size(), 0);
    for (string word : dict) {
      int pos = s.find(word, 0);
      while (pos != string::npos) {
        setMask(mask, pos, pos + word.size());
        pos = s.find(word, pos + 1);
      }
    }
    string ans;
    for (int i = 0; i < s.size(); ++i) {
      if ((!i || mask[i - 1] == 0) && mask[i] == 1) ans += "<b>";
      ans += s[i];
      if (mask[i] == 1 && (mask[i + 1] == 0 || i == s.size() - 1)) ans += "</b>";
    }
    return ans;
  }
};