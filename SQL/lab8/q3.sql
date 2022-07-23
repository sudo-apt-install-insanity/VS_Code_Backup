DECLARE 
    a number;
    b number;
    c number;
BEGIN
    DBMS_OUTPUT.PUT_LINE('Enter values of a, b');
    a := &a;
    b := &b;
    
    DBMS_OUTPUT.PUT_LINE('Before Swapping: ');
    
    DBMS_OUTPUT.PUT_LINE('A: '||a);
    DBMS_OUTPUT.PUT_LINE('B: '||b);
    
    c := a;
    a := b;
    b := c;

    DBMS_OUTPUT.PUT_LINE('Value After Swapping: ');
    DBMS_OUTPUT.PUT_LINE('A: '||a);
    DBMS_OUTPUT.PUT_LINE('B: '||b);

END;