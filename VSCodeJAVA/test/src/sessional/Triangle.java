
public class Triangle{
    public int a;
    public int b;
    public int c;

    public Triangle(){
        a = b = c = 0;
    }
    public Triangle(int a, int b, int c) throws NoTriangleFormException{
        if((a + b < c) || (b + c < a) || (c + a <  b)){
            throw new NoTriangleFormException("Not a a valid Triangle");
        }
        this.a = a;
        this.b = b;
        this.c = c;
    }
    public static void main(String[] args){
        Triangle triangle = new Triangle();
        try{
            triangle = new Triangle(1, 4, 6);
        }catch(NoTriangleFormException e){
            System.out.println(e);
            return;
        }
        triangle.display();
    }
    public double find_area90(){
        double s = (a + b + c)/2;
        double area = Math.sqrt(s*(s-a)*(s-b)*(s-c));
        return area;
    }
    public double find_perimeter(){
        double perimeter = a + b +c;
        return perimeter;
    }
    void display(){
        System.out.println("Area : "+find_area90()+"\nPerimeter : "+find_perimeter());
    }
}

class NoTriangleFormException extends Exception{
    public NoTriangleFormException(String str) {
        super(str);
    }
}