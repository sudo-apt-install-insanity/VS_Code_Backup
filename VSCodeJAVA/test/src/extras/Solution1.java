package extras;
import java.util.Scanner;

class PhotoFrame {
    private int id;
    private int length;
    private int breadth;
    private String material;


    PhotoFrame(){
        id = 0;
        length = 0;
        breadth = 0;
        material = ""; 
    }
    PhotoFrame(int id,int length,int breadth,String material){
        this.id = id;
        this.length = length;
        this.breadth = breadth;
        this.material = material; 
    }

    int getId(){
        return id;
    }
    int getLength(){
        return length;
    }
    int getBreadth(){
        return breadth;
    }
    String getMaterial(){
        return material;
    }

    void printPhotoFrame(){
        System.out.println("id-"+id);
        System.out.println("Length-"+length);
        System.out.println("Breadth-"+breadth);
        System.out.println("Material-"+material);
    }

};

public class Solution1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if(!sc.hasNext()){
            sc.close();
            return;
        }
        

        int size = sc.nextInt();

        PhotoFrame[] list = new PhotoFrame[size];
        for(int i = 0;i < size ; i++){
            int id = sc.nextInt();
            int l = sc.nextInt();
            int b = sc.nextInt();
            sc.nextLine();
            String mat = sc.nextLine();
            list[i] = new PhotoFrame(id,l,b,mat);
        }
        String material = sc.nextLine();

        

        double average = getAverageAreaOfPhotoFramesByMaterial(list, material);
        if(average > 0 )
            System.out.println(average);
        else
            System.out.println("No such Photo Frame available.");

        PhotoFrame answer = findPhotoFrameWithSecondLargestBreadth(list);
        if(answer != null && answer.getMaterial().equalsIgnoreCase(material)){
            answer.printPhotoFrame();
        }
        else{
            System.out.println("No such Photo Frame available.");
        }
            
        sc.close();
    }


    static double getAverageAreaOfPhotoFramesByMaterial(PhotoFrame[] list,String material){
        double totalArea = 0;
        int count = 0;
        for(PhotoFrame i : list){
            String currentMaterial = i.getMaterial();
            if(currentMaterial.equalsIgnoreCase(material)){
                totalArea += (i.getLength() * i.getBreadth());
                count++;
            }
        }
        if(count == 0)
            return 0;
        if(totalArea/count < 25)
            return 0;
        return totalArea/count;
    }

    static PhotoFrame findPhotoFrameWithSecondLargestBreadth(PhotoFrame[] list){
        PhotoFrame ans = new PhotoFrame();
        for (int i = 0; i < list.length; i++) {
            for (int j = 1; j < list.length; j++) {
                if (list[i].getBreadth() > list[j].getBreadth()) {
                    PhotoFrame temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
        ans = list[list.length - 1 - 1];
        return ans;
    }
}