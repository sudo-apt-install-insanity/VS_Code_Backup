import java.util.Scanner;

class Sapling {
    private int id;
    private String name;
    private int count;
    private int price;

    int getId() {
        return id;
    }

    String getName() {
        return name;
    }

    int getCount() {
        return count;
    }

    int getPrice() {
        return price;
    }

    void setId(int id) {
        this.id = id;
    }

    void setName(String name) {
        this.name = name;
    }

    void setCount(int count) {
        this.count = count;
    }

    void setPrice(int price) {
        this.price = price;
    }

    Sapling() {
        id = 0;
        name = "";
        count = 0;
        price = 0;
    }

    Sapling(int id, String name, int count, int price) {
        this.name = name;
        this.id = id;
        this.count = count;
        this.price = price;
    }

    Sapling(Sapling obj) {
        this.id = obj.id;
        this.name = obj.name;
        this.count = obj.count;
        this.price = obj.price;
    }

};

public class Solution1 {
    public static void main(String[] args) {
        Sapling[] list = new Sapling[4];
        Sapling[] ans = new Sapling[4];
        for (int i = 0; i < ans.length; i++) {
            ans[i] = new Sapling();
        }
        int count;
        int price;
        int avg;
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 4; i++) {
            list[i] = new Sapling();
            list[i].setId(sc.nextInt());
            sc.nextLine();
            list[i].setName(sc.nextLine());
            list[i].setCount(sc.nextInt());
            list[i].setPrice(sc.nextInt());
        }
        count = sc.nextInt();
        price = sc.nextInt();
        // System.out.println(findAvgOfCount(list,count));
        avg = findAvgOfCount(list, count);
        if (avg == 0)
            System.out.println("No record found.");
        else
            System.out.println(avg);

        list = sortNameByPrice(list, price);
        for (int i = 0; i < list.length - 1; i++) {
            if (list[0].getId() != 0) {
                System.out.println(list[i].getName());
            }
        }
        if (list[0].getId() == 0) {
            System.out.println("No record found with mentioned attribute.");
        }

        sc.close();
    }

    static int findAvgOfCount(Sapling[] list, int count) {
        int avg = 0, c = 0;
        for (int i = 0; i < list.length; i++) {
            if (list[i].getCount() < count) {
                avg += list[i].getCount();
                c++;
            }
        }
        if (c == 0)
            return 0;
        return avg / c;
    }

    static Sapling[] sortNameByPrice(Sapling[] list, int price) {
        for (int i = 0; i < list.length - 1; i++) {
            for (int j = i + 1; j < list.length; j++) {
                if (list[i].getPrice() > list[j].getPrice()) {
                    Sapling temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }
        int x = 0;
        Sapling[] ans = new Sapling[4];
        for (int i = 0; i < list.length; i++) {
            if (list[i].getPrice() < price) {
                ans[x] = new Sapling(list[i]);

            } else {
                ans[x] = new Sapling();
            }
            x++;
        }
        return ans;
    }
}