# [627. Swap Salary (Easy)](https://leetcode.com/problems/swap-salary/)

Given a table <code>salary</code>, such as the one below, that has m=male and  f=female values. Swap all f and m values (i.e., change all f values to m and vice versa) with a single update query and no intermediate temp table.<p></p>
 
For example:<p></p>
 
<pre>| id | name | sex | salary |
|----|------|-----|--------|
| 1  | A    | m   | 2500   |
| 2  | B    | f   | 1500   |
| 3  | C    | m   | 5500   |
| 4  | D    | f   | 500    |
</pre>
After running your query, the above salary table should have the following rows:
<pre>| id | name | sex | salary |
|----|------|-----|--------|
| 1  | A    | f   | 2500   |
| 2  | B    | m   | 1500   |
| 3  | C    | f   | 5500   |
| 4  | D    | m   | 500    |
</pre>

**Companies**:  
[Adobe](https://leetcode.com/company/adobe), [Google](https://leetcode.com/company/google)

## Solution 1.

```sql
# OJ: https://leetcode.com/problems/swap-salary/
# Author: github.com/lzl124631x
UPDATE salary
SET
    sex = CASE sex
        WHEN 'm' THEN 'f'
        ELSE 'm'
    END;
```