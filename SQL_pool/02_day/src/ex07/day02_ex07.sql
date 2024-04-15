SELECT pizzeria.name
FROM pizzeria
JOIN menu m on pizzeria.id = m.pizzeria_id
JOIN person_visits on pizzeria.id = person_visits.pizzeria_id
JOIN person ON person_visits.person_id = person.id
WHERE visit_date = '2022-01-08' AND person.name='Dmitriy' AND m.price < 800
