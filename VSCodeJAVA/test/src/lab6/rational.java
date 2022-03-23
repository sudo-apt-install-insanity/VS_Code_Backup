package lab6;

class rational 
{
    int p;
    int q;
    rational(int p, int q) 
    {
        this.p = p;
        this.q = q;
    }
    rational add(rational r) 
    {
        int denominator = r.q * q;
        int numerator = q * r.p + p * r.q;
        rational result = new rational(numerator, denominator);
        return result;
    }

    rational subtract(rational r) 
    {
        int denominator = r.q * q;
        int numerator = q * r.p - p * r.q;
        rational result = new rational(numerator, denominator);
        return result;
    }

    rational multiply(rational r) 
    {
        int numerator = p * r.p;
        int denominator = q * r.q;
        rational result = new rational(numerator, denominator);
        return result;
    }

    rational divide(rational r) 
    {
        int denominator = p * r.q;
        int numerator = q * r.p;
        rational result = new rational(numerator, denominator);
        return result;
    }
}