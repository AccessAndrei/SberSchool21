SELECT id,
       name,
       age,
       CASE
           WHEN (age BETWEEN 10 AND 20) then 'interval #1'
           WHEN (age BETWEEN 21 AND 23) then 'interval #2'
           else 'interval #3'
           END interval_info
FROM person
ORDER BY interval_info