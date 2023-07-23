# [2179. Count Good Triplets in an Array (Hard)](https://leetcode.com/problems/count-good-triplets-in-an-array/)

<p>You are given two <strong>0-indexed</strong> arrays <code>nums1</code> and <code>nums2</code> of length <code>n</code>, both of which are <strong>permutations</strong> of <code>[0, 1, ..., n - 1]</code>.</p>

<p>A <strong>good triplet</strong> is a set of <code>3</code> <strong>distinct</strong> values which are present in <strong>increasing order</strong> by position both in <code>nums1</code> and <code>nums2</code>. In other words, if we consider <code>pos1<sub>v</sub></code> as the index of the value <code>v</code> in <code>nums1</code> and <code>pos2<sub>v</sub></code> as the index of the value <code>v</code> in <code>nums2</code>, then a good triplet will be a set <code>(x, y, z)</code> where <code>0 &lt;= x, y, z &lt;= n - 1</code>, such that <code>pos1<sub>x</sub> &lt; pos1<sub>y</sub> &lt; pos1<sub>z</sub></code> and <code>pos2<sub>x</sub> &lt; pos2<sub>y</sub> &lt; pos2<sub>z</sub></code>.</p>

<p>Return <em>the <strong>total number</strong> of good triplets</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [2,0,1,3], nums2 = [0,1,2,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 
There are 4 triplets (x,y,z) such that pos1<sub>x</sub> &lt; pos1<sub>y</sub> &lt; pos1<sub>z</sub>. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
Out of those triplets, only the triplet (0,1,3) satisfies pos2<sub>x</sub> &lt; pos2<sub>y</sub> &lt; pos2<sub>z</sub>. Hence, there is only 1 good triplet.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>3 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= n - 1</code></li>
	<li><code>nums1</code> and <code>nums2</code> are permutations of <code>[0, 1, ..., n - 1]</code>.</li>
</ul>


**Similar Questions**:
* [Count of Smaller Numbers After Self (Hard)](https://leetcode.com/problems/count-of-smaller-numbers-after-self/)
* [Increasing Triplet Subsequence (Medium)](https://leetcode.com/problems/increasing-triplet-subsequence/)
* [Create Sorted Array through Instructions (Hard)](https://leetcode.com/problems/create-sorted-array-through-instructions/)

## Solution 1. Divide and Conquer (Merge Sort)


The first idea is that we pick a number as the middle number in the triplet, and count the common numbers in front of this number and after this number.

For example, 

```
A = [4,0,1,3,2]
B = [4,1,0,2,3]
```

For number `1`, there is a single common number (`4`) in front of `1` and two common numbers (`3,4`) after `1`, so the count of triplets with `1` in the middle is `1 * 2 = 2`.

But counting the common numbers is not easy. **Since the numbers are permutations of `[0, N-1]`, we can simplify the problem by mapping one of the array to `[0, N-1]`.**

For example, if we map `A` to `[0, N-1]`.

```
A = [4,0,1,3,2]
A'= [0,1,2,3,4]
mapping = 4->0, 0->1, 1->2, 3->3, 2->4
```

We apply the same mapping to `B`

```
B = [4,1,0,2,3]
B'= [0,2,1,4,3]
```

Now look at the new arrays

```
A = [0,1,2,3,4]
B = [0,2,1,4,3]
```

For the number `1`, we trivially know that in `A`, there is one number `0` before it and 3 numbers `2,3,4` after it. So, we just need to look at `B`. The problem now becomes counting in `B` the numbers smaller than `1` before `1` and numbers greater than `1` after `1`.

Let `lt[i]` be the count of numbers smaller than `B[i]`. The count of common numbers less than `B[i]` in both arrays is `min(B[i], lt[i]) = lt[i]`. The count of common numbers after `B[i]` in `A` is `N - B[i] - 1`. The count of common numbers after `B[i]` in `B` is `N - i - 1 - (B[i] - lt[i]) = N - B[i] - 1 - i + lt[i]`. Since `i >= lt[i]`, `-i + lt[i] <= 0`, the count of common numbers after `B[i]` in both arrays is `N - B[i] - 1 - i + lt[i]`.

So, the count of triplets with `B[i]` as the middle number is `lt[i] * (N - B[i] - 1 - i + lt[i])`

```cpp
// OJ: https://leetcode.com/problems/count-good-triplets-in-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    long long goodTriplets(vector<int>& A, vector<int>& B) {
        long N = A.size(), ans = 0;
        vector<int> m(N), lt(N), tmp(N), tmpLt(N), index(N);
        for (int i = 0; i < N; ++i) m[A[i]] = i;
        for (int i = 0; i < N; ++i) {
            B[i] = m[B[i]];
            index[B[i]] = i;
        }
        function<void(int, int)> merge = [&](int begin, int end) {
            if (begin + 1 >= end) return;
            int mid = (begin + end) / 2;
            merge(begin, mid);
            merge(mid, end);
            int i = begin, j = mid, k = begin;
            for (; k < end; ++k) {
                if (j >= end || (i < mid && B[i] < B[j])) {
                    tmp[k] = B[i];
                    tmpLt[k] = lt[i];
                    ++i;
                } else {
                    tmp[k] = B[j];
                    tmpLt[k] = lt[j] + i - begin;
                    ++j;
                }
            }
            for (int i = begin; i < end; ++i) {
                B[i] = tmp[i];
                lt[i] = tmpLt[i];
            }
        };
        merge(0, N);
        for (int i = 0; i < N; ++i) {
            ans += (long)lt[i] * (N - B[i] - 1 - index[B[i]] + lt[i]);
        }
        return ans;
    }
};
```

## Solution 2. Binary Index Tree

```cpp
// OJ: https://leetcode.com/problems/count-good-triplets-in-an-array/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode-cn.com/problems/count-good-triplets-in-an-array/solution/deng-jie-zhuan-huan-shu-zhuang-shu-zu-by-xmyd/
class Solution {
public:
    long long goodTriplets(vector<int> &A, vector<int> &B) {
        int N = A.size();
        vector<int> m(N);
        for (int i = 0; i < N; ++i) m[A[i]] = i;
        long long ans = 0;
        vector<int> tree(N + 1);
        for (int i = 1; i < N - 1; ++i) {
            for (int j = m[B[i - 1]] + 1; j <= N; j += j & -j) ++tree[j]; // increment the count of m[B[i-1]]
            int y = m[B[i]], less = 0;
            for (int j = y; j; j &= j - 1) less += tree[j]; // count all the numbers less than m[B[i]]
            ans += (long)less * (N - 1 - y - (i - less));
        }
        return ans;
    }
};
```