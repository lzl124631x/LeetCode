# [271. Encode and Decode Strings (Medium)](https://leetcode.com/problems/encode-and-decode-strings)

<p>Design an algorithm to encode <b>a list of strings</b> to <b>a string</b>. The encoded string is then sent over the network and is decoded back to the original list of strings.</p>
<p>Machine 1 (sender) has the function:</p>
<pre>string encode(vector&lt;string&gt; strs) {
  // ... your code
  return encoded_string;
}</pre>
<pre>vector&lt;string&gt; decode(string s) {
  //... your code
  return strs;
}
</pre>
<p>So Machine 1 does:</p>
<pre>string encoded_string = encode(strs);
</pre>
<p>and Machine 2 does:</p>
<pre>vector&lt;string&gt; strs2 = decode(encoded_string);
</pre>
<p><code>strs2</code> in Machine 2 should be the same as <code>strs</code> in Machine 1.</p>
<p>Implement the <code>encode</code> and <code>decode</code> methods.</p>
<p>You are not allowed to&nbsp;solve the problem using any serialize methods (such as <code>eval</code>).</p>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> dummy_input = ["Hello","World"]
<strong>Output:</strong> ["Hello","World"]
<strong>Explanation:</strong>
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---&gt; Machine 2

Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
</pre>
<p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> dummy_input = [""]
<strong>Output:</strong> [""]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>
<ul>
	<li><code>1 &lt;= strs.length &lt;= 200</code></li>
	<li><code>0 &lt;= strs[i].length &lt;= 200</code></li>
	<li><code>strs[i]</code> contains any possible characters out of <code>256</code> valid ASCII characters.</li>
</ul>
<p>&nbsp;</p>
<p><strong>Follow up: </strong>Could you write a generalized algorithm to work on any possible set of characters?</p>

**Companies**:
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [Square](https://leetcode.com/company/square)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [String](https://leetcode.com/tag/string/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Count and Say (Medium)](https://leetcode.com/problems/count-and-say/)
* [Serialize and Deserialize Binary Tree (Hard)](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
* [String Compression (Medium)](https://leetcode.com/problems/string-compression/)
* [Count Binary Substrings (Easy)](https://leetcode.com/problems/count-binary-substrings/)

## Solution 1.

We use `$x` as a separator. To avoid confusing the `$x` in the original string as a separator, we escape `$` sign using `$` sign, so `ab$xcd` is escaped to be `ab$$xcd`.

```cpp
// OJ: https://leetcode.com/problems/encode-and-decode-strings/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Codec {
public:
    string encode(vector<string>& strs) {
        string ans;
        for (string &str : strs) {
            for (char c : str) {
                if (c == '$') ans.push_back(c);
                ans.push_back(c);
            }
            ans.push_back('$');
            ans.push_back('x');
        }
        return ans;
    }
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0, N = s.size();
        while (i < N) {
            string str;
            for (; i < N; ++i) {
                if (s[i] != '$') str.push_back(s[i]);
                else if (i + 1 < N && s[i + 1] == '$') str.push_back(s[i++]);
                else {
                    i += 2;
                    break;
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};
```