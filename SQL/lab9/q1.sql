DECLARE
  year NUMBER;
BEGIN
  year := &year;
  IF MOD(year, 4)=0
    AND
    MOD(year, 100)!=0
    OR
    MOD(year, 400)=0 THEN
    dbms_output.Put_line('Leap year ');
  ELSE
    dbms_output.Put_line('Not a leap year.');
  END IF;
END;