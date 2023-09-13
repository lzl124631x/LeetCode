# [717. 1-bit and 2-bit Characters (Easy)](https://leetcode.com/problems/1-bit-and-2-bit-characters/)

<p>We have two special characters. The first character can be represented by one bit <code>0</code>. The second character can be represented by two bits (<code>10</code> or <code>11</code>).  </p>

<p>Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> 
bits = [1, 0, 0]
<b>Output:</b> True
<b>Explanation:</b> 
The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> 
bits = [1, 1, 1, 0]
<b>Output:</b> False
<b>Explanation:</b> 
The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
</pre>
<p></p>

<p><b>Note:</b>
</p><li><code>1 &lt;= len(bits) &lt;= 1000</code>.</li>
<li><code>bits[i]</code> is always <code>0</code> or <code>1</code>.</li>
<p></p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

**Similar Questions**:
* [Gray Code (Medium)](https://leetcode.com/problems/gray-code/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& A) {
        for (int i = 0, N = A.size(); i < N; ) {
            if (A[i] == 1) {
                if (i + 2 < N) i += 2;
                else return false;
            } else if (i == N - 1) return true;
            else ++i;
        }
        return false;
    }
};
```