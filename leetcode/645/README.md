# [645. Set Mismatch (Easy)](https://leetcode.com/problems/set-mismatch/)

<p>You have a set of integers <code>s</code>, which originally contains all the numbers from <code>1</code> to <code>n</code>. Unfortunately, due to some error, one of the numbers in <code>s</code> got duplicated to another number in the set, which results in <strong>repetition of one</strong> number and <strong>loss of another</strong> number.</p>

<p>You are given an integer array <code>nums</code> representing the data status of this set after the error.</p>

<p>Find the number that occurs twice and the number that is missing and return <em>them in the form of an array</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,2,4]
<strong>Output:</strong> [2,3]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1]
<strong>Output:</strong> [1,2]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Find the Duplicate Number (Medium)](https://leetcode.com/problems/find-the-duplicate-number/)

## Solution 1. unordered_map

```cpp
// OJ: https://leetcode.com/problems/set-mismatch
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& A) {
        unordered_map<int, int> m;
        for (auto n : A) m[n]++;
        int missing, dup;
        for (int i = 1; i <= A.size(); ++i) {
            if (!m.count(i)) missing = i;
            if (m[i] == 2) dup = i;
        }
        return { dup, missing };
    }
};
```

## Solution 2. Sort

```cpp
// OJ: https://leetcode.com/problems/set-mismatch/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& A) {
        sort(begin(A), end(A));
        int dup, missing = 1;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] == A[i - 1]) dup = A[i];
            else if (A[i] > A[i - 1] + 1) missing = A[i - 1] + 1;
        }
        return { dup, A.back() != A.size() ? (int)A.size() : missing };
    }
};
```
## Solution 3. Flip Sign

If we can encode the Counts Array into `nums`, we can save space.

When we visit a number `n` in `nums`, we invert `nums[abs(n) - 1]`. If the number `n` just appears once, the corresponding `nums[abs(n) - 1]` will be negative. When we see a negative `nums[abs(n) - 1]`, it means `n` has been visited -- it's the duplicate.

If `nums[i]` is left positive, then `i + 1` is the missing number.

```cpp
// OJ: https://leetcode.com/problems/set-mismatch/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup, missing;
        for (int n : nums) {
            if (nums[abs(n) - 1] < 0) dup = abs(n);
            else nums[abs(n) - 1] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) missing = i + 1;
        }
        return { dup, missing };
    }
};
```

## Solution 3. Swap

```cpp
// OJ: https://leetcode.com/problems/set-mismatch/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& A) {
        int N = A.size();
        for (int i = 0; i < A.size(); ++i) {
            while (A[i] != i + 1 && A[A[i] - 1] != A[i]) swap(A[i], A[A[i] - 1]);
        }
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != i + 1) return {A[i], i + 1};
        }
        return {};
    }
};
```