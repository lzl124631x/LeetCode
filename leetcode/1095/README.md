# [1095. Find in Mountain Array (Hard)](https://leetcode.com/problems/find-in-mountain-array)

<p><em>(This problem is an <strong>interactive problem</strong>.)</em></p>

<p>You may recall that an array <code>arr</code> is a <strong>mountain array</strong> if and only if:</p>

<ul>
	<li><code>arr.length &gt;= 3</code></li>
	<li>There exists some <code>i</code> with <code>0 &lt; i &lt; arr.length - 1</code> such that:
	<ul>
		<li><code>arr[0] &lt; arr[1] &lt; ... &lt; arr[i - 1] &lt; arr[i]</code></li>
		<li><code>arr[i] &gt; arr[i + 1] &gt; ... &gt; arr[arr.length - 1]</code></li>
	</ul>
	</li>
</ul>

<p>Given a mountain array <code>mountainArr</code>, return the <strong>minimum</strong> <code>index</code> such that <code>mountainArr.get(index) == target</code>. If such an <code>index</code> does not exist, return <code>-1</code>.</p>

<p><strong>You cannot access the mountain array directly.</strong> You may only access the array using a <code>MountainArray</code> interface:</p>

<ul>
	<li><code>MountainArray.get(k)</code> returns the element of the array at index <code>k</code> (0-indexed).</li>
	<li><code>MountainArray.length()</code> returns the length of the array.</li>
</ul>

<p>Submissions making more than <code>100</code> calls to <code>MountainArray.get</code> will be judged <em>Wrong Answer</em>. Also, any solutions that attempt to circumvent the judge will result in disqualification.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> array = [1,2,3,4,5,3,1], target = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> array = [0,1,2,4,2,1], target = 3
<strong>Output:</strong> -1
<strong>Explanation:</strong> 3 does not exist in <code>the array,</code> so we return -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= mountain_arr.length() &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= mountain_arr.get(index) &lt;= 10<sup>9</sup></code></li>
</ul>


**Companies**:
[Bloomberg](https://leetcode.com/company/bloomberg), [Apple](https://leetcode.com/company/apple), [Uber](https://leetcode.com/company/uber), [Google](https://leetcode.com/company/google)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [Binary Search](https://leetcode.com/tag/binary-search), [Interactive](https://leetcode.com/tag/interactive)

**Similar Questions**:
* [Peak Index in a Mountain Array (Medium)](https://leetcode.com/problems/peak-index-in-a-mountain-array)
* [Minimum Number of Removals to Make Mountain Array (Hard)](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array)
* [Find Good Days to Rob the Bank (Medium)](https://leetcode.com/problems/find-good-days-to-rob-the-bank)

**Hints**:
* Based on whether A[i-1] < A[i] < A[i+1], A[i-1] < A[i] > A[i+1], or A[i-1] > A[i] > A[i+1], we are either at the left side, peak, or right side of the mountain.  We can binary search to find the peak.
After finding the peak, we can binary search two more times to find whether the value occurs on either side of the peak.

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/find-in-mountain-array
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(logN)
class Solution {
public:
    int findInMountainArray(int target, MountainArray &A) {
        int len = A.length();
        unordered_map<int, int> m;
        auto get = [&](int i) {
            return m.count(i) ? m[i] : (m[i] = A.get(i));
        };
        function<int(int, int, bool)> findInMonoArray;
        function<int(int, int)> findInMountainArray = [&](int L, int R) {
            if (L > R) return -1;
            if (L == R || L == R - 1) return get(L) == target ? L : (L == R - 1 && get(R) == target ? R : -1);
            int lv = get(L), rv = get(R), M = (L + R) / 2, a = get(M), b = get(M + 1);
            if (a < b) {
                int x = findInMonoArray(L, M + 1, true);
                return x != -1 ? x : findInMountainArray(M + 2, R);
            }
            int x = findInMountainArray(L, M - 1);
            return x != -1 ? x : findInMonoArray(M, R, false);
        };
        findInMonoArray = [&](int L, int R, bool increasing) {
            if (L > R) return -1;
            while (L <= R) {
                int M = (L + R) / 2, mid = get(M);
                if (mid == target) return M;
                if ((increasing && mid > target) || (!increasing && mid < target)) R = M - 1;
                else L = M + 1;
            }
            return -1;
        };
        return findInMountainArray(0, len - 1);
    }
};
```

## Solution 2. Binary Search

```cpp
// OJ: https://leetcode.com/problems/find-in-mountain-array/
// Author: github.com/lzl124631x
// Time: O(logN)
// Space: O(1)
class Solution {
    int binarySearch(int target, MountainArray &A, int L, int R, int dir) {
        while (L <= R) {
            int M = (L + R) / 2, val = A.get(M);
            if (val == target) return M;
            bool left = (dir == 1 && val < target) || (dir == -1 && val > target);
            if (left) L = M + 1;
            else R = M - 1;
        }
        return -1;
    }
    int findTop(MountainArray &A, int N) {
        int L = 0, R = N - 1;
        while (L <= R) {
            int M = (L + R) / 2, left = M - 1 >= 0 ? A.get(M - 1) : INT_MIN, val = A.get(M), right = M + 1 < N ? A.get(M + 1) : INT_MIN;
            if (val > left && val > right) return M;
            else if (val < left) R = M - 1;
            else L = M + 1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &A) {
        int N = A.length(), top = findTop(A, N), a = binarySearch(target, A, 0, top, 1);
        return a != -1 ? a : binarySearch(target, A, top + 1, N - 1, -1);
    }
};
```