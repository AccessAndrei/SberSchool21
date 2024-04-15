SELECT pizza_name, p.name as pizzeria_name
FROM menu
JOIN person_order po on menu.id = po.menu_id
JOIN pizzeria p on menu.pizzeria_id = p.id
JOIN person on po.person_id = person.id
WHERE person.name IN ('Denis', 'Anna')
ORDER BY pizza_name, p.name