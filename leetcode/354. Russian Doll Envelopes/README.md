# [354. Russian Doll Envelopes (Hard)](https://leetcode.com/problems/russian-doll-envelopes/)

<p>You have a number of envelopes with widths and heights given as a pair of integers <code>(w, h)</code>. One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.</p>

<p>What is the maximum number of envelopes can you Russian doll? (put one inside other)</p>

<p><b>Note:</b><br>
Rotation is not allowed.</p>

<p><strong>Example:</strong></p>

<div>
<pre><strong>Input: </strong><span id="example-input-1-1">[[5,4],[6,4],[6,7],[2,3]]</span>
<strong>Output: </strong><span id="example-output-1">3 
<strong>Explanation: T</strong></span>he maximum number of envelopes you can Russian doll is <code>3</code> ([2,3] =&gt; [5,4] =&gt; [6,7]).
</pre>
</div>


**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/), [Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

**Similar Questions**:
* [Longest Increasing Subsequence (Medium)](https://leetcode.com/problems/longest-increasing-subsequence/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/russian-doll-envelopes/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
// Ref: https://leetcode.com/problems/russian-doll-envelopes/discuss/82763/Java-NLogN-Solution-with-Explanation
bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& A) {
        sort(begin(A), end(A), cmp);
        if (i.first == j.first)
        vector<int> dp;
        for (int i = 0; i < A.size(); ++i) {
            auto it = lower_bound(begin(dp), end(dp), A[i][1]);
            if (it == end(dp)) dp.push_back(A[i][1]);
            else *it = A[i][1];
        }
        return dp.size();
  }
};
```