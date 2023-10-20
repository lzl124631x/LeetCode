# [2780. Minimum Index of a Valid Split (Medium)](https://leetcode.com/problems/minimum-index-of-a-valid-split)

<p>An element <code>x</code> of an integer array <code>arr</code> of length <code>m</code> is <strong>dominant</strong> if <code>freq(x) * 2 &gt; m</code>, where <code>freq(x)</code> is the number of occurrences of <code>x</code> in <code>arr</code>. Note that this definition implies that <code>arr</code> can have <strong>at most one</strong> dominant element.</p>

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code> with one dominant element.</p>

<p>You can split <code>nums</code> at an index <code>i</code> into two arrays <code>nums[0, ..., i]</code> and <code>nums[i + 1, ..., n - 1]</code>, but the split is only <strong>valid</strong> if:</p>

<ul>
	<li><code>0 &lt;= i &lt; n - 1</code></li>
	<li><code>nums[0, ..., i]</code>, and <code>nums[i + 1, ..., n - 1]</code> have the same dominant element.</li>
</ul>

<p>Here, <code>nums[i, ..., j]</code> denotes the subarray of <code>nums</code> starting at index <code>i</code> and ending at index <code>j</code>, both ends being inclusive. Particularly, if <code>j &lt; i</code> then <code>nums[i, ..., j]</code> denotes an empty subarray.</p>

<p>Return <em>the <strong>minimum</strong> index of a <strong>valid split</strong></em>. If no valid split exists, return <code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,2,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can split the array at index 2 to obtain arrays [1,2,2] and [2]. 
In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 &gt; 3. 
In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 &gt; 1.
Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split. 
It can be shown that index 2 is the minimum index of a valid split. </pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,3,1,1,1,7,1,2,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> We can split the array at index 4 to obtain arrays [2,1,3,1,1] and [1,7,1,2,1].
In array [2,1,3,1,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 &gt; 5.
In array [1,7,1,2,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 &gt; 5.
Both [2,1,3,1,1] and [1,7,1,2,1] have the same dominant element as nums, so this is a valid split.
It can be shown that index 4 is the minimum index of a valid split.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,3,3,3,7,2,2]
<strong>Output:</strong> -1
<strong>Explanation:</strong> It can be shown that there is no valid split.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code> has exactly one dominant element.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Hash Table](https://leetcode.com/tag/hash-table), [Sorting](https://leetcode.com/tag/sorting)

**Similar Questions**:
* [Majority Element (Easy)](https://leetcode.com/problems/majority-element)
* [Partition Array into Disjoint Intervals (Medium)](https://leetcode.com/problems/partition-array-into-disjoint-intervals)

**Hints**:
* Find the dominant element of nums by using a hashmap to maintain element frequency, we denote the dominant element as x and its frequency as f.
* For each index in [0, n - 2], calculate f1, x’s frequency in the subarray [0, i] when looping the index. And f2, x’s frequency in the subarray [i + 1, n - 1] which is equal to f - f1. Then we can check whether x is dominant in both subarrays.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-index-of-a-valid-split
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int minimumIndex(vector<int>& A) {
        unordered_map<int, int> leftCnt, rightCnt;
        set<pair<int, int>> left, right; // cnt, number
        for (int n : A) rightCnt[n]++;
        for (auto &[n, c] : rightCnt) right.emplace(c, n);
        int N = A.size();
        for (int i = 0; i < N - 1; ++i) {
            int n = A[i], c = rightCnt[n], lc = leftCnt[n];
            right.erase({c, n});
            if (c - 1 > 0) right.emplace(c - 1, n);
            rightCnt[n]--;
            if (lc != 0) left.erase({lc, n});
            left.emplace(lc + 1, n);
            leftCnt[n]++;
            if (left.rbegin()->first * 2 > i + 1 && right.rbegin()->first * 2 > N - i - 1 && left.rbegin()->second == right.rbegin()->second) return i;
        }
        return -1;
    }
};
```

## Solution 2.

If the left side has a new dominant element, it must be `A[i]`.

Even though the dominant element in the right side might not be `A[i]` as well, but we can check `A[i]`'s frequency in the right side. If this frequency multiplied by `2` is greater than `N-i-1`, then `A[i]` is also the dominant element in the right side.

```cpp
// OJ: https://leetcode.com/problems/minimum-index-of-a-valid-split
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minimumIndex(vector<int>& A) {
        unordered_map<int, int> L, R;
        int N = A.size();
        for (int n : A) R[n]++;
        for (int i = 0; i < N - 1; ++i) {
            int a = ++L[A[i]], b = --R[A[i]];
            if (a * 2 > i + 1 && b * 2 > N - i - 1) return i;
        }
        return -1;
    }
};
```