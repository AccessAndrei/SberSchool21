SELECT person.name as person_name1, p.name as person_name2, person.address as common_address
FROM person
         JOIN person p ON person.address = p.address AND person.name != p.name AND person.id > p.id
WHERE person.name != p.name;
