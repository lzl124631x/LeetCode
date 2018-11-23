# [9. Palindrome Number (Easy)](https://leetcode.com/problems/palindrome-number/)

<p>Determine whether an integer is a palindrome. An integer&nbsp;is&nbsp;a&nbsp;palindrome when it&nbsp;reads the same backward as forward.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> 121
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> -121
<strong>Output:</strong> false
<strong>Explanation:</strong> From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> 10
<strong>Output:</strong> false
<strong>Explanation:</strong> Reads 01 from right to left. Therefore it is not a palindrome.
</pre>

<p><strong>Follow up:</strong></p>

<p>Coud you solve&nbsp;it without converting the integer to a string?</p>


**Companies**:  
JPMorgan, Amazon, Bloomberg, Adobe, Microsoft, Facebook, Yahoo, Tencent

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Palindrome Linked List (Easy)](https://leetcode.com/problems/palindrome-linked-list/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/palindrome-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int a = x, b = 0;
        while (a) {
            b *= 10;
            b += a % 10;
            a /= 10;
        }
        return b == x;
    }
};
```