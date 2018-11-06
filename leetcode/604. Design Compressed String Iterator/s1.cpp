// OJ: https://leetcode.com/problems/design-compressed-string-iterator
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class StringIterator {
private:
  string str;
  int index = 0, nextIndex = 0, cnt = 0;
  void load() {
    while (index < str.size() && !cnt) {
      index = nextIndex;
      nextIndex = index + 1;
      while (nextIndex < str.size() && isdigit(str[nextIndex])) cnt = cnt * 10 + str[nextIndex++] - '0';
    }
  }
public:
  StringIterator(string compressedString) : str(compressedString) {
    load();
  }

  char next() {
    if (!hasNext()) return ' ';
    char ans = str[index];
    --cnt;
    load();
    return ans;
  }

  bool hasNext() {
    return index < str.size();
  }
};