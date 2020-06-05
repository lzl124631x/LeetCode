# [344. Reverse String (Easy)](https://leetcode.com/problems/reverse-string/)

<p>Write a function that reverses a string. The input string is given as an array of characters <code>char[]</code>.</p>

<p>Do not allocate extra space for another array, you must do this by <strong>modifying the input array&nbsp;<a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a></strong> with O(1) extra memory.</p>

<p>You may assume all the characters consist of <a href="https://en.wikipedia.org/wiki/ASCII#Printable_characters" target="_blank">printable ascii characters</a>.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["h","e","l","l","o"]</span>
<strong>Output: </strong><span id="example-output-1">["o","l","l","e","h"]</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">["H","a","n","n","a","h"]</span>
<strong>Output: </strong><span id="example-output-2">["h","a","n","n","a","H"]</span>
</pre>
</div>
</div>

**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Amazon](https://leetcode.com/company/amazon), [Facebook](https://leetcode.com/company/facebook), [Adobe](https://leetcode.com/company/adobe), [GoDaddy](https://leetcode.com/company/godaddy), [Bloomberg](https://leetcode.com/company/bloomberg)

**Related Topics**:  
[Two Pointers](https://leetcode.com/tag/two-pointers/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Reverse Vowels of a String (Easy)](https://leetcode.com/problems/reverse-vowels-of-a-string/)
* [Reverse String II (Easy)](https://leetcode.com/problems/reverse-string-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/reverse-string/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) swap(s[i++], s[j--]);
    }
};
```