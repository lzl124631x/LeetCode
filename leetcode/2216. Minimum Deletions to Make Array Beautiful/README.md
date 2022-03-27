# [2216. Minimum Deletions to Make Array Beautiful (Medium)](https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code>. The array <code>nums</code> is <strong>beautiful</strong> if:</p>

<ul>
	<li><code>nums.length</code> is even.</li>
	<li><code>nums[i] != nums[i + 1]</code> for all <code>i % 2 == 0</code>.</li>
</ul>

<p>Note that an empty array is considered beautiful.</p>

<p>You can delete any number of elements from <code>nums</code>. When you delete an element, all the elements to the right of the deleted element will be <strong>shifted one unit to the left</strong> to fill the gap created and all the elements to the left of the deleted element will remain <strong>unchanged</strong>.</p>

<p>Return <em>the <strong>minimum</strong> number of elements to delete from </em><code>nums</code><em> to make it </em><em>beautiful.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,2,3,5]
<strong>Output:</strong> 1
<strong>Explanation:</strong> You can delete either <code>nums[0]</code> or <code>nums[1]</code> to make <code>nums</code> = [1,2,3,5] which is beautiful. It can be proven you need at least 1 deletion to make <code>nums</code> beautiful.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,2,2,3,3]
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can delete <code>nums[0]</code> and <code>nums[5]</code> to make nums = [1,2,2,3] which is beautiful. It can be proven you need at least 2 deletions to make nums beautiful.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/), [Greedy](https://leetcode.com/tag/greedy/)

**Similar Questions**:
* [Minimum Deletions to Make Character Frequencies Unique (Medium)](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)
* [Minimum Operations to Make the Array Alternating (Medium)](https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/)

## Solution 1. Two Pointers + Greedy

We can greedily find the even and odd pairs from left to right.

**Why greedy**? Think if the first two elements, if they are equal, we have to delete one of them -- deleting the rest of the numbers won't change anything to these first two equal numbers. So, when we see two equal numbers, we have to delete one of them, until we find two non-equal numbers.

Use two pointers `i` the write pointer and `j` the read pointer.

We keep the following process until `j` exhausts the array.
* Write `A[j]` to the even-indexed `A[i]` and increment both pointers.
* Try to find the odd-indexed value. Keep skipping/deleting if `A[j] == A[i-1]`.
* If found a valid odd-indexed value, write `A[j]` to `A[i]` and increment both pointers.

Lastly, if the resultant array has an odd length (i.e. `i % 2 != 0`), we delete the last element.

```cpp
// OJ: https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1) extra space
class Solution {
public:
    int minDeletion(vector<int>& A) {
        int i = 0, N = A.size(), j = 0, ans = 0;
        while (j < N) {
            A[i++] = A[j++]; // Write `A[j]` to the even-indexed `A[i]`, increment both pointers
            while (j < N && A[i - 1] == A[j]) ++j, ++ans; // Trying to find the odd-indexed value. Keep skipping/deleting if `A[j] == A[i-1]`
            if (j < N) A[i++] = A[j++]; // If found, write `A[j]` to `A[i]` and increment both pointers
        }
        if (i % 2) ++ans; // If the resultant array is of odd length, delete the last element
        return ans;
    }
};
```

## Solution 2. Greedy

Similar to Solution 1, just find non-equal pairs `A[i]` and `A[i + 1]`. If `A[i] == A[i + 1]`, delete `A[i]` and `++i`.

If in the end, there is no such pair, delete `A[i]`.

```cpp
// OJ: https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minDeletion(vector<int>& A) {
        int i = 0, N = A.size(), ans = 0;
        for (; i < N; i += 2) {
            while (i + 1 < N && A[i] == A[i + 1]) ++i, ++ans; // delete `A[i]`
            if (i + 1 == N) ++ans; // can't find a pair, delete `A[i]`
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/discuss/1886930