# [409. Longest Palindrome (Easy)](https://leetcode.com/problems/longest-palindrome/)

<p>Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.</p>

<p>This is case sensitive, for example <code>"Aa"</code> is not considered a palindrome here.</p>

<p><b>Note:</b><br>
Assume the length of given string will not exceed 1,010.
</p>

<p><b>Example: </b>
</p><pre>Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
</pre>
<p></p>

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Palindrome Permutation (Easy)](https://leetcode.com/problems/palindrome-permutation/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-palindrome/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) because there are at most 52 unique characters
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> cnt;
        for (char c : s) cnt[c]++;
        int ans = 0, odd = 0;
        for (auto &p : cnt) {
            if (p.second % 2) {
                odd = 1; 
                ans += p.second - 1;
            } else ans += p.second;
        }
        return ans + odd;
    }
};
```