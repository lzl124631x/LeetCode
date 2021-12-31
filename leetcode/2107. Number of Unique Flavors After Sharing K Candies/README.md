# [2107. Number of Unique Flavors After Sharing K Candies (Medium)](https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/)

<p>You are given a <strong>0-indexed</strong> integer array <code>candies</code>, where <code>candies[i]</code> represents the flavor of the <code>i<sup>th</sup></code> candy. Your mom wants you to share these candies with your little sister by giving her <code>k</code> <strong>consecutive</strong> candies, but you want to keep as many flavors of candies as possible.</p>

<p>Return <em>the <strong>maximum</strong> number of <strong>unique</strong> flavors of candy you can keep after sharing </em><em> with your sister.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> candies = [1,<u>2,2,3</u>,4,3], k = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
Give the candies in the range [1, 3] (inclusive) with flavors [2,2,3].
You can eat candies with flavors [1,4,3].
There are 3 unique flavors, so return 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> candies = [2,2,2,<u>2,3</u>,3], k = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
Give the candies in the range [3, 4] (inclusive) with flavors [2,3].
You can eat candies with flavors [2,2,2,3].
There are 2 unique flavors, so return 2.
Note that you can also share the candies with flavors [2,2] and eat the candies with flavors [2,2,3,3].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> candies = [2,4,5], k = 0
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
You do not have to give any candies.
You can eat the candies with flavors [2,4,5].
There are 3 unique flavors, so return 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= candies.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= candies[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= candies.length</code></li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Sliding Window](https://leetcode.com/tag/sliding-window/)

**Similar Questions**:
* [Remove Boxes (Hard)](https://leetcode.com/problems/remove-boxes/)
* [Subarrays with K Different Integers (Hard)](https://leetcode.com/problems/subarrays-with-k-different-integers/)

## Solution 1. Fixed-length Sliding Window

```cpp
// OJ: https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int shareCandies(vector<int>& A, int k) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int n : A) cnt[n]++;
        for (int i = 0, N = A.size(); i < N; ++i) { // Give out candies in window `[i-k+1, i]`
            cnt[A[i]]--; // Give out `A[i]`
            if (i - k >= 0) cnt[A[i - k]]++; // Reclaim `A[i-k]`
            if (cnt[A[i]] == 0) cnt.erase(A[i]);
            if (i >= k - 1) ans = max(ans, (int)cnt.size()); // Take the maximum possible unique flavors left after giving out.
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/discuss/1658450/C%2B%2B-Fixed-length-Sliding-Window