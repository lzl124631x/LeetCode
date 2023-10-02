# [2231. Largest Number After Digit Swaps by Parity (Easy)](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/)

<p>You are given a positive integer <code>num</code>. You may swap any two digits of <code>num</code> that have the same <strong>parity</strong> (i.e. both odd digits or both even digits).</p>

<p>Return<em> the <strong>largest</strong> possible value of </em><code>num</code><em> after <strong>any</strong> number of swaps.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = 1234
<strong>Output:</strong> 3412
<strong>Explanation:</strong> Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = 65875
<strong>Output:</strong> 87655
<strong>Explanation:</strong> Swap the digit 8 with the digit 6, this results in the number 85675.
Swap the first digit 5 with the digit 7, this results in the number 87655.
Note that there may be other sequences of swaps but it can be shown that 87655 is the largest possible number.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= num &lt;= 10<sup>9</sup></code></li>
</ul>


**Similar Questions**:
* [Largest Number At Least Twice of Others (Easy)](https://leetcode.com/problems/largest-number-at-least-twice-of-others/)
* [Sort Array By Parity (Easy)](https://leetcode.com/problems/sort-array-by-parity/)
* [Sort Array By Parity II (Easy)](https://leetcode.com/problems/sort-array-by-parity-ii/)
* [Smallest String With Swaps (Medium)](https://leetcode.com/problems/smallest-string-with-swaps/)
* [Rearrange Array Elements by Sign (Medium)](https://leetcode.com/problems/rearrange-array-elements-by-sign/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
// Author: github.com/lzl124631x
// Time: O(KlogK) where K is the number of digits in `n`
// Space: O(K)
class Solution {
public:
    int largestInteger(int n) {
        vector<int> odd, even;
        auto s = to_string(n);
        for (int i = 0; i < s.size(); ++i) {
            if ((s[i] - '0') % 2) odd.push_back(i);
            else even.push_back(i);
        }
        auto cmp = [&](int a, int b) { return s[a] > s[b]; };
        sort(begin(odd), end(odd), cmp);
        sort(begin(even), end(even), cmp);
        int ans = 0;
        for (int i = 0, j = 0, k = 0; i < s.size(); ++i) {
            if ((s[i] - '0') % 2) ans = ans * 10 + (s[odd[j++]] - '0');
            else ans = ans * 10 + (s[even[k++]] - '0');
        }
        return ans;
    }
};
```