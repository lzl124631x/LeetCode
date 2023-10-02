# [2080. Range Frequency Queries (Medium)](https://leetcode.com/problems/range-frequency-queries/)

<p>Design a data structure to find the <strong>frequency</strong> of a given value in a given subarray.</p>

<p>The <strong>frequency</strong> of a value in a subarray is the number of occurrences of that value in the subarray.</p>

<p>Implement the <code>RangeFreqQuery</code> class:</p>

<ul>
	<li><code>RangeFreqQuery(int[] arr)</code> Constructs an instance of the class with the given <strong>0-indexed</strong> integer array <code>arr</code>.</li>
	<li><code>int query(int left, int right, int value)</code> Returns the <strong>frequency</strong> of <code>value</code> in the subarray <code>arr[left...right]</code>.</li>
</ul>

<p>A <strong>subarray</strong> is a contiguous sequence of elements within an array. <code>arr[left...right]</code> denotes the subarray that contains the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> (<strong>inclusive</strong>).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["RangeFreqQuery", "query", "query"]
[[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]
<strong>Output</strong>
[null, 1, 2]

<strong>Explanation</strong>
RangeFreqQuery rangeFreqQuery = new RangeFreqQuery([12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]);
rangeFreqQuery.query(1, 2, 4); // return 1. The value 4 occurs 1 time in the subarray [33, 4]
rangeFreqQuery.query(0, 11, 33); // return 2. The value 33 occurs 2 times in the whole array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= arr[i], value &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= left &lt;= right &lt; arr.length</code></li>
	<li>At most <code>10<sup>5</sup></code> calls will be made to <code>query</code></li>
</ul>


**Companies**:  
[Quora](https://leetcode.com/company/quora)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Binary Search](https://leetcode.com/tag/binary-search/)

## Solution 1. Binary Search

Initialization: For each unique value in `A`, store its corresponding indices in a map `m`.

Query: 
* If `value` doesn't exist in the original array, return `0`.
* Otherwise, let `v = m[value]` -- the array of all the indices of `value` in the original array
* Let `j` be the first index that `v[j] > right`.
* Let `i` be the first index that `v[i] >= left`.
* The answer is `j - i`.

```cpp
// OJ: https://leetcode.com/problems/range-frequency-queries/
// Author: github.com/lzl124631x
// Time:
//      RangeFreqQuery: O(N)
//      query: O(log(N))
// Space: O(N)
class RangeFreqQuery {
    unordered_map<int, vector<int>> m; // map from a value to all its indices
public:
    RangeFreqQuery(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i) m[A[i]].push_back(i);
    }
    int query(int left, int right, int value) {
        if (m.count(value) == 0) return 0; // `value` doesn't exist in the original array
        auto &v = m[value]; // `v` is the array of all the indices of `value` in the original array
        int j = upper_bound(begin(v), end(v), right) - begin(v); // Find the first index `j` that `v[j] > right`.
        int i = lower_bound(begin(v), end(v), left) - begin(v); // Find the first index `i` that `v[i] >= left`.
        return j - i; // The answer is `j - i`
    }
};
```

## Discuss

https://leetcode.com/problems/range-frequency-queries/discuss/1589028/C%2B%2B-Straightforward-Binary-Search