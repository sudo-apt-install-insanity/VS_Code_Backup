package extras;
public class equation {
    int a,b,c;
    double r1,r2;
    void setCoeff(int x,int y,int z){
        a = x;
        b = y;
        c = z;
    }
    void findRoots(){
        r1 = ((0-b) + Math.sqrt(Math.pow(b,2) - (4 * a * c)))/2 * a;
        r2 = ((0-b) - Math.sqrt(Math.pow(b,2) - (4 * a * c)))/2 * a;
    }

}
