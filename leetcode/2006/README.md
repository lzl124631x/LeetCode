# [2006. Count Number of Pairs With Absolute Difference K (Easy)](https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/)

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the number of pairs</em> <code>(i, j)</code> <em>where</em> <code>i &lt; j</code> <em>such that</em> <code>|nums[i] - nums[j]| == k</code>.</p>

<p>The value of <code>|x|</code> is defined as:</p>

<ul>
	<li><code>x</code> if <code>x &gt;= 0</code>.</li>
	<li><code>-x</code> if <code>x &lt; 0</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,2,1], k = 1
<strong>Output:</strong> 4
<strong>Explanation:</strong> The pairs with an absolute difference of 1 are:
- [<strong><u>1</u></strong>,<strong><u>2</u></strong>,2,1]
- [<strong><u>1</u></strong>,2,<strong><u>2</u></strong>,1]
- [1,<strong><u>2</u></strong>,2,<strong><u>1</u></strong>]
- [1,2,<strong><u>2</u></strong>,<strong><u>1</u></strong>]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,3], k = 3
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no pairs with an absolute difference of 3.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,1,5,4], k = 2
<strong>Output:</strong> 3
<b>Explanation:</b> The pairs with an absolute difference of 2 are:
- [<strong><u>3</u></strong>,2,<strong><u>1</u></strong>,5,4]
- [<strong><u>3</u></strong>,2,1,<strong><u>5</u></strong>,4]
- [3,<strong><u>2</u></strong>,1,5,<strong><u>4</u></strong>]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 99</code></li>
</ul>


**Similar Questions**:
* [Two Sum (Easy)](https://leetcode.com/problems/two-sum/)
* [K-diff Pairs in an Array (Medium)](https://leetcode.com/problems/k-diff-pairs-in-an-array/)
* [Finding Pairs With a Certain Sum (Medium)](https://leetcode.com/problems/finding-pairs-with-a-certain-sum/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int countKDifference(vector<int>& A, int k) {
        int N = A.size(), ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                ans += abs(A[i] - A[j]) == k;
            }
        }
        return ans;
    }
};
```

## Solution 2. Sliding Window

After sorting the array `A`, we can use sliding window to count the number of elements `== A[i] + k` so that we just traverse `A` once.

```cpp
// OJ: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int countKDifference(vector<int>& A, int k) {
        int N = A.size(), ans = 0, j = 0;
        sort(begin(A), end(A));
        for (int i = 0; i < N; ) {
            int n = A[i], cnt = 0;
            while (i < N && A[i] == n) ++i, ++cnt;
            while (j < N && A[j] < n + k) ++j;
            int start = j;
            while (j < N && A[j] == n + k) ++j;
            ans += (j - start) * cnt;
        }
        return ans;
    }
};
```

## Solution 3. Frequency Map

```cpp
// OJ: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(C) where `C` is the range of numbers in `A`.
class Solution {
public:
    int countKDifference(vector<int>& A, int k) {
        int N = A.size(), ans = 0, cnt[101] = {};
        for (int n : A) {
            ans += (n + k <= 100 ? cnt[n + k] : 0) + (n - k >= 1 ? cnt[n - k] : 0);
            cnt[n]++;
        }
        return ans;
    }
};
```