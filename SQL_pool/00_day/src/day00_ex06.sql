SELECT
    (SELECT name
     FROM person
     WHERE id = person_order.person_id
    ) AS name,
    CASE
    WHEN (SELECT name from person where person.id= person_order.person_id) = 'Denis' THEN TRUE
    else FALSE
    END check_name
FROM person_order
WHERE order_date = '2022-01-07'
AND menu_id IN (13, 14, 18);