# [899. Orderly Queue (Hard)](https://leetcode.com/problems/orderly-queue/)

<p>You are given a string <code>s</code> and an integer <code>k</code>. You can choose one of the first <code>k</code> letters of <code>s</code> and append it at the end of the string..</p>

<p>Return <em>the lexicographically smallest string you could have after applying the mentioned step any number of moves</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "cba", k = 1
<strong>Output:</strong> "acb"
<strong>Explanation:</strong> 
In the first move, we move the 1<sup>st</sup> character 'c' to the end, obtaining the string "bac".
In the second move, we move the 1<sup>st</sup> character 'b' to the end, obtaining the final result "acb".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "baaca", k = 3
<strong>Output:</strong> "aaabc"
<strong>Explanation:</strong> 
In the first move, we move the 1<sup>st</sup> character 'b' to the end, obtaining the string "aacab".
In the second move, we move the 3<sup>rd</sup> character 'c' to the end, obtaining the final result "aaabc".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consist of lowercase English letters.</li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/), [Sorting](https://leetcode.com/tag/sorting/)


## Solution 1.

When `K >= 2`, we can in effect swap any two characters, which means we can do bubble sort. So the result for `K >= 2` is just the sorted `S`.

When `K == 1`, we need to rotate the string and find the minimum.

```cpp
// OJ: https://leetcode.com/problems/orderly-queue/
// Author: github.com/lzl124631x
// Time: O(S^2)
// Space: O(S)
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string ans = S;
        for (int i = 1; i < S.size(); ++i) {
            rotate(S.begin(), S.begin() + 1, S.end());
            if (S < ans) ans = S;
        }
        return ans;
    }
};
```