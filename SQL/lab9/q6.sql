DECLARE
    givenDate DATE;
BEGIN
    givenDate := TO_DATE('&month/&year','mm/yyyy');
    givenDate := LAST_DAY(givenDate);
    DBMS_OUTPUT.PUT_LINE(TO_CHAR(givenDate,'DD'));
END;

