# [271. Encode and Decode Strings (Medium)](https://leetcode.com/problems/encode-and-decode-strings/)

<p>
Design an algorithm to encode <b>a list of strings</b> to <b>a string</b>. The encoded string is then sent over the network and is decoded back to the original list of strings.</p>

<p>
Machine 1 (sender) has the function:
</p><pre>string encode(vector&lt;string&gt; strs) {
  // ... your code
  return encoded_string;
}</pre>

Machine 2 (receiver) has the function:
<pre>vector&lt;string&gt; decode(string s) {
  //... your code
  return strs;
}</pre>
<p></p>

<p>
So Machine 1 does:
</p><pre>string encoded_string = encode(strs);</pre>
<p></p>

<p>
and Machine 2 does:
</p><pre>vector&lt;string&gt; strs2 = decode(encoded_string);</pre>
<p></p>

<p>
<code>strs2</code> in Machine 2 should be the same as <code>strs</code> in Machine 1.
</p>

<p>Implement the <code>encode</code> and <code>decode</code> methods.
</p>

<p><b>Note:</b><br>
</p><ul>
<li>The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.</li>
<li>Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.</li>
<li>Do not rely on any library method such as <code>eval</code> or serialize methods. You should implement your own encode/decode algorithm.</li>
</ul><p></p>

**Companies**:  
[Google](https://leetcode.com/company/google), [Square](https://leetcode.com/company/square), [Twitter](https://leetcode.com/company/twitter)

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Count and Say (Easy)](https://leetcode.com/problems/count-and-say/)
* [Serialize and Deserialize Binary Tree (Hard)](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)
* [String Compression (Easy)](https://leetcode.com/problems/string-compression/)
* [Count Binary Substrings (Easy)](https://leetcode.com/problems/count-binary-substrings/)

## Solution 1.

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