# OJ: https://leetcode.com/problems/find-customer-referee/
# Author: github.com/lzl124631x
SELECT
    name
FROM
    customer
WHERE
    referee_id <> 2 OR referee_id IS NULL