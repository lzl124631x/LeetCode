# [929. Unique Email Addresses (Easy)](https://leetcode.com/problems/unique-email-addresses)

Every email consists of a local name and a domain name, separated by the @ sign.

For example, in `alice@leetcode.com`, `alice` is the local name, and `leetcode.com` is the domain name.

Besides lowercase letters, these emails may contain `'.'`s or `'+'`s.

If you add periods (`'.'`) between some characters in the **local name** part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, `"alice.z@leetcode.com"` and `"alicez@leetcode.com"` forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus (`'+'`) in the **local name**, everything after the first plus sign will be **ignored**. This allows certain emails to be filtered, for example `m.y+name@email.com` will be forwarded to `my@email.com`.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of `emails`, we send one email to each address in the list.  How many different addresses actually receive mails? 

**Example 1:**

**Input:** \["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"\]  
**Output:** 2  
**Explanation:** "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails

**Note:**

*   `1 <= emails[i].length <= 100`
*   `1 <= emails.length <= 100`
*   Each `emails[i]` contains exactly one `'@'` character.

## Solution 1.

```cpp
// OJ: hhttps://leetcode.com/problems/unique-email-addresses/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
private:
    string normalize(string &email) {
        string ans;
        int i = 0;
        for (; email[i] != '@'; ++i) {
            if (isalpha(email[i])) ans += email[i];
            if (email[i] == '+') break;
        }
        while (email[i] != '@') ++i;
        return ans + email.substr(i);
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (auto email : emails) {
            s.insert(normalize(email));
        }
        return s.size();
    }
};
```