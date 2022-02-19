# [2177. Find Three Consecutive Integers That Sum to a Given Number (Medium)](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/)

<p>Given an integer <code>num</code>, return <em>three consecutive integers (as a sorted array)</em><em> that <strong>sum</strong> to </em><code>num</code>. If <code>num</code> cannot be expressed as the sum of three consecutive integers, return<em> an <strong>empty</strong> array.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = 33
<strong>Output:</strong> [10,11,12]
<strong>Explanation:</strong> 33 can be expressed as 10 + 11 + 12 = 33.
10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = 4
<strong>Output:</strong> []
<strong>Explanation:</strong> There is no way to express 4 as the sum of 3 consecutive integers.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= num &lt;= 10<sup>15</sup></code></li>
</ul>


**Similar Questions**:
* [Longest Consecutive Sequence (Medium)](https://leetcode.com/problems/longest-consecutive-sequence/)

## Solution 1. Math

Let `x` be the first number of the 3 consecutive numbers. Then `num = x + x + 1 + x + 2 = 3 * x + 3`. Since `x` is an integer, `num` must be multiple of `3`, and `x = num / 3 - 1`. 

```cpp
// OJ: https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3) return {};
        long x = num / 3 - 1; 
        return {x, x + 1, x + 2};
    }
};
```

Or one-liner

```cpp
// OJ: https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        return num % 3 ? vector<long long>{} : vector<long long>{num / 3 - 1, num / 3, num / 3 + 1};
    }
};
```

## Discuss

https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/discuss/1783380/C%2B%2B-Math-one-liner