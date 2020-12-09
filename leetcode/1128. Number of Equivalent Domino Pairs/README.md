# [1128. Number of Equivalent Domino Pairs (Easy)](https://leetcode.com/problems/number-of-equivalent-domino-pairs/)

<p>Given a list of <code>dominoes</code>,&nbsp;<code>dominoes[i] = [a, b]</code>&nbsp;is <em>equivalent</em> to <code>dominoes[j] = [c, d]</code>&nbsp;if and only if either (<code>a==c</code> and <code>b==d</code>), or (<code>a==d</code> and <code>b==c</code>) - that is, one domino can be rotated to be equal to another domino.</p>

<p>Return the number of pairs <code>(i, j)</code> for which <code>0 &lt;= i &lt; j &lt; dominoes.length</code>, and&nbsp;<code>dominoes[i]</code> is equivalent to <code>dominoes[j]</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> dominoes = [[1,2],[2,1],[3,4],[5,6]]
<strong>Output:</strong> 1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= dominoes.length &lt;= 40000</code></li>
	<li><code>1 &lt;= dominoes[i][j] &lt;= 9</code></li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& A) {
        map<vector<int>, int> m;
        int ans = 0;
        for (auto &v : A) {
            sort(begin(v), end(v));
            ans += m[v];
            m[v]++;
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& A) {
        for (auto &v : A) sort(begin(v), end(v));
        sort(begin(A), end(A));
        int ans = 0;
        for (int i = 0, N = A.size(); i < N;) {
            int start = i;
            while (i < N && A[i] == A[start]) ++i;
            int len = i - start;
            ans += (len - 1) * len / 2;
        }
        return ans;
    }
};
```

## Solution 3.

```cpp
// OJ: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& A) {
        int cnt[10][10] = {}, ans = 0;
        for (auto &v : A) {
            if (v[0] > v[1]) swap(v[0], v[1]);
            ans += cnt[v[0]][v[1]]++;
        }
        return ans;
    }
};
```