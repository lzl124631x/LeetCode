# [2094. Finding 3-Digit Even Numbers (Easy)](https://leetcode.com/problems/finding-3-digit-even-numbers/)

<p>You are given an integer array <code>digits</code>, where each element is a digit. The array may contain duplicates.</p>

<p>You need to find <strong>all</strong> the <strong>unique</strong> integers that follow the given requirements:</p>

<ul>
	<li>The integer consists of the <strong>concatenation</strong> of <strong>three</strong> elements from <code>digits</code> in <strong>any</strong> arbitrary order.</li>
	<li>The integer does not have <strong>leading zeros</strong>.</li>
	<li>The integer is <strong>even</strong>.</li>
</ul>

<p>For example, if the given <code>digits</code> were <code>[1, 2, 3]</code>, integers <code>132</code> and <code>312</code> follow the requirements.</p>

<p>Return <em>a <strong>sorted</strong> array of the unique integers.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> digits = [2,1,3,0]
<strong>Output:</strong> [102,120,130,132,210,230,302,310,312,320]
<strong>Explanation:</strong> 
All the possible integers that follow the requirements are in the output array. 
Notice that there are no <strong>odd</strong> integers or integers with <strong>leading zeros</strong>.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> digits = [2,2,8,8,2]
<strong>Output:</strong> [222,228,282,288,822,828,882]
<strong>Explanation:</strong> 
The same digit can be used as many times as it appears in <code>digits</code>. 
In this example, the digit 8 is used twice each time in 288, 828, and 882. 
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> digits = [3,7,5]
<strong>Output:</strong> []
<strong>Explanation:</strong> 
No <strong>even</strong> integers can be formed using the given digits.
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> digits = [0,2,0,0]
<strong>Output:</strong> [200]
<strong>Explanation:</strong> 
The only valid integer that can be formed with three digits and <strong>no leading zeros</strong> is 200.
</pre>

<p><strong>Example 5:</strong></p>

<pre><strong>Input:</strong> digits = [0,0,0]
<strong>Output:</strong> []
<strong>Explanation:</strong> 
All the integers that can be formed have <strong>leading zeros</strong>. Thus, there are no valid integers.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;=&nbsp;digits.length &lt;= 100</code></li>
	<li><code>0 &lt;= digits[i] &lt;= 9</code></li>
</ul>


**Similar Questions**:
* [Find Numbers with Even Number of Digits (Easy)](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/)

## Solution 1. Brute Force

```cpp
// OJ: https://leetcode.com/problems/finding-3-digit-even-numbers/
// Author: github.com/lzl124631x
// Time: O(N^3 * log(1000))
// Space: O(1000) = O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& A) {
        set<int> s;
        int N = A.size();
        for (int i = 0; i < N; ++i) {
            if (A[i] == 0) continue;
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                for (int k = 0; k < N; ++k) {
                    if (k == i || k == j) continue;
                    if (A[k] % 2) continue;
                    s.insert(A[i] * 100 + A[j] * 10 + A[k]);
                }
            }
        }
        return vector<int>(begin(s), end(s));
    }
};
```

## Solution 2. DFS

```cpp
// OJ: https://leetcode.com/problems/finding-3-digit-even-numbers/
// Author: github.com/lzl124631x
// Time: O(N + 10^3)
// Space: O(10) = O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& A) {
        int cnt[10] = {};
        for (int n : A) cnt[n]++;
        vector<int> ans;
        function<void(int, int)> dfs = [&](int i, int n) {
            if (i == 3) {
                ans.push_back(n);
                return;
            }
            for (int d = 0; d <= 9; ++d) {
                if (cnt[d] == 0 || (i == 0 && d == 0) || (i == 2 && d % 2)) continue;
                cnt[d]--;
                dfs(i + 1, n * 10 + d);
                cnt[d]++;
            }
        };
        dfs(0, 0);
        return ans;
    }
};
```

## Solution 3. Counting

```cpp
// OJ: https://leetcode.com/problems/finding-3-digit-even-numbers/
// Author: github.com/lzl124631x
// Time: O(N + 10^3)
// Space: O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& A) {
        int cnt[10] = {};
        for (int n : A) cnt[n]++;
        vector<int> ans;
        for (int n = 100; n < 1000; ++n) {
            if (n % 2) continue;
            int a = n / 100, b = n % 100 / 10, c = n % 10, used[10] = {};
            used[a]++;
            used[b]++;
            used[c]++;
            if (used[a] > cnt[a] || used[b] > cnt[b] || used[c] > cnt[c]) continue;
            ans.push_back(n);
        }
        return ans;
    }
};
```

## Solution 4. 

```cpp
// OJ: https://leetcode.com/problems/finding-3-digit-even-numbers/
// Author: github.com/lzl124631x
// Time: O(N + 9 * 10 * 5)
// Space: O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& A) {
        int cnt[10] = {};
        for (int n : A) cnt[n]++;
        vector<int> ans;
        for (int i = 1; i <= 9; ++i) {
            if (cnt[i] == 0) continue;
            for (int j = 0; j <= 9; ++j) {
                if (cnt[j] - (i == j) == 0) continue;
                for (int k = 0; k <= 8; k += 2) {
                    if (cnt[k] - (i == k) - (j == k) == 0) continue;
                    ans.push_back(i * 100 + j * 10 + k);
                }
            }
        }
        return ans;
    }
};
```