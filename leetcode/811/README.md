# [811. Subdomain Visit Count (Easy)](https://leetcode.com/problems/subdomain-visit-count/)

<p>A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.</p>

<p>Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".</p>

<p>We are given a list <code>cpdomains</code> of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.</p>

<pre><strong>Example 1:</strong>
<strong>Input:</strong> 
["9001 discuss.leetcode.com"]
<strong>Output:</strong> 
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
<strong>Explanation:</strong> 
We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

</pre>

<pre><strong>Example 2:</strong>
<strong>Input:</strong> 
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
<strong>Output:</strong> 
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
<strong>Explanation:</strong> 
We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

</pre>

<p><strong>Notes: </strong></p>

<ul>
	<li>The length of <code>cpdomains</code> will not exceed&nbsp;<code>100</code>.&nbsp;</li>
	<li>The length of each domain name will not exceed <code>100</code>.</li>
	<li>Each address will have either 1 or 2 "." characters.</li>
	<li>The input count&nbsp;in any count-paired domain will not exceed <code>10000</code>.</li>
	<li>The answer output can be returned in any order.</li>
</ul>


## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/subdomain-visit-count/
// Author: github.com/lzl124631x
// Time: O(N*S^2) where N is count of cpdomains, S is max length of cpdomain string.
// Space: O(N)
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (auto cpdomain : cpdomains) {
            int cnt = stoi(cpdomain), i = cpdomain.find_first_of(" ");
            string domain = cpdomain.substr(i + 1);
            while (true) {
                m[domain] += cnt;
                i = domain.find_first_of(".");
                if (i == string::npos) break;
                domain = domain.substr(i + 1);
            }
        }
        vector<string> v;
        for (auto p : m) {
            v.push_back(to_string(p.second) + " " + p.first);
        }
        return v;
    }
};
```