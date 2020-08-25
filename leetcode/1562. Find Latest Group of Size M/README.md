# [1562. Find Latest Group of Size M (Medium)](https://leetcode.com/problems/find-latest-group-of-size-m/)

<p>Given an array <code>arr</code>&nbsp;that represents a permutation of numbers from <code>1</code>&nbsp;to <code>n</code>. You have a binary string of size&nbsp;<code>n</code>&nbsp;that initially has all its bits set to zero.</p>

<p>At each step <code>i</code>&nbsp;(assuming both the binary string and <code>arr</code> are 1-indexed) from <code>1</code> to&nbsp;<code>n</code>, the bit at position&nbsp;<code>arr[i]</code>&nbsp;is set to&nbsp;<code>1</code>. You are given an integer&nbsp;<code>m</code>&nbsp;and you need to find the latest step at which there exists a group of ones of length&nbsp;<code>m</code>. A group of ones is a contiguous substring of 1s such that it cannot be extended in either direction.</p>

<p>Return <em>the latest step at which there exists a group of ones of length <strong>exactly</strong></em>&nbsp;<code>m</code>. <em>If no such group exists, return</em>&nbsp;<code>-1</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [3,5,1,2,4], m = 1
<strong>Output:</strong> 4
<strong>Explanation:
</strong>Step 1: "00<u>1</u>00", groups: ["1"]
Step 2: "0010<u>1</u>", groups: ["1", "1"]
Step 3: "<u>1</u>0101", groups: ["1", "1", "1"]
Step 4: "1<u>1</u>101", groups: ["111", "1"]
Step 5: "111<u>1</u>1", groups: ["11111"]
The latest step at which there exists a group of size 1 is step 4.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [3,1,5,4,2], m = 2
<strong>Output:</strong> -1
<strong>Explanation:
</strong>Step 1: "00<u>1</u>00", groups: ["1"]
Step 2: "<u>1</u>0100", groups: ["1", "1"]
Step 3: "1010<u>1</u>", groups: ["1", "1", "1"]
Step 4: "101<u>1</u>1", groups: ["1", "111"]
Step 5: "1<u>1</u>111", groups: ["11111"]
No group of size 2 exists during any step.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [1], m = 1
<strong>Output:</strong> 1
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> arr = [2,1], m = 2
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == arr.length</code></li>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>1 &lt;= arr[i] &lt;= n</code></li>
	<li>All integers in&nbsp;<code>arr</code>&nbsp;are&nbsp;<strong>distinct</strong>.</li>
	<li><code>1 &lt;= m&nbsp;&lt;= arr.length</code></li>
</ul>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Data on Interval's Edge

We store the length information on the edge nodes of the intervals. When merging intervals, we only need to update the new edge nodes since they are the only ones that we'll use later.

```cpp
// OJ: https://leetcode.com/problems/find-latest-group-of-size-m/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// Ref: https://leetcode.com/problems/find-latest-group-of-size-m/discuss/806786/JavaC%2B%2BPython-Count-the-Length-of-Groups-O(N)
class Solution {
public:
    int findLatestStep(vector<int>& A, int m) {
        int N = A.size(), ans = -1;
        if (N == m) return N;
        vector<int> len(N + 2);
        for (int i = 0; i < N; ++i) {
            int n = A[i], left = len[n - 1], right = len[n + 1];
            len[n - left] = len[n + right] = left + right + 1;
            if (left == m || right == m) ans = i;
        }
        return ans;
    }
};
```

## Solution 2. UnionFind

```cpp
// OJ: https://leetcode.com/problems/find-latest-group-of-size-m/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
    vector<int> id, size;
    int cnt = 0;
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
    void connect(int x, int y, int m) {
        int p = find(x), q = find(y);
        if (size[q] == m) --cnt;
        size[p] += size[q];
        id[q] = p;
    }
public:
    int findLatestStep(vector<int>& A, int m) {
        int N = A.size(), ans = -1;
        id.assign(N, 0);
        size.assign(N, 0);
        iota(begin(id), end(id), 0);
        for (int i = 0; i < N; ++i) {
            int n = A[i] - 1;
            size[n] = 1;
            if (n - 1 >= 0 && size[n - 1]) connect(n, n - 1, m);
            if (n + 1 < N && size[n + 1]) connect(n, n + 1, m);
            if (size[n] == m) ++cnt;
            if (cnt) ans = i + 1;
        }
        return ans;
    }
};
```