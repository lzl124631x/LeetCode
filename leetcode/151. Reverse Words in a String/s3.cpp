class Solution {
public:
  void reverseWords(string &s) {
    stringstream ss(s);
    string word, ans;
    while (ss >> word) {
      reverse(word.begin(), word.end());
      if (ans.size()) ans += ' ';
      ans += word;
    }
    reverse(ans.begin(), ans.end());
    s = ans;
  }
};