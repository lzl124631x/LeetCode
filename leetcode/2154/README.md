# [2154. Keep Multiplying Found Values by Two (Easy)](https://leetcode.com/problems/keep-multiplying-found-values-by-two/)

<p>You are given an array of integers <code>nums</code>. You are also given an integer <code>original</code> which is the first number that needs to be searched for in <code>nums</code>.</p>

<p>You then do the following steps:</p>

<ol>
	<li>If <code>original</code> is found in <code>nums</code>, <strong>multiply</strong> it by two (i.e., set <code>original = 2 * original</code>).</li>
	<li>Otherwise, <strong>stop</strong> the process.</li>
	<li><strong>Repeat</strong> this process with the new number as long as you keep finding the number.</li>
</ol>

<p>Return <em>the <strong>final</strong> value of </em><code>original</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [5,3,6,1,12], original = 3
<strong>Output:</strong> 24
<strong>Explanation:</strong> 
- 3 is found in nums. 3 is multiplied by 2 to obtain 6.
- 6 is found in nums. 6 is multiplied by 2 to obtain 12.
- 12 is found in nums. 12 is multiplied by 2 to obtain 24.
- 24 is not found in nums. Thus, 24 is returned.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,7,9], original = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong>
- 4 is not found in nums. Thus, 4 is returned.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i], original &lt;= 1000</code></li>
</ul>


**Similar Questions**:
* [Largest Number At Least Twice of Others (Easy)](https://leetcode.com/problems/largest-number-at-least-twice-of-others/)
* [Check If N and Its Double Exist (Easy)](https://leetcode.com/problems/check-if-n-and-its-double-exist/)

## Solution 1. Set + Simulation

```cpp
// OJ: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int findFinalValue(vector<int>& A, int n) {
        set<int> s(begin(A), end(A));
        while (s.count(n)) n *= 2;
        return n;
    }
};
```

## Solution 2. Bucket Count + Simulation

```cpp
// OJ: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(R) where `R` is the range of numbers in `A`
class Solution {
public:
    int findFinalValue(vector<int>& A, int n) {
        int seen[1001] = {};
        for (int x : A) seen[x] = 1;
        while (n < 1001 && seen[n]) n *= 2;
        return n;
    }
};
```

## Solution 3. Sorting + One Pass

```cpp
// OJ: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findFinalValue(vector<int>& A, int n) {
        sort(begin(A), end(A));
        for (int i = 0, N = A.size(); i < N;) {
            while (i < N && A[i] < n) ++i;
            if (i == N || A[i] != n) break;
            n *= 2;
        }
        return n;
    }
};
```

## Discuss

https://leetcode.com/problems/keep-multiplying-found-values-by-two/discuss/1730124