/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment1;
import java.lang.*;
import java.util.*;
/**
 *
 * @author c147241
 */
class Extra{
    public static void prob1(){
            Random r1 = new Random();
            //Random r2 = new Random();
            int []a = new int[10];
            double []b = new double[10];
            for(int i=0;i<10;i++){
                a[i] = r1.nextInt(100);
                b[i] = r1.nextInt(49) + r1.nextInt(99)/100;
            }
            System.out.println("Integer Sum is: "+prob1.average(a)+"\n Double sum is:  "+ prob1.average(b) );
   }
    public static void prob3(){
        Account_prob3 []acc = new Account_prob3[5];
        for(int i=0;i<5;i++){
            acc[i]=new Account_prob3(i*1000,i*1000);
            acc[i].mod_annualInterestRate(3);
            acc[i].withdraw(500);
            acc[i].deposit(1000);
            System.out.println("Account "+i+":");
            acc[i].print();
        }
            
        }
    
    public static void prob_5(){
        for(int i=0;i<18;i++){
            prob5.add("a"+i, "CSE");
        }
        prob5.drop("a14");
        for(int i=0;i<18;i++){
            System.out.println(prob5.N[i]+" is added into "+prob5.C[i]);
        }
    }
    public static void bankmod(){
            Bank_mod check=new Bank_mod(1,100000,3,6);
            check.print();
            ArrayList al= new ArrayList();
            for(int i=1;i<=5;i++){
                System.out.println("Input the interest");
                Scanner sc=new Scanner(System.in);
                int interest=sc.nextInt();
                check=new Bank_mod(i,1000*i,interest,i*3);
                al.add(check);
                check.printcd();
        }
            
    }
       
    }

public class Assignment1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int check=4;
        if(check==7)StrikerGame.playgame();
        if(check==1)Extra.prob1();
        if(check==2)prob2.least_dist();
        if(check==3)Extra.prob3();
        if(check==4)prob4.local_main();
        if(check==5)Extra.prob_5();
        if(check==6)Extra.bankmod();
    }
}
