CREATE INDEX IF NOT EXISTS idx_person_name ON person (UPPER(name));

SET enable_seqscan TO OFF;
EXPLAIN
SELECT name
FROM person
WHERE UPPER(name) = 'NATALY';