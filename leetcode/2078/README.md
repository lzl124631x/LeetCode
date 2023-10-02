# [2078. Two Furthest Houses With Different Colors (Easy)](https://leetcode.com/problems/two-furthest-houses-with-different-colors/)

<p>There are <code>n</code> houses evenly lined up on the street, and each house is beautifully painted. You are given a <strong>0-indexed</strong> integer array <code>colors</code> of length <code>n</code>, where <code>colors[i]</code> represents the color of the <code>i<sup>th</sup></code> house.</p>

<p>Return <em>the <strong>maximum</strong> distance between <strong>two</strong> houses with <strong>different</strong> colors</em>.</p>

<p>The distance between the <code>i<sup>th</sup></code> and <code>j<sup>th</sup></code> houses is <code>abs(i - j)</code>, where <code>abs(x)</code> is the <strong>absolute value</strong> of <code>x</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/31/eg1.png" style="width: 610px; height: 84px;">
<pre><strong>Input:</strong> colors = [<u><strong>1</strong></u>,1,1,<strong><u>6</u></strong>,1,1,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> In the above image, color 1 is blue, and color 6 is red.
The furthest two houses with different colors are house 0 and house 3.
House 0 has color 1, and house 3 has color 6. The distance between them is abs(0 - 3) = 3.
Note that houses 3 and 6 can also produce the optimal answer.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/10/31/eg2.png" style="width: 426px; height: 84px;">
<pre><strong>Input:</strong> colors = [<u><strong>1</strong></u>,8,3,8,<u><strong>3</strong></u>]
<strong>Output:</strong> 4
<strong>Explanation:</strong> In the above image, color 1 is blue, color 8 is yellow, and color 3 is green.
The furthest two houses with different colors are house 0 and house 4.
House 0 has color 1, and house 4 has color 3. The distance between them is abs(0 - 4) = 4.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> colors = [<u><strong>0</strong></u>,<strong><u>1</u></strong>]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The furthest two houses with different colors are house 0 and house 1.
House 0 has color 0, and house 1 has color 1. The distance between them is abs(0 - 1) = 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n ==&nbsp;colors.length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>0 &lt;= colors[i] &lt;= 100</code></li>
	<li>Test data are generated such that <strong>at least</strong> two houses have different colors.</li>
</ul>


**Similar Questions**:
* [Replace Elements with Greatest Element on Right Side (Easy)](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/)
* [Maximum Distance Between a Pair of Values (Medium)](https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/)
* [Maximum Difference Between Increasing Elements (Easy)](https://leetcode.com/problems/maximum-difference-between-increasing-elements/)

## Solution 1. Map

For each `A[i]`:
* If this is the first occurrence of this value, store `A[i] -> i` in a map `m`.
* Loop through each `num, index` pair the map `m` and calculate the maximum `i - index` value if `num != A[i]`.

```cpp
// OJ: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// Author: github.com/lzl124631x
// Time: O(NM) where `N` is the length of `A` and `M` is the range of numbers in `A`.
// Space: O(M)
class Solution {
public:
    int maxDistance(vector<int>& A) {
        unordered_map<int, int> m; // first occurrence index
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (m.count(A[i]) == 0) m[A[i]] = i;
            for (auto &[c, j] : m) {
                if (c != A[i]) {
                    ans = max(ans, i - j);
                }
            }
        }
        return ans;
    }
};
```

Or use array.

```cpp
// OJ: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// Author: github.com/lzl124631x
// Time: O(NM) where `N` is the length of `A` and `M` is the range of numbers in `A`.
// Space: O(M)
class Solution {
public:
    int maxDistance(vector<int>& A) {
        int ans = 0, index[101] = {[0 ... 100] = -1};
        for (int i = 0; i < A.size(); ++i) {
            if (index[A[i]] == -1) index[A[i]] = i;
            for (int j = 0; j <= 100; ++j) {
                if (index[j] != -1 && j != A[i]) {
                    ans = max(ans, i - index[j]);
                }
            }
        }
        return ans;
    }
};
```

## Solution 2. Mono-increasing Index Array

For each `A[i]`:
* If this is the first occurrence of this value, push `i` into a `vector<int> index`.
* Loop through each index value `j` in `index` array, and update answer with `i - j` for the first `A[j] != A[i]`. This step at most looks at two indices, so it's `O(1)` time.

```cpp
// OJ: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// Author: github.com/lzl124631x
// Time: O(N) where `N` is the length of `A` and `M` is the range of numbers in `A`.
// Space: O(M)
class Solution {
public:
    int maxDistance(vector<int>& A) {
        vector<int> index; // first occurrence index
        int ans = 0, seen[101] = {};
        for (int i = 0; i < A.size(); ++i) {
            if (!seen[i]) {
                seen[i] = 1;
                index.push_back(i);
            }
            for (int j : index) {
                if (A[j] != A[i]) {
                    ans = max(ans, i - j);
                    break;
                }
            }
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/two-furthest-houses-with-different-colors/discuss/1589010/C%2B%2B-O(N)-Time-One-Pass