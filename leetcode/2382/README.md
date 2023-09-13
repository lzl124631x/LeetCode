# [2382. Maximum Segment Sum After Removals (Hard)](https://leetcode.com/problems/maximum-segment-sum-after-removals)

<p>You are given two <strong>0-indexed</strong> integer arrays <code>nums</code> and <code>removeQueries</code>, both of length <code>n</code>. For the <code>i<sup>th</sup></code> query, the element in <code>nums</code> at the index <code>removeQueries[i]</code> is removed, splitting <code>nums</code> into different segments.</p>
<p>A <strong>segment</strong> is a contiguous sequence of <strong>positive</strong> integers in <code>nums</code>. A <strong>segment sum</strong> is the sum of every element in a segment.</p>
<p>Return<em> an integer array </em><code>answer</code><em>, of length </em><code>n</code><em>, where </em><code>answer[i]</code><em> is the <strong>maximum</strong> segment sum after applying the </em><code>i<sup>th</sup></code> <em>removal.</em></p>
<p><strong>Note:</strong> The same index will <strong>not</strong> be removed more than once.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,5,6,1], removeQueries = [0,3,2,4,1]
<strong>Output:</strong> [14,7,2,2,0]
<strong>Explanation:</strong> Using 0 to indicate a removed element, the answer is as follows:
Query 1: Remove the 0th element, nums becomes [0,2,5,6,1] and the maximum segment sum is 14 for segment [2,5,6,1].
Query 2: Remove the 3rd element, nums becomes [0,2,5,0,1] and the maximum segment sum is 7 for segment [2,5].
Query 3: Remove the 2nd element, nums becomes [0,2,0,0,1] and the maximum segment sum is 2 for segment [2]. 
Query 4: Remove the 4th element, nums becomes [0,2,0,0,0] and the maximum segment sum is 2 for segment [2]. 
Query 5: Remove the 1st element, nums becomes [0,0,0,0,0] and the maximum segment sum is 0, since there are no segments.
Finally, we return [14,7,2,2,0].</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,11,1], removeQueries = [3,2,1,0]
<strong>Output:</strong> [16,5,3,0]
<strong>Explanation:</strong> Using 0 to indicate a removed element, the answer is as follows:
Query 1: Remove the 3rd element, nums becomes [3,2,11,0] and the maximum segment sum is 16 for segment [3,2,11].
Query 2: Remove the 2nd element, nums becomes [3,2,0,0] and the maximum segment sum is 5 for segment [3,2].
Query 3: Remove the 1st element, nums becomes [3,0,0,0] and the maximum segment sum is 3 for segment [3].
Query 4: Remove the 0th element, nums becomes [0,0,0,0] and the maximum segment sum is 0, since there are no segments.
Finally, we return [16,5,3,0].
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>n == nums.length == removeQueries.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= removeQueries[i] &lt; n</code></li>
	<li>All the values of <code>removeQueries</code> are <strong>unique</strong>.</li>
</ul>

**Companies**:
[Infosys](https://leetcode.com/company/infosys)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Union Find](https://leetcode.com/tag/union-find/), [Prefix Sum](https://leetcode.com/tag/prefix-sum/), [Ordered Set](https://leetcode.com/tag/ordered-set/)

## Solution 1. Manage Intervals with Ordered Set

```cpp
// OJ: https://leetcode.com/problems/maximum-segment-sum-after-removals
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& A, vector<int>& Q) {
        int N = A.size();
        vector<long long> ans;
        typedef pair<int, int> PII;
        vector<long long> sum(N + 1);
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        auto cmp = [&](auto &a, auto &b) { return a.second < b.second; };
        set<PII, decltype(cmp)> intervals(cmp);
        intervals.insert({0, N - 1});
        multiset<long long> s{sum.back()};
        for (int q : Q) {
            auto it = intervals.lower_bound({q, q});
            auto [a, b] = *it;
            intervals.erase(it);
            s.erase(s.find(sum[b + 1] - sum[a]));
            if (a <= q - 1) {
                intervals.insert({a, q - 1});
                s.insert(sum[q] - sum[a]);
            }
            if (b >= q + 1) {
                intervals.insert({q + 1, b});
                s.insert(sum[b + 1] - sum[q + 1]);
            }
            ans.push_back(s.size() ? *s.rbegin() : 0);
        }
        return ans;
    }
};
```

## Solution 2. Union Find

Traverse the queries in the reverse order. Use Union find to keep track of the segment sums.

```cpp
// OJ: https://leetcode.com/problems/maximum-segment-sum-after-removals
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& A, vector<int>& Q) {
        long long N = A.size(), mxSum = 0;
        vector<long long> ans(N), sum(begin(A), end(A));
        vector<int> id(N), seen(N);
        iota(begin(id), end(id), 0);
        function<int(int)> find = [&](int a) {
            return id[a] == a ? a : (id[a] = find(id[a]));
        };
        auto connect = [&](int a, int b) {
            int p = find(a), q = find(b);
            if (p == q) return;
            id[q] = p;
            sum[p] += sum[q];
        };
        for (int i = N - 1; i >= 0; --i) {
            int q = Q[i];
            seen[q] = 1;
            if (q - 1 >= 0 && seen[q - 1]) connect(q - 1, q);
            if (q + 1 < N && seen[q + 1]) connect(q, q + 1);
            mxSum = max(mxSum, sum[find(q)]);
            if (i > 0) ans[i - 1] = mxSum;
        }
        return ans;
    }
};
```