# [2170. Minimum Operations to Make the Array Alternating (Medium)](https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/)

<p>You are given a <strong>0-indexed</strong> array <code>nums</code> consisting of <code>n</code> positive integers.</p>

<p>The array <code>nums</code> is called <strong>alternating</strong> if:</p>

<ul>
	<li><code>nums[i - 2] == nums[i]</code>, where <code>2 &lt;= i &lt;= n - 1</code>.</li>
	<li><code>nums[i - 1] != nums[i]</code>, where <code>1 &lt;= i &lt;= n - 1</code>.</li>
</ul>

<p>In one <strong>operation</strong>, you can choose an index <code>i</code> and <strong>change</strong> <code>nums[i]</code> into <strong>any</strong> positive integer.</p>

<p>Return <em>the <strong>minimum number of operations</strong> required to make the array alternating</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,1,3,2,4,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong>
One way to make the array alternating is by converting it to [3,1,3,<u><strong>1</strong></u>,<u><strong>3</strong></u>,<u><strong>1</strong></u>].
The number of operations required in this case is 3.
It can be proven that it is not possible to make the array alternating in less than 3 operations. 
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,2,2,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong>
One way to make the array alternating is by converting it to [1,2,<u><strong>1</strong></u>,2,<u><strong>1</strong></u>].
The number of operations required in this case is 2.
Note that the array cannot be converted to [<u><strong>2</strong></u>,2,2,2,2] because in this case nums[0] == nums[1] which violates the conditions of an alternating array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Minimum Number of Flips to Make the Binary String Alternating (Medium)](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)

## Solution 1. Counting

```cpp
// OJ: https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minimumOperations(vector<int>& A) {
        unordered_map<int, int> odd, even;
        for (int i = 0; i < A.size(); ++i) {
            if (i % 2) odd[A[i]]++;
            else even[A[i]]++;
        }
        int oddCnt[2] = {}, oddNum[2] = {}, evenCnt[2] = {}, evenNum[2] = {};
        for (auto &[n, cnt] : odd) {
            if (cnt > oddCnt[0]) oddCnt[1] = oddCnt[0], oddNum[1] = oddNum[0], oddCnt[0] = cnt, oddNum[0] = n;
            else if (cnt > oddCnt[1]) oddCnt[1] = cnt, oddNum[1] = n;
        }
        for (auto &[n, cnt] : even) {
            if (cnt > evenCnt[0]) evenCnt[1] = evenCnt[0], evenNum[1] = evenNum[0], evenCnt[0] = cnt, evenNum[0] = n;
            else if (cnt > evenNum[1]) evenCnt[1] = cnt, evenNum[1] = n;
        }
        if (oddNum[0] != evenNum[0]) return A.size() - oddCnt[0] - evenCnt[0];
        return min(A.size() - oddCnt[0] - evenCnt[1], A.size() - evenCnt[0] - oddCnt[1]);
    }
};
```