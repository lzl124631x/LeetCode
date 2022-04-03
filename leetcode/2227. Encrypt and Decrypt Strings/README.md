# [2227. Encrypt and Decrypt Strings (Hard)](https://leetcode.com/problems/encrypt-and-decrypt-strings/)

<p>You are given a character array <code>keys</code> containing <strong>unique</strong> characters and a string array <code>values</code> containing strings of length 2. You are also given another string array <code>dictionary</code> that contains all permitted original strings after decryption. You should implement a data structure that can encrypt or decrypt a <strong>0-indexed</strong> string.</p>

<p>A string is <strong>encrypted</strong> with the following process:</p>

<ol>
	<li>For each character <code>c</code> in the string, we find the index <code>i</code> satisfying <code>keys[i] == c</code> in <code>keys</code>.</li>
	<li>Replace <code>c</code> with <code>values[i]</code> in the string.</li>
</ol>

<p>A string is <strong>decrypted</strong> with the following process:</p>

<ol>
	<li>For each substring <code>s</code> of length 2 occurring at an even index in the string, we find an <code>i</code> such that <code>values[i] == s</code>. If there are multiple valid <code>i</code>, we choose <strong>any</strong> one of them. This means a string could have multiple possible strings it can decrypt to.</li>
	<li>Replace <code>s</code> with <code>keys[i]</code> in the string.</li>
</ol>

<p>Implement the <code>Encrypter</code> class:</p>

<ul>
	<li><code>Encrypter(char[] keys, String[] values, String[] dictionary)</code> Initializes the <code>Encrypter</code> class with <code>keys, values</code>, and <code>dictionary</code>.</li>
	<li><code>String encrypt(String word1)</code> Encrypts <code>word1</code> with the encryption process described above and returns the encrypted string.</li>
	<li><code>int decrypt(String word2)</code> Returns the number of possible strings <code>word2</code> could decrypt to that also appear in <code>dictionary</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["Encrypter", "encrypt", "decrypt"]
[[['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]], ["abcd"], ["eizfeiam"]]
<strong>Output</strong>
[null, "eizfeiam", 2]

<strong>Explanation</strong>
Encrypter encrypter = new Encrypter([['a', 'b', 'c', 'd'], ["ei", "zf", "ei", "am"], ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"]);
encrypter.encrypt("abcd"); // return "eizfeiam". 
&nbsp;                          // 'a' maps to "ei", 'b' maps to "zf", 'c' maps to "ei", and 'd' maps to "am".
encrypter.decrypt("eizfeiam"); // return 2. 
                              // "ei" can map to 'a' or 'c', "zf" maps to 'b', and "am" maps to 'd'. 
                              // Thus, the possible strings after decryption are "abad", "cbad", "abcd", and "cbcd". 
                              // 2 of those strings, "abad" and "abcd", appear in dictionary, so the answer is 2.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= keys.length == values.length &lt;= 26</code></li>
	<li><code>values[i].length == 2</code></li>
	<li><code>1 &lt;= dictionary.length &lt;= 100</code></li>
	<li><code>1 &lt;= dictionary[i].length &lt;= 100</code></li>
	<li>All <code>keys[i]</code> and <code>dictionary[i]</code> are <strong>unique</strong>.</li>
	<li><code>1 &lt;= word1.length &lt;= 2000</code></li>
	<li><code>1 &lt;= word2.length &lt;= 200</code></li>
	<li>All <code>word1[i]</code> appear in <code>keys</code>.</li>
	<li><code>word2.length</code> is even.</li>
	<li><code>keys</code>, <code>values[i]</code>, <code>dictionary[i]</code>, <code>word1</code>, and <code>word2</code> only contain lowercase English letters.</li>
	<li>At most <code>200</code> calls will be made to <code>encrypt</code> and <code>decrypt</code> <strong>in total</strong>.</li>
</ul>


**Companies**:  
[Duolingo](https://leetcode.com/company/duolingo)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [Implement Trie (Prefix Tree) (Medium)](https://leetcode.com/problems/implement-trie-prefix-tree/)
* [Word Search II (Hard)](https://leetcode.com/problems/word-search-ii/)
* [Implement Trie II (Prefix Tree) (Medium)](https://leetcode.com/problems/implement-trie-ii-prefix-tree/)

## Solution 1. Hash Map

`encrypt` is straightforward. For `decrypt`, we can precompute ans store the frequencies of encrypted permitted original strings in a map `freq`, and return `freq[word]` in `decrypt`.

```cpp
// OJ: https://leetcode.com/problems/encrypt-and-decrypt-strings/
// Author: github.com/lzl124631x
// Time:
//      Encrypter: O(K + V + D) where `K` is the length of `keys`, `V` and `D` are the sizes of all the contents in `values` and `dict`, respectively.
//      encrypt: O(W) where `W` is the length of the input word
//      decrypt: O(W)
// Space: O(K + V + D)
class Encrypter {
    unordered_map<char, string> m; // mapping from character keys to corresponding value strings
    unordered_map<string, int> freq; // frequency map of encrypted permitted original strings
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < keys.size(); ++i) {
            m[keys[i]] = values[i];
        }
        for (auto &s : dictionary) {
            auto e = encrypt(s);
            if (e.size()) freq[e]++;
        }
    }
    string encrypt(string s) {
        string ans;
        for (char c : s) {
            if (m.count(c) == 0) return ""; // invalid key character met, return empty string.
            ans += m[c];
        }
        return ans;
    }
    int decrypt(string s) {
        return freq.count(s) ? freq[s] : 0;
    }
};
```

The problem didn't say clearly whether a permitted original string might include unsupported keys. If it might include, then we need to consider the following testcase:

```
["Encrypter","decrypt"]
[[["a"],["pq"],["a","ax"]],["pq"]]
```

## Discuss

https://leetcode.com/problems/encrypt-and-decrypt-strings/discuss/1908851