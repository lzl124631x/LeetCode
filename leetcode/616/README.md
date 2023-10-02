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

The first naive solution came to my mind is using a mask to denote which part of the string needs get bolded. So I created a `vector<bool> bold` of length `s.size()`. For each word in `A`, find its occurrence in `s`, mark the corresponding range to `true`s in `mask`. Finally, output the result using that `mask`.

```cpp
// OJ: https://leetcode.com/problems/add-bold-tag-in-string
// Author: github.com/lzl124631x
// Time: O(DWK)
//    where D is size of dict, W is average length of words in dict
//    K is average occurrence of words in s.
// Space: O(N)
class Solution {
public:
    string addBoldTag(string s, vector<string>& A) {
        int N = s.size();
        vector<bool> bold(N);
        for (auto &w : A) {
            int i = s.find(w);
            while (i != string::npos) {
                for (int j = 0; j < w.size(); ++j) bold[i + j] = true;
                i = s.find(w, i + 1);
            }
        }
        string ans;
        for (int i = 0; i < N; ) {
            if (bold[i]) {
                ans += "<b>";
                while (i < N && bold[i]) ans += s[i++];
                ans += "</b>";
            } else ans += s[i++];
        }
        return ans;
    }
};
```
