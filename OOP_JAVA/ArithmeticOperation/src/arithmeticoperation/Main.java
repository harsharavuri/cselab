/*
 * Main.java
 *
 * Created on March 10, 2016, 2:13 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package arithmeticoperation;
import java.util.*;
import java.lang.*;
/**
 *
 * @author c147241
 */

public class Main {
    
    public static void main(String[] args) {
        // TODO code application logic here
        int choice=0;
        int a=1;
        int b=1;
        int final_value=0;
        Operations Operation = new Operations();
        Scanner sc = new Scanner(System.in);
        do{
            System.out.println("Enter the values of the variables");
            a=sc.nextInt();
            b=sc.nextInt();
            System.out.println("Enter 1 for addition, 2 for sub, 3 for mul, 4 for division, 0 to exit");
            choice=sc.nextInt();
            switch(choice){
                case 1:final_value = Operation.add(a,b);break;
                case 2:final_value = Operation.subtract(a,b);break;
                case 3:final_value = Operation.multiply(a,b);break;
                case 4:final_value = Operation.divide(a,b);break;
                default:{System.out.println("Wrong Input, exiting ....");return;}
                        
            }
            System.out.println("Required Value is: "+final_value);
            
                
        }while(choice==1||choice==2||choice==3||choice==4);
    }
    
}
