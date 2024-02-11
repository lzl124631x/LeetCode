# [3036. Number of Subarrays That Match a Pattern II (Hard)](https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-ii)

<p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of size <code>n</code>, and a <strong>0-indexed</strong> integer array <code>pattern</code> of size <code>m</code> consisting of integers <code>-1</code>, <code>0</code>, and <code>1</code>.</p>

<p>A <span data-keyword="subarray">subarray</span> <code>nums[i..j]</code> of size <code>m + 1</code> is said to match the <code>pattern</code> if the following conditions hold for each element <code>pattern[k]</code>:</p>

<ul>
	<li><code>nums[i + k + 1] &gt; nums[i + k]</code> if <code>pattern[k] == 1</code>.</li>
	<li><code>nums[i + k + 1] == nums[i + k]</code> if <code>pattern[k] == 0</code>.</li>
	<li><code>nums[i + k + 1] &lt; nums[i + k]</code> if <code>pattern[k] == -1</code>.</li>
</ul>

<p>Return <em>the<strong> count</strong> of subarrays in</em> <code>nums</code> <em>that match the</em> <code>pattern</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,5,6], pattern = [1,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The pattern [1,1] indicates that we are looking for strictly increasing subarrays of size 3. In the array nums, the subarrays [1,2,3], [2,3,4], [3,4,5], and [4,5,6] match this pattern.
Hence, there are 4 subarrays in nums that match the pattern.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,4,4,1,3,5,5,3], pattern = [1,0,-1]
<strong>Output:</strong> 2
<strong>Explanation: </strong>Here, the pattern [1,0,-1] indicates that we are looking for a sequence where the first number is smaller than the second, the second is equal to the third, and the third is greater than the fourth. In the array nums, the subarrays [1,4,4,1], and [3,5,5,3] match this pattern.
Hence, there are 2 subarrays in nums that match the pattern.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n == nums.length &lt;= 10<sup>6</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= m == pattern.length &lt; n</code></li>
	<li><code>-1 &lt;= pattern[i] &lt;= 1</code></li>
</ul>


**Similar Questions**:
* [Match Substring After Replacement (Hard)](https://leetcode.com/problems/match-substring-after-replacement)

**Hints**:
* Create a second array <code>nums2</code> such that <code>nums2[i] = 1</code> if <code>nums[i + 1] > nums[i]</code>, <code>nums2[i] = 0</code> if <code>nums[i + 1] == nums[i]</code>, and <code>nums2[i] = -1</code> if <code>nums[i + 1] < nums[i]</code>.
* The problem becomes: “Count the number of subarrays in <code>nums2</code> that are equal to <code>pattern</code>.
* Use Knuth-Morris-Pratt or Z-Function algorithms.

## Solution 1. KMP

Firstly, turn the array `A` into a string `s` with `a, b, c` (meaning `-1, 0, 1`) denoting the relative order of its consecutive letters.

For example, `A = [1,4,4,1,3,5,5,3]`, then `s = "cbaccba"`.

Secondly, convert pattern array into a string of `a, b, c` as well.

For example, `P = [1,0,-1]`, then `p = "cba"`.

Lastly, count the number of occurrence of `p` in `s`. We can use KMP to do this in `O(M + N)` time.

```cpp
// OJ: https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-ii
// Author: github.com/lzl124631x
// Time: O(M + N)
// Space: O(M + N)
class Solution {
    vector<int> getLps(string &s) {
        int N = s.size(), i = 0;
        vector<int> lps(N); // lps[0] is always 0
        for (int j = 1; j < N; ++j) {
            while (i > 0 && s[i] != s[j]) i = lps[i - 1]; // when s[i] can't match s[j], keep moving `i` backwards to `lps[i-1]`
            i += s[i] == s[j]; // Move `i` if s[j] matches s[i]
            lps[j] = i; // Assign the matched length to lps[j]
        }
        return lps;
    }
    int KMPCount(string s, string t) {
        if (t.empty()) return 0;
        int M = s.size(), N = t.size(), i = 0, j = 0, ans = 0;
        auto lps = getLps(t);
        while (i < M) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
                if (j == N) {
                    ++ans;
                    j = lps[j - 1]; // Full match found. Move `j` back to `lps[j-1]` to skip matched prefix
                }
            } else {
                if (j) j = lps[j - 1];
                else ++i;
            }
        }
        return ans;
    }
public:
    int countMatchingSubarrays(vector<int>& A, vector<int>& P) {
        int N = A.size(), M = P.size();
        string s, p;
        for (int i = 1; i < N; ++i) {
            s.push_back(A[i] > A[i - 1] ? 'a' : (A[i] == A[i - 1] ? 'b' : 'c'));
        }
        for (auto &n : P) {
            p.push_back(n == 1 ? 'a' : (n == 0 ? 'b' : 'c'));
        }
        return KMPCount(s, p);
    }
};
```