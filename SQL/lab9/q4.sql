DROP TABLE ITEM;
CREATE TABLE ITEM (ItemNum NUMBER NOT NULL);
DESC ITEM;

DECLARE
    n number (1):=1;

BEGIN
    LOOP
        INSERT INTO ITEM(ITEMNUM)
        VALUES(n);
        n:=n+1;
        IF n>5 THEN 
            EXIT;
        END IF;
    END LOOP;
END;
/
SELECT * FROM ITEM;
commit;