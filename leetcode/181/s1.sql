# OJ: https://leetcode.com/problems/employees-earning-more-than-their-managers/
# Author: github.com/lzl124631x
SELECT a.Name AS Employee
FROM Employee a JOIN Employee b
ON a.ManagerId = b.Id AND a.Salary > b.Salary