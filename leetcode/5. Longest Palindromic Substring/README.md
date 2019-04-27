# [5. Longest Palindromic Substring (Medium)](https://leetcode.com/problems/longest-palindromic-substring/)

<p>Given a string <strong>s</strong>, find the longest palindromic substring in <strong>s</strong>. You may assume that the maximum length of <strong>s</strong> is 1000.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> "babad"
<strong>Output:</strong> "bab"
<strong>Note:</strong> "aba" is also a valid answer.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> "cbbd"
<strong>Output:</strong> "bb"
</pre>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Microsoft](https://leetcode.com/company/microsoft), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple), [Adobe](https://leetcode.com/company/adobe), [Yahoo](https://leetcode.com/company/yahoo), [Bloomberg](https://leetcode.com/company/bloomberg), [Uber](https://leetcode.com/company/uber), [Pure Storage](https://leetcode.com/company/pure-storage), [eBay](https://leetcode.com/company/ebay), [Alibaba](https://leetcode.com/company/alibaba), [LinkedIn](https://leetcode.com/company/linkedin), [Cisco](https://leetcode.com/company/cisco), [NetEase](https://leetcode.com/company/netease), [Oracle](https://leetcode.com/company/oracle), [Roblox](https://leetcode.com/company/roblox)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-palindromic-substring/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
private:
    int expand(string &s, int L, int R) {
        while (L >= 0 && R < s.size() && s[L] == s[R]) {
            --L;
            ++R;
        }
        return R - L - 1;
    }
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            int len = max(len1, len2);
            if (len > maxLen) {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }
};
```