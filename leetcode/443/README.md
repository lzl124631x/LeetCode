# [443. String Compression (Medium)](https://leetcode.com/problems/string-compression/)

<p>Given an array of characters <code>chars</code>, compress it using the following algorithm:</p>

<p>Begin with an empty string <code>s</code>. For each group of <strong>consecutive repeating characters</strong> in <code>chars</code>:</p>

<ul>
	<li>If the group's length is 1, append the character to&nbsp;<code>s</code>.</li>
	<li>Otherwise, append the character followed by the group's length.</li>
</ul>

<p>The compressed string&nbsp;<code>s</code> <strong>should not be returned separately</strong>, but instead be stored&nbsp;<strong>in the input character array&nbsp;<code>chars</code></strong>. Note that group lengths that are 10 or longer will be split into multiple characters in&nbsp;<code>chars</code>.</p>

<p>After you are done <b>modifying the input array</b>, return <em>the new length of the array</em>.</p>
You must write an algorithm that uses only constant extra space.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> chars = ["a","a","b","b","c","c","c"]
<strong>Output:</strong> Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
<strong>Explanation:</strong>&nbsp;The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> chars = ["a"]
<strong>Output:</strong> Return 1, and the first character of the input array should be: ["a"]
<strong>Explanation:</strong>&nbsp;The only group is "a", which remains uncompressed since it's a single character.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
<strong>Output:</strong> Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
<strong>Explanation:</strong>&nbsp;The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> chars = ["a","a","a","b","b","a","a"]
<strong>Output:</strong> Return 6, and the first 6 characters of the input array should be: ["a","3","b","2","a","2"].
<strong>Explanation:</strong>&nbsp;The groups are "aaa", "bb", and "aa". This compresses to "a3b2a2". Note that each group is independent even if two groups have the same character.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= chars.length &lt;= 2000</code></li>
	<li><code>chars[i]</code> is a lower-case English letter, upper-case English letter, digit, or symbol.</li>
</ul>


**Companies**:  
[Goldman Sachs](https://leetcode.com/company/goldman-sachs), [Microsoft](https://leetcode.com/company/microsoft), [Apple](https://leetcode.com/company/apple), [Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Yandex](https://leetcode.com/company/yandex), [Google](https://leetcode.com/company/google), [Cisco](https://leetcode.com/company/cisco), [eBay](https://leetcode.com/company/ebay), [Redfin](https://leetcode.com/company/redfin), [Nvidia](https://leetcode.com/company/nvidia)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Count and Say (Medium)](https://leetcode.com/problems/count-and-say/)
* [Encode and Decode Strings (Medium)](https://leetcode.com/problems/encode-and-decode-strings/)
* [Design Compressed String Iterator (Easy)](https://leetcode.com/problems/design-compressed-string-iterator/)
* [Decompress Run-Length Encoded List (Easy)](https://leetcode.com/problems/decompress-run-length-encoded-list/)
## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/string-compression/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(log_10^N)
class Solution {
public:
    int compress(vector<char>& A) {
        int j = 0;
        for (int i = 0; i < A.size(); ++i) {
            char c = A[i];
            int cnt = 1;
            while (i + 1 < A.size() && A[i + 1] == c) ++i, ++cnt;
            A[j++] = c;
            if (cnt == 1) continue;
            auto s = to_string(cnt);
            for (char d : s) A[j++] = d;
        }
        return j;
    }
};
```

Or don't use `to_string` which takes extra space.

```cpp
// OJ: https://leetcode.com/problems/string-compression/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int compress(vector<char>& A) {
        int j = 0;
        for (int i = 0; i < A.size(); ++i) {
            char c = A[i];
            int cnt = 1, p = 1;
            while (i + 1 < A.size() && A[i + 1] == c) ++i, ++cnt;
            A[j++] = c;
            if (cnt == 1) continue;
            while (cnt / p) p *= 10;
            for (p /= 10; p; p /= 10) {
                A[j++] = '0' + cnt / p;
                cnt %= p;
            }
        }
        return j;
    }
};
```