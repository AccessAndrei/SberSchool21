CREATE OR REPLACE FUNCTION fnc_fibonacci (pstop INTEGER DEFAULT 10)
RETURNS TABLE (fibonacci_num INTEGER) AS $BODY$
DECLARE
    a INTEGER;
    b INTEGER;
    c INTEGER;
BEGIN
    a := 0;
    b := 1;
    fibonacci_num := 0;
    WHILE
        fibonacci_num < pstop LOOP
        c := a + b;
        fibonacci_num := c;
        IF
            fibonacci_num < pstop THEN
            RETURN NEXT;
        END IF;
        a := b;
        b := c;
    END LOOP;
END;
$BODY$
LANGUAGE PLPGSQL;

SELECT * FROM fnc_fibonacci(100);
SELECT * FROM fnc_fibonacci();