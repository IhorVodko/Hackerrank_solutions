/*problem: https://www.hackerrank.com/challenges/print-prime-numbers/problem
MySQL*/

SELECT GROUP_CONCAT(num_a SEPARATOR '&')
FROM (
    SELECT @num:=@num+1 as num_a
    FROM information_schema.tables t1,
         information_schema.tables t2,
         (SELECT @num:=1) tmp0
) temp_num0
WHERE num_a<=1000 AND NOT EXISTS(
        SELECT * FROM (
            SELECT @numb:=@numb+1 as num_b 
            FROM information_schema.tables t1,
                 information_schema.tables t2,
                 (SELECT @numb:=1) tmp1
                 LIMIT 1000
        ) temp_num1
        WHERE FLOOR(num_a/num_b)=(num_a/num_b) AND num_b<num_a
    );
