# [1295. Find Numbers with Even Number of Digits (Easy)](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)

Given an array <code>nums</code> of integers, return how many of them contain an <strong>even number</strong> of digits.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [12,345,2,6,7896]
<strong>Output:</strong> 2
<strong>Explanation: 
</strong>12 contains 2 digits (even number of digits).&nbsp;
345 contains 3 digits (odd number of digits).&nbsp;
2 contains 1 digit (odd number of digits).&nbsp;
6 contains 1 digit (odd number of digits).&nbsp;
7896 contains 4 digits (even number of digits).&nbsp;
Therefore only 12 and 7896 contain an even number of digits.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [555,901,482,1771]
<strong>Output:</strong> 1 
<strong>Explanation: </strong>
Only 1771 contains an even number of digits.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10^5</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    int getCount(int n) {
        int cnt = 0;
        while (n) {
            n /= 10;
            ++cnt;
        }
        return cnt;
    }
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int n : nums) {
            if (getCount(n) % 2 == 0) cnt++;
        }
        return cnt;
    }
};
```