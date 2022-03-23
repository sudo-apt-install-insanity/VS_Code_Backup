package lab7;

class shape 
{
    int l,w;
    shape(int length,int width)
    {
        l=length;
        w=width;
    }
}
class box extends shape
{
    int h;
    box(int length,int width,int height)
    {
        super(length,width);
        h=height;
    }
}
class woodbox extends box
{
    int t;
    woodbox(int length,int width,int height,int thick)
    {
        super(length,width,height);
        t=thick;
    }
    void show()
    {
        System.out.println("Length : "+l);
        System.out.println("Breadth : "+w);
        System.out.println("Height : "+h);
        System.out.println("Thickness : "+t);
    }
    public static void main(String args[])
    {
        woodbox obj=new woodbox(10,20,30,5);
        obj.show();
    }
}