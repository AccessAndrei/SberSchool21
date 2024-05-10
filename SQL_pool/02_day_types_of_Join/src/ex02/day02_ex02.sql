SELECT COALESCE(person.name, '-')          AS person_name,
       COALESCE(visit_date:: text, 'null') AS visit_date,
       COALESCE(pizzeria.name, '-')        AS pizzeria_name
FROM person
         FULL JOIN (SELECT *
                    FROM person_visits
                    WHERE visit_date = '2022-01-01'
                       OR visit_date = '2022-01-02'
                       OR visit_date = '2022-01-03') AS pv ON person.id = pv.person_id
         FULL JOIN pizzeria ON pv.pizzeria_id = pizzeria.id
ORDER BY person_name,
         visit_date,
         pizzeria_name;