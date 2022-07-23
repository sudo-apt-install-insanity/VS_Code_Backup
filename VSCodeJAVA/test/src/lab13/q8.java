import java.io.*;

public class q8 {
    public static void main(String[] args) throws IOException {

        FileInputStream in = new FileInputStream("inb.txt");
        FileOutputStream out = new FileOutputStream("outb.txt");
        int c;
        System.out.println("Reading and Writing to file using byte stream .........");
        while ((c = in.read()) != -1) {
            System.out.print((char) c);
            out.write(c);
        }
        in.close();
        out.close();
        System.out.println("\n");
        c = 0;
        System.out.println("Reading and Writing to file using char stream .........");
        
        FileReader inc = new FileReader("inc.txt");
        FileWriter outc = new FileWriter("outc.txt");
        while ((c = inc.read()) != -1) {
            outc.write(c);
            System.out.print((char) c);
        }
        inc.close();
        outc.close();
    }
}