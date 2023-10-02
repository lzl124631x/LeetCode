# [774. Minimize Max Distance to Gas Station (Hard)](https://leetcode.com/problems/minimize-max-distance-to-gas-station/)

<p>You are given an integer array <code>stations</code> that represents the positions of the gas stations on the <strong>x-axis</strong>. You are also given an integer <code>k</code>.</p>

<p>You should add <code>k</code> new gas stations. You can add the stations anywhere on the <strong>x-axis</strong>, and not necessarily on an integer position.</p>

<p>Let <code>penalty()</code> be the maximum distance between <strong>adjacent</strong> gas stations after adding the <code>k</code> new stations.</p>

<p>Return <em>the smallest possible value of</em> <code>penalty()</code>. Answers within <code>10<sup>-6</sup></code> of the actual answer will be accepted.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> stations = [1,2,3,4,5,6,7,8,9,10], k = 9
<strong>Output:</strong> 0.50000
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> stations = [23,24,36,39,46,56,57,65,84,98], k = 1
<strong>Output:</strong> 14.00000
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>10 &lt;= stations.length &lt;= 2000</code></li>
	<li><code>0 &lt;= stations[i] &lt;= 10<sup>8</sup></code></li>
	<li><code>stations</code> is sorted in a <strong>strictly increasing</strong> order.</li>
	<li><code>1 &lt;= k &lt;= 10<sup>6</sup></code></li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

**Similar Questions**:
* [Koko Eating Bananas (Medium)](https://leetcode.com/problems/koko-eating-bananas/)

## Solution 1. Binary Answer

```cpp
// OJ: https://leetcode.com/problems/minimize-max-distance-to-gas-station/
// Author: github.com/lzl124631x
// Time: O(N * (logN + logM)) where `M` is the maximum difference between two adjacent elements.
// Space: O(N)
class Solution {
    bool valid(vector<double> &dist, double M, int k) {
        for (int i = 0; i < dist.size() && dist[i] > M; ++i) {
            k -= ceil(dist[i] / M) - 1; // k -= int(dist[i] / M); also works
            if (k < 0) return false;
        }
        return true;
    }
public:
    double minmaxGasDist(vector<int>& A, int k) {
        vector<double> dist;
        for (int i = 1; i < A.size(); ++i) {
            dist.push_back(A[i] - A[i - 1]);
        }
        sort(begin(dist), end(dist), greater());
        double L = 0, R = dist[0], eps = 1e-6;
        while (R - L >= eps) {
            double M = (L + R) / 2;
            if (valid(dist, M, k)) R = M;
            else L = M;
        }
        return L;
    }
};
```

Or we can just use the original array.

```cpp
// OJ: https://leetcode.com/problems/minimize-max-distance-to-gas-station/
// Author: github.com/lzl124631x
// Time: O(N * (logN + logM))
// Space: O(1)
class Solution {
    bool valid(vector<int> &A, double M, int k) {
        for (int i = 1; i < A.size(); ++i) {
            k -= (int)((A[i] - A[i - 1]) / M);
            if (k < 0) return false;
        }
        return true;
    }
public:
    double minmaxGasDist(vector<int>& A, int k) {
        double L = 0, R = 1e8, eps = 1e-6;
        while (R - L >= eps) {
            double M = (L + R) / 2;
            if (valid(A, M, k)) R = M;
            else L = M;
        }
        return L;
    }
};
```