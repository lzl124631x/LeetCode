# [507. Perfect Number (Easy)](https://leetcode.com/problems/perfect-number/)

<p>We define the Perfect Number is a <b>positive</b> integer that is equal to the sum of all its <b>positive</b> divisors except itself. 
</p>
Now, given an <b>integer</b> n, write a function that returns true when it is a perfect number and false when it is not.
<p></p>

<p><b>Example:</b><br>
</p><pre><b>Input:</b> 28
<b>Output:</b> True
<b>Explanation:</b> 28 = 1 + 2 + 4 + 7 + 14
</pre>
<p></p>

<p><b>Note:</b>
The input number <b>n</b> will not exceed 100,000,000. (1e8)
</p>

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Self Dividing Numbers (Easy)](https://leetcode.com/problems/self-dividing-numbers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/perfect-number/
// Author: github.com/lzl124631x
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 0, end = sqrt(num);
        for (int i = 1; i <= end; ++i) {
            if (num % i) continue;
            int j = num / i;
            sum += i;
            if (j != i && j != num) sum += j;
        }
        return sum == num;
    }
};
```