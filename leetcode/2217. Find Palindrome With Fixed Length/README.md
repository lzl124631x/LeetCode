# [2217. Find Palindrome With Fixed Length (Medium)](https://leetcode.com/problems/find-palindrome-with-fixed-length/)

<p>Given an integer array <code>queries</code> and a <strong>positive</strong> integer <code>intLength</code>, return <em>an array</em> <code>answer</code> <em>where</em> <code>answer[i]</code> <em>is either the </em><code>queries[i]<sup>th</sup></code> <em>smallest <strong>positive palindrome</strong> of length</em> <code>intLength</code> <em>or</em> <code>-1</code><em> if no such palindrome exists</em>.</p>

<p>A <strong>palindrome</strong> is a number that reads the same backwards and forwards. Palindromes cannot have leading zeros.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> queries = [1,2,3,4,5,90], intLength = 3
<strong>Output:</strong> [101,111,121,131,141,999]
<strong>Explanation:</strong>
The first few palindromes of length 3 are:
101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, ...
The 90<sup>th</sup> palindrome of length 3 is 999.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> queries = [2,4,6], intLength = 4
<strong>Output:</strong> [1111,1331,1551]
<strong>Explanation:</strong>
The first six palindromes of length 4 are:
1001, 1111, 1221, 1331, 1441, and 1551.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= queries.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= queries[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= intLength&nbsp;&lt;= 15</code></li>
</ul>


**Companies**:  
[VMware](https://leetcode.com/company/vmware)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/)

**Similar Questions**:
* [Palindrome Number (Easy)](https://leetcode.com/problems/palindrome-number/)
* [Find the Closest Palindrome (Hard)](https://leetcode.com/problems/find-the-closest-palindrome/)

## Solution 1.

Let `half` be the first half of the palindrome. The range of it is `begin = 10^((len-1)/2)` (inclusive) to `end = 10^((len+1)/2)` (exclusive).

For a given `rank = Q[i]`, `half = begin + Q[i] - 1`. We can use `getPalindrome` helper function to generate the palindrome.

```cpp
// OJ: https://leetcode.com/problems/find-palindrome-with-fixed-length/
// Author: github.com/lzl124631x
// Time: O(QL)
// Space: O(1) extra space
class Solution {
    long getPalindrome(long half, bool odd) {
        long pal = half;
        if (odd) half /= 10;
        for (; half; half /= 10) pal = pal * 10 + half % 10;
        return pal;
    }
public:
    vector<long long> kthPalindrome(vector<int>& Q, int len) {
        long begin = pow(10L, (len - 1) / 2), end = pow(10L, (len + 1) / 2);
        vector<long long> ans(Q.size(), -1);
        for (int i = 0; i < Q.size(); ++i) {
            long half = begin + Q[i] - 1;
            if (half < end) ans[i] = getPalindrome(half, len % 2);
        }
        return ans;
    }
};
```

## Discuss

https://leetcode.com/problems/find-palindrome-with-fixed-length/discuss/1887018/