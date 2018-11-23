# [344. Reverse String (Easy)](https://leetcode.com/problems/reverse-string/)

<p>Write a function that takes a string as input and returns the string reversed.</p>

<p><strong>Example 1:</strong></p>

<div>
<pre><strong>Input: </strong><span id="example-input-1-1">"hello"</span>
<strong>Output: </strong><span id="example-output-1">"olleh"</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"A man, a plan, a canal: Panama"</span>
<strong>Output: </strong><span id="example-output-2">"amanaP :lanac a ,nalp a ,nam A"</span>
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
    string reverseString(string s) {
    	return string(s.rbegin(), s.rend());
    }
};
```