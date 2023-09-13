# [535. Encode and Decode TinyURL (Medium)](https://leetcode.com/problems/encode-and-decode-tinyurl/)

<blockquote>Note: This is a companion problem to the <a href="https://leetcode.com/discuss/interview-question/system-design/" target="_blank">System Design</a> problem: <a href="https://leetcode.com/discuss/interview-question/124658/Design-a-URL-Shortener-(-TinyURL-)-System/" target="_blank">Design TinyURL</a>.</blockquote>

<p>TinyURL is a URL shortening service where you enter a URL such as <code>https://leetcode.com/problems/design-tinyurl</code> and it returns a short URL such as <code>http://tinyurl.com/4e9iAk</code>. Design a class to encode a URL and decode a tiny URL.</p>

<p>There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.</p>

<p>Implement the <code>Solution</code> class:</p>

<ul>
	<li><code>Solution()</code> Initializes the object of the system.</li>
	<li><code>String encode(String longUrl)</code> Returns a tiny URL for the given <code>longUrl</code>.</li>
	<li><code>String decode(String shortUrl)</code> Returns the original long URL for the given <code>shortUrl</code>. It is guaranteed that the given <code>shortUrl</code> was encoded by the same object.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> url = "https://leetcode.com/problems/design-tinyurl"
<strong>Output:</strong> "https://leetcode.com/problems/design-tinyurl"

<strong>Explanation:</strong>
Solution obj = new Solution();
string tiny = obj.encode(url); // returns the encoded tiny url.
string ans = obj.decode(tiny); // returns the original url after deconding it.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= url.length &lt;= 10<sup>4</sup></code></li>
	<li><code>url</code> is guranteed to be a valid URL.</li>
</ul>


**Companies**:  
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [String](https://leetcode.com/tag/string/), [Design](https://leetcode.com/tag/design/), [Hash Function](https://leetcode.com/tag/hash-function/)

## Solution 1. Simple Counter

```cpp
// OJ: https://leetcode.com/problems/encode-and-decode-tinyurl/
// Author: github.com/lzl124631x
// Time: O(S) for all
// Space: O(N)
const string origin = "http://tinyurl.com";
class Solution {
private:
    unordered_map<int, string> m;
    int i = 0;
public:
    string encode(string longUrl) {
        m[i] = longUrl;
        return origin + to_string(i++);
    }
    string decode(string shortUrl) {
        return m[stoi(shortUrl.substr(origin.size()))];
    }
};
```

* The range of URLs that can be decoded is limited by the range of `int`.

* If excessively large number of URLs have to be encoded, after the range of `int` is exceeded, integer overflow could lead to overwriting the previous URLs' encodings, leading to the performance degradation.

* The length of the URL isn't necessarily shorter than the incoming `longURL`. It is only dependent on the relative order in which the URLs are encoded.

* One problem with this method is that it is very easy to predict the next code generated, since the pattern can be detected by generating a few encoded URLs.

## Solution 2. Variable-length Encoding

```cpp
// OJ: https://leetcode.com/problems/encode-and-decode-tinyurl/
// Author: github.com/lzl124631x
// Time: O(S) for all
// Space: O(N)
const string origin = "http://tinyurl.com";
const string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
class Solution {
private:
    unordered_map<string, string> m;
    int i = 1;
    string getKey() {
        int tmp = i;
        string key;
        while (tmp > 0) {
            tmp--;
            key += tmp % chars.size();
            tmp /= chars.size();
        }
        return key;
    }
public:
    string encode(string longUrl) {
        string key = getKey();
        m[key] = longUrl;
        i++;
        return origin + key;
    }
    string decode(string shortUrl) {
        return m[shortUrl.substr(origin.size())];
    }
};
```

* The number of URLs that can be encoded is, again, dependent on the range of `int`, since, the same countcount will be generated after overflow of integers.

* The length of the encoded URLs isn't necessarily short, but is to some extent dependent on the order in which the incoming `longURL`'s are encountered. For example, the codes generated will have the lengths in the following order: 1(62 times), 2(62 * 62 times) and so on.

* The performance is quite good, since the same code will be repeated only after the integer overflow limit, which is quite large.

* In this case also, the next code generated could be predicted by the use of some calculations.