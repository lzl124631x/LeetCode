# OJ: https://leetcode.com/problems/second-highest-salary/
# Author: github.com/lzl124631x
SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary