# [2404. Most Frequent Even Element (Easy)](https://leetcode.com/problems/most-frequent-even-element)

<p>Given an integer array <code>nums</code>, return <em>the most frequent even element</em>.</p>
<p>If there is a tie, return the <strong>smallest</strong> one. If there is no such element, return <code>-1</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [0,1,2,2,4,4,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [4,4,4,9,2,4]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 4 is the even element appears the most.
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [29,47,21,41,13,37,25,7]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no even element.
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 2000</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Counting](https://leetcode.com/tag/counting/)

**Similar Questions**:
* [Majority Element (Easy)](https://leetcode.com/problems/majority-element/)
* [Majority Element II (Medium)](https://leetcode.com/problems/majority-element-ii/)
* [Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)
* [Sort Characters By Frequency (Medium)](https://leetcode.com/problems/sort-characters-by-frequency/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/most-frequent-even-element
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int mostFrequentEven(vector<int>& A) {
        unordered_map<int, int> cnt;
        for (int n : A) {
            if (n % 2 == 0) cnt[n]++;
        }
        int maxFreq = 0, ans = -1;
        for (auto &[n, c] : cnt) {
            if (c > maxFreq) {
                ans = n;
                maxFreq = c;
            } else if (c == maxFreq && n < ans) ans = n;
        }
        return ans;
    }
};
```