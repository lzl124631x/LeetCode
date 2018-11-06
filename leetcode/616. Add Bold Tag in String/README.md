# [616. Add Bold Tag in String (Medium)](https://leetcode.com/problems/add-bold-tag-in-string)

Given a string **s** and a list of strings **dict**, you need to add a closed pair of bold tag `<b>` and `</b>` to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

**Example 1:**  

```
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
```

**Example 2:**

```
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
```

**Note:**  

1.  The given dict won't contain duplicates, and its length won't exceed 100.
2.  All the strings in input have length in range [1, 1000].

## Solution 1.

The first naive solution came to my mind is using a mask to denote which part of the string needs get bolded. So I created a `vector<int> mask` of length `s.size()`. For each word in `dict`, find its occurrence in `s`, mark the corresponding range to `1`s in `mask`. Finally, output the result using that `mask`.

```cpp
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
```
