DECLARE
    a NUMBER;

BEGIN
    a:=10;
    LOOP
        DBMS_OUTPUT.PUT_LINE(a);
        a:=a-1;
    IF a=0 THEN EXIT;
    END IF;
    END LOOP;
END;
/