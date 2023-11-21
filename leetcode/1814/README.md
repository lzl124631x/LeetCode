# [1814. Count Nice Pairs in an Array (Medium)](https://leetcode.com/problems/count-nice-pairs-in-an-array)

<p>You are given an array <code>nums</code> that consists of non-negative integers. Let us define <code>rev(x)</code> as the reverse of the non-negative integer <code>x</code>. For example, <code>rev(123) = 321</code>, and <code>rev(120) = 21</code>. A pair of indices <code>(i, j)</code> is <strong>nice</strong> if it satisfies all of the following conditions:</p>

<ul>
	<li><code>0 &lt;= i &lt; j &lt; nums.length</code></li>
	<li><code>nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])</code></li>
</ul>

<p>Return <em>the number of nice pairs of indices</em>. Since that number can be too large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [42,11,1,97]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [13,10,35,24,76]
<strong>Output:</strong> 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Uber](https://leetcode.com/company/uber), [Navi](https://leetcode.com/company/navi), [Square](https://leetcode.com/company/square)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Math](https://leetcode.com/tag/math), [Counting](https://leetcode.com/tag/counting)

**Similar Questions**:
* [Number of Pairs of Interchangeable Rectangles (Medium)](https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles)
* [Count Number of Bad Pairs (Medium)](https://leetcode.com/problems/count-number-of-bad-pairs)
* [Number of Pairs Satisfying Inequality (Hard)](https://leetcode.com/problems/number-of-pairs-satisfying-inequality)

**Hints**:
* The condition can be rearranged to (nums[i] - rev(nums[i])) == (nums[j] - rev(nums[j])).
* Transform each nums[i] into (nums[i] - rev(nums[i])). Then, count the number of (i, j) pairs that have equal values.
* Keep a map storing the frequencies of values that you have seen so far. For each i, check if nums[i] is in the map. If it is, then add that count to the overall count. Then, increment the frequency of nums[i].

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/count-nice-pairs-in-an-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    long rev(long x) {
        long ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& A) {
        unordered_map<int, int> m;
        long ans = 0, mod = 1e9 + 7;
        for (int n : A) {
            long x = n - rev(n);
            ans = (ans + m[x]++) % mod;
        }
        return ans;
    }
};
```