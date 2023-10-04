# [2468. Split Message Based on Limit (Hard)](https://leetcode.com/problems/split-message-based-on-limit)

<p>You are given a string, <code>message</code>, and a positive integer, <code>limit</code>.</p>

<p>You must <strong>split</strong> <code>message</code> into one or more <strong>parts</strong> based on <code>limit</code>. Each resulting part should have the suffix <code>&quot;&lt;a/b&gt;&quot;</code>, where <code>&quot;b&quot;</code> is to be <strong>replaced</strong> with the total number of parts and <code>&quot;a&quot;</code> is to be <strong>replaced</strong> with the index of the part, starting from <code>1</code> and going up to <code>b</code>. Additionally, the length of each resulting part (including its suffix) should be <strong>equal</strong> to <code>limit</code>, except for the last part whose length can be <strong>at most</strong> <code>limit</code>.</p>

<p>The resulting parts should be formed such that when their suffixes are removed and they are all concatenated <strong>in order</strong>, they should be equal to <code>message</code>. Also, the result should contain as few parts as possible.</p>

<p>Return<em> the parts </em><code>message</code><em> would be split into as an array of strings</em>. If it is impossible to split <code>message</code> as required, return<em> an empty array</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> message = &quot;this is really a very awesome message&quot;, limit = 9
<strong>Output:</strong> [&quot;thi&lt;1/14&gt;&quot;,&quot;s i&lt;2/14&gt;&quot;,&quot;s r&lt;3/14&gt;&quot;,&quot;eal&lt;4/14&gt;&quot;,&quot;ly &lt;5/14&gt;&quot;,&quot;a v&lt;6/14&gt;&quot;,&quot;ery&lt;7/14&gt;&quot;,&quot; aw&lt;8/14&gt;&quot;,&quot;eso&lt;9/14&gt;&quot;,&quot;me&lt;10/14&gt;&quot;,&quot; m&lt;11/14&gt;&quot;,&quot;es&lt;12/14&gt;&quot;,&quot;sa&lt;13/14&gt;&quot;,&quot;ge&lt;14/14&gt;&quot;]
<strong>Explanation:</strong>
The first 9 parts take 3 characters each from the beginning of message.
The next 5 parts take 2 characters each to finish splitting message. 
In this example, each part, including the last, has length 9. 
It can be shown it is not possible to split message into less than 14 parts.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> message = &quot;short message&quot;, limit = 15
<strong>Output:</strong> [&quot;short mess&lt;1/2&gt;&quot;,&quot;age&lt;2/2&gt;&quot;]
<strong>Explanation:</strong>
Under the given constraints, the string can be split into two parts: 
- The first part comprises of the first 10 characters, and has a length 15.
- The next part comprises of the last 3 characters, and has a length 8.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= message.length &lt;= 10<sup>4</sup></code></li>
	<li><code>message</code> consists only of lowercase English letters and <code>&#39; &#39;</code>.</li>
	<li><code>1 &lt;= limit &lt;= 10<sup>4</sup></code></li>
</ul>


**Companies**:
[Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[String](https://leetcode.com/tag/string), [Binary Search](https://leetcode.com/tag/binary-search)

**Similar Questions**:
* [Text Justification (Hard)](https://leetcode.com/problems/text-justification)
* [Search a 2D Matrix (Medium)](https://leetcode.com/problems/search-a-2d-matrix)
* [Sentence Screen Fitting (Medium)](https://leetcode.com/problems/sentence-screen-fitting)

**Hints**:
* Could you solve the problem if you knew how many digits the total number of parts has?
* Try all possible lengths of the total number of parts, and see if the string can be split such that the total number of parts has that length.
* Binary search can be used for each part length to find the precise number of parts needed.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/split-message-based-on-limit
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<string> splitMessage(string s, int limit) {
        int N = s.size();
        vector<int> cnt{9};
        vector<string> ans;
        for (int d = 1; true; ++d) { // split the message into `d`-digit parts
            int total = N, totalParts = 0;
            for (int i = 1; i <= d && total > 0; ++i) { // fill the `i`-digit parts
                int len = 3 + i + d, diff = limit - len; // the tag part takes `len` space. We fill rest `diff` characters with characters from `s`
                if (diff <= 0) break; // can't consume any characters from `s`. It's meaningless to add more parts. Break
                int parts = min(total / diff + (total % diff > 0), cnt[i - 1]); // we can take this many `i`-digit parts.
                totalParts += parts;
                total -= parts * diff;
            }
            if (totalParts == 0) break; // We can't fill any parts. It's impossible to split.
            if (total <= 0) { // We've found a split
                total = N;
                for (int i = 1, id = 1, j = 0; i <= d && total > 0; ++i) {
                    int len = 3 + i + d, diff = limit - len, parts = min(total / diff + (total % diff > 0), cnt[i - 1]);
                    for (int k = 0; k < parts; ++k) {
                        ans.push_back(s.substr(j, diff) + "<" + to_string(id++) + "/" + to_string(totalParts) + ">");
                        j += diff;
                    }
                    total -= parts * diff;
                }
                break;
            }
            cnt.push_back(cnt.back() * 10);
        }
        return ans;
    }
};
```