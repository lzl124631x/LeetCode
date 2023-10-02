# [2288. Apply Discount to Prices (Medium)](https://leetcode.com/problems/apply-discount-to-prices)

<p>A <strong>sentence</strong> is a string of single-space separated words where each word can contain digits, lowercase letters, and the dollar sign <code>'$'</code>. A word represents a <strong>price</strong> if it is a sequence of digits preceded by a dollar sign.</p>
<ul>
	<li>For example, <code>"$100"</code>, <code>"$23"</code>, and <code>"$6"</code> represent prices while <code>"100"</code>, <code>"$"</code>, and <code>"$1e5"</code> do not.</li>
</ul>
<p>You are given a string <code>sentence</code> representing a sentence and an integer <code>discount</code>. For each word representing a price, apply a discount of <code>discount%</code> on the price and <strong>update</strong> the word in the sentence. All updated prices should be represented with <strong>exactly two</strong> decimal places.</p>
<p>Return <em>a string representing the modified sentence</em>.</p>
<p>Note that all prices will contain <strong>at most</strong> <code>10</code> digits.</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> sentence = "there are $1 $2 and 5$ candies in the shop", discount = 50
<strong>Output:</strong> "there are $0.50 $1.00 and 5$ candies in the shop"
<strong>Explanation:</strong> 
The words which represent prices are "$1" and "$2". 
- A 50% discount on "$1" yields "$0.50", so "$1" is replaced by "$0.50".
- A 50% discount on "$2" yields "$1". Since we need to have exactly 2 decimal places after a price, we replace "$2" with "$1.00".
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$", discount = 100
<strong>Output:</strong> "1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"
<strong>Explanation:</strong> 
Applying a 100% discount on any price will result in 0.
The words representing prices are "$3", "$5", "$6", and "$9".
Each of them is replaced by "$0.00".
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= sentence.length &lt;= 10<sup>5</sup></code></li>
	<li><code>sentence</code> consists of lowercase English letters, digits, <code>' '</code>, and <code>'$'</code>.</li>
	<li><code>sentence</code> does not have leading or trailing spaces.</li>
	<li>All words in <code>sentence</code> are separated by a single space.</li>
	<li>All prices will be <strong>positive</strong> numbers without leading zeros.</li>
	<li>All prices will have <strong>at most</strong> <code>10</code> digits.</li>
	<li><code>0 &lt;= discount &lt;= 100</code></li>
</ul>

**Companies**:
[Amazon](https://leetcode.com/company/amazon)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Multiply Strings (Medium)](https://leetcode.com/problems/multiply-strings/)
* [Apply Discount Every n Orders (Medium)](https://leetcode.com/problems/apply-discount-every-n-orders/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/apply-discount-to-prices
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string discountPrices(string s, int discount) {
        istringstream ss(s);
        string word, ans;
        while (ss >> word) {
            if (ans.size()) ans += ' ';
            if (word[0] == '$' && word.size() > 1) {
                long long i = 1, num = 0;
                while (i < word.size() && isdigit(word[i])) {
                    num = num * 10 + (word[i++] - '0');
                }
                if (i == word.size()) {
                    ostringstream tmp;
                    tmp << fixed << setprecision(2) << num * (100 - discount) / 100.;
                    ans += "$" + tmp.str();
                    continue;
                }
            }
            ans += word;
        }
        return ans;
    }
};
```