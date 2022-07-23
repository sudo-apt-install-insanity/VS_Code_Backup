 class Employee {
    public String name;
    public int Emp_ID;
    public double Basic_Salary;
    public double Gross_Salary;

    public Employee(String name, int emp_ID, double basic_Salary) {
        this.name = name;
        Emp_ID = emp_ID;
        Basic_Salary = basic_Salary;
    }

    public double find_GrossSalary(){
        Gross_Salary = Basic_Salary;
        return Gross_Salary;
    }
}

class TechEmp extends Employee{
    public TechEmp(String name, int emp_ID, double basic_Salary) {
        super(name, emp_ID, basic_Salary);    
    }
    public double find_GrossSalary(){
        Gross_Salary = Basic_Salary + (Basic_Salary * 1.2) + (Basic_Salary * 0.15);
        return Gross_Salary;
    }
}

class NotechEmp extends Employee{

    public int years_of_experience;
    public NotechEmp(String name, int emp_ID, double basic_Salary, int years_of_Experience) {
        super(name, emp_ID, basic_Salary);
        this.years_of_experience = years_of_Experience;
    }

    public double find_GrossSalary(){
        Gross_Salary = Basic_Salary * years_of_experience;
        return Gross_Salary;
    }
}

public class Demo{
    public static void main(String[] args) {
        Employee techEmployee = new TechEmp("Ainesh", 1234, 1000);
        System.out.println("Tech Employee Details");
        System.out.println("Name: " + techEmployee.name);
        System.out.println("Emp ID: " + techEmployee.Emp_ID);
        System.out.println("Emp Salary: " + techEmployee.Basic_Salary);
        System.out.println("Gross Salary: " + techEmployee.find_GrossSalary());


        Employee nonTechEmployee = new NotechEmp("Ainesh", 1234, 1000, 10);
        System.out.println("\nNon Tech Employee Details");
        System.out.println("Name: " + nonTechEmployee.name);
        System.out.println("Emp ID: " + nonTechEmployee.Emp_ID);
        System.out.println("Emp Salary: " + nonTechEmployee.Basic_Salary);
        System.out.println("Gross Salary: " + nonTechEmployee.find_GrossSalary());


    }
}