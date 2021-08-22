# [1980. Find Unique Binary String (Medium)](https://leetcode.com/problems/find-unique-binary-string/)

<p>Given an array of strings <code>nums</code> containing <code>n</code> <strong>unique</strong> binary strings each of length <code>n</code>, return <em>a binary string of length </em><code>n</code><em> that <strong>does not appear</strong> in <code>nums</code>. If there are multiple answers, you may return <strong>any</strong> of them</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = ["01","10"]
<strong>Output:</strong> "11"
<strong>Explanation:</strong> "11" does not appear in nums. "00" would also be correct.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = ["00","01"]
<strong>Output:</strong> "11"
<strong>Explanation:</strong> "11" does not appear in nums. "10" would also be correct.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = ["111","011","001"]
<strong>Output:</strong> "101"
<strong>Explanation:</strong> "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 16</code></li>
	<li><code>nums[i].length == n</code></li>
	<li><code>nums[i] </code>is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


**Similar Questions**:
* [Missing Number (Easy)](https://leetcode.com/problems/missing-number/)
* [Find All Numbers Disappeared in an Array (Easy)](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
* [Random Pick with Blacklist (Hard)](https://leetcode.com/problems/random-pick-with-blacklist/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/find-unique-binary-string/
// Author: github.com/lzl124631x
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& A) {
        int n = A.size();
        unordered_set<int> s;
        for (auto &n : A) {
            s.insert(stoi(n, 0, 2));
        }
        for (int i = 0; i <= n; ++i) {
            if (s.count(i)) continue;
            string ans;
            for (int j = 0; j < n; ++j) {
                ans += '0' + (i & 1);
                i >>= 1;
            }
            reverse(begin(ans), end(ans));
            return ans;
        }
        return "";
    }
};
```