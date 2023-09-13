# [1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows (Hard)](https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/)

<p>You are given an&nbsp;<code>m&nbsp;* n</code>&nbsp;matrix,&nbsp;<code>mat</code>, and an integer <code>k</code>,&nbsp;which&nbsp;has its rows sorted in non-decreasing&nbsp;order.</p>

<p>You are allowed to choose exactly 1 element from each row to form an array.&nbsp;Return the Kth <strong>smallest</strong> array sum among all possible arrays.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> mat = [[1,3,11],[2,4,6]], k = 5
<strong>Output:</strong> 7
<strong>Explanation: </strong>Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  </pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> mat = [[1,3,11],[2,4,6]], k = 9
<strong>Output:</strong> 17
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
<strong>Output:</strong> 9
<strong>Explanation:</strong> Choosing one element from each row, the first k smallest sum are:
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> mat = [[1,1,10],[2,2,9]], k = 7
<strong>Output:</strong> 12
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == mat.length</code></li>
	<li><code>n == mat.length[i]</code></li>
	<li><code>1 &lt;= m, n &lt;= 40</code></li>
	<li><code>1 &lt;= k &lt;= min(200, n ^&nbsp;m)</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 5000</code></li>
	<li><code>mat[i]</code> is a non decreasing array.</li>
</ul>


**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/)

## Solution 1.

Ugly answer wrote during the context.

```cpp
// OJ: https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
// Author: github.com/lzl124631x
typedef pair<int, string> Pair;
struct Cmp {
    bool operator()(const Pair &a, const Pair &b) {
        return a.first > b.first;
    }
};
class Solution {
    string hash(vector<int> &idx) {
        string s;
        for (int i = 0; i < idx.size(); ++i) {
            auto h = to_string(idx[i]);
            if (h.size() == 1) h = "0" + h;
            s += h;
        }
        return s;
    }
    vector<int> dehash(string s, int M) {
        vector<int> v(M);
        for (int i = 0; i < M; ++i) v[i] = (s[2 * i] - '0') * 10 + s[2 * i + 1] - '0';
        return v;
    }
public:
    int kthSmallest(vector<vector<int>>& A, int k) {
        int M = A.size(), N = A[0].size(), sum = 0;
        unordered_set<string> seen;
        priority_queue<Pair, vector<Pair>, Cmp> q;
        vector<int> idx(M);
        auto idxHash = hash(idx);
        seen.insert(idxHash);
        for (int i = 0; i < M; ++i) sum += A[i][0];
        q.emplace(sum, idxHash);
        int x = 1;
        while (k--) {
            auto &p = q.top();
            sum = p.first;
            auto v = dehash(p.second, M);
            for (int i = 0; i < M; ++i) {
                if (v[i] + 1 >= N) continue;
                int nsum = sum + A[i][v[i] + 1] - A[i][v[i]];
                v[i]++;
                auto h = hash(v);
                if (!seen.count(h)) {
                    q.emplace(nsum, h);
                    seen.insert(h);
                }
                v[i]--;
            }
            q.pop();
        }
        return sum;
    }
};
```