# [600. Non-negative Integers without Consecutive Ones (Hard)](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)

<p>Given a positive integer n, find the number of <b>non-negative</b> integers less than or equal to n, whose binary representations do NOT contain <b>consecutive ones</b>.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 5
<b>Output:</b> 5
<b>Explanation:</b> 
Here are the non-negative integers &lt;= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
</pre>
<p></p>

<p><b>Note:</b>
1 &lt;= n &lt;= 10<sup>9</sup>
</p>


**Companies**:  
[Pocket Gems](https://leetcode.com/company/pocket-gems)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

Let `f(n)` be the numbers less than or equal to `n` whose binary representations DO contain consecutive ones.

x | binary(x) | has consecutive ones
---|---|---
0 | 0 | 
1 | 1 | 
2 | 10 | 
3 | 11 | 1
4 | 100 | 
5 | 101 |
6 | 110 | 1
7 | 111 | 1
8 | 1000 |
9 | 1001 |
10 | 1010 |
11 | 1011 | 1
12 | 1100 | 1
13 | 1101 | 1
14 | 1110 | 1
15 | 1111 | 1
16 | 10000 |

We can find pattern in this way:

1. We separate the table rows according to count of bits. So 0~1 is the first group, 2~3 is the second group, 4~7 is the third group, 8~15 is the forth group...
2. Starting from the second group, the numbers in the second half of the group all have consecutive ones, simply because they have leading `11`.
3. For the numbers in the first half of the groups, the pattern is the same after removing the leading `10`.  
Take 14 as example which is in group 8~15, it's in the second half, so 12~14 all have consecutive ones. And 8~11 has the same pattern as 0~3.

So we can get this equation:

```
let k = floor(log2(n))
let p = 2^k
f(n) = f(p-1) +
       { f(n-p)                        if n-(p-1)<= p/2
       { n-(p-1)-p/2 + f(p/2-1)        if n-(p-1)>p/2
```

```cpp
// OJ: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
private:
    unordered_map<int, int> m;
    int find(int num) {
        if (num < 2) return 0;
        if (m.find(num) != m.end()) return m[num];
        int k = log2(num), p = pow(2, k);
        int ans = find(p - 1);
        if (num > p / 2 * 3 - 1) ans += num - p / 2 * 3 + 1 + find(p / 2 - 1);
        else ans += find(num - p);
        return m[num] = ans;
    }
public:
    int findIntegers(int num) {
        return num + 1 - find(num);
    }
};
```