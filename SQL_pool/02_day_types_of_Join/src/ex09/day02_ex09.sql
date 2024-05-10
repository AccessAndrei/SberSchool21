SELECT person.name
FROM person
JOIN person_order ON person.id = person_order.person_id
JOIN (SELECT * FROM menu WHERE pizza_name IN ('cheese pizza', 'pepperoni pizza')) AS menu_m_p ON person_order.menu_id = menu_m_p.id
WHERE person.gender = 'female'
GROUP BY person.name
HAVING COUNT(DISTINCT menu_m_p.id) = 2
ORDER BY person.name;
