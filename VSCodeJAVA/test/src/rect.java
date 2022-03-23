public class rect {
    int base,height;

    rect(){
        base = 4;
        height = 5;
    }
    rect(int base,int height){
        this.base = base;
        this.height = height;
    }
    int findPerimeter(){
        return 2*(base+height);
    }

    int findArea(){
        return base*height;
    }
    
}
