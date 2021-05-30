# [266. Palindrome Permutation (Easy)](https://leetcode.com/problems/palindrome-permutation/)

<p>Given a string, determine if a permutation of the string could form a palindrome.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> <code>"code"</code>
<strong>Output:</strong> false</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> <code>"aab"</code>
<strong>Output:</strong> true</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> <code>"carerac"</code>
<strong>Output:</strong> true</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

**Similar Questions**:
* [Longest Palindromic Substring (Medium)](https://leetcode.com/problems/longest-palindromic-substring/)
* [Valid Anagram (Easy)](https://leetcode.com/problems/valid-anagram/)
* [Palindrome Permutation II (Medium)](https://leetcode.com/problems/palindrome-permutation-ii/)
* [Longest Palindrome (Easy)](https://leetcode.com/problems/longest-palindrome/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/palindrome-permutation/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int cnt[26] = {}, single = 0;
        for (char c : s) cnt[c - 'a']++;
        for (int n : cnt) {
            single += n % 2;
            if (single > 1) return false;
        }
        return true;
    }
};
```