SELECT person.name
FROM person
JOIN person_order ON person.id = person_order.person_id
JOIN public.menu m on person_order.menu_id = m.id
WHERE address IN ('Moscow', 'Samara') AND m.pizza_name IN ('mushroom pizza', 'pepperoni pizza') AND person.gender = 'male'
ORDER BY name DESC

