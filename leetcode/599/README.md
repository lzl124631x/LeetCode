# [599. Minimum Index Sum of Two Lists (Easy)](https://leetcode.com/problems/minimum-index-sum-of-two-lists/)

<p>
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings. 
</p>
<p>
You need to help them find out their <b>common interest</b> with the <b>least list index sum</b>. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.
</p>


<p><b>Example 1:</b><br>
</p><pre><b>Input:</b>
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
<b>Output:</b> ["Shogun"]
<b>Explanation:</b> The only restaurant they both like is "Shogun".
</pre>
<p></p>

<p><b>Example 2:</b><br>
</p><pre><b>Input:</b>
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
<b>Output:</b> ["Shogun"]
<b>Explanation:</b> The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
</pre>
<p></p>


<p><b>Note:</b><br>
</p><ol>
<li>The length of both lists will be in the range of [1, 1000].</li>
<li>The length of strings in both lists will be in the range of [1, 30].</li>
<li>The index is starting from 0 to the list length minus 1.</li>
<li>No duplicates in both lists.</li>
</ol>
<p></p>

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
// Author: github.com/lzl124631x
// Time: O(L1 + L2)
// Space: O(L1)
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); ++i) m[list1[i]] = i;
        int minSum = INT_MAX;
        vector<string> ans;
        for (int i = 0; i < list2.size() && i <= minSum; ++i) {
            if (m.find(list2[i]) == m.end() || i + m[list2[i]] > minSum) continue;
            if (i + m[list2[i]] < minSum) {
                ans.clear();
                minSum = i + m[list2[i]];
            }
            ans.push_back(list2[i]);
        }
        return ans;
    }
};
```