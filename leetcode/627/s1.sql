# OJ: https://leetcode.com/problems/swap-salary/
# Author: github.com/lzl124631x
UPDATE salary
SET
    sex = CASE sex
        WHEN 'm' THEN 'f'
        ELSE 'm'
    END;