# [923. 3Sum With Multiplicity (Medium)](https://leetcode.com/problems/3sum-with-multiplicity/)

<p>Given an integer array <code>arr</code>, and an integer <code>target</code>, return the number of tuples <code>i, j, k</code> such that <code>i &lt; j &lt; k</code> and <code>arr[i] + arr[j] + arr[k] == target</code>.</p>

<p>As the answer can be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [1,1,2,2,3,3,4,4,5,5], target = 8
<strong>Output:</strong> 20
<strong>Explanation: </strong>
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1,1,2,2,2,2], target = 5
<strong>Output:</strong> 12
<strong>Explanation: </strong>
arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 3000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 100</code></li>
	<li><code>0 &lt;= target &lt;= 300</code></li>
</ul>


**Companies**:  
[Quora](https://leetcode.com/company/quora)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Sorting](https://leetcode.com/tag/sorting/), [Counting](https://leetcode.com/tag/counting/)

## Solution 1. Hash Table

```cpp
// OJ: https://leetcode.com/problems/3sum-with-multiplicity/solution/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int, long> m;
        long ans = 0, mod = 1e9 + 7;
        for (int n : A) m[n]++;
        for (auto &[a, ca] : m) {
            for (auto &[b, cb] : m) {
                int c = target - a - b;
                if (m.count(c) == 0) continue;
                int cc = m[c];
                if (a == b && b == c) ans += ca * (ca - 1) * (ca - 2) / 6; // all three are equal
                else if (a == b && b != c) ans += ca * (ca - 1) / 2 * cc; // first two are equal and the 3rd is not
                else if (a < b && b < c) ans += ca * cb * cc; // all three are not equal
            }
        }
        return ans % mod;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/3sum-with-multiplicity/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        unordered_map<int, long> m;
        long ans = 0, mod = 1e9 + 7;
        for (int n : A) m[n]++;
        for (auto &[a, ca] : m) {
            for (auto &[b, cb] : m) {
                int c = target - a - b;
                if (a > b || b > c || m.count(c) == 0) continue;
                int cc = m[c];
                if (a == b && b == c) ans += ca * (ca - 1) * (ca - 2) / 6;
                else if (a == b) ans += ca * (ca - 1) / 2 * cc;
                else if (a == c) ans += ca * (ca - 1) / 2 * cb;
                else if (b == c) ans += cb * (cb - 1) / 2 * ca;
                else ans += ca * cb * cc;
            }
        }
        return ans % mod;
    }
};
```