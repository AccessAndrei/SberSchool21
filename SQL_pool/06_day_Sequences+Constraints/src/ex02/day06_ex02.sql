SELECT person.name,
       menu.pizza_name,
       menu.price,
       menu.price - menu.price * person_discounts.discount/100 AS discount_price,
       pizzeria.name
FROM menu
         INNER JOIN person_order ON menu.id = person_order.menu_id
         INNER JOIN person ON person_order.person_id = person.id
         INNER JOIN person_discounts ON person.id = person_discounts.person_id
         INNER JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
ORDER BY person.name, pizza_name
