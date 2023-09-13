# [315. Count of Smaller Numbers After Self (Hard)](https://leetcode.com/problems/count-of-smaller-numbers-after-self)

<p>Given an integer array <code>nums</code>, return<em> an integer array </em><code>counts</code><em> where </em><code>counts[i]</code><em> is the number of smaller elements to the right of </em><code>nums[i]</code>.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [5,2,6,1]
<strong>Output:</strong> [2,1,1,0]
<strong>Explanation:</strong>
To the right of 5 there are <b>2</b> smaller elements (2 and 1).
To the right of 2 there is only <b>1</b> smaller element (1).
To the right of 6 there is <b>1</b> smaller element (1).
To the right of 1 there is <b>0</b> smaller element.
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [-1]
<strong>Output:</strong> [0]
</pre>
<p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [-1,-1]
<strong>Output:</strong> [0,0]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/), [Merge Sort](https://leetcode.com/tag/merge-sort/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

**Similar Questions**:
* [Count of Range Sum (Hard)](https://leetcode.com/problems/count-of-range-sum/)
* [Queue Reconstruction by Height (Medium)](https://leetcode.com/problems/queue-reconstruction-by-height/)
* [Reverse Pairs (Hard)](https://leetcode.com/problems/reverse-pairs/)
* [How Many Numbers Are Smaller Than the Current Number (Easy)](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)
* [Count Good Triplets in an Array (Hard)](https://leetcode.com/problems/count-good-triplets-in-an-array/)
* [Count the Number of K-Big Indices (Hard)](https://leetcode.com/problems/count-the-number-of-k-big-indices/)

## Solution 1. Divide and Conquer (Merge Sort)

The idea is similar to Merge Sort.

```cpp
// OJ: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    vector<int> id, tmp, ans;
    void solve(vector<int> &A, int begin, int end) {
        if (begin + 1 >= end) return;
        int mid = (begin + end) / 2, i = begin, j = mid, k = begin;
        solve(A, begin, mid);
        solve(A, mid, end);
        for (; i < mid; ++i) {
            while (j < end && A[id[j]] < A[id[i]]) {
                tmp[k++] = id[j++];
            }
            ans[id[i]] += j - mid;
            tmp[k++] = id[i];
        }
        for (; j < end; ++j) tmp[k++] = id[j];
        for (int i = begin; i < end; ++i) id[i] = tmp[i];
    }
public:
    vector<int> countSmaller(vector<int>& A) {
        int N = A.size();
        id.assign(N, 0);
        tmp.assign(N, 0);
        ans.assign(N, 0);
        iota(begin(id), end(id), 0);
        solve(A, 0, N);
        return ans;
    }
};
```

## Solution 2. Binary Indexed Tree

```cpp
// OJ: https://leetcode.com/problems/count-of-smaller-numbers-after-self
// Author: github.com/lzl124631x
// Time: O(NlogM) where M is the range of A[i]
// Space: O(M)
class BIT {
    vector<int> node;
    static inline int lb(int x) { return x & -x; }
public:
    BIT(int N) : node(N + 1) {}
    int query(int i) { // query range is [-1, N-1]. [0,N-1] are valid external indices. -1 is a special index meaning 
empty set
        int ans = 0;
        for (++i; i; i -= lb(i)) ans += node[i];
        return ans;
    }
    void update(int i, int delta) {
        for (++i; i < node.size(); i += lb(i)) node[i] += delta;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& A) {
        long N = A.size(), offset = 1e4; 
        vector<int> ans(N);
        BIT bit(2 * 1e4 + 1); // query(i) is the number of elements <= i
        for (int i = N - 1; i >= 0; --i) {
            ans[i] = bit.query(offset + A[i] - 1);
            bit.update(offset + A[i], 1);
        }
        return ans;
    }
};
```
