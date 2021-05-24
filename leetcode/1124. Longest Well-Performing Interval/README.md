# [1124. Longest Well-Performing Interval (Medium)](https://leetcode.com/problems/longest-well-performing-interval/)

<p>We are given <code>hours</code>, a list of the number of hours&nbsp;worked per day for a given employee.</p>

<p>A day is considered to be a <em>tiring day</em> if and only if the number of hours worked is (strictly) greater than <code>8</code>.</p>

<p>A <em>well-performing interval</em> is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.</p>

<p>Return the length of the longest well-performing interval.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> hours = [9,9,6,0,6,6,9]
<strong>Output:</strong> 3
<strong>Explanation: </strong>The longest well-performing interval is [9,9,6].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= hours.length &lt;= 10000</code></li>
	<li><code>0 &lt;= hours[i] &lt;= 16</code></li>
</ul>


**Companies**:  
[Adobe](https://leetcode.com/company/adobe)

**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)


## Note

Turn each `A[i]` to `1` if `A[i] > 8` otherwise `-1`. This problem becomes "find the longest subarray with the positive sum".

We can calculate a prefix sum array `prefix` where `prefix[i + 1] = A[0] + A[1] + ... + A[i]`. Given a `prefix[i]` (`i >= 1`), find the smallest `j >= 0` such that `prefix[i] - prefix[j] > 0`, and `j - i` is the optimal subarray length.

**Observations**:

* If `prefix[i] > 0` (`1 <= i <= N`), since `prefix[0] = 0`, so the optimal subarray length must be `i`.
* If `prefix[i] < 0` (`1 <= i <= N`), we need to find the smallest `j >= 0` that `prefix[j] > prefix[i]` and the optimal subarray length is `i - j`. If `prefix[i]` is the smallest value we've seen thus far, we would want to store `i` in a mono-decreasing stack.

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/longest-well-performing-interval/
// Author: github.com/lzl124631x
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int longestWPI(vector<int>& A) {
        int N = A.size(), ans = 0;
        for (int &n : A) n = n > 8 ? 1 : -1;
        vector<int> prefix(N + 1), s{0};
        for (int i = 0; i < N; ++i) prefix[i + 1] = prefix[i] + A[i];
        for (int i = 1; i <= N; ++i) {
            if (prefix[i] == prefix[s.back()]) continue;
            else if (prefix[i] < prefix[s.back()]) s.push_back(i);
            else {
                auto it = upper_bound(begin(s), end(s), prefix[i], [&](int a, int b) { return prefix[b] < a; });
                ans = max(ans, i - *it);
            }
        }
        return ans;
    }
};
```

## Solution 2.

```cpp
// OJ: https://leetcode.com/problems/longest-well-performing-interval/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestWPI(vector<int>& A) {
        int N = A.size(), ans = 0, j = 0;
        for (int &n : A) n = n > 8 ? 1 : -1;
        vector<int> prefix(N + 1), s{0};
        for (int i = 0; i < N; ++i) prefix[i + 1] = prefix[i] + A[i];
        for (int i = 1; i <= N; ++i) {
            if (prefix[i] == prefix[s.back()]) continue;
            if (prefix[i] <= prefix[s[j]]) {
                while (j < s.size() && prefix[i] <= prefix[s[j]]) ++j;
                if (j == s.size() && prefix[s[j - 1]] != prefix[i]) s.push_back(i);
                if (prefix[s[j]] < prefix[i]) ans = max(ans, i - s[j]);
            } else {
                while (j > 0 && prefix[i] > prefix[s[j - 1]]) --j;
                ans = max(ans, i - s[j]);
            }
        }
        return ans;
    }
};
```

## Solution 3. Prefix State Map

```cpp
// OJ: https://leetcode.com/problems/longest-well-performing-interval/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestWPI(vector<int>& A) {
        int N = A.size(), ans = 0, sum = 0;
        unordered_map<int, int> m{{0,-1}};
        for (int i = 0; i < N; ++i) {
            sum += A[i] > 8 ? 1 : -1;
            int s = min(sum - 1, 0);
            if (m.count(s)) ans = max(ans, i - m[s]);
            else if (sum < 0 && m.count(sum) == 0) m[sum] = i;
        }
        return ans;
    }
};
```

## Solution 4. Mono-stack

```cpp
// OJ: https://leetcode.com/problems/longest-well-performing-interval/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int longestWPI(vector<int>& A) {
        int N = A.size(), ans = 0;
        vector<int> prefix(N + 1);
        for (int i = 0; i < N; ++i) prefix[i + 1] = prefix[i] + (A[i] > 8 ? 1 : -1);
        stack<int> s;
        for (int i = 0; i <= N; ++i) {
            if (s.empty() || prefix[i] < prefix[s.top()]) s.push(i);
        }
        for (int i = N; i > 0 && s.size(); --i) {
            while (s.size() && prefix[s.top()] < prefix[i]) {
                ans = max(ans, i - s.top());
                s.pop();
            }
        }
        return ans;
    }
};
```