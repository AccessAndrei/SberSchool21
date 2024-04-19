SET enable_seqscan TO OFF;
EXPlAIN ANALYZE
SELECT menu.pizza_name, pizzeria.name AS pizzeria_name
FROM pizzeria
JOIN menu ON pizzeria.id = menu.pizzeria_id;
