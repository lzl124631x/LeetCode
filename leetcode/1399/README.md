# [1399. Count Largest Group (Easy)](https://leetcode.com/problems/count-largest-group/)

<p>Given an integer&nbsp;<code>n</code>.&nbsp;Each number from <code>1</code> to <code>n</code> is grouped according to the sum of its digits.&nbsp;</p>

<p>Return&nbsp;how many groups have the largest size.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> n = 13
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9]. There are 4 groups with largest size.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are 2 groups [1], [2] of size 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> n = 15
<strong>Output:</strong> 6
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> n = 24
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10^4</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-largest-group/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> m;
        for (int i = 1; i <= n; ++i) {
            int sum = 0, x = i;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            m[sum]++;
        }
        int maxSize = 0;
        for (auto &p : m) {
            maxSize = max(maxSize, p.second);
        }
        int ans = 0;
        for (auto &p : m) {
            if (p.second == maxSize) ++ans;
        }
        return ans;
    }
};
```