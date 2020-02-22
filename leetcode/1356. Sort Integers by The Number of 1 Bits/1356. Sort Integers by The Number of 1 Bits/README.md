# [1356. Sort Integers by The Number of 1 Bits (Easy)](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/)

<p>Given an integer array <code>arr</code>. You have to sort the integers in the array&nbsp;in ascending order by the number of <strong>1's</strong>&nbsp;in their binary representation and in case of two or more integers have the same number of <strong>1's</strong> you have to sort them in ascending order.</p>

<p>Return <em>the sorted array</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [0,1,2,3,4,5,6,7,8]
<strong>Output:</strong> [0,1,2,4,8,3,5,6,7]
<strong>Explantion:</strong> [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [1024,512,256,128,64,32,16,8,4,2,1]
<strong>Output:</strong> [1,2,4,8,16,32,64,128,256,512,1024]
<strong>Explantion:</strong> All integers have 1 bit in the binary representation, you should just sort them in ascending order.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> arr = [10000,10000]
<strong>Output:</strong> [10000,10000]
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> arr = [2,3,5,7,11,13,17,19]
<strong>Output:</strong> [2,3,5,17,7,11,13,19]
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> arr = [10,100,1000,10000]
<strong>Output:</strong> [10,100,10000,1000]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 500</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10^4</code></li>
</ul>


**Related Topics**:  
[Sort](https://leetcode.com/tag/sort/), [Bit Manipulation](https://leetcode.com/tag/bit-manipulation/)

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