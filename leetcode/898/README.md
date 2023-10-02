# [898. Bitwise ORs of Subarrays (Medium)](https://leetcode.com/problems/bitwise-ors-of-subarrays/)

<p>We have an array <code>arr</code> of non-negative integers.</p>

<p>For every (contiguous) subarray <code>sub = [arr[i], arr[i + 1], ..., arr[j]]</code> (with <code>i &lt;= j</code>), we take the bitwise OR of all the elements in <code>sub</code>, obtaining a result <code>arr[i] | arr[i + 1] | ... | arr[j]</code>.</p>

<p>Return the number of possible results. Results that occur more than once are only counted once in the final answer</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [0]
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only one possible result: 0.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,1,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [1,2,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The possible results are 1, 2, 3, 4, 6, and 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i]&nbsp;&lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

## Solution 1.

**Complexity Analysis**: 

Let `XOR(i, j) = A[i] | A[i + 1] | ... | A[j]`. Hash set `cur` stores all `XOR(0, i), XOR(1, i), ..., XOR(i, i)`.

Since
* there are at most 30 bits for a positive number `0 <= A[i] <= 1e9`
* `XOR(k, i)` must covers all the bits in `XOR(k + 1, i)` and at most has one more bit 1 than the latter.
  
The set `cur` or the sequence `XOR(0, i), XOR(1, i), ..., XOR(i, i)` must at most has 30 unique values.

So, `cur.size() <= 30` and `ans.size() <= 30 * A.size()`.

So the time and space complexities are `O(30N)`.

```cpp
// OJ: https://leetcode.com/problems/bitwise-ors-of-subarrays/
// Author: github.com/lzl124631x
// Time: O(30N)
// Space: O(30N)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> all, cur, next;
        for (int n : A) {
            next.clear();
            next.insert(n);
            for (int prev : cur) next.insert(prev | n);
            for (int m : next) all.insert(m);
            swap(cur, next);
        }
        return all.size();
    }
};
```

Or use `vector<int>`.

```cpp
// OJ: https://leetcode.com/problems/bitwise-ors-of-subarrays/
// Author: github.com/lzl124631x
// Time: O(30N)
// Space: O(30N)
class Solution {
public:
    int subarrayBitwiseORs(vector<int> A) {
        vector<int> ans;
        int left = 0, right; // numbers in range [left, right) correspond to `cur` set.
        for (int n : A) {
            right = ans.size();
            ans.push_back(n);
            for (int i = left; i < right; ++i) {
                if (ans.back() != (ans[i] | n)) {
                    ans.push_back(ans[i] | n);
                }
            }
            left = right;
        }
        sort(begin(ans), end(ans));
        return unique(begin(ans), end(ans)) - begin(ans);
    }
};
```