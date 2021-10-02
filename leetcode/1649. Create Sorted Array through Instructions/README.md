# [1649. Create Sorted Array through Instructions (Hard)](https://leetcode.com/problems/create-sorted-array-through-instructions/)

<p>Given an integer array <code>instructions</code>, you are asked to create a sorted array from the elements in <code>instructions</code>. You start with an empty container <code>nums</code>. For each element from <strong>left to right</strong> in <code>instructions</code>, insert it into <code>nums</code>. The <strong>cost</strong> of each insertion is the <b>minimum</b> of the following:</p>

<ul>
	<li>The number of elements currently in <code>nums</code> that are <strong>strictly less than</strong> <code>instructions[i]</code>.</li>
	<li>The number of elements currently in <code>nums</code> that are <strong>strictly greater than</strong> <code>instructions[i]</code>.</li>
</ul>

<p>For example, if inserting element <code>3</code> into <code>nums = [1,2,3,5]</code>, the <strong>cost</strong> of insertion is <code>min(2, 1)</code> (elements <code>1</code> and <code>2</code> are less than <code>3</code>, element <code>5</code> is greater than <code>3</code>) and <code>nums</code> will become <code>[1,2,3,3,5]</code>.</p>

<p>Return <em>the <strong>total cost</strong> to insert all elements from </em><code>instructions</code><em> into </em><code>nums</code>. Since the answer may be large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> instructions = [1,5,6,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
The total cost is 0 + 0 + 0 + 1 = 1.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> instructions = [1,2,3,6,5,4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> instructions = [1,3,3,3,2,4,2,1,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3].
Insert 3 with cost min(1, 0) = 0, now nums = [1,3,3,3].
Insert 2 with cost min(1, 3) = 1, now nums = [1,2,3,3,3].
Insert 4 with cost min(5, 0) = 0, now nums = [1,2,3,3,3,4].
​​​​​​​Insert 2 with cost min(1, 4) = 1, now nums = [1,2,2,3,3,3,4].
​​​​​​​Insert 1 with cost min(0, 6) = 0, now nums = [1,1,2,2,3,3,3,4].
​​​​​​​Insert 2 with cost min(2, 4) = 2, now nums = [1,1,2,2,2,3,3,3,4].
The total cost is 0 + 0 + 0 + 0 + 1 + 0 + 1 + 0 + 2 = 4.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= instructions.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= instructions[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Related Topics**:  
[Binary Indexed Tree](https://leetcode.com/tag/binary-indexed-tree/), [Segment Tree](https://leetcode.com/tag/segment-tree/), [Ordered Map](https://leetcode.com/tag/ordered-map/)

## Solution 1. BIT

```cpp
// OJ: https://leetcode.com/problems/create-sorted-array-through-instructions/
// Author: github.com/lzl124631x
// Time: O(NlogM) where M is the range of A[i]
// Space: O(M)
// Ref: https://leetcode.com/problems/create-sorted-array-through-instructions/discuss/927531/JavaC%2B%2BPython-Binary-Indexed-Tree
int c[100001] = {};
class Solution {
public:
    static inline int lowbit(int x) { return x & -x; }
    int createSortedArray(vector<int>& A) {
        memset(c, 0, sizeof(c));
        int ans = 0, N = A.size(), mod = 1e9 + 7;
        for (int i = 0; i < N; ++i) {
            ans = (ans + min(get(A[i] - 1), i - get(A[i]))) % mod;
            update(A[i]);
        }
        return ans;
    }
    void update(int x) {
        for (; x < 100001; x += lowbit(x)) c[x]++;
    }
    int get(int x) { // returns the sum of numbers smaller than x
        int ans = 0;
        for (; x > 0; x -= lowbit(x)) ans += c[x];
        return ans;
    }
};
```

## Solution 2. Divide and Conquer

```cpp
// OJ: https://leetcode.com/problems/create-sorted-array-through-instructions/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
const int maxN = 100001;
int id[maxN], lt[maxN], gt[maxN], tmp[maxN];
class Solution {
    void solve(vector<int> &A, int begin, int end) {
        if (begin + 1 >= end) return;
        int mid = (begin + end) / 2, i = begin, j = mid, k = begin;
        solve(A, begin, mid);
        solve(A, mid, end);
        for (; j < end; ++j) {
            while (i < mid && A[id[i]] < A[id[j]]) ++i;
            lt[id[j]] += i - begin;
        }
        for (i = mid - 1, j = end - 1; j >= mid; --j) {
            while (i >= begin && A[id[i]] > A[id[j]]) --i;
            gt[id[j]] += mid - i - 1;
        }
        for (i = begin, j = mid; i < mid || j < end;) {
            if (j >= end || (i < mid && A[id[i]] < A[id[j]])) tmp[k++] = id[i++];
            else tmp[k++] = id[j++];
        }
        for (i = begin; i < end; ++i) id[i] = tmp[i];
    }
public:
    int createSortedArray(vector<int>& A) {
        long N = A.size(), ans = 0, mod = 1e9 + 7;
        iota(begin(id), begin(id) + N, 0);
        memset(lt, 0, sizeof(lt));
        memset(gt, 0, sizeof(lt));
        solve(A, 0, N);
        for (int i = 0; i < N; ++i) ans = (ans + min(lt[i], gt[i])) % mod;
        return ans;
    }
};
```