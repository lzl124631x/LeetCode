# [1570. Dot Product of Two Sparse Vectors (Medium)](https://leetcode.com/problems/dot-product-of-two-sparse-vectors/)

<p>Given two sparse vectors, compute their dot product.</p>

<p>Implement class <code>SparseVector</code>:</p>

<ul data-indent="0" data-stringify-type="unordered-list">
	<li><code>SparseVector(nums)</code>&nbsp;Initializes the object with the vector <code>nums</code></li>
	<li><code>dotProduct(vec)</code>&nbsp;Compute the dot product between the instance of <em>SparseVector</em> and <code>vec</code></li>
</ul>

<p>A <strong>sparse vector</strong> is a vector that has mostly zero values, you should store the sparse vector&nbsp;<strong>efficiently </strong>and compute the dot product between two <em>SparseVector</em>.</p>

<p><strong>Follow up:&nbsp;</strong>What if only one of the vectors is sparse?</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums1 = [1,0,0,2,3], nums2 = [0,3,0,4,0]
<strong>Output:</strong> 8
<strong>Explanation:</strong> v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 1*0 + 0*3 + 0*0 + 2*4 + 3*0 = 8
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [0,1,0,0,0], nums2 = [0,0,0,0,2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> v1 = SparseVector(nums1) , v2 = SparseVector(nums2)
v1.dotProduct(v2) = 0*0 + 1*0 + 0*0 + 0*0 + 0*2 = 0
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums1 = [0,1,0,0,2,0,0], nums2 = [1,0,0,0,3,0,4]
<strong>Output:</strong> 6
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10^5</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i]&nbsp;&lt;= 100</code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Hash Table](https://leetcode.com/tag/hash-table/), [Two Pointers](https://leetcode.com/tag/two-pointers/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
// Author: github.com/lzl124631x
// Time:
//      SparseVector: O(NlogN)
//      dotProduct: O(min(A, B));
// Space: O(M) where M is the number of non-zero values in the input array
class SparseVector {
    map<int, int> m;
public:
    SparseVector(vector<int> &A) {
        for (int i = 0; i < A.size(); ++i) {
            if (A[i]) m[i] = A[i];
        }
    }
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for (auto a = m.begin(), b = vec.m.begin(); a != m.end() && b != vec.m.end(); ) {
            if (a->first < b->first) ++a;
            else if (a->first > b->first) ++b;
            else {
                ans += a->second * b->second;
                ++a;
                ++b;
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/dot-product-of-two-sparse-vectors/
// Author: github.com/lzl124631x
// Time:
//      SparseVector: O(N)
//      dotProduct: O(A)
// Space: O(M) where M is the number of non-zero values in the input array
class SparseVector {
    unordered_map<int, int> m;
public:
    SparseVector(vector<int> &A) {
        for (int i = 0; i < A.size(); ++i) {
            if (A[i]) m[i] = A[i];
        }
    }
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for (auto &[index, val] : m) {
            if (vec.m.count(index)) ans += val * vec.m[index];
        }
        return ans;
    }
};
```