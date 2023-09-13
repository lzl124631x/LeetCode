# OJ: https://leetcode.com/problems/employee-bonus/
# Author: github.com/lzl124631x
SELECT
    Employee.name, Bonus.bonus
FROM
    Employee LEFT JOIN Bonus
    ON Employee.empId = Bonus.empId
WHERE
    bonus < 1000 OR bonus IS NULL