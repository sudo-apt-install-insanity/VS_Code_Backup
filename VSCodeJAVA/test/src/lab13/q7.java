public class q7 {
    public static void main(String[] args) {
        String s1 = "fool";
        String s2 = "wool";
        System.out.println("s1.regionMatches(1, s2, 1, 3) : " + s1.regionMatches(1, s2, 1, 3));
        System.out.println("s1.startsWith(ool,1) : " + s1.startsWith("ool", 1));
        System.out.println("s1.startsWith(ool) : " + s1.startsWith("ool"));
        System.out.println("s2.endsWith(ool,1) : " + s2.endsWith("ool"));
        System.out.println("s1.compareTo(s2) : " + s2.compareTo(s1));
        s1 = s1 +" "+ s2;
        System.out.println("s1.indexOf('l') : " + s1.indexOf('l'));
        System.out.println("s1.indexOf('l',5) : " + s1.indexOf('l',5));
        System.out.println("s1.indexOf(ol) : " + s1.indexOf("ol"));
        System.out.println("s1.indexOf(ol,5) : " + s1.indexOf("ol",5));
        
    }
}