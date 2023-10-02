# [881. Boats to Save People (Medium)](https://leetcode.com/problems/boats-to-save-people/)

<p>You are given an array <code>people</code> where <code>people[i]</code> is the weight of the <code>i<sup>th</sup></code> person, and an <strong>infinite number of boats</strong> where each boat can carry a maximum weight of <code>limit</code>. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most <code>limit</code>.</p>

<p>Return <em>the minimum number of boats to carry every given person</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> people = [1,2], limit = 3
<strong>Output:</strong> 1
<strong>Explanation:</strong> 1 boat (1, 2)
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> people = [3,2,2,1], limit = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 boats (1, 2), (2) and (3)
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> people = [3,5,3,4], limit = 5
<strong>Output:</strong> 4
<strong>Explanation:</strong> 4 boats (3), (3), (4), (5)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= people.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= people[i] &lt;= limit &lt;= 3 * 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Salesforce](https://leetcode.com/company/salesforce), [Amazon](https://leetcode.com/company/amazon), [Cisco](https://leetcode.com/company/cisco), [Uber](https://leetcode.com/company/uber)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Two Pointers](https://leetcode.com/tag/two-pointers/), [Greedy](https://leetcode.com/tag/greedy/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1. Greedy

The first intuition is that we can greedily fill from heavy people or from light people. From heavy is more promising because we can use the light people to fill in the boats.

```cpp
// OJ: https://leetcode.com/problems/boats-to-save-people/
// Author: github.com/lzl124631x
// Time: O(NlogD) where N is to total number of people
//                and D is the distinct count of weights.
// Space: O(D)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        map<int, int, greater<int>> m;
        for (int w : people) m[w]++;
        int ans = 0;
        while (m.size()) {
            int w = limit, cnt = 0;
            while (w > 0 && cnt < 2) {
                auto it = m.lower_bound(w);
                if (it == m.end()) break;
                w -= it->first;
                if (--it->second == 0) m.erase(it->first);
                ++cnt;
            }
            ++ans;
        }
        return ans;
    }
};
```

## Solution 2. Greedy + Two Pointers

For the lightest person `a`, if `a` can pair with the heaviest person `b`, let `a` do so.

If not, then the heaviest person `b` can't pair with any one, let `b` go alone.

```cpp
// OJ: https://leetcode.com/problems/boats-to-save-people/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int numRescueBoats(vector<int>& A, int limit) {
        sort(begin(A), end(A));
        int i = 0, j = A.size() - 1, ans = 0;
        while (i <= j) {
            ++ans;
            if (A[i] + A[j] <= limit) ++i;
            --j;
        }
        return ans;
    }
};
```