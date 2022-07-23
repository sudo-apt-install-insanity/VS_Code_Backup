DECLARE
    a NUMBER;

BEGIN
    a:=1;
    DBMS_OUTPUT.PUT_LINE('ODD NUMBERS FROM 1-10 ARE : ');
    LOOP
        IF (MOD(a,2)!=0) THEN
        DBMS_OUTPUT.PUT_LINE(a || ' ');
        END IF;
        a:=a+1;
    IF a>=10 THEN EXIT;
    END IF;
    END LOOP;
END;
/