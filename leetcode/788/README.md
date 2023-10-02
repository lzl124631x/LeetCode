# [788. Rotated Digits (Easy)](https://leetcode.com/problems/rotated-digits/)

<p>X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.&nbsp; Each digit must be rotated - we cannot choose to leave it alone.</p>

<p>A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.</p>

<p>Now&nbsp;given a positive number <code>N</code>, how many numbers X from <code>1</code> to <code>N</code> are good?</p>

<pre><strong>Example:</strong>
<strong>Input:</strong> 10
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li>N&nbsp; will be in range <code>[1, 10000]</code>.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/rotated-digits/
// Author: github.com/lzl124631x
// Time: O(ND) where D is the count of digits in N
// Space: O(1)
class Solution {
private:
    bool isGood(int N) {
        bool good = false;
        while (N) {
            int d = N % 10;
            if (d == 3 || d == 4 || d == 7) return false;
            if (d == 2 || d == 5 || d == 6 || d == 9) good = true;
            N /= 10;
        }
        return good;
    }
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        for (int i = 1; i <= N; ++i) {
            if (isGood(i)) ++cnt;
        }
        return cnt;
    }
};
```