# [181. Employees Earning More Than Their Managers (Easy)](https://leetcode.com/problems/employees-earning-more-than-their-managers/)

<p>The <code>Employee</code> table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.</p>

<pre>+----+-------+--------+-----------+
| Id | Name  | Salary | ManagerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+
</pre>

<p>Given the <code>Employee</code> table, write a SQL query that finds out employees who earn more than their managers. For the above table, Joe is the only employee who earns more than his manager.</p>

<pre>+----------+
| Employee |
+----------+
| Joe      |
+----------+
</pre>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook)

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/employees-earning-more-than-their-managers/
# Author: github.com/lzl124631x
SELECT a.Name AS Employee
FROM Employee a JOIN Employee b
ON a.ManagerId = b.Id AND a.Salary > b.Salary
```