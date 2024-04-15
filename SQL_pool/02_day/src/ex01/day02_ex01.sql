SELECT dates :: date AS missing_date
FROM generate_series('2022-01-01', '2022-01-10', interval '1 day') AS dates
         LEFT JOIN (SELECT * FROM person_visits WHERE person_id = 1 OR person_id = 2) AS subquery
                   ON dates = subquery.visit_date
WHERE person_id IS NULL
ORDER BY person_id
