# [1889. Minimum Space Wasted From Packaging (Hard)](https://leetcode.com/problems/minimum-space-wasted-from-packaging/)

<p>You have <code>n</code> packages that you are trying to place in boxes, <strong>one package in each box</strong>. There are <code>m</code> suppliers that each produce boxes of <strong>different sizes</strong> (with infinite supply). A package can be placed in a box if the size of the package is <strong>less than or equal to</strong> the size of the box.</p>

<p>The package sizes are given as an integer array <code>packages</code>, where <code>packages[i]</code> is the <strong>size</strong> of the <code>i<sup>th</sup></code> package. The suppliers are given as a 2D integer array <code>boxes</code>, where <code>boxes[j]</code> is an array of <strong>box sizes</strong> that the <code>j<sup>th</sup></code> supplier produces.</p>

<p>You want to choose a <strong>single supplier</strong> and use boxes from them such that the <strong>total wasted space </strong>is <strong>minimized</strong>. For each package in a box, we define the space <strong>wasted</strong> to be <code>size of the box - size of the package</code>. The <strong>total wasted space</strong> is the sum of the space wasted in <strong>all</strong> the boxes.</p>

<ul>
	<li>For example, if you have to fit packages with sizes <code>[2,3,5]</code> and the supplier offers boxes of sizes <code>[4,8]</code>, you can fit the packages of size-<code>2</code> and size-<code>3</code> into two boxes of size-<code>4</code> and the package with size-<code>5</code> into a box of size-<code>8</code>. This would result in a waste of <code>(4-2) + (4-3) + (8-5) = 6</code>.</li>
</ul>

<p>Return <em>the <strong>minimum total wasted space</strong> by choosing the box supplier <strong>optimally</strong>, or </em><code>-1</code> <i>if it is <strong>impossible</strong> to fit all the packages inside boxes. </i>Since the answer may be <strong>large</strong>, return it <strong>modulo </strong><code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> packages = [2,3,5], boxes = [[4,8],[2,8]]
<strong>Output:</strong> 6
<strong>Explanation</strong>: It is optimal to choose the first supplier, using two size-4 boxes and one size-8 box.
The total waste is (4-2) + (4-3) + (8-5) = 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> packages = [2,3,5], boxes = [[1,4],[2,3],[3,4]]
<strong>Output:</strong> -1
<strong>Explanation:</strong> There is no box that the package of size 5 can fit in.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> packages = [3,5,8,10,11,12], boxes = [[12],[11,9],[10,5,14]]
<strong>Output:</strong> 9
<strong>Explanation:</strong> It is optimal to choose the third supplier, using two size-5 boxes, two size-10 boxes, and two size-14 boxes.
The total waste is (5-3) + (5-5) + (10-8) + (10-10) + (14-11) + (14-12) = 9.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == packages.length</code></li>
	<li><code>m == boxes.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= packages[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= boxes[j].length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= boxes[j][k] &lt;= 10<sup>5</sup></code></li>
	<li><code>sum(boxes[j].length) &lt;= 10<sup>5</sup></code></li>
	<li>The elements in <code>boxes[j]</code> are <strong>distinct</strong>.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Prefix Sum

```cpp
// OJ: https://leetcode.com/problems/minimum-space-wasted-from-packaging/
// Author: github.com/lzl124631x
// Time: O(PlogP + BlogB)
// Space: O(max(P))
class Solution {
public:
    int minWastedSpace(vector<int>& P, vector<vector<int>>& B) {
        long mod = 1e9 + 7, ans = LONG_MAX, N = P.size(), sum[100001] = {}, cnt[100001] = {};
        sort(begin(P), end(P));
        for (int i = 1, j = 0; i < 100001; ++i) {
            sum[i] = sum[i - 1];
            cnt[i] = cnt[i - 1];
            while (j < N && P[j] == i) {
                sum[i] += i;
                cnt[i]++;
                ++j;
            }
        }
        for (auto &b : B) {
            sort(begin(b), end(b));
            if (b.back() < P.back()) continue;
            long tmp = 0, prev = 0;
            for (int i = 0; i < b.size(); ++i) {
                tmp += (cnt[b[i]] - cnt[prev]) * b[i] - (sum[b[i]] - sum[prev]);
                prev = b[i];
            }
            ans = min(ans, tmp);
        }
        return ans == LONG_MAX ? -1 : ans % mod;
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/minimum-space-wasted-from-packaging/
// Author: github.com/lzl124631x
// Time: O(PlogP + BlogB + BlogP)
// Space: O(P)
class Solution {
public:
    int minWastedSpace(vector<int>& P, vector<vector<int>>& B) {
        long mod = 1e9 + 7, ans = LONG_MAX, N = P.size();
        sort(begin(P), end(P));
        vector<long> sum(N + 1);
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + P[i];
        for (auto &b : B) {
            sort(begin(b), end(b));
            if (b.back() < P.back()) continue;
            long tmp = 0, prev = 0;
            for (int i = 0; i < b.size(); ++i) {
                int cur = upper_bound(begin(P) + prev, end(P), b[i]) - begin(P);
                tmp += (cur - prev) * b[i] - (sum[cur] - sum[prev]);
                prev = cur;
            }
            ans = min(ans, tmp);
        }
        return ans == LONG_MAX ? -1 : ans % mod;
    }
};
```

The prefix sum array is actually not necessary.

```cpp
// OJ: https://leetcode.com/problems/minimum-space-wasted-from-packaging/
// Author: github.com/lzl124631x
// Time: O(PlogP + BlogB + BlogP)
// Space: O(1)
class Solution {
public:
    int minWastedSpace(vector<int>& P, vector<vector<int>>& B) {
        long mod = 1e9 + 7, ans = LONG_MAX, N = P.size(), sum = accumulate(begin(P), end(P), 0L);
        sort(begin(P), end(P));
        for (auto &b : B) {
            sort(begin(b), end(b));
            if (b.back() < P.back()) continue;
            long tmp = 0, prev = 0;
            for (int i = 0; i < b.size(); ++i) {
                int cur = upper_bound(begin(P) + prev, end(P), b[i]) - begin(P);
                tmp += (cur - prev) * b[i];
                prev = cur;
            }
            ans = min(ans, tmp - sum);
        }
        return ans == LONG_MAX ? -1 : ans % mod;
    }
};
```