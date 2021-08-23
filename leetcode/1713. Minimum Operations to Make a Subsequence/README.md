# [1713. Minimum Operations to Make a Subsequence (Hard)](https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/)

<p>You are given an array <code>target</code> that consists of <strong>distinct</strong> integers and another integer array <code>arr</code> that <strong>can</strong> have duplicates.</p>

<p>In one operation, you can insert any integer at any position in <code>arr</code>. For example, if <code>arr = [1,4,1,2]</code>, you can add <code>3</code> in the middle and make it <code>[1,4,<u>3</u>,1,2]</code>. Note that you can insert the integer at the very beginning or end of the array.</p>

<p>Return <em>the <strong>minimum</strong> number of operations needed to make </em><code>target</code><em> a <strong>subsequence</strong> of </em><code>arr</code><em>.</em></p>

<p>A <strong>subsequence</strong> of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, <code>[2,7,4]</code> is a subsequence of <code>[4,<u>2</u>,3,<u>7</u>,2,1,<u>4</u>]</code> (the underlined elements), while <code>[2,4,2]</code> is not.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> target = [5,1,3], <code>arr</code> = [9,4,2,3,4]
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can add 5 and 1 in such a way that makes <code>arr</code> = [<u>5</u>,9,4,<u>1</u>,2,3,4], then target will be a subsequence of <code>arr</code>.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> target = [6,4,8,1,3,2], <code>arr</code> = [4,7,6,2,3,8,6,1]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= target.length, arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= target[i], arr[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>target</code> contains no duplicates.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Binary Search](https://leetcode.com/tag/binary-search/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. LCS to LIS

The problem is the same as finding the longest common subsequence (LCS) between `T` and `A`. But the LCS DP solution takes `O(TA)` time and will get TLE.

To improve it, we can use the constraint that `T` contains no duplicate. So `T` tells us the arrangement of the numbers. We can replace each element in `A` with the index it appeared in `T`. Then the problem becomes finding the longest increasing subseqence (LIS) which can be done within `O(AlogA)` time.

### Time Complexity

Generating the index map takes `O(T)` time.

Generating the `idx` array takes `O(A)` time.

LIS part takes `O(AlogA)` time.

So overall it's `O(T + AlogA)`.

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/
// Author: github.com/lzl124631x
// Time: O(T + AlogA)
// Space: O(T + A)
class Solution {
public:
    int minOperations(vector<int>& T, vector<int>& A) {
        unordered_map<int, int> m;
        for (int i = 0; i < T.size(); ++i) m[T[i]] = i;
        vector<int> idx, lis;
        for (int n : A) {
            if (m.count(n)) idx.push_back(m[n]);
        }
        for (int n : idx) {
            int i = lower_bound(begin(lis), end(lis), n) - begin(lis);
            if (i == lis.size()) lis.push_back(n);
            else lis[i] = n;
        }
        return T.size() - lis.size();
    }
};
```

## Solution 2. LCS to LIS

For each `T[i]`, we can find a set `S` of indexes such that `A[j] = T[i]` where `j` is in `S`.

For example:

```
T = [6,4,8,1,3,2], A = [4,7,6,2,3,8,6,1]
6 -> [2, 6]
4 -> [0]
8 -> [5]
1 -> [7]
3 -> [4]
2 -> [3]
```
Now we want to find a longest increasing sequence in these indexes. The LIS in the example is `[2, 5, 7]`, which means `[6, 8, 1]` is a LCS between `T` and `A`.

We can reverse each array and concatenate them together and compute the LIS of the resulting array. In the above example, the concatenated array is `[6, 2, 0, 5, 7, 4, 3]`.

### Time Complexity

Generating the index map takes `O(T)` time.

Generating `idx` and `merged` arrays takes `O(A)` time.

LIS part takes `O(AlogA)` time.

So overall it's `O(T + AlogA)`.

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/
// Author: github.com/lzl124631x
// Time: O(T + AlogA)
// Space: O(T + A)
class Solution {
public:
    int minOperations(vector<int>& T, vector<int>& A) {
        unordered_map<int, int> m;
        for (int i = 0; i < T.size(); ++i) m[T[i]] = i;
        vector<vector<int>> idx(T.size());
        for (int i = A.size() - 1; i >= 0; --i) {
            if (m.count(A[i])) idx[m[A[i]]].push_back(i);
        }
        vector<int> merged, lis;
        for (auto &v : idx) {
            for (int n : v) merged.push_back(n);
        }
        for (int n : merged) {
            int i = lower_bound(begin(lis), end(lis), n) - begin(lis);
            if (i == lis.size()) lis.push_back(n);
            else lis[i] = n;
        }
        return T.size() - lis.size();
    }
};
```