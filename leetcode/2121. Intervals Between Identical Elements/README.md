# [2121. Intervals Between Identical Elements (Medium)](https://leetcode.com/problems/intervals-between-identical-elements/)

<p>You are given a <strong>0-indexed</strong> array of <code>n</code> integers <code>arr</code>.</p>

<p>The <strong>interval</strong> between two elements in <code>arr</code> is defined as the <strong>absolute difference</strong> between their indices. More formally, the <strong>interval</strong> between <code>arr[i]</code> and <code>arr[j]</code> is <code>|i - j|</code>.</p>

<p>Return <em>an array</em> <code>intervals</code> <em>of length</em> <code>n</code> <em>where</em> <code>intervals[i]</code> <em>is <strong>the sum of intervals</strong> between </em><code>arr[i]</code><em> and each element in </em><code>arr</code><em> with the same value as </em><code>arr[i]</code><em>.</em></p>

<p><strong>Note:</strong> <code>|x|</code> is the absolute value of <code>x</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [2,1,3,1,2,3,3]
<strong>Output:</strong> [4,2,7,2,4,4,5]
<strong>Explanation:</strong>
- Index 0: Another 2 is found at index 4. |0 - 4| = 4
- Index 1: Another 1 is found at index 3. |1 - 3| = 2
- Index 2: Two more 3s are found at indices 5 and 6. |2 - 5| + |2 - 6| = 7
- Index 3: Another 1 is found at index 1. |3 - 1| = 2
- Index 4: Another 2 is found at index 0. |4 - 0| = 4
- Index 5: Two more 3s are found at indices 2 and 6. |5 - 2| + |5 - 6| = 4
- Index 6: Two more 3s are found at indices 2 and 5. |6 - 2| + |6 - 5| = 5
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [10,5,10,10]
<strong>Output:</strong> [5,0,3,4]
<strong>Explanation:</strong>
- Index 0: Two more 10s are found at indices 2 and 3. |0 - 2| + |0 - 3| = 5
- Index 1: There is only one 5 in the array, so its sum of intervals to identical elements is 0.
- Index 2: Two more 10s are found at indices 0 and 3. |2 - 0| + |2 - 3| = 3
- Index 3: Two more 10s are found at indices 0 and 2. |3 - 0| + |3 - 2| = 4
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == arr.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[TuSimple](https://leetcode.com/company/tusimple), [Wayve](https://leetcode.com/company/wayve)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/)

**Similar Questions**:
* [Continuous Subarray Sum (Medium)](https://leetcode.com/problems/continuous-subarray-sum/)

## Solution 1.

Assume number `k` appears at indices `1, 3, 5, 7`.

For index `1`, `ans[1] = |3-1|+|5-1|+|7-1| = (3+5+7) - 3*1`.

For index `3`, `ans[3] = |3-1|+|5-3|+|7-3| = (5+7) - 2*3 + 1*3 - 1`

...

We can find the following pattern:

Here only consider the indices of the same numbers. Let `rightSum`/`leftSum` be the sum of indices to the right/left of `i`, and `rightCnt`/`leftCnt` be the number of indices to the right/left of `i`.

```
ans[i] = rightSum - rightCnt * i + leftCnt * i - leftSum
```

```cpp
// OJ: https://leetcode.com/problems/intervals-between-identical-elements/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<long long> getDistances(vector<int>& A) {
        unordered_map<int, long> leftSum, leftCnt, rightSum, rightCnt;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            rightSum[A[i]] += i;
            ++rightCnt[A[i]];
        }
        vector<long long> ans(N);
        for (int i = 0; i < N; ++i) {
            rightSum[A[i]] -= i;
            rightCnt[A[i]]--;
            ans[i] = rightSum[A[i]] - rightCnt[A[i]] * i + leftCnt[A[i]] * i - leftSum[A[i]];
            leftSum[A[i]] += i;
            leftCnt[A[i]]++;
        }
        return ans;
    }
};
```

We can update the formula to the following

```
ans[i] = (rightSum - leftSum) - (rightCnt - leftCnt) * i
       = diffSum - diffCnt * i
```

In this way, we only need to keep track of the diffs.

```cpp
// OJ: https://leetcode.com/problems/intervals-between-identical-elements/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<long long> getDistances(vector<int>& A) {
        unordered_map<int, long> diffSum, diffCnt;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            diffSum[A[i]] += i;
            ++diffCnt[A[i]];
        }
        vector<long long> ans(N);
        for (int i = 0; i < N; ++i) {
            diffSum[A[i]] -= i;
            diffCnt[A[i]]--;
            ans[i] = diffSum[A[i]] - diffCnt[A[i]] * i;
            diffSum[A[i]] -= i;
            diffCnt[A[i]]--;
        }
        return ans;
    }
};
```

Minor simplification: We can include `|i-i| = 0` in the formula.

For example:

For index `1`, `ans[1] = |1-1|+|3-1|+|5-1|+|7-1| = (1+3+5+7) - 4*1`.

For index `3`, `ans[3] = |3-1|+|3-3|+|5-3|+|7-3| = (3+5+7) - 3*3 + 1*3 - 1`

...

Now we can define `rightSum` and `rightCnt` be the sum/count of indices `>= i`.

```cpp
// OJ: https://leetcode.com/problems/intervals-between-identical-elements/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<long long> getDistances(vector<int>& A) {
        long long diffSum[100001] = {}, diffCnt[100001] = {}, N = A.size();
        for (int i = 0; i < N; ++i) {
            diffSum[A[i]] += i;
            diffCnt[A[i]]++;
        }
        vector<long long> ans(N);
        for (int i = 0; i < N; ++i) {
            ans[i] = diffSum[A[i]] - diffCnt[A[i]] * i;
            diffSum[A[i]] -= 2 * i;
            diffCnt[A[i]] -= 2;
        }
        return ans;
    }
};
```

## Solution 2.

Similar to [1685. Sum of Absolute Differences in a Sorted Array (Medium)](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/)

```cpp
// OJ: https://leetcode.com/problems/intervals-between-identical-elements/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<long long> getDistances(vector<int>& A) {
        unordered_map<int, vector<int>> m;
        int N = A.size();
        vector<long long> ans(N);
        for (int i = 0; i < N; ++i) m[A[i]].push_back(i);
        for (auto &[n, v] : m) {
            long total = accumulate(begin(v), end(v), 0L), right = total;
            for (long i = 0; i < v.size(); ++i) {
                ans[v[i]] = right - (v.size() - i) * v[i] + i * v[i] - (total - right);
                right -= v[i];
            }
        }
        return ans;
    }
};
```