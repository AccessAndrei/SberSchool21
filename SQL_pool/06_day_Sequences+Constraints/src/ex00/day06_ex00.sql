CREATE TABLE IF NOT EXISTS person_discounts(
    id bigint PRIMARY KEY,
    person_id BIGINT NOT NULL,
    pizzeria_id BIGINT NOT NULL,
    CONSTRAINT fk_person_discounts_person_id FOREIGN KEY (person_id) REFERENCES person(id),
    CONSTRAINT fk_person_discounts_pizzeria_id FOREIGN KEY (pizzeria_id) REFERENCES pizzeria(id),
    discount numeric(8,1)
);

select count(*) = 1 as check
from pg_tables
where tablename = 'person_discounts'