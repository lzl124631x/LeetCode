# [1452. People Whose List of Favorite Companies Is Not a Subset of Another List (Medium)](https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/)

<p>Given the array <code>favoriteCompanies</code> where <code>favoriteCompanies[i]</code> is the list of favorites companies for the <code>ith</code> person (<strong>indexed from 0</strong>).</p>

<p><em>Return the indices of people whose list of favorite companies is not a <strong>subset</strong> of any other list of favorites companies</em>. You must return the indices&nbsp;in increasing order.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> favoriteCompanies = [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
<strong>Output:</strong> [0,1,4] 
<strong>Explanation:</strong> 
Person with index=2 has favoriteCompanies[2]=["google","facebook"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"] corresponding to the person with index 0. 
Person with index=3 has favoriteCompanies[3]=["google"] which is a subset of favoriteCompanies[0]=["leetcode","google","facebook"] and favoriteCompanies[1]=["google","microsoft"]. 
Other lists of favorite companies are not a subset of another list, therefore, the answer is [0,1,4].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> favoriteCompanies = [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
<strong>Output:</strong> [0,1] 
<strong>Explanation:</strong> In this case favoriteCompanies[2]=["facebook","google"] is a subset of favoriteCompanies[0]=["leetcode","google","facebook"], therefore, the answer is [0,1].
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
<strong>Output:</strong> [0,1,2,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;favoriteCompanies.length &lt;= 100</code></li>
	<li><code>1 &lt;=&nbsp;favoriteCompanies[i].length &lt;= 500</code></li>
	<li><code>1 &lt;=&nbsp;favoriteCompanies[i][j].length &lt;= 20</code></li>
	<li>All strings in <code>favoriteCompanies[i]</code> are <strong>distinct</strong>.</li>
	<li>All lists of favorite companies are <strong>distinct</strong>, that is, If we sort alphabetically each list then <code>favoriteCompanies[i] != favoriteCompanies[j].</code></li>
	<li>All strings consist of lowercase English letters only.</li>
</ul>


**Related Topics**:  
[String](https://leetcode.com/tag/string/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/
// Author: github.com/lzl124631x
// Time: O(NM + N^2) where N is the length of A and M is the maximum length of A[i]
// Space: O(NM)
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& A) {
        int id = 0, N = A.size();
        vector<bitset<50000>> v;
        unordered_map<string, int> m;
        for (auto &p : A) {
            bitset<50000> bs;
            for (auto &c : p) {
                if (m.count(c) == 0) m[c] = id++;
                bs.set(m[c]);
            }
            v.push_back(bs);
        }
        vector<int> ans;
        for (int i = 0; i < N; ++i) {
            int j = 0;
            for (; j < N; ++j) {
                if (i == j) continue;
                if ((v[i] | v[j]) == v[j]) break;
            }
            if (j == N) ans.push_back(i);
        }
        return ans;
    }
};
```