# [2513. Minimize the Maximum of Two Arrays (Medium)](https://leetcode.com/problems/minimize-the-maximum-of-two-arrays)

<p>We have two arrays <code>arr1</code> and <code>arr2</code> which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:</p>

<ul>
	<li><code>arr1</code> contains <code>uniqueCnt1</code> <strong>distinct</strong> positive integers, each of which is <strong>not divisible</strong> by <code>divisor1</code>.</li>
	<li><code>arr2</code> contains <code>uniqueCnt2</code> <strong>distinct</strong> positive integers, each of which is <strong>not divisible</strong> by <code>divisor2</code>.</li>
	<li><strong>No</strong> integer is present in both <code>arr1</code> and <code>arr2</code>.</li>
</ul>

<p>Given <code>divisor1</code>, <code>divisor2</code>, <code>uniqueCnt1</code>, and <code>uniqueCnt2</code>, return <em>the <strong>minimum possible maximum</strong> integer that can be present in either array</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
We can distribute the first 4 natural numbers into arr1 and arr2.
arr1 = [1] and arr2 = [2,3,4].
We can see that both arrays satisfy all the conditions.
Since the maximum value is 4, we return it.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> divisor1 = 3, divisor2 = 5, uniqueCnt1 = 2, uniqueCnt2 = 1
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
Here arr1 = [1,2], and arr2 = [3] satisfy all conditions.
Since the maximum value is 3, we return it.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> divisor1 = 2, divisor2 = 4, uniqueCnt1 = 8, uniqueCnt2 = 2
<strong>Output:</strong> 15
<strong>Explanation:</strong> 
Here, the final possible arrays can be arr1 = [1,3,5,7,9,11,13,15], and arr2 = [2,6].
It can be shown that it is not possible to obtain a lower maximum satisfying all conditions. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= divisor1, divisor2 &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= uniqueCnt1, uniqueCnt2 &lt; 10<sup>9</sup></code></li>
	<li><code>2 &lt;= uniqueCnt1 + uniqueCnt2 &lt;= 10<sup>9</sup></code></li>
</ul>


**Related Topics**:  
[Math](https://leetcode.com/tag/math), [Binary Search](https://leetcode.com/tag/binary-search), [Number Theory](https://leetcode.com/tag/number-theory)

**Hints**:
* Use binary search to find smallest maximum element.
* Add numbers divisible by x in nums2 and vice versa.

## Solution 1.

Binary search in range `[0, INT_MAX]`.

For a given `x`, define `valid(x)` as whether we can form two arrays satisfying the requirements.

**How many numbers we can use freely in both arrays?** For numbers in `[1, x]`,  there are `x / a` numbers that can't go into `arr1`, and `x / b` numbers that can't go into `arr2`. These two set of numbers might have some overlap. There are `never = x / lcm` such numbers where `lcm = a * b / gcd(a, b)` is the least common multiple of `a` and `b`. These `never` numbers can't go into either array. So, within `[1, x]`, there are `x - x/a - x/b + never` numbers we can use **freely** to fill both arrays. We need to `+ never` because we excluded these `never` numbers once in `x/a` and once in `x/b`, so we need to add `never` back to avoid excess removal.

**How many free numbers we need in both arrays?** Aside from these `x - x/a - x/b + never` free numbers, we have some **limited** numbers that can only go into one of the arrays. `x/b - never` numbers can go into `arr1`, and `x/a - never` numbers can go into `arr2`. So, `arr1` need `max(0, u1 - (x/b - never))` free numbers, and `arr2` need `max(0, u2 - (x/a - never))` free numbers.

In sum, we can define `valid(x)` as whether we have enough free numbers after filling limited numbers first. That is `x - x/a - x/b + never >= max(0, u1 - x/b + never) + max(0, u2 - x/a + never)`.

```cpp
// OJ: https://leetcode.com/problems/minimize-the-maximum-of-two-arrays
// Author: github.com/lzl124631x
// Time: O(logINT_MAX)
// Space: O(1)
class Solution {
public:
    int minimizeSet(int a, int b, int u1, int u2) {
        long L = 0, R = INT_MAX, lcm = (long)a * b / gcd(a, b);
        auto valid = [&](long x) {
            long never = x / lcm;
            return x - x / a - x / b + never >= max(0L, u1 - x / b + never) + max(0L, u2 - x / a + never);
        };
        while (L <= R) {
            long M = (L + R) / 2;
            if (valid(M)) R = M - 1;
            else L = M + 1;
        }
        return L;
    }
};
```

## TODO

https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/solutions/2947402/no-binary-search-solution-top-100-runtime-memory/