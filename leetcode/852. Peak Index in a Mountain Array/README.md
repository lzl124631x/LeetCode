# [852. Peak Index in a Mountain Array (Easy)](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

<p>Let's call an array <code>A</code> a <em>mountain</em>&nbsp;if the following properties hold:</p>

<ul>
	<li><code>A.length &gt;= 3</code></li>
	<li>There exists some <code>0 &lt; i&nbsp;&lt; A.length - 1</code> such that <code>A[0] &lt; A[1] &lt; ... A[i-1] &lt; A[i] &gt; A[i+1] &gt; ... &gt; A[A.length - 1]</code></li>
</ul>

<p>Given an array that is definitely a mountain, return any&nbsp;<code>i</code>&nbsp;such that&nbsp;<code>A[0] &lt; A[1] &lt; ... A[i-1] &lt; A[i] &gt; A[i+1] &gt; ... &gt; A[A.length - 1]</code>.</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">[0,1,0]</span>
<strong>Output: </strong><span id="example-output-1">1</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">[0,2,1,0]</span>
<strong>Output: </strong><span id="example-output-2">1</span></pre>
</div>

<p><strong>Note:</strong></p>

<ol>
	<li><code>3 &lt;= A.length &lt;= 10000</code></li>
	<li><code><font face="monospace">0 &lt;= A[i] &lt;= 10^6</font></code></li>
	<li>A&nbsp;is a mountain, as defined above.</li>
</ol>


## Solution 1. Linear Search
```cpp
// OJ: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 1;
        while (i < A.size() && A[i] > A[i - 1]) ++i;
        return i - 1;
    }
};
```

## Solution 2. Binary Search
```cpp
// OJ: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int L = 1, R = A.size() - 2;
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] > A[M - 1]) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};
```