# [906. Super Palindromes (Hard)](https://leetcode.com/problems/super-palindromes/)

<p>Let's say a positive integer is a&nbsp;<em>superpalindrome</em>&nbsp;if it is a palindrome, and it is also the square of a palindrome.</p>

<p>Now, given two positive&nbsp;integers <code>L</code> and <code>R</code> (represented as strings), return the number of superpalindromes in the inclusive range <code>[L, R]</code>.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>L = <span id="example-input-1-1">"4"</span>, R = <span id="example-input-1-2">"1000"</span>
<strong>Output: </strong>4
<span><strong>Explanation</strong>: </span>4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= len(L) &lt;= 18</code></li>
	<li><code>1 &lt;= len(R) &lt;= 18</code></li>
	<li><code>L</code> and <code>R</code> are strings representing integers in the range <code>[1, 10^18)</code>.</li>
	<li><code>int(L) &lt;= int(R)</code></li>
</ol>

<div>
<p>&nbsp;</p>
</div>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/super-palindromes/
// Author: github.com/lzl124631x
// Time: O(W^(1/4)*logW)
// Space: O(logW)
// Ref: https://leetcode.com/problems/super-palindromes/solution/
typedef unsigned long long ULL;
class Solution {
private:
    bool isPalindrome(ULL n) {
        ULL r = 0, num = n;
        while (n) {
            r = r * 10 + n % 10;
            n /= 10;
        }
        return r == num;
    }
public:
    int superpalindromesInRange(string L, string R) {
        ULL i = 1, ans = 0, nl = stoull(L), nr = stoull(R), MAGIC = 100000;
        for (int k = 1; k < MAGIC; ++k) {
            string s = to_string(k);
            for (int i = s.size() - 2; i >= 0; --i) s += s[i];
            ULL n = stoull(s);
            n *= n;
            if (n > nr) break;
            if (n >= nl && isPalindrome(n)) ++ans;
        }
        for (int k = 1; k < MAGIC; ++k) {
            string s = to_string(k);
            for (int i = s.size() - 1; i >= 0; --i) s += s[i];
            ULL n = stoull(s);
            n *= n;
            if (n > nr) break;
            if (n >= nl && isPalindrome(n)) ++ans;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/super-palindromes/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
// Ref: https://leetcode.com/problems/super-palindromes/discuss/170728/no-more-this-type-questions-for-contest!
typedef unsigned long long ULL;
class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        vector<ULL> v{
            1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004 ,404090404, 10000200001l, 10221412201l, 12102420121l, 12345654321l, 40000800004l , 1000002000001l, 1002003002001l, 1004006004001l, 1020304030201l, 1022325232201l, 1024348434201l, 1210024200121l, 1212225222121l, 1214428244121l, 1232346432321l, 1234567654321l, 4000008000004l, 4004009004004l, 100000020000001l, 100220141022001l, 102012040210201l, 102234363432201l, 121000242000121l, 121242363242121l, 123212464212321l, 123456787654321l, 400000080000004l, 10000000200000001l, 10002000300020001l, 10004000600040001l, 10020210401202001l, 10022212521222001l, 10024214841242001l, 10201020402010201l, 10203040504030201l, 10205060806050201l, 10221432623412201l, 10223454745432201l, 12100002420000121l, 12102202520220121l, 12104402820440121l, 12122232623222121l, 12124434743442121l, 12321024642012321l, 12323244744232321l, 12343456865434321l, 12345678987654321l, 40000000800000004l, 40004000900040004l
        };
        return upper_bound(v.begin(), v.end(), stoull(R)) - lower_bound(v.begin(), v.end(), stoull(L));
    }
};
```