class Solution {
public:
  void reverseWords(string &s) {
    stringstream ss(s);
    string word, ans;
    while (ss >> word) {
      if (ans.size()) word += ' ';
      ans = word + ans;
    }
    s = ans;
  }
};