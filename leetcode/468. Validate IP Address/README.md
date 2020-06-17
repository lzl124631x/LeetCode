# [468. Validate IP Address (Medium)](https://leetcode.com/problems/validate-ip-address/)

<p>
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.
</p>

<p>
<b>IPv4</b> addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,<code>172.16.254.1</code>;
</p>

<p>
Besides, leading zeros in the IPv4 is invalid. For example, the address <code>172.16.254.01</code> is invalid.
</p>

<p>
<b>IPv6</b> addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address <code>2001:0db8:85a3:0000:0000:8a2e:0370:7334</code> is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so <code>2001:db8:85a3:0:0:8A2E:0370:7334</code> is also a valid IPv6 address(Omit leading zeros and using upper cases).
</p>


<p>
However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, <code>2001:0db8:85a3::8A2E:0370:7334</code> is an invalid IPv6 address.
</p>

<p>
Besides, extra leading zeros in the IPv6 is also invalid. For example, the address <code>02001:0db8:85a3:0000:0000:8a2e:0370:7334</code> is invalid.
</p>


<p><b>Note:</b>
You may assume there is no extra space or special characters in the input string.
</p>

<p><b>Example 1:</b><br>
</p><pre><b>Input:</b> "172.16.254.1"

<b>Output:</b> "IPv4"

<b>Explanation:</b> This is a valid IPv4 address, return "IPv4".
</pre>
<p></p>


<p><b>Example 2:</b><br>
</p><pre><b>Input:</b> "2001:0db8:85a3:0:0:8A2E:0370:7334"

<b>Output:</b> "IPv6"

<b>Explanation:</b> This is a valid IPv6 address, return "IPv6".
</pre>
<p></p>

<p><b>Example 3:</b><br>
</p><pre><b>Input:</b> "256.256.256.256"

<b>Output:</b> "Neither"

<b>Explanation:</b> This is neither a IPv4 address nor a IPv6 address.
</pre>
<p></p>

**Related Topics**:  
[String](https://leetcode.com/tag/string/)

**Similar Questions**:
* [IP to CIDR (Easy)](https://leetcode.com/problems/ip-to-cidr/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3362/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
    bool isValidIPv6(string &IP) {
        int i = 0, N = IP.size(), segment = 0;
        while (i < N) {
            int cnt = 0;
            while (i < N && (isdigit(IP[i]) || (IP[i] >= 'a' && IP[i] <= 'f') || (IP[i] >= 'A' && IP[i] <= 'F'))) {
                ++i;
                if (++cnt > 4) return false;
            }
            if (cnt == 0) return false;
            ++segment;
            if (segment < 8) {
                if (i >= N || IP[i] != ':') return false;
                ++i;
            } else if (segment > 8) return false;
        }
        return segment == 8;
    }
    bool isValidIPv4(string &IP) {
        int i = 0, N = IP.size(), segment = 0;
        while (i < N) {
            int num = 0, digit = 0;
            bool leadingZero = i < N && IP[i] == '0';
            while (i < N && isdigit(IP[i])) {
                num = num * 10 + (IP[i++] - '0');
                ++digit;
                if (digit > 3 || num > 255) return false;
            }
            if (digit == 0) return false;
            ++segment;
            if (leadingZero && (num != 0 || digit != 1)) return false;
            if (segment < 4) {
                if (i >= N || IP[i] != '.') return false;
                ++i;
            } else if (segment > 4) return false;
        }
        return segment == 4;
    }
public:
    string validIPAddress(string IP) {
        if (isValidIPv4(IP)) return "IPv4";
        if (isValidIPv6(IP)) return "IPv6";
        return "Neither";
    }
};
```