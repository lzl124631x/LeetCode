# [600. Non-negative Integers without Consecutive Ones (Hard)](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)

<p>Given a positive integer <code>n</code>, return the number of the integers in the range <code>[0, n]</code> whose binary representations <strong>do not</strong> contain consecutive ones.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 5
<strong>Output:</strong> 5
<strong>Explanation:</strong>
Here are the non-negative integers &lt;= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and the other 5 satisfy the rule. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> 2
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Pocket Gems](https://leetcode.com/company/pocket-gems)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [House Robber (Medium)](https://leetcode.com/problems/house-robber/)
* [House Robber II (Medium)](https://leetcode.com/problems/house-robber-ii/)
* [Ones and Zeroes (Medium)](https://leetcode.com/problems/ones-and-zeroes/)

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


## Solution 2. DP

```cpp
// OJ: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
    unordered_map<int, int> m;
public:
    int findIntegers(int n) {
        if (n <= 1) return n + 1;
        if (m.count(n)) return m[n];
        int first = -1, second = -1;
        for (int i = 31; i >= 0 && second == -1; --i) {
            if ((n >> i & 1) == 0) continue;
            if (first == -1) first = i;
            else second = i;
        }
        if (second == -1) {
            return m[n] = findIntegers((1 << first) - 1) + 1;
        }
        if (first != second + 1) {
            return m[n] = findIntegers(n - (1 << first)) + findIntegers((1 << first) - 1);
        }
        return m[n] = findIntegers((1 << first) - 1) + findIntegers((1 << second) - 1);
    }
};
```