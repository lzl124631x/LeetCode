# [1287. Element Appearing More Than 25% In Sorted Array (Easy)](https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array)

<p>Given an integer array <strong>sorted</strong> in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,2,2,6,6,6,6,7,10]
<strong>Output:</strong> 6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> arr = [1,1]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= arr.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Companies**:
[Amazon](https://leetcode.com/company/amazon), [Adobe](https://leetcode.com/company/adobe), [Facebook](https://leetcode.com/company/facebook), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array)

**Hints**:
* Divide the array in four parts [1 - 25%] [25 - 50 %] [50 - 75 %] [75% - 100%]
* The answer should be in one of the ends of the intervals.
* In order to check which is element is the answer we can count the frequency with binarySearch.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& A) {
        int start = 0, N = A.size();
        for (int i = 1; i < N; ) {
            while (i < N && A[i] == A[start]) ++i;
            if (i - start > N / 4) return A[start];
            start = i;
        }
        return A[0];
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& A) {
        int N = A.size(), t = N / 4;
        for (int i = 0; i < N - t; ++i) {
            if (A[i] == A[i + t]) return A[i];
        }
        return -1;
    }
};
```

## Solution 3. Binary Search

```cpp
// OJ: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& A) {
        int N = A.size(), sizes[3] = { N / 4, N / 2, N * 3 / 4 };
        for (int i : sizes) {
            if (upper_bound(begin(A), end(A), A[i]) - lower_bound(begin(A), end(A), A[i]) > N / 4) return A[i];
        }
        return -1;
    }
};
```