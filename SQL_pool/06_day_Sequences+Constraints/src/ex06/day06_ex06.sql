CREATE SEQUENCE IF NOT EXISTS seq_person_discounts
AS BIGINT
INCREMENT 1
MINVALUE 1;
ALTER TABLE person_discounts ALTER COLUMN id SET DEFAULT nextval('seq_person_discounts');
SELECT setval('seq_person_discounts', (SELECT COUNT(*) + 1 FROM person_discounts));

select count(*)=1 as check1,
max("start_value") = 1 as check2,
max("last_value") > 5 as check3
from pg_sequences
where sequencename = 'seq_person_discounts'