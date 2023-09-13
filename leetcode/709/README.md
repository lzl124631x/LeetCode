# [709. To Lower Case (Easy)](https://leetcode.com/problems/to-lower-case/)

<p>Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.</p>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">"Hello"</span>
<strong>Output: </strong><span id="example-output-1">"hello"</span>
</pre>

<div>
<p><strong>Example 2:</strong></p>

<pre><strong>Input: </strong><span id="example-input-2-1">"here"</span>
<strong>Output: </strong><span id="example-output-2">"here"</span>
</pre>

<div>
<p><strong>Example 3:</strong></p>

<pre><strong>Input: </strong><span id="example-input-3-1">"LOVELY"</span>
<strong>Output: </strong><span id="example-output-3">"lovely"</span>
</pre>
</div>
</div>
</div>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/to-lower-case/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string toLowerCase(string str) {
        for (char &c : str) c = tolower(c);
        return str;
    }
};
```