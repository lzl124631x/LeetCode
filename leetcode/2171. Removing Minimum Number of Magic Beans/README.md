# [2171. Removing Minimum Number of Magic Beans (Medium)](https://leetcode.com/problems/removing-minimum-number-of-magic-beans/)

<p>You are given an array of <strong>positive</strong> integers <code>beans</code>, where each integer represents the number of magic beans found in a particular magic bag.</p>

<p><strong>Remove</strong> any number of beans (<strong>possibly none</strong>) from each bag such that the number of beans in each remaining <strong>non-empty</strong> bag (still containing <strong>at least one</strong> bean) is <strong>equal</strong>. Once a bean has been removed from a bag, you are <strong>not</strong> allowed to return it to any of the bags.</p>

<p>Return <em>the <strong>minimum</strong> number of magic beans that you have to remove</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> beans = [4,<u><strong>1</strong></u>,6,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
- We remove 1 bean from the bag with only 1 bean.
  This results in the remaining bags: [4,<b><u>0</u></b>,6,5]
- Then we remove 2 beans from the bag with 6 beans.
  This results in the remaining bags: [4,0,<strong><u>4</u></strong>,5]
- Then we remove 1 bean from the bag with 5 beans.
  This results in the remaining bags: [4,0,4,<b><u>4</u></b>]
We removed a total of 1 + 2 + 1 = 4 beans to make the remaining non-empty bags have an equal number of beans.
There are no other solutions that remove 4 beans or fewer.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> beans = [<strong><u>2</u></strong>,10,<u><strong>3</strong></u>,<strong><u>2</u></strong>]
<strong>Output:</strong> 7
<strong>Explanation:</strong>
- We remove 2 beans from one of the bags with 2 beans.
  This results in the remaining bags: [<u><strong>0</strong></u>,10,3,2]
- Then we remove 2 beans from the other bag with 2 beans.
  This results in the remaining bags: [0,10,3,<u><strong>0</strong></u>]
- Then we remove 3 beans from the bag with 3 beans. 
  This results in the remaining bags: [0,10,<u><strong>0</strong></u>,0]
We removed a total of 2 + 2 + 3 = 7 beans to make the remaining non-empty bags have an equal number of beans.
There are no other solutions that removes 7 beans or fewer.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= beans.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= beans[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Minimum Moves to Equal Array Elements II (Medium)](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)
* [Minimum Operations to Reduce X to Zero (Medium)](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

## Solution 1. Sorting

Sort the original array `A`.

If we select `A[i]` as the number of beans in a non-empty bag, the number of removals needed is `sum(A) - (N - i) * A[i]`.

**Meaning of equation**

For all `A[j] (j < i)`, they are completely removed, contributing `A[0] + .. + A[i-1]` removals.

For all `A[j] (j >= i)`, they become all `A[i]`s, contributing `A[i] + .. + A[N-1] - (N-i) * A[i]` removals.

Summing these two up, we get `sum(A) - (N - i) * A[i]`.

Another way to think this is to remove every thing and recover `(N - i) * A[i]` beans that shouldn't be removed.

**Why we should pick the number from `A`**

Assume `A  = [1,5,10]`. If we pick a number that is not in `A`, say `3`, `A` becomes `[0,3,3]`. This is definitely not better than picking `A[i] = 5` resulting in `[0,5,5]`. So, a solution picking a non-existent number is always dominated by another solution picking an existing number.

**Example:**

`A = [1,4,5,6]`, `sum(A) = 16`

* If we pick `A[0] = 1`, the result array is `[1,1,1,1]`, # of removals is `16 - (4 - 0) * 1 = 12`.
* If we pick `A[1] = 4`, the result array is `[0,4,4,4]`, # of removals is `16 - (4 - 1) * 4 = 4`.
* If we pick `A[2] = 5`, the result array is `[0,0,5,5]`, # of removals is `16 - (4 - 2) * 5 = 6`.
* If we pick `A[3] = 6`, the result array is `[0,0,0,6]`, # of removals is `16 - (4 - 3) * 6 = 10`.

```cpp
// OJ: https://leetcode.com/problems/removing-minimum-number-of-magic-beans/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    long long minimumRemoval(vector<int>& A) {
        long N = A.size(), ans = LLONG_MAX, sum = accumulate(begin(A), end(A), 0L);
        sort(begin(A), end(A));
        for (int i = 0; i < N; ++i) ans = min(ans, sum - (N - i) * A[i]);
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/removing-minimum-number-of-magic-beans/discuss/1766764