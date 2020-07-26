# [258. Add Digits (Easy)](https://leetcode.com/problems/add-digits/)

<p>Given a non-negative integer <code>num</code>, repeatedly add all its digits until the result has only one digit.</p>

<p><strong>Example:</strong></p>

<pre><strong>Input:</strong> <code>38</code>
<strong>Output:</strong> 2 
<strong>Explanation: </strong>The process is like: <code>3 + 8 = 11</code>, <code>1 + 1 = 2</code>. 
&nbsp;            Since <code>2</code> has only one digit, return it.
</pre>

<p><b>Follow up:</b><br>
Could you do it without any loop/recursion in O(1) runtime?</p>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Happy Number (Easy)](https://leetcode.com/problems/happy-number/)
* [Sum of Digits in the Minimum Number (Easy)](https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/)

## Solution 1.

See explanation in https://leetcode.com/problems/add-digits/solution/.

```cpp
// OJ: https://leetcode.com/problems/add-digits/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int addDigits(int num) {
        return num ? (num % 9 ? num % 9 : 9) : 0;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/add-digits/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int addDigits(int num) {
        return num ? 1 + (num - 1) % 9 : 0;
    }
};
```