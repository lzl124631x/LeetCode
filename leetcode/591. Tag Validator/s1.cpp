// OJ: https://leetcode.com/problems/tag-validator
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(H)
class Solution {
private:
  enum State {
    INIT,
    START_TAG,
    TAG_CONTENT,
    END_TAG,
    CDATA
  };
public:
  bool isValid(string code) {
    stack<string> s;
    State state = INIT;
    string startTag, endTag;
    int i = 0;
    while (i < code.size()) {
      switch(state) {
        case INIT: {
          if (code[i] != '<') return false;
          ++i; // <
          state = START_TAG;
          break;
        }
        case START_TAG: {
          while (i < code.size() && isupper(code[i])) {
            startTag += code[i++];
          }
          if (i >= code.size() || code[i] != '>' || startTag.empty() || startTag.size() > 9) return false;
          s.push(startTag);
          ++i; // >
          state = TAG_CONTENT;
          break;
        }
        case TAG_CONTENT: {
          while (i < code.size() && code[i] != '<') ++i;
          if (i >= code.size() || code[i] != '<') return false;
          ++i; // <
          if (i < code.size() && code[i] == '/') {
              ++i; // /
              state = END_TAG;
              endTag.clear();
          } else if (i < code.size() && code[i] == '!') {// <![CDATA[
            string mark = "![CDATA[";
            int j = 0;
            while (i < code.size() && j < mark.size() && code[i] == mark[j]) ++i, ++j;
            if (j < mark.size()) return false;
            state = CDATA;
          } else {
            state = START_TAG;
            startTag.clear();
          }
          break;
        }
        case END_TAG: {
          while (i < code.size() && isupper(code[i])) {
            endTag += code[i++];
          }
          if (i >= code.size() || code[i] != '>' || endTag.empty() || s.empty() || s.top() != endTag) return false;
          s.pop();
          ++i; // >
          if (s.empty() && i < code.size()) return false;
          state = TAG_CONTENT;
          break;
        }
        case CDATA: {
          int end = code.find("]]>", i);
          if (end == string::npos) return false;
          i = end + 3;
          state = TAG_CONTENT;
          break;
        }
      }
    }
    return s.empty();
  }
};