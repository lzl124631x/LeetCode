# [135. Candy (Hard)](https://leetcode.com/problems/candy/)

<p>There are <code>n</code> children standing in a line. Each child is assigned a rating value given in the integer array <code>ratings</code>.</p>

<p>You are giving candies to these children subjected to the following requirements:</p>

<ul>
	<li>Each child must have at least one candy.</li>
	<li>Children with a higher rating get more candies than their neighbors.</li>
</ul>

<p>Return <em>the minimum number of candies you need to have to distribute the candies to the children</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> ratings = [1,0,2]
<strong>Output:</strong> 5
<strong>Explanation:</strong> You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> ratings = [1,2,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == ratings.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= ratings[i] &lt;= 2 * 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Apple](https://leetcode.com/company/apple)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. BFS

```cpp
// OJ: https://leetcode.com/problems/candy/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int candy(vector<int>& A) {
        int N = A.size();
        vector<int> v(N);
        queue<int> q;
        for (int i = 0; i < N; ++i) {
            if ((i - 1 < 0 || A[i] <= A[i - 1]) && (i + 1 >= N || A[i] <= A[i + 1])) {
                q.push(i);
                v[i] = 1;
            }
        }
        while (q.size()) {
            int i = q.front();
            q.pop();
            for (int j = -1; j <= 1; j += 2) {
                int k = i + j;
                if (k < 0 || k >= N) continue;
                if (A[k] > A[i] && v[k] < 1 + v[i]) {
                    v[k] = 1 + v[i];
                    q.push(k);
                } 
            }
        }
        return accumulate(begin(v), end(v), 0);
    }
};
```

## TODO

https://leetcode.com/problems/candy/solution/