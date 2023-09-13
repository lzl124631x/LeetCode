# [176. Second Highest Salary (Easy)](https://leetcode.com/problems/second-highest-salary/)

<p>Write a SQL query to get the second highest salary from the <code>Employee</code> table.</p>

<pre>+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
</pre>

<p>For example, given the above Employee table, the query should return <code>200</code> as the second highest salary. If there is no second highest salary, then the query should return <code>null</code>.</p>

<pre>+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
</pre>


**Companies**:  
[Amazon](https://leetcode.com/company/amazon), [Google](https://leetcode.com/company/google), [Adobe](https://leetcode.com/company/adobe), [Walmart Labs](https://leetcode.com/company/walmart-labs), [Apple](https://leetcode.com/company/apple), [Microsoft](https://leetcode.com/company/microsoft), [Yahoo](https://leetcode.com/company/yahoo)

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/second-highest-salary/
# Author: github.com/lzl124631x
SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary
```