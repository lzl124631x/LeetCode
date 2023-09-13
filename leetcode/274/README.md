# [274. H-Index (Medium)](https://leetcode.com/problems/h-index/)

<p>Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.</p>

<p>According to the <a href="https://en.wikipedia.org/wiki/H-index" target="_blank">definition of h-index on Wikipedia</a>: "A scientist has index <i>h</i> if <i>h</i> of his/her <i>N</i> papers have <b>at least</b> <i>h</i> citations each, and the other <i>N − h</i> papers have <b>no more than</b> <i>h</i> citations each."</p>

<p><b>Example:</b></p>

<pre><b>Input:</b> <code>citations = [3,0,6,1,5]</code>
<b>Output:</b> 3 
<strong>Explanation: </strong><code>[3,0,6,1,5] </code>means the researcher has <code>5</code> papers in total and each of them had 
             received <code>3, 0, 6, 1, 5</code> citations respectively. 
&nbsp;            Since the researcher has <code>3</code> papers with <b>at least</b> <code>3</code> citations each and the remaining 
&nbsp;            two with <b>no more than</b> <code>3</code> citations each, her h-index is <code>3</code>.</pre>

<p><strong>Note:&nbsp;</strong>If there are several possible values for <em>h</em>, the maximum one is taken as the h-index.</p>


**Related Topics**:  
[Hash Table](https://leetcode.com/tag/hash-table/), [Sort](https://leetcode.com/tag/sort/)

**Similar Questions**:
* [H-Index II (Medium)](https://leetcode.com/problems/h-index-ii/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/h-index/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int hIndex(vector<int>& A) {
        sort(begin(A), end(A));
        int L = 0, R = A.size() - 1, N = A.size();
        while (L <= R) {
            int M = (L + R) / 2;
            if (A[M] < N - M) L = M + 1;
            else R = M - 1;
        }
        return N - L;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/h-index/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int hIndex(vector<int>& A) {
        int N = A.size(), sum = 0;
        vector<int> cnt(N + 1);
        for (int n : A) cnt[min(n, N)]++;
        for (int i = N; i >= 0; --i) {
            sum += cnt[i];
            if (sum >= i) return i;
        }
        return -1;
    }
};
```