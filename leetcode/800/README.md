# [800. Similar RGB Color (Easy)](https://leetcode.com/problems/similar-rgb-color/)

<p>In the following, every capital letter represents some hexadecimal digit from <code>0</code> to <code>f</code>.</p>

<p>The red-green-blue color <code>"#AABBCC"</code>&nbsp;can be written&nbsp;as&nbsp;<code>"#ABC"</code> in&nbsp;shorthand.&nbsp; For example, <code>"#15c"</code> is shorthand for the color <code>"#1155cc"</code>.</p>

<p>Now, say the similarity between two colors <code>"#ABCDEF"</code> and <code>"#UVWXYZ"</code> is <code>-(AB - UV)^2 -&nbsp;(CD - WX)^2 -&nbsp;(EF - YZ)^2</code>.</p>

<p>Given the color <code>"#ABCDEF"</code>, return a 7 character color&nbsp;that is most similar to <code>#ABCDEF</code>, and has a shorthand (that is, it can be represented as some <code>"#XYZ"</code></p>

<pre><strong>Example 1:</strong>
<strong>Input:</strong> color = "#09f166"
<strong>Output:</strong> "#11ee66"
<strong>Explanation: </strong> 
The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.
</pre>

<p><strong>Note:</strong></p>

<ul>
	<li><code>color</code> is a string of length <code>7</code>.</li>
	<li><code>color</code> is a valid RGB color: for <code>i &gt; 0</code>, <code>color[i]</code> is a hexadecimal digit from <code>0</code> to <code>f</code></li>
	<li>Any answer which has the same (highest)&nbsp;similarity as the best answer will be accepted.</li>
	<li>All inputs and outputs should use lowercase letters, and the output is 7 characters.</li>
</ul>


**Companies**:  
[Google](https://leetcode.com/company/google)

**Related Topics**:  
[Math](https://leetcode.com/tag/math/), [String](https://leetcode.com/tag/string/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/similar-rgb-color/
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
    const string digits = "0123456789abcdef";
public:
    string similarRGB(string color) {
        string ans = "#";
        for (int i = 0; i < 3; ++i) {
            char a = color[1 + i * 2], b = color[2 + i * 2];
            int hex1 = stoi(color.substr(1 + i * 2, 2), nullptr, 16);
            int best = 0, bestSim = INT_MIN;
            for (int j = 0; j < 16; ++j) {
                int hex2 = j * 16 + j;
                int sim = -pow(hex1 - hex2, 2);
                if (sim > bestSim) {
                    bestSim = sim;
                    best = j;
                }
            }
            char c = digits[best];
            ans += c;
            ans += c;
        }
        return ans;
    }
};
```