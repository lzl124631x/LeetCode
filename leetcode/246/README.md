# [246. Strobogrammatic Number (Easy)](https://leetcode.com/problems/strobogrammatic-number/)

<p>A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).</p>

<p>Write a function to determine if a number is strobogrammatic. The number is represented as a string.</p>

<p><b>Example 1:</b></p>

<pre><b>Input:</b>  "69"
<b>Output:</b> true
</pre>

<p><b>Example 2:</b></p>

<pre><b>Input:</b>  "88"
<b>Output:</b> true</pre>

<p><b>Example 3:</b></p>

<pre><b>Input:</b>  "962"
<b>Output:</b> false</pre>


**Companies**:  
[Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Strobogrammatic Number II (Medium)](https://leetcode.com/problems/strobogrammatic-number-ii/)
* [Strobogrammatic Number III (Hard)](https://leetcode.com/problems/strobogrammatic-number-iii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/strobogrammatic-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
private:
    bool same(char a, char b) {
        return a == b && (a == '0' || a == '1' || a == '8');
    }
    bool match(char a, char b) {
        if (a > b) swap(a, b);
        return same(a, b) || (a == '6' && b == '9');
    }
public:
    bool isStrobogrammatic(string num) {
        int i = 0, j = num.size() - 1;
        for (; i <= j; ++i, --j) {
            if ((i != j && !match(num[i], num[j]))
               || (i == j && !same(num[i], num[j]))) return false;
        }
        return true;
    }
};
```