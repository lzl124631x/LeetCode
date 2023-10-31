# [1356. Sort Integers by The Number of 1 Bits (Easy)](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits)

<p>You are given an integer array <code>arr</code>. Sort the integers in the array&nbsp;in ascending order by the number of <code>1</code>&#39;s&nbsp;in their binary representation and in case of two or more integers have the same number of <code>1</code>&#39;s you have to sort them in ascending order.</p>

<p>Return <em>the array after sorting it</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [0,1,2,3,4,5,6,7,8]
<strong>Output:</strong> [0,1,2,4,8,3,5,6,7]
<strong>Explantion:</strong> [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1024,512,256,128,64,32,16,8,4,2,1]
<strong>Output:</strong> [1,2,4,8,16,32,64,128,256,512,1024]
<strong>Explantion:</strong> All integers have 1 bit in the binary representation, you should just sort them in ascending order.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 500</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:
[JPMorgan](https://leetcode.com/company/jpmorgan), [Accenture](https://leetcode.com/company/accenture), [Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Visa](https://leetcode.com/company/visa), [Infosys](https://leetcode.com/company/infosys), [VMware](https://leetcode.com/company/vmware), [MathWorks](https://leetcode.com/company/mathworks)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation), [Sorting](https://leetcode.com/tag/sorting), [Counting](https://leetcode.com/tag/counting)

**Similar Questions**:
* [Find Subsequence of Length K With the Largest Sum (Easy)](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum)

**Hints**:
* Simulate the problem. Count the number of 1's in the binary representation of each integer.
* Sort by the number of 1's ascending and by the value in case of tie.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
    int cnt(int n) {
        int c = 0;
        for (; n; n >>= 1) {
            if (n & 1) ++c;
        }
        return c;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        int N = arr.size();
        vector<pair<int, int>> v(N);
        for (int i = 0; i < N; ++i) v[i] = make_pair(cnt(arr[i]), arr[i]);
        sort(v.begin(), v.end());
        for (int i = 0; i < N; ++i) arr[i] = v[i].second;
        return arr;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<int> sortByBits(vector<int>& A) {
        sort(begin(A), end(A), [](int a, int b) {
            int x = __builtin_popcount(a), y = __builtin_popcount(b);
            return x != y ? x < y : a < b;
        });
        return A;
    }
};
```