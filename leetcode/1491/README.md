# [1491. Average Salary Excluding the Minimum and Maximum Salary (Easy)](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/)

<p>Given an array of <strong>unique</strong> integers <code>salary</code>&nbsp;where <code>salary[i]</code> is the salary of the employee <code>i</code>.</p>

<p>Return the average salary of employees excluding the minimum and maximum salary.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> salary = [4000,3000,1000,2000]
<strong>Output:</strong> 2500.00000
<strong>Explanation: </strong>Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000)/2= 2500
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> salary = [1000,2000,3000]
<strong>Output:</strong> 2000.00000
<strong>Explanation: </strong>Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000)/1= 2000
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> salary = [6000,5000,4000,3000,2000,1000]
<strong>Output:</strong> 3500.00000
</pre>

<p><strong>Example 4:</strong></p>

<pre><strong>Input:</strong> salary = [8000,9000,2000,3000,6000,1000]
<strong>Output:</strong> 4750.00000
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= salary.length &lt;= 100</code></li>
	<li><code>10^3&nbsp;&lt;= salary[i] &lt;= 10^6</code></li>
	<li><code>salary[i]</code> is unique.</li>
	<li>Answers within <code>10^-5</code> of the actual value will be accepted as correct.</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sort](https://leetcode.com/tag/sort/)

## Solution 1.

```cpp
// OJ: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
class Solution {
public:
    double average(vector<int>& A) {
        return (accumulate(begin(A), end(A), 0.) - *max_element(begin(A), end(A)) - *min_element(begin(A), end(A))) / (A.size() - 2);
    }
};
```