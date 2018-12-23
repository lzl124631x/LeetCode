# [961. N-Repeated Element in Size 2N Array (Easy)](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)

<p>In a array <code>A</code> of size <code>2N</code>, there are <code>N+1</code> unique elements, and exactly one of these elements is repeated N times.</p>

<p>Return the element repeated <code>N</code> times.</p>

<p>&nbsp;</p>

<ol>
</ol>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[1,2,3,3]</span>
<strong>Output: </strong><span id="example-output-1">3</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[2,1,2,5,3,2]</span>
<strong>Output: </strong><span id="example-output-2">2</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">[5,1,5,2,5,3,5,4]</span>
<strong>Output: </strong><span id="example-output-3">5</span>
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>4 &lt;= A.length &lt;= 10000</code></li>
	<li><code>0 &lt;= A[i] &lt; 10000</code></li>
	<li><code>A.length</code> is even</li>
</ol>
</div>
</div>
</div>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/n-repeated-element-in-size-2n-array
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> s;
        for (int n : A) {
            if (s.find(n) != s.end()) return n;
            s.insert(n);
        }
    }
};
```

## Solution 2.

For the duplicate number, it either shows side by side (`A[i]` and `A[i + 1]`) or alternated(`A[i]` and `A[i + 2]`), or at the front and rear like `[2, 1, 3, 2]`.

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
      for (int i = 0; i < A.size() - 2; ++i) {
          if (A[i + 1] == A[i + 2]) return A[i + 1];
          if (A[i] == A[i + 1] || A[i] == A[i + 2]) return A[i];
      }
      return A[0]; 
    }
};
```