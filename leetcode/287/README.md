# [287. Find the Duplicate Number (Medium)](https://leetcode.com/problems/find-the-duplicate-number)

<p>Given an array of integers <code>nums</code> containing&nbsp;<code>n + 1</code> integers where each integer is in the range <code>[1, n]</code> inclusive.</p>

<p>There is only <strong>one repeated number</strong> in <code>nums</code>, return <em>this&nbsp;repeated&nbsp;number</em>.</p>

<p>You must solve the problem <strong>without</strong> modifying the array <code>nums</code>&nbsp;and uses only constant extra space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,3,4,2,2]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,1,3,4,2]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>nums.length == n + 1</code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
	<li>All the integers in <code>nums</code> appear only <strong>once</strong> except for <strong>precisely one integer</strong> which appears <strong>two or more</strong> times.</li>
</ul>

<p>&nbsp;</p>
<p><b>Follow up:</b></p>

<ul>
	<li>How can we prove that at least one duplicate number must exist in <code>nums</code>?</li>
	<li>Can you solve the problem in linear runtime complexity?</li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Yahoo](https://leetcode.com/company/yahoo), [Microsoft](https://leetcode.com/company/microsoft), [PhonePe](https://leetcode.com/company/phonepe), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Apple](https://leetcode.com/company/apple), [Google](https://leetcode.com/company/google), [Facebook](https://leetcode.com/company/facebook), [Uber](https://leetcode.com/company/uber), [Bloomberg](https://leetcode.com/company/bloomberg), [Qualcomm](https://leetcode.com/company/qualcomm), [Cisco](https://leetcode.com/company/cisco), [Walmart Labs](https://leetcode.com/company/walmart-labs)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Two Pointers](https://leetcode.com/tag/two-pointers), [Binary Search](https://leetcode.com/tag/binary-search), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation)

**Similar Questions**:
* [First Missing Positive (Hard)](https://leetcode.com/problems/first-missing-positive)
* [Single Number (Easy)](https://leetcode.com/problems/single-number)
* [Linked List Cycle II (Medium)](https://leetcode.com/problems/linked-list-cycle-ii)
* [Missing Number (Easy)](https://leetcode.com/problems/missing-number)
* [Set Mismatch (Easy)](https://leetcode.com/problems/set-mismatch)

## Solution 1. Binary Search

Numbers less than the duplicate number must have frequencies less than or equal to themselves.

Examples:

* `A = [1 2 3 3 4]`, `1,2` have frequencies (`1,2`) less than or equal to themselves.
* `A = [3 2 3 3 4]`, `1,2` have frequencies (`0,1`) less than or equal to themselves. 

`L < R` template:

* Range: `[1, A.size()-1]` 
* Let `cnt` be the count of numbers less than or equal to `M`. If `cnt <= M`, the duplicate number is greater than `M`, so `L = M + 1`; otherwise, `R = M`.

```cpp
// OJ: https://leetcode.com/problems/find-the-duplicate-number/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int L = 1, R = A.size() - 1;
        while (L < R) {
            int M = (L + R) / 2, cnt = 0;
            for (int n : A) cnt += n <= M;
            if (cnt <= M) L = M + 1;
            else R = M;
        }
        return L;
    }
};
```

`L <= R` template:

* Range: `[1, A.size()-1]`.
* Let `cnt` be the count of numbers less than or equal to `M`. The answer is the first number that `cnt > ` itself. So, we return `L` in the end.

```cpp
// OJ: https://leetcode.com/problems/find-the-duplicate-number/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int L = 1, R = A.size() - 1;
        while (L <= R) {
            int M = (L + R) / 2, cnt = 0;
            for (int n : A) cnt += n <= M;
            if (cnt <= M) L = M + 1;
            else R = M - 1;
        }
        return L;
    }
};
```

## Solution 2. Floyd's Tortoise and Hare (Cycle Detection)

```cpp
// OJ: https://leetcode.com/problems/find-the-duplicate-number/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int p = A[0], q = A[p];
        for (; p != q; p = A[p], q = A[A[q]]);
        for (p = 0; p != q; p = A[p], q = A[q]);
        return p;
    }
};
```

## Solution 3. Cycle Sort

```cpp
// OJ: https://leetcode.com/problems/find-the-duplicate-number
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& A) {
        for (int i = 0, N = A.size(); i < N; ++i) {
            while (A[i] - 1 != i) {
                if (A[i] == A[A[i] - 1]) return A[i];
                swap(A[i], A[A[i] - 1]);
            }
        }
        return -1;
    }
};
```