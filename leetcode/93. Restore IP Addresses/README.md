# [93. Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses)

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given `"25525511135"`,

return `["255.255.11.135", "255.255.111.35"]`. (Order does not matter)

## Solution 1. Backtracking

Plain backtracking. Maximum depth is 4. Be aware of the cases where ip segment starts with `0` or ip segment is greater than `255`.

```cpp
// OJ: https://leetcode.com/problems/restore-ip-addresses
// Author: github.com/lzl124631x
// Time: O(1)
// Space: O(1)
class Solution {
private:
  vector<string> ans;
  void dfs(string &s, int start, int pos, string &ip) {
    if (pos == 4) {
      if (start == s.size()) ans.push_back(ip);
      return;
    }
    int i = 0;
    for (int num = 0; i < 3 && start + i < s.size(); ++i) {
      num = num * 10 + s[start + i] - '0';
      if (num > 255 || (s[start] == '0' && i)) break;
      ip.push_back(s[start + i]);
      if (pos < 3) ip.push_back('.');
      dfs(s, start + i + 1, pos + 1, ip);
      if (pos < 3) ip.pop_back();
    }
    while (i--) ip.pop_back();
  }
public:
  vector<string> restoreIpAddresses(string s) {
    string ip;
    dfs(s, 0, 0, ip);
    return ans;
  }
};
```