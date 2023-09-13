# [2455. Average Value of Even Numbers That Are Divisible by Three (Easy)](https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three)

<p>Given an integer array <code>nums</code> of <strong>positive</strong> integers, return <em>the average value of all even integers that are divisible by</em> <code>3</code><i>.</i></p>
<p>Note that the <strong>average</strong> of <code>n</code> elements is the <strong>sum</strong> of the <code>n</code> elements divided by <code>n</code> and <strong>rounded down</strong> to the nearest integer.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,3,6,10,12,15]
<strong>Output:</strong> 9
<strong>Explanation:</strong> 6 and 12 are even numbers that are divisible by 3. (6 + 12) / 2 = 9.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,4,7,10]
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no single number that satisfies the requirement, so return 0.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>

**Companies**:
[IBM](https://leetcode.com/company/ibm)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Binary Prefix Divisible By 5 (Easy)](https://leetcode.com/problems/binary-prefix-divisible-by-5/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int averageValue(vector<int>& A) {
        int cnt = 0, sum = 0;
        for (int n : A) {
            if (n % 2 == 0 && n % 3 == 0) ++cnt, sum += n;
        }
        return cnt ? sum / cnt : 0;
    }
};
```