# [2148. Count Elements With Strictly Smaller and Greater Elements  (Easy)](https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/)

<p>Given an integer array <code>nums</code>, return <em>the number of elements that have <strong>both</strong> a strictly smaller and a strictly greater element appear in </em><code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [11,7,2,15]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.
Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.
In total there are 2 elements having both a strictly smaller and a strictly greater element appear in <code>nums</code>.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [-3,3,3,90]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The element 3 has the element -3 strictly smaller than it and the element 90 strictly greater than it.
Since there are two elements with the value 3, in total there are 2 elements having both a strictly smaller and a strictly greater element appear in <code>nums</code>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


**Similar Questions**:
* [Find Smallest Letter Greater Than Target (Easy)](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)

## Solution 1. Binary Search

```cpp
// OJ: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
// Author: github.com/lzl124631x
// Time: O(NlogU) where U is the number of unique elements in `A`
// Space: O(U)
class Solution {
public:
    int countElements(vector<int>& A) {
        set<int> s(begin(A), end(A));
        int ans = 0;
        for (int n : A) {
            ans += s.lower_bound(n) != s.begin() && s.upper_bound(n) != s.end();
        }
        return ans;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int countElements(vector<int>& A) {
        sort(begin(A), end(A));
        int ans = 0;
        for (int n : A) {
            ans += lower_bound(begin(A), end(A), n) != begin(A) && upper_bound(begin(A), end(A), n) != end(A);
        }
        return ans;
    }
};
```

## Solution 2. Exclude Smallest and Greatest Elements

```cpp
// OJ: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int countElements(vector<int>& A) {
        sort(begin(A), end(A));
        int i = 0, j = A.size() - 1;
        while (i <= j && A[i] == A[0]) ++i;
        while (i <= j && A[j] == A.back()) --j;
        return j - i + 1;
    }
};
```

Or

```cpp
// OJ: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countElements(vector<int>& A) {
        int mn = A[0], mx = A[0], ans = A.size(), minCnt = 0, maxCnt = 0;
        for (int n : A) {
            if (n < mn) {
                minCnt = 1;
                mn = n;
            } else if (n == mn) ++minCnt;
            if (n > mx) {
                maxCnt = 1;
                mx = n;
            } else if (n == mx) ++maxCnt;
        }
        return max(0, (int)A.size() - minCnt - maxCnt);
    }
};
```

## Discuss 

https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/discuss/1711250/C%2B%2B-Binary-Search-O(NlogN)