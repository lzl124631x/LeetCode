# [2391. Minimum Amount of Time to Collect Garbage (Medium)](https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage)

<p>You are given a <strong>0-indexed</strong> array of strings <code>garbage</code> where <code>garbage[i]</code> represents the assortment of garbage at the <code>i<sup>th</sup></code> house. <code>garbage[i]</code> consists only of the characters <code>&#39;M&#39;</code>, <code>&#39;P&#39;</code> and <code>&#39;G&#39;</code> representing one unit of metal, paper and glass garbage respectively. Picking up <strong>one</strong> unit of any type of garbage takes <code>1</code> minute.</p>

<p>You are also given a <strong>0-indexed</strong> integer array <code>travel</code> where <code>travel[i]</code> is the number of minutes needed to go from house <code>i</code> to house <code>i + 1</code>.</p>

<p>There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house <code>0</code> and must visit each house <strong>in order</strong>; however, they do <strong>not</strong> need to visit every house.</p>

<p>Only <strong>one</strong> garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks <strong>cannot</strong> do anything.</p>

<p>Return<em> the <strong>minimum</strong> number of minutes needed to pick up all the garbage.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> garbage = [&quot;G&quot;,&quot;P&quot;,&quot;GP&quot;,&quot;GG&quot;], travel = [2,4,3]
<strong>Output:</strong> 21
<strong>Explanation:</strong>
The paper garbage truck:
1. Travels from house 0 to house 1
2. Collects the paper garbage at house 1
3. Travels from house 1 to house 2
4. Collects the paper garbage at house 2
Altogether, it takes 8 minutes to pick up all the paper garbage.
The glass garbage truck:
1. Collects the glass garbage at house 0
2. Travels from house 0 to house 1
3. Travels from house 1 to house 2
4. Collects the glass garbage at house 2
5. Travels from house 2 to house 3
6. Collects the glass garbage at house 3
Altogether, it takes 13 minutes to pick up all the glass garbage.
Since there is no metal garbage, we do not need to consider the metal garbage truck.
Therefore, it takes a total of 8 + 13 = 21 minutes to collect all the garbage.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> garbage = [&quot;MMM&quot;,&quot;PGM&quot;,&quot;GP&quot;], travel = [3,10]
<strong>Output:</strong> 37
<strong>Explanation:</strong>
The metal garbage truck takes 7 minutes to pick up all the metal garbage.
The paper garbage truck takes 15 minutes to pick up all the paper garbage.
The glass garbage truck takes 15 minutes to pick up all the glass garbage.
It takes a total of 7 + 15 + 15 = 37 minutes to collect all the garbage.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= garbage.length &lt;= 10<sup>5</sup></code></li>
	<li><code>garbage[i]</code> consists of only the letters <code>&#39;M&#39;</code>, <code>&#39;P&#39;</code>, and <code>&#39;G&#39;</code>.</li>
	<li><code>1 &lt;= garbage[i].length &lt;= 10</code></li>
	<li><code>travel.length == garbage.length - 1</code></li>
	<li><code>1 &lt;= travel[i] &lt;= 100</code></li>
</ul>


**Companies**:
[Microsoft](https://leetcode.com/company/microsoft)

**Related Topics**:  
[Array](https://leetcode.com/tag/array), [String](https://leetcode.com/tag/string), [Prefix Sum](https://leetcode.com/tag/prefix-sum)

**Hints**:
* Where can we save time? By not visiting all the houses.
* For each type of garbage, find the house with the highest index that has at least 1 unit of this type of garbage.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int N = garbage.size(), last[3] = {-1,-1,-1}, ans = 0;
        vector<array<int, 3>> A(N);
        for (int i = 0; i < N; ++i) {
            for (char c : garbage[i]) {
                int j = c == 'M' ? 0 : (c == 'P' ? 1 : 2);
                A[i][j]++;
                last[j] = i;
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j <= last[i]; ++j) {
                ans += A[j][i];
                if (j > 0) ans += travel[j - 1];
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int N = garbage.size(), seen[3] = {}, ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            for (char c : garbage[i]) {
                int j = c == 'M' ? 0 : (c == 'P' ? 1 : 2);
                seen[j] = 1;
            }
            ans += garbage[i].size();
            if (i > 0) {
                for (int j = 0; j < 3; ++j) {
                    if (seen[j]) ans += travel[i - 1];
                }
            }
        }
        return ans;
    }
};
```